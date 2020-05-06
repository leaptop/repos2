using L1_2;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//implementing the Jordan-Gauss method + rectangle method (метод Жордана-Гауса и метод прямоугольников)
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
            n1 = 3; //number of rows
            n2 = 6; //number of columns
            mas = new Drob[n1, n2];//the matrix to solve 
            masBumaga = new Drob[n1, n2];//the matrix to solve 
            dataGridView1.RowCount = n1 * 100;
            dataGridView1.ColumnCount = n2;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

            mas[0, 0] = new Drob(5, 1); mas[0, 1] = new Drob(1, 1); mas[0, 2] = new Drob(-1, 1); mas[0, 3] = new Drob(0, 1); mas[0, 4] = new Drob(0, 1); mas[0, 5] = new Drob(12, 1);
            mas[1, 0] = new Drob(5, 1); mas[1, 1] = new Drob(4, 1); mas[1, 2] = new Drob(0, 1); mas[1, 3] = new Drob(-1, 1); mas[1, 4] = new Drob(0, 1); mas[1, 5] = new Drob(33, 1);
            mas[2, 0] = new Drob(2, 1); mas[2, 1] = new Drob(5, 1); mas[2, 2] = new Drob(0, 1); mas[2, 3] = new Drob(0, 1); mas[2, 4] = new Drob(-1, 1); mas[2, 5] = new Drob(20, 1);
            masBumaga = mas;
            //masBumaga[0, 0] = new Drob(4, 1); masBumaga[0, 1] = new Drob(-11, 1); masBumaga[0, 2] = new Drob(13, 1); masBumaga[0, 3] = new Drob(-6, 1); masBumaga[0, 4] = new Drob(8, 1); masBumaga[0, 5] = new Drob(8, 1);
            //masBumaga[1, 0] = new Drob(7, 1); masBumaga[1, 1] = new Drob(12, 1); masBumaga[1, 2] = new Drob(5, 1); masBumaga[1, 3] = new Drob(-3, 1); masBumaga[1, 4] = new Drob(9, 1); masBumaga[1, 5] = new Drob(54, 1);
            //masBumaga[2, 0] = new Drob(-6, 1); masBumaga[2, 1] = new Drob(9, 1); masBumaga[2, 2] = new Drob(-17, 1); masBumaga[2, 3] = new Drob(13, 1); masBumaga[2, 4] = new Drob(-7, 1); masBumaga[2, 5] = new Drob(-16, 1);
            //masBumaga[3, 0] = new Drob(-17, 1); masBumaga[3, 1] = new Drob(-7, 1); masBumaga[3, 2] = new Drob(-30, 1); masBumaga[3, 3] = new Drob(30, 1); masBumaga[3, 4] = new Drob(-14, 1); masBumaga[3, 5] = new Drob(-86, 1);

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
            /* masBumaga[0, 0] = new Drob(15, 1); masBumaga[0, 1] = new Drob(-5, 1); masBumaga[0, 2] = new Drob(8, 1); masBumaga[0, 3] = new Drob(11, 1); masBumaga[0, 4] = new Drob(-6, 1); masBumaga[0, 5] = new Drob(-76, 1);
             masBumaga[1, 0] = new Drob(15, 1); masBumaga[1, 1] = new Drob(1, 1); masBumaga[1, 2] = new Drob(7, 1); masBumaga[1, 3] = new Drob(1, 1); masBumaga[1, 4] = new Drob(11, 1); masBumaga[1, 5] = new Drob(-79, 1);
             masBumaga[2, 0] = new Drob(-5, 1); masBumaga[2, 1] = new Drob(11, 1); masBumaga[2, 2] = new Drob(5, 1); masBumaga[2, 3] = new Drob(-9, 1); masBumaga[2, 4] = new Drob(10, 1); masBumaga[2, 5] = new Drob(-6, 1);
             masBumaga[3, 0] = new Drob(13, 1); masBumaga[3, 1] = new Drob(-5, 1); masBumaga[3, 2] = new Drob(-1, 1); masBumaga[3, 3] = new Drob(11, 1); masBumaga[3, 4] = new Drob(3, 1); masBumaga[3, 5] = new Drob(-27, 1);
             masBumaga[4, 0] = new Drob(15, 1); masBumaga[4, 1] = new Drob(4, 1); masBumaga[4, 2] = new Drob(-3, 1); masBumaga[4, 3] = new Drob(-1, 1); masBumaga[4, 4] = new Drob(3, 1); masBumaga[4, 5] = new Drob(-4, 1);
             */
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

            Drob d1 = new Drob(-94, 3);
            Drob d2 = new Drob(1, 1);
            Drob d3 = new Drob(28, 3);
            Drob d4 = new Drob(-1, 2);
            Drob dRes = new Drob(0, 0);
            d1 = db.mul(d1, d2);
            textBox1.AppendText(d1.toStr() + "\n");
            d3 = db.mul(d3, d4);
            textBox2.AppendText(d3.toStr() + "\n");
            d1 = db.sub(d1, d3);
            textBox3.AppendText(d1.toStr() + "\n");
            //textBox1.Text = dRes.toStr();
            // db.test();
        }

        private void button4_Click(object sender, EventArgs e)//                  "Solve"
        {
            if (flagSolved) return;
            Drob d = new Drob(0, 0);//just an object for functions invocation
            int x0 = 0, y0 = 0, x1 = 0, y1 = 0;// works for the first case for all columns!
            int x2 = 0, y2 = 0, x3 = 0, y3 = 0;
            int rColumn = 0;
            for (int rRow = 0; rRow < n1; rRow++)//rRow & rColumn are my untouchable row and coulumn
            {
                for (rColumn = rRow; rColumn < n2 - 1; rColumn++)//moving diagonally down &/or right // NO. Moving lr=eft horizontally in a search for a non-zerp el-t 
                {
                    //my mistake is apparently going lots of times after finding a non-zero value in a row... I need only use the value once...
                    // if (rColumn == n2) break;//if it's the end of the row and there are no non-zero elements, then break searching in this row(inner for loop)
                    if (mas[rRow, rColumn].numerator == 0)//if the solving element is not 0, then continue searchin the row
                        continue;
                    else// else we have found a non-zero element of our row and start solving
                        break;
                }


                {
                    Drob temp1 = (Drob)mas[rRow, rColumn].Clone();//created a clone of the solving element
                    for (int i = rColumn; i < n2; i++)
                    {
                        mas[rRow, i] = d.div(mas[rRow, i], temp1);//turning the solving element to 1 by divividing all the elements of the row by the first element
                    }
                    {
                        x0 = 0; y0 = rColumn; //assigned the 0 element
                        x1 = 0; y1 = rColumn + 1;   //assigned the second element - to the right horizontally
                        x2 = rRow; y2 = rColumn + 1;   //assigned the third element (RESOLVING) - down vertically
                        x3 = rRow; y3 = rColumn; // assigned the fourth element - to the left horizontally
                        //the elements are always multiplied correctly. The only exceptional case is when the first row is resolving. It is solved down below.

                        if (rRow == 0)//if the rRow is the first one, then
                        {
                            x0 = rRow + 1; x1 = rRow + 1;
                        }
                        else if (rRow == (n1 - 1))//else if the rRow is the last one, it doen't matter
                        {
                            //nothing to do here. It must be worked in iteration by rows.
                        }
                        while (y1 < n2)//walk through the columns
                        {
                            while (x0 < n1)//walk down through rows, assigning mas[x1, y1] new values
                            {//по идее начианть красивее с  х1,у1.
                                if (x0 == rRow)
                                {//if encountered with the resolving row, just skip it.
                                    x0++; x1++;
                                    continue;
                                }
                                mas[x1, y1] = //not sure if it (-->колонка всегда начинается с колонки разрешающего элемента )is still needed to be written here
                                        d.sub(
                                            d.mul(mas[x1, y1], mas[x3, y3]), //first diagonal multiplied
                                            d.mul(mas[x0, y0], mas[x2, y2]));
                                x0++; x1++;//going through orange and blue squares(just down)

                            }
                            x0 = 0; x1 = 0;//got back up to resolve a new column
                            y1++; y2++;//координаты столбцов(одного столбца по сути) сместились вправо(розовый прямоугольник)
                        }
                    }

                    for (int i = 0; i < n1; i++)//it has to be done at the end of the iteration
                    {
                        if (i == rRow) continue;
                        mas[i, rColumn].numerator = 0;//turning all the other elements of the rColumn to 0
                        mas[i, rColumn].denominator = 0;//(as a part of the rectangle method)
                    }
                }
                fillTable();//first step: have turned the first(solving) element to 1 and all the other elements of the rColumn to 0

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
//if(rRow > 0 && rRow < n1 - 1)
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


//untoucheableRow = rRow;//this rRow is needed to skip during the solving

//temp1 = mas[rRow, rColumn];//the reneved solving element(1/1)// these rRow & rColumn will stay... 
////I can rely on these coordinates
//for (int rowS = 0, columnS = rColumn; rowS < n1-1; rowS++)
//{
//    //int rowT = rowS + 1;
//    int columnT = rColumn + 1;
//    int x0 = rowS, y0 = rColumn, x1 = rowS, y1 = columnS;
//    int x2 = rowS + 1, y2 = columnS + 1, x3 = rowS + 1, y3 = rColumn + 1;
//    if (rowS == untoucheableRow) continue;//пытаюсь проскочить через разрешающий ряд
//    //if()
//    else mas[rowS, columnS] = //колонка всегда начинается с колонки разрешающего элемента
//            d.sub(
//                d.mul(mas[x0, y0], mas[x2, y2]), //first diagonal multiplied
//                d.mul(mas[x1, y1], mas[x3, y3]));
//}
