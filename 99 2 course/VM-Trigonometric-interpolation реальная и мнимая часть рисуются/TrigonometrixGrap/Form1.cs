using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Math;
using System.Numerics; // Для комплексных чисел

namespace TrigonometrixGrap
{
    public partial class Form1 : Form
    {
        // Колличество точек, по которым интерполируем (по умолчанию)
        public int NNN = 4;

        public Form1()
        {
            InitializeComponent();
            // При загрузке формы:

            // Прописываем кол-во точек в textBoxe'e
            textBoxCount.Text = NNN.ToString();
            
            // Значения по умолчанию для функции
            double[,] dataHomeWork = new double[NNN, 2];
            for(double i=0, x = 0; i<NNN; i++, x+=3)
            {
                dataHomeWork[(int)i, 0] = x;
                dataHomeWork[(int)i, 1] = x;
            }

            // Определим кол-во строк и столбцов в dataGridView
            dataGridView1.RowCount = dataHomeWork.GetLength(0);
            dataGridView1.ColumnCount = dataHomeWork.GetLength(1);

            // Пишем значения из массива в ячейки dataGrodView1
            for (int i = 0; i < dataHomeWork.GetLength(0); i++)
            {
                for (int j = 0; j < dataHomeWork.GetLength(1); j++)
                {
                    dataGridView1.Rows[i].Cells[j].Value = dataHomeWork[i, j];
                }
            }
        }

        // Кнопка ПОСТРОИТЬ ГРАФИКИ
        private void button3_Click(object sender, EventArgs e)
        {
            Graphics g = pictureBox1.CreateGraphics();
            g.TranslateTransform((float)pictureBox1.Width / 2, (float)pictureBox1.Height / 2);
            DrawBorder();
                      
            int cx = pictureBox1.Width;
            int cy = pictureBox1.Height;

            // Колличество точек, по которым строим график
            int N = NNN;
            // Массив точек оригинального графика
            PointF[] originalF = new PointF[N];

            // Массив с точками интерполчции, который будет передаваться в функцию интерполяции
            double[,] inputData = new double[2, N];
            for (int i = 0; i < N; i++)
            {
                //Преобразуем значения из ячеек в числа, и пишем в массив
                inputData[0, i] = originalF[i].X = Convert.ToInt32(dataGridView1.Rows[i].Cells[0].Value);
                inputData[1, i] = originalF[i].Y = Convert.ToInt32(dataGridView1.Rows[i].Cells[1].Value);
            }

            // ИНТЕРПОЛЯРНУТЫЙ ГРАФИК
            // Определим, сколько нам нужно точек, что бы его нарисовать
            double oblastOpr = originalF[N - 1].X - originalF[0].X;
            PointF[] interpolReal = new PointF[(int)(oblastOpr * 250)];
            PointF[] interpolImage = new PointF[(int)(oblastOpr * 250)];

            double step = originalF[0].X;
            for (int i = 0; i < oblastOpr * 250; i++)
            {
                step += 0.004; // 1/250
                
                // Заполняем график реальной частти
                interpolReal[i].X = (float)step;
                interpolReal[i].Y = ((float)Interpolation_Trigonometrix(inputData, step, N).Real) * (-1);

                // Заполняем график мнимой части
                interpolImage[i].X = (float)step;
                interpolImage[i].Y = ((float)Interpolation_Trigonometrix(inputData, step, N).Imaginary) * (-1);
            }

            // Меняем все Y знак напротивоположный в связи с особенностью координат графики.
            for (int i = 0; i < N; i++)
            {
                originalF[i].X = originalF[i].X * 25;
                originalF[i].Y = originalF[i].Y * -1 * 25;
            }

            //Рисуем точки построения оригинального графика
            Pen pen = new Pen(Brushes.Blue, 3F);
            for (int i = 0; i < N; i++)
            {
                g.DrawEllipse(pen, originalF[i].X, originalF[i].Y, 2, 2);
            }
                
            // Рисуем оригинальный график. Точки, соединенные линиями.
            Pen a = new Pen(Color.Black, 2);
            g.DrawLines(a, originalF);

            // Выводим приближенные графики 
            for (int i = 0; i < oblastOpr * 250; i++)
            {
                // Реальной части
                g.FillRectangle(Brushes.Red, interpolReal[i].X*25, interpolReal[i].Y*25, 1, 1);
                // И мнимой части
                g.FillRectangle(Brushes.Green, interpolImage[i].X*25, interpolImage[i].Y*25, 1, 1);
            }
        }

