using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Windows.Forms;
//using System.Collections.ObjectModel.ArrayList;


namespace L0
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public int n;
        public int m;
        double[,] mas;
        public string[] elems;

        private void button1_Click(object sender, EventArgs e)//the Start button
        {
            // This will equal Infinity.
            // Console.WriteLine("PositiveInfinity plus 10.0 = "+ (Double.PositiveInfinity + 10.0).ToString());
            n = Convert.ToInt32(numericUpDown1.Value);
            if (n > 1000 || n < 0)
            {
                MessageBox.Show("Значение N в множестве по умолчанию не м.б. более 1000");
                numericUpDown1.Value = n = 0;
                return;
            }

            elems = new string[n];
            for (int i = 0; i < n; i++) { elems[i] = "V" + Convert.ToString(i); }

            Random rand = new Random();
            if (n != 0)
            {
                mas = new double[n, n];
                dataGridView1.RowCount = n;
                dataGridView1.ColumnCount = n;
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

                double[,] masBumaga = new double[n, n];
                for (int ii = 0; ii < n; ++ii)
                {
                    for (int jj = 0; jj < n; ++jj)
                    {
                        masBumaga[ii, jj] = Double.PositiveInfinity;// на старте длины рёбер бесконечны(связей нет)
                    }
                }
                masBumaga[0, 1] = 5; masBumaga[1, 0] = 5; masBumaga[0, 2] = 7; masBumaga[2, 0] = 7;
                masBumaga[0, 4] = 1; masBumaga[4, 0] = 1; masBumaga[4, 3] = 3; masBumaga[3, 4] = 3;
                masBumaga[3, 2] = 2; masBumaga[2, 3] = 2; masBumaga[1, 2] = 6; masBumaga[2, 1] = 6;
                masBumaga[1, 4] = 4; masBumaga[4, 1] = 4;
                //Console.WriteLine("masBumaga[1, 4] = " + masBumaga[1, 4]);
                //Console.WriteLine("masBumaga[1, 3] = " + masBumaga[1, 3]);
                for (int i0 = 0; i0 < n; ++i0)
                {
                    dataGridView1.Rows[i0].HeaderCell.Value = elems[i0].ToString();//называю хедеры рядов(строк) именами elems
                    for (int j0 = 0; j0 < n; ++j0)
                    {
                        mas[i0, j0] = Double.PositiveInfinity;// на старте длины рёбер бесконечны(связей нет)
                        mas[i0, j0] = masBumaga[i0, j0];
                        dataGridView1.Columns[j0].HeaderCell.Value = elems[j0].ToString();//называю хедеры колонок(столбцов) именами elems
                                                                                          // mas[i, j] = rand.Next(20);
                        dataGridView1.Rows[i0].Cells[j0].Value = mas[i0, j0];
                    }
                }
            }

            else
            {
                MessageBox.Show("N не может быть нулевым");
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
        }
        private void makeSymmetrical()
        {

        }
        private void button3_Click(object sender, EventArgs e)//это кнопка Check
        {
            int i = 0, j = 0;
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {//двойная некрасивая проверка на правильность матрицы бинарного отношения(проверяет, использованы ли допустимые символы)
                    try
                    {//это присвоение чисел из таблички и скорее всего проверка на символы, не являющиеся числами
                        mas[i, j] = Convert.ToDouble(dataGridView1.Rows[i].Cells[j].Value);
                    }
                    catch (Exception ee)//типа если не удалось конвертнуть, то это не было числом
                    {
                        MessageBox.Show("Значения ячеек м.б. только числами.\n" +
                            "Проверьте ячейку [" + i + "][" + j + "] (" + elems[i] + ", " + elems[j] + ")", "неверный ввод",
     MessageBoxButtons.OK, MessageBoxIcon.Error); Console.WriteLine(ee); return;
                    }
                }
            }
            symmetryCheck();
            antySymmetryCheck();
            transitivityCheck();
        }

        public void symmetryCheck()
        {
            int i = 0, j = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                {
                    if (mas[i, j] != mas[j, i])
                    {
                        textBox3.Text = "Отношение не симметрично, т.к. (" + elems[i] + ", " + elems[j] +
                            ") не равно (" + elems[j] + ", " + elems[i] + ")";
                        return;
                    }
                    else continue;
                }
            textBox3.Text = "Отношение симметрично, т.к. все симметричные относительно главной диагонали элементы матрицы равны";
        }
        public void antySymmetryCheck()
        {
            int i = 0, j = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    if ((mas[i, j] == mas[j, i]) && mas[i, j] != 0)
                    {
                        textBox4.Text = "Отношение не антисимметрично, т.к. (" + elems[i] + ", " + elems[j] +
                            ") равно (" + elems[j] + ", " + elems[i] + ")";
                        return;
                    }
                    else continue;
                }
            textBox4.Text = "Отношение антисимметрично, т.к. все единич. эл-ты преобразованиемием симметрии отн. главн. диаг. переходят в нули";
        }
        public void transitivityCheck()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mas[i, j] == 1)//нахожу существующую связь между i & j
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (mas[j, k] == 1 && !(mas[i, k] == 1))//начинаю перебирать варианты k куда может привести j
                            {//и есть ли путь из i в k. Если нет, то транзитивность отсутствует
                                textBox5.Text = "Отношение не транзитивно, т.к. (" + elems[i] + ", " + elems[j] +
                            ") равно 1, (" + elems[j] + ", " + elems[k] + ") равно 1, а ("
                            + elems[i] + ", " + elems[k] + ")  не равно 1";
                                return;
                            }
                        }
                    }
                }
            }
            textBox5.Text = "Отношение транзитивно, т.к. (a, b) & (b, c) => (a, c) выполняется для любых трёх элементов";
            return;
        }
        private void sizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.Owner = this;
            f.ShowDialog();
        }
        private void button4_Click(object sender, EventArgs e)//AllInfinity
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = double.PositiveInfinity;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
        }
        private void button2_Click(object sender, EventArgs e)//All0
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = 0;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
        }
        private void button5_Click(object sender, EventArgs e)//TransExamp
        {
            button2_Click(sender, e);
            mas[0, 1] = 1;
            dataGridView1.Rows[0].Cells[1].Value = mas[0, 1];
            mas[1, 2] = 1;
            dataGridView1.Rows[1].Cells[2].Value = mas[1, 2];
            mas[0, 2] = 1;
            dataGridView1.Rows[0].Cells[2].Value = mas[0, 2];
        }
        private void button6_Click(object sender, EventArgs e)//задать новое множество
        {
            string s = textBox7.Text;
            elems = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            elems = elems.Distinct().ToArray();
            n = elems.Length;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    if (String.Compare(elems[j], elems[i]) > 0)
                    {
                        string tmp = elems[j];
                        elems[j] = elems[i];
                        elems[i] = tmp;
                    }
                }
            Random rand = new Random();
            if (n != 0)
            {
                dataGridView1.RowCount = n;
                dataGridView1.ColumnCount = n;
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

                mas = new double[n, n];
                int i, j;
                for (i = 0; i < n; ++i)
                {
                    dataGridView1.Rows[i].HeaderCell.Value = elems[i].ToString();//называю хедеры рядов(строк) именами elems
                    for (j = 0; j < n; ++j)
                    {
                        dataGridView1.Columns[j].HeaderCell.Value = elems[j].ToString();//называю хедеры колонок(столбцов) именами elems
                        mas[i, j] = rand.Next(2);
                        dataGridView1.Rows[i].Cells[j].Value = mas[i, j];

                    }
                }
            }
            else
            {
                MessageBox.Show("N не может быть нулевым");
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
        }
        private void Button7_Click(object sender, EventArgs e)//кнопка "сделать неориентированным"
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = mas[j, i];
                }
            }
        }
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ФИО: Алексеев С.В. \nГруппа:ИП-712");
        }
        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Реализую алгоритм Дейкстры");
        }
        private void DataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {// Была пролблема: Не получется интерактивно менять значения datagridview и массива mas почему-то. 
            if (checkBox1.Checked)
            {
                Int32 i = e.RowIndex;
                Int32 j = e.ColumnIndex;// получилось, просто забывал конвертнуть всё время
                mas[i, j] = Convert.ToDouble(dataGridView1.Rows[i].Cells[j].Value);
                dataGridView1.Rows[j].Cells[i].Value = mas[i, j];
            }
        }

        private void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void CheckBox1_CheckStateChanged(object sender, EventArgs e)
        {

        }

        protected struct MyEdge//вот эти рёбрышки надо добавлять/удалять в алгоритме Краскала
        {
            public string name;
            public void setF(int hh) { from = hh; }
            public int from;//из какой вершины направлен
            public void setv1(string hh) { vertice1 = hh; }
            public String vertice1;//типа может быть буду проверку полноты остова проверять именами
            public void setTo(int hh) { to = hh; }
            public int to;//в какую вершину направлен
            public void setv2(string hh) { vertice2 = hh; }
            public String vertice2;
            public void setW(double hh) { weight = hh; }
            public double weight;//длина ребра
        }
        protected List<MyEdge> arr;//Здесь соберу все рёбра
        public void Button7_Click_1(object sender, EventArgs e)//Краскал
        {
            //double[] edges = new double[(n * (n - 1) / 2)];// формула максимального числа рёбер(полного графа)           
            arr = new List<MyEdge>();
            for (int i = 0; i < n; i++)//Отрезаю нижний треугольник, т.к. граф  неориентированный
            {
                for (int j = 0; j < i; j++)
                {
                    mas[i, j] = double.PositiveInfinity;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!Double.IsInfinity(mas[i, j]))//если не бесконечность, значит есть вершина
                    {
                        MyEdge me = new MyEdge();
                        me.from = i;//записал в ребро  всю инфу
                        me.to = j;
                        me.vertice1 = dataGridView1.Rows[i].HeaderCell.Value.ToString();
                        me.vertice2 = dataGridView1.Columns[j].HeaderCell.Value.ToString();
                        me.weight = mas[i, j];
                        arr.Add(me);
                    }
                }
            }
            IEnumerable<MyEdge> query = arr.OrderBy(MyEdge => MyEdge.weight);//просто делает запрос, исходный массив не сортируется
            List<MyEdge> srtd = new List<MyEdge>();//список отсортированных рёбер
            for (int i = 0; i < arr.Count; i++)
            {//добавил ссылки в новый массив. srtd вроде как получился индексным             
                srtd.Add(query.ElementAt(i));
            }
            List<MyEdge> resultEdges = new List<MyEdge>();//здесь начинается уже Краскал... надеюсь
            List<string> vertices = new List<string>();
            for (int i = 0; i < srtd.Count; i++)
            {
                bool v1 = false, v2 = false;
                foreach (string str in vertices)//проходим по всем накопленным на данный момент вершинам
                {
                    if (str.Equals(srtd[i].vertice1)) v1 = true;//если очередная вершина равна одной из тех, 
                    //что в добавляемом ребре ставим флаг v1 = true
                    else if (str.Equals(srtd[i].vertice2)) v2 = true;// если и вторая вершина нового ребра уже 
                    //присутствует в списке, то ставим флаг v2 = true
                }//если хоть одна вершина оказалась новой для нас, то добавляем это ребро
                if (!v1 || !v2)
                {
                    resultEdges.Add(srtd[i]);
                    if (!v1) vertices.Add(srtd[i].vertice1);//также пополняем список вершин
                    if (!v2) vertices.Add(srtd[i].vertice2);
                }//теперь для каждой вершины прохожу путь from to и записываю посещенные вершины...нет...
                //если в итоге .... это должно быть рекурсивным вызовом... который можно произвести из любой вершины
                //если не все вершины окажутся включёнными, нужно продолжать добавлять рёбра и запускать рекурсию
                //каждый раз

            }

            for (int i = 0; i < n; i++)
            {//Все вершины в бесконечность перед обновлением матрицы
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = double.PositiveInfinity;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
            for (int a = 0; a < resultEdges.Count; a++)
            {//засовываю в mas & datagridview пересчитанные Краскалом значения
                int i = resultEdges[a].from;
                int j = resultEdges[a].to;
                double w = resultEdges[a].weight;
                mas[i, j] = w;
                dataGridView1.Rows[i].Cells[j].Value = w;
            }
        }


    }
}
