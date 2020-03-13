using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//implementing the Jordan-Gauss method + rectangle method
namespace L1_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }
        public int currentRow = 0;//для прорисовки промежуточных решений
        public int n1;//число строк
        public int n2;//число столбцов
        public Drob[,] mas;//матрица

        public string[] elems;//список имён вершин для подписи в матрице       
        public Drob[,] masBumaga;//массив для хранения матрицы в коде
        public double[,] masBumaga2;//массив для запоминания вводимых матриц
        public bool load;
        public bool flagSolved = false;

        private void button1_Click(object sender, EventArgs e)//                    "Build a table"
        {
            load = false;
            n1 = Convert.ToInt32(numericUpDown1.Value);
            n2 = Convert.ToInt32(numericUpDown2.Value);
            elems = new string[n2];
            for (int i = 0; i < n2; i++) { elems[i] = "X" + Convert.ToString(i); }
            Random rand = new Random();
            if (n1 != 0 && n2 != 0)
            {
                mas = new Drob[n1, n2];//the matrix to solve 
                dataGridView1.RowCount = n1 * 100;
                dataGridView1.ColumnCount = n2;
                dataGridView1.AutoSizeColumnsMode =
                    DataGridViewAutoSizeColumnsMode.DisplayedCells;

                fillTable();
            }
            initilaizeHeaders();
        }
        private void button2_Click(object sender, EventArgs e) //                   "Load"
        {

            load = true;
            n1 = 5; n2 = 6;
            mas = new Drob[n1, n2];//the matrix to solve 
            masBumaga = new Drob[n1, n2];//the matrix to solve 
            dataGridView1.RowCount = n1 * 100;
            dataGridView1.ColumnCount = n2;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
            /* 1 2 3 | 5
             * 4 5 6 | 8
             * 7 8 0 | 2
             */
            /* masBumaga[0, 0] = new Drob(1, 1); masBumaga[0, 1] = new Drob(2, 1); masBumaga[0, 2] = new Drob(3, 1); masBumaga[0, 3] = new Drob(5, 1);
             masBumaga[1, 0] = new Drob(4, 1); masBumaga[1, 1] = new Drob(5, 1); masBumaga[1, 2] = new Drob(6, 1); masBumaga[1, 3] = new Drob(8, 1);
             masBumaga[2, 0] = new Drob(7, 1); masBumaga[2, 1] = new Drob(8, 1); masBumaga[2, 2] = new Drob(0, 0); masBumaga[2, 3] = new Drob(2, 1);
             */
            /* 2 -3 5 7     | 1
             * 4 -6 2 3     | 2
             * 2 -3 -11 -15 | 1
             */
            masBumaga[0, 0] = new Drob(15, 1); masBumaga[0, 1] = new Drob(-5, 1); masBumaga[0, 2] = new Drob(8, 1); masBumaga[0, 3] = new Drob(11, 1); masBumaga[0, 4] = new Drob(-6, 1); masBumaga[0, 5] = new Drob(-76, 1);
            masBumaga[1, 0] = new Drob(15, 1); masBumaga[1, 1] = new Drob(1, 1); masBumaga[1, 2] = new Drob(7, 1); masBumaga[1, 1] = new Drob(1, 1); masBumaga[1, 4] = new Drob(11, 1); masBumaga[1, 5] = new Drob(-79, 1);
            masBumaga[2, 0] = new Drob(-5, 1); masBumaga[2, 1] = new Drob(11, 1); masBumaga[2, 2] = new Drob(5, 1); masBumaga[2, 3] = new Drob(-9, 1); masBumaga[2, 4] = new Drob(10, 1); masBumaga[2, 5] = new Drob(-6, 1);
            masBumaga[3, 0] = new Drob(13, 1); masBumaga[3, 1] = new Drob(-5, 1); masBumaga[3, 2] = new Drob(-1, 1); masBumaga[3, 3] = new Drob(11, 1); masBumaga[3, 4] = new Drob(3, 1); masBumaga[3, 5] = new Drob(-27, 1);
            masBumaga[4, 0] = new Drob(15, 1); masBumaga[4, 1] = new Drob(4, 1); masBumaga[4, 2] = new Drob(-3, 1); masBumaga[4, 3] = new Drob(-1, 1); masBumaga[4, 4] = new Drob(3, 1); masBumaga[4, 5] = new Drob(-4, 1);

            mas = masBumaga;
            initilaizeHeaders();
            fillTable();
        }
        private void initilaizeHeaders()
        {
            elems = new string[n2];
            for (int i = 0; i < n2; i++)
            {
                elems[i] = "X" + Convert.ToString(i);
                if (i == (n2 - 1)) elems[i] = "= ";
            }
            for (int i = 0; i < n2; i++)
            {
                dataGridView1.Columns[i].HeaderCell.Value = elems[i];
            }
        }
        private void fillTable()//fills dataGridView with the contents of mas
        {

            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    dataGridView1.Rows[currentRow + i].Cells[j].Value = mas[i, j].toStr();
                }
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
            currentRow += (n1 + 1);//для прорисовки матрицы
        }

        private void button3_Click(object sender, EventArgs e) //                 "test"
        {
            Drob db = new Drob(0, 0);
            db.test();
        }

        private void button4_Click(object sender, EventArgs e)//                  "Solve"
        {
            if (flagSolved) return;
            //int untoucheableColumn = -1;
            //  int untoucheableRow = 0;//the solving rslvRow stays untoucheable
            Drob d = new Drob(0, 0);//just an object for functions invocation
            for (int rslvRow = 0; rslvRow < 3; rslvRow++)
            {
                bool flag = true;
                for (int column = rslvRow; flag; column++)//moving diagonally down &/or right
                {
                    if (column == n2) break;
                    if (mas[rslvRow, column].numerator == 0)//if the solving element is not 0
                        continue;
                    else// else start solving
                    {
                        Drob temp1 = (Drob)mas[rslvRow, column].Clone();//created a clone of the solving element
                        for (int i = column; i < n2; i++)
                        {
                            mas[rslvRow, i] = d.div(mas[rslvRow, i], temp1);//turning the solving element to 1
                        }
                        //FIRST CASE: first rslvRow is resolving and first element is not zero... just don't insert the first element as zero:
                        if (rslvRow == 0)//ALL THESE THREE CASES CAN BE WRITTEN IN ONE... BUT I'M TOO TIRED AND I NEED TO DO A LOT OF OTHER WORK
                        {
                            int x0 = 0, y0 = 0, x1 = 0, y1 = 1;// works for the first case for all columns!
                            int x2 = 1, y2 = 1, x3 = 1, y3 = 0;
                            for (int i = 1; i < n2; i++)//walk through the columns
                            {
                                for (; x2 < n1 || x3 < n1;)
                                {
                                    mas[x2, y2] = //колонка всегда начинается с колонки разрешающего элемента
                                            d.sub(
                                                d.mul(mas[x0, y0], mas[x2, y2]), //first diagonal multiplied
                                                d.mul(mas[x1, y1], mas[x3, y3]));

                                    x2++; x3++;//going through orange and blue squares
                                }
                                x2 = rslvRow + 1; x3 = rslvRow + 1;
                                y1++; y2++;//координаты столбцов(одного столбца по сути) сместились вправо(розовый прямоугольник)
                            }
                        }
                        //SECOND CASE: MIDDLE ROW
                        else if (rslvRow > 0 && rslvRow < n1 - 1)
                        {
                            int x0 = rslvRow, y0 = column, x1 = 0, y1 = column;
                            int x2 = 0, y2 = column + 1, x3 = rslvRow, y3 = column + 1;
                            for (int i = 1; i < n2; i++)//walk through the columns
                            {
                                for (; x1 < n1 || x2 < n1 || y2 < n2;)
                                {
                                    if (x2 == rslvRow) { x1++; x2++; } //avoiding the resolving rslvRow
                                    if (x1 == n1 || x2 == n1 || y2 == n2) break;

                                    mas[x2, y2] = //колонка всегда начинается с колонки разрешающего элемента
                                            d.sub(
                                                d.mul(mas[x0, y0], mas[x2, y2]), //first diagonal multiplied
                                                d.mul(mas[x1, y1], mas[x3, y3]));
                                    x1++; x2++;//going through orange and blue squares                           
                                }
                                x1 = 0; x2 = 0;//HERE
                                               // y1++; 
                                y2++;
                                y3++;
                                if (y2 >= n2 || y3 >= n2)
                                {
                                    break;
                                }
                            }
                        }
                        //THIRD CASE: THE LOWEST ROW IS RESOLVING
                        else if (rslvRow == (n1 - 1))
                        {
                            int x0 = rslvRow, y0 = column, x1 = 0, y1 = column;
                            int x2 = 0, y2 = column + 1, x3 = rslvRow, y3 = column + 1;
                            for (int i = 1; i < n2; i++)//walk through the columns
                            {
                                for (; x1 < n1 || x2 < n1 || y2 < n2;)
                                {
                                    if (x2 == rslvRow) { x1++; x2++; } //avoiding the resolving rslvRow
                                    if (x1 == n1 || x2 == n1 || y2 == n2 || y3 == n2) break;

                                    mas[x2, y2] = //колонка всегда начинается с колонки разрешающего элемента
                                            d.sub(
                                                d.mul(mas[x0, y0], mas[x2, y2]), //first diagonal multiplied
                                                d.mul(mas[x1, y1], mas[x3, y3]));
                                    x1++; x2++;//going through orange and blue squares
                                    //if (x1 == rslvRow || x2 == rslvRow) continue;//avoiding the resolving rslvRow
                                    //ПРОБЛЕМА С ТРЕТЬЕЙ СТРОКОЙ
                                }
                                x1 = 0; x2 = 0;//HERE                                               
                                y2++;
                                y3++;
                                if (y2 >= n2 || y3 >= n2)
                                {
                                    break;
                                }
                            }
                        }
                        for (int i = 0; i < n1; i++)//it has to be done at the end of the iteration
                        {
                            if (i == rslvRow) continue;
                            mas[i, column].numerator = 0;//turning all the other elements of the column to 0
                            mas[i, column].denominator = 0;//(as a part of the rectangle method)
                        }
                        flag = false;//next motion through the columns is unnecessary. Should go to the next rslvRow.
                    }
                    //else continue;
                    fillTable();//first step: have turned the first(solving) element to 1 and all the other elements of the column to 0
                }
            }
            String answer = "";
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n2 - 1; j++)
                {
                    if (mas[i, j].numerator != 0)
                    {
                        if (mas[i, j].numerator == 1 && mas[i, j].denominator == 1)
                        {
                            if (mas[i, j].numerator > 0)
                                answer += (" + " + elems[j] + " ");
                            else
                                if (mas[i, j].numerator < 0)
                                answer += (" - " + elems[j] + " ");
                        }
                        else
                        {
                            if (mas[i, j].numerator > 0)
                                answer += ("  +  " + mas[i, j].toStr() + "*" + elems[j] + " ");
                            else
                                if (mas[i, j].numerator < 0)
                                answer += (mas[i, j].toStr() + "*" + elems[j] + " ");
                        }
                    }
                }
                if (answer.Length > 0)
                {
                    answer += ("  =  " + mas[i, n2 - 1].toStr() + "; \n\n");
                    textBox1.Text += answer;
                    answer = "";
                }
            }
            flagSolved = true;//защита от повторного нажатия кнопки solve
        }
    }
}
////second case: one of the middle rows is resolving
//if(rslvRow > 0 && rslvRow < n1 - 1)
//{
//    int x0 = 0, y0 = 0, x1 = 0, y1 = 1;
//    int x2 = 1, y2 = 1, x3 = 1, y3 = 0;
//    for (; x2 < n1 || x3 < n1;)
//    {
//        mas[x2, y2] = //колонка всегда начинается с колонки разрешающего элемента
//                d.sub(
//                    d.mul(mas[x0, y0], mas[x2, y2]), //first diagonal multiplied
//                    d.mul(mas[x1, y1], mas[x3, y3]));
//        x2++; x3++;
//    }
//}


//untoucheableRow = rslvRow;//this rslvRow is needed to skip during the solving

//temp1 = mas[rslvRow, column];//the reneved solving element(1/1)// these rslvRow & column will stay... 
////I can rely on these coordinates
//for (int rowS = 0, columnS = column; rowS < n1-1; rowS++)
//{
//    //int rowT = rowS + 1;
//    int columnT = column + 1;
//    int x0 = rowS, y0 = column, x1 = rowS, y1 = columnS;
//    int x2 = rowS + 1, y2 = columnS + 1, x3 = rowS + 1, y3 = column + 1;
//    if (rowS == untoucheableRow) continue;//пытаюсь проскочить через разрешающий ряд
//    //if()
//    else mas[rowS, columnS] = //колонка всегда начинается с колонки разрешающего элемента
//            d.sub(
//                d.mul(mas[x0, y0], mas[x2, y2]), //first diagonal multiplied
//                d.mul(mas[x1, y1], mas[x3, y3]));
//}