        // Кнопка ПЕРЕРИСОВАТЬ
        private void button1_Click(object sender, EventArgs e)
        {
            Graphics g = pictureBox1.CreateGraphics();
            g.Clear(Color.White);
            DrawBorder();
        }

        // ТРИГОНОМЕТРИЧЕСКАЯ ИНТЕРПОЛЯЦИЯ
        // На вход подаётся динамический массив с точками интерполяции, точка в которой нужно найти значение y и колличество точек интерполяции
        public Complex Interpolation_Trigonometrix(double[,] dataMatrix, double x, int N)
        {
            // Переменная комплексного числа. Стандартная библитека System.Math
            Complex y = new Complex(0,0);

            // Определим число точек интерполяции и размер шага
            double n = N, h = dataMatrix[0, 1] - dataMatrix[0, 0];
            
            // Создадим массив комплексных чисел
            Complex[] massA = new Complex[N];

            // Формула (4.18б)
            for (double j=-(n/2)+1, i=0; j<=(n/2); j++, i++)
            {
                // Окугляем число до целого. !!! Нужно для случая с нечетным числом точек интерполяции
                j = Floor(j); // стандартная библиотека System.Math

                Complex Temp = new Complex(0, 0);
                for (double k = 0; k < n; k++)
                {
                    //MessageBox.Show("j = " + j.ToString() + "\n" + "k = " + k.ToString());          //
                    double xx = (PI * -2 * (k * j / n));
                    Complex temmp = new Complex(Cos(xx), Sin(xx));
                    Temp = Temp + dataMatrix[1, (int)k] * temmp;
                }
                Temp /= n;
                massA[(int)i] = Temp;
            }

            // Найдем значение в конкретной точке
            Complex temp = new Complex(0,0);
            
            // Формула (4.18а)
            for (double j = -(n / 2)+1, i = 0; j <= (n / 2); j++, i++)
            {
                // Окугляем число до целого. !!! Нужно для случая с нечетным числом точек интерполяции
                j = Floor(j); // стандартная библиотека System.Math

                //MessageBox.Show("j = " + j.ToString());                                             //
                double xx = (2 * PI * j * ((x - dataMatrix[0, 0]) / (n * h)));
                Complex tempp = new Complex(Cos(xx), Sin(xx));
                temp = temp + massA[(int)i] * tempp;
            }
            y = temp;
            // Возвращаем комплексное число
            return y;
        }

        // Отрисовка рамки и системы координат
        public void DrawBorder()
        {
            Graphics g = pictureBox1.CreateGraphics();
            g.Clear(Color.White);
            int a = pictureBox1.Width;
            int b = pictureBox1.Height;
            for (int i = 0; i < a; i += 25)
            {
                Point aa = new Point(), bb = new Point();
                aa.X = i - 1;
                aa.Y = b / 2 - 5;
                bb.X = i - 1;
                bb.Y = b / 2 + 5;
                g.DrawLine(Pens.Silver, aa, bb);
                g.DrawString(((a / 25 / 2 - i / 25 + 1) * -1).ToString(), new Font("Cambria", 8), Brushes.Silver, new PointF(aa.X - 8, aa.Y + 15));
            }
            for (int i = 0; i < b; i += 25)
            {
                Point aa = new Point(), bb = new Point();
                aa.X = a / 2 - 5;
                aa.Y = i + 5;
                bb.X = a / 2 + 5;
                bb.Y = i + 5;
                g.DrawLine(Pens.Silver, aa, bb);
                g.DrawString(((b / 25 / 2 - i / 25 + 1) - 2).ToString(), new Font("Cambria", 8), Brushes.Silver, new PointF(aa.X - 14, aa.Y + 18));
            }
            Pen blackPen = new Pen(Color.Black, 3);
            blackPen.Width = 1; 
            Rectangle Rectangle = new Rectangle(0, 0, a - 1, b - 1);
            g.DrawRectangle(blackPen, Rectangle);
            g.DrawLine(blackPen, a / 2, 0, a / 2, b);
            g.DrawLine(blackPen, 0, b / 2, a, b / 2);
            g.Dispose();
        }

        // Обработчик события для textBox'a
        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                dataGridView1.RowCount  = Convert.ToInt32(textBoxCount.Text);
                NNN = Convert.ToInt32(textBoxCount.Text);
                dataGridView1.ColumnCount = 2;
            }
        }
    }
}
