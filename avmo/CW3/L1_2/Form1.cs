using CW3;
using System;                       //Получается, что число базисных переменных всегда равно числу ограничений(числу строк)
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//implementing the Jordan-Gauss method + rectangle method (метод Жордана-Гауса и метод прямоугольников)
namespace CW3

{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            masOld = new Drob[n1, n2];//матрица не рабочая
            //инициализирую функцию
            fun = new Drob[n3];//инициализирую массив коэффициентов исследуемой функции
            fun[0] = new Drob(7, 1);
            fun[1] = new Drob(1, 1);
            //инициализирую матрицу коэффициентов системы в канонической форме. Свободные члены справа:
            mas = new Drob[n1, n2];
            mas[0, 0] = new Drob(5, 1); mas[0, 1] = new Drob(1, 1); mas[0, 2] = new Drob(-1, 1); mas[0, 3] = new Drob(0, 1); mas[0, 4] = new Drob(0, 1); mas[0, 5] = new Drob(12, 1);
            mas[1, 0] = new Drob(5, 1); mas[1, 1] = new Drob(4, 1); mas[1, 2] = new Drob(0, 1); mas[1, 3] = new Drob(-1, 1); mas[1, 4] = new Drob(0, 1); mas[1, 5] = new Drob(33, 1);
            mas[2, 0] = new Drob(2, 1); mas[2, 1] = new Drob(5, 1); mas[2, 2] = new Drob(0, 1); mas[2, 3] = new Drob(0, 1); mas[2, 4] = new Drob(-1, 1); mas[2, 5] = new Drob(20, 1);
            for (int i = 0; i < n1; i++)
            {
                basis[i] = i;//заполняю массив базисных переменных(по уcловию x1, x2, x3)
            }


        }
        public int currentRow = 0;//для прорисовки промежуточных решений(чтобы новые матрицы рисовались ниже)
        public const int n1 = 3;//число строк(число уравнений системы)
        public const int n2 = 6;//число столбцов(коэффициенты при переменных + 1 свободный член)(5+1)
        public const int n3 = 2;//число переменных в матрице, не приведённой к каноническому виду, равное числу коэффициентов в исследуемой функции
        public const int n4 = 9;//число всех названий столбцов
        public Drob[,] masOld;
        public Drob[] fun;// массив коэффициентов исследуемой функции
        //С этого момента не буду заморачиваться с красивым оформлением, взаимодействием с пользователем в рантайме
        public int[] basis = new int[n1];// базисные переменные заданные условием задачи. Их может быть ровно столько, сколько уравнений в системе
        //массив для вообще всех переменных наверное не нужен....
        public Drob[,] mas;//массив для хранения матрицы в коде
        public int resolvRow = 0;//переменная, указывающая текущую резольвирующую строку
        public int resolvColumn = 0;//переменная, указывающая текущий резольвирующий столбец
        public string[] elems;//список имён вершин для подписи в матрице   
        public Drob d = new Drob(1,1);//объект для вызова методов. Криво конечно, но пока так...

        public double[,] masBumaga2;//массив для запоминания вводимых матриц
        public bool load;
        public bool flagSolved = false;

        private void printMatrixMasBumaga(object sender, EventArgs e) // <--- КНОПКА  "Вывести матрицу"
        {
            dataGridView1.RowCount = n1 * 100;//просто делаю всю полосу подлиннее с запасом
            dataGridView1.ColumnCount = n4;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
            initilaizeHeaders();
            fillTable();
            rctnApply();

        }

        private void initilaizeHeaders()//------------------------------------расписал заголовки вверху таблицы
        {
            elems = new string[n4];
            for (int i = 0; i < n2 -1; i++)
            {
                elems[i] = "x" + Convert.ToString(i);
                //if (i == (n2 - 1)) elems[i] = "= ";
            }
            elems[n2 - 1] = "своб.Чл.";
            elems[n2] = "б.п.\nX";
            elems[n2 + 1] = "резCтолб.";
            elems[n2+2] = "резCтр.";
            for (int i = 0; i < elems.Length; i++)
            {
                dataGridView1.Columns[i].HeaderCell.Value = elems[i];
            }
        }
        private void fillTable()//---------------------------------------------заполнил dataGridView1 содержимым mas
        {

            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    dataGridView1.Rows[currentRow + i].Cells[j].Value = mas[i, j].toStr();
                }
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            //dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
            currentRow += (n1 + 1);//для прорисовки матрицы
        }

        //-------------теперь нужно пройтись прямоугольником по матричке, чтобы во-первых получить базис в соответствии с условием задачи(0,1,2), а во-вторых
        //получить строку со значениями функции при этом базисе... это(второе), кстати, не факт, что нужно. Ну да ладно, сделаю так.

        //---методу прямоугольника надо знать и резольв. строку и резольв. столбец? Нет. Столбец нормально
        public void rctn(int row/*номер строки, в которой базисная переменная*/, int index /*индекс базисной переменной*/)// -----------------метод прямоугольника. У меня есть массив basis, обозначающий индексы переменных, которые сейчас считаются базисными.
        {           //------------------------
                    //в начале у меня есть index - индекс текущей базисной переменной для одного полного прохода прямоугольником по матрице. А также есть row - номер строки,
                    //в которой этот индекс указан. 
                    //т.о. выбрал строку резольвирующую. Эту строку надо разделить 
                    //Индексы чисел массива basis - номера строк, а сами числа - индексы базисных переменных
                    // Видимо не важно в какой строке будет единица, важно, чтобы единицы просто были в разных строках
       
            for (int i = 0; i < n2; i++)//n2(сейчас 6) раз надо пройтись по столбцам. Резольвирующий столбец можно не исключать из алгоритма, т.к. всё равно получаются нули. А резольвирующую строку я всё равно пропускаю.
            {
                for (int j = 0; j < n1; j++)//n1 раз надо пройтись по строкам, избегая резольвирующую
                {
                    if (!(j == row || i == index))// если строка не резольвирующая, и столбец не резольвирующий то делаем прямоугольник
                    {
                        Drob multiaa; Drob divibb; Drob subcc = new Drob(1,1); Drob dd;

                        multiaa = d.mul(mas[row, i], mas[j, index]);
                        divibb = d.div(multiaa, mas[row, index]);
                        subcc = d.sub(mas[j, i], divibb);// проблема в том, что прямоугольником нужно проходиться до того момента, когда в резольвирующем столбце появились нули.
                        textBox4.Text += ("multiaa = " + multiaa.toStr() + ", divibb = " + divibb.toStr() + ", subcc = " + subcc.toStr()+ " END \0");
                        mas[j, i] =(Drob) subcc.Clone();

                    }
                }
            }//только сейчас можно занулить остальные элементы резольвирующего столбца
            
            for (int i = 0; i < n1; i++)
            {
                if (!(i == row)) mas[i, index] = new Drob(0, 0);
            }
            Drob temp = (Drob)mas[row, index].Clone();
            //теперь элементы резольвирующей строки надо разделить на mas[row, index]:
            for (int i = 0; i < n2; i++)
            {
                mas[row, i] = d.div(mas[row, i], temp);
            }
        }
        public void rctnApply()
        {//здесь нужно принять решение, какие строки и столбцы будут резольвирующими. Эта информация есть в basis. 
            //basis[0] - индекс первой базисной переменной. Ею называем первую
            //строку симплекс-таблицы. При этом при вызове прямоугольника 0 будет резольвирующей 
            //строкой, индекс будет резольвирующим столбцом.
            //basis[1] - индекс второй базисной переменной. Ею называем вторую строку и т.д. 
            for (int i = 0; i < basis.Length ; i++)
            {
                rctn(i, basis[i]);
                fillTable();
            }//Привели систему к единичной матрице методом жордановских преобразований. Теперь в качестве базисных переменных нужно принять
        }
        //б.п. после свободных членов рисовать
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
                    if (masOld[rRow, rColumn].numerator == 0)//if the solving element is not 0, then continue searchin the row
                        continue;
                    else// else we have found a non-zero element of our row and start solving
                        break;
                }


                {
                    Drob temp1 = (Drob)masOld[rRow, rColumn].Clone();//created a clone of the solving element
                    for (int i = rColumn; i < n2; i++)
                    {
                        masOld[rRow, i] = d.div(masOld[rRow, i], temp1);//turning the solving element to 1 by divividing all the elements of the row by the first element
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
                            while (x0 < n1)//walk down through rows, assigning masOld[x1, y1] new values
                            {//по идее начианть красивее с  х1,у1.
                                if (x0 == rRow)
                                {//if encountered with the resolving row, just skip it.
                                    x0++; x1++;
                                    continue;
                                }
                                masOld[x1, y1] = //not sure if it (-->колонка всегда начинается с колонки разрешающего элемента )is still needed to be written here
                                        d.sub(
                                            d.mul(masOld[x1, y1], masOld[x3, y3]), //first diagonal multiplied
                                            d.mul(masOld[x0, y0], masOld[x2, y2]));
                                x0++; x1++;//going through orange and blue squares(just down)

                            }
                            x0 = 0; x1 = 0;//got back up to resolve a new column
                            y1++; y2++;//координаты столбцов(одного столбца по сути) сместились вправо(розовый прямоугольник)
                        }
                    }

                    for (int i = 0; i < n1; i++)//it has to be done at the end of the iteration
                    {
                        if (i == rRow) continue;
                        masOld[i, rColumn].numerator = 0;//turning all the other elements of the rColumn to 0
                        masOld[i, rColumn].denominator = 0;//(as a part of the rectangle method)
                    }
                }
                fillTable();//first step: have turned the first(solving) element to 1 and all the other elements of the rColumn to 0

            }
            String answer = "";
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n2 - 1; j++)
                {
                    if (masOld[i, j].numerator != 0)
                    {
                        if (masOld[i, j].numerator == 1 && masOld[i, j].denominator == 1)
                        {
                            if (masOld[i, j].numerator > 0)
                                answer += (" + " + elems[j] + " ");
                            else
                                if (masOld[i, j].numerator < 0)
                                answer += (" - " + elems[j] + " ");
                        }
                        else
                        {
                            if (masOld[i, j].numerator > 0)
                                answer += ("  +  " + masOld[i, j].toStr() + "*" + elems[j] + " ");
                            else
                                if (masOld[i, j].numerator < 0)
                                answer += (masOld[i, j].toStr() + "*" + elems[j] + " ");
                        }
                    }
                }
                if (answer.Length > 0)
                {
                    answer += ("  =  " + masOld[i, n2 - 1].toStr() + "; \n\n");
                    textBox1.Text += answer;
                    answer = "";
                }
            }
            flagSolved = true;//защита от повторного нажатия кнопки solve
        }

        private void button1_Click(object sender, EventArgs e)//                    "Build a table"
        {
            load = false;
            //n1 = Convert.ToInt32(numericUpDown1.Value);
            // n2 = Convert.ToInt32(numericUpDown2.Value);
            elems = new string[n2];
            for (int i = 0; i < n2; i++) { elems[i] = "X" + Convert.ToString(i); }
            Random rand = new Random();
            if (n1 != 0 && n2 != 0)
            {
                masOld = new Drob[n1, n2];//the matrix to solve 
                dataGridView1.RowCount = n1 * 100;//просто делаю всю полосу подлиннее с запасом
                dataGridView1.ColumnCount = (n2);
                dataGridView1.AutoSizeColumnsMode =
                    DataGridViewAutoSizeColumnsMode.DisplayedCells;

                fillTable();
            }
            initilaizeHeaders();
        }
        private void button2_Click(object sender, EventArgs e) //                   "Load"
        {

            load = true;
            masOld = new Drob[n1, n2];//the matrix to solve 
            mas = new Drob[n1, n2];//the matrix to solve 
            dataGridView1.RowCount = n1 * 100;
            dataGridView1.ColumnCount = n2;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;



            /* 1 2 3 | 5
             * 4 5 6 | 8
             * 7 8 0 | 2
             */
            /* mas[0, 0] = new Drob(1, 1); mas[0, 1] = new Drob(2, 1); mas[0, 2] = new Drob(3, 1); mas[0, 3] = new Drob(5, 1);
             mas[1, 0] = new Drob(4, 1); mas[1, 1] = new Drob(5, 1); mas[1, 2] = new Drob(6, 1); mas[1, 3] = new Drob(8, 1);
             mas[2, 0] = new Drob(7, 1); mas[2, 1] = new Drob(8, 1); mas[2, 2] = new Drob(0, 0); mas[2, 3] = new Drob(2, 1);
             */
            /* 2 -3 5 7     | 1
             * 4 -6 2 3     | 2
             * 2 -3 -11 -15 | 1
             */
            /* mas[0, 0] = new Drob(15, 1); mas[0, 1] = new Drob(-5, 1); mas[0, 2] = new Drob(8, 1); mas[0, 3] = new Drob(11, 1); mas[0, 4] = new Drob(-6, 1); mas[0, 5] = new Drob(-76, 1);
             mas[1, 0] = new Drob(15, 1); mas[1, 1] = new Drob(1, 1); mas[1, 2] = new Drob(7, 1); mas[1, 3] = new Drob(1, 1); mas[1, 4] = new Drob(11, 1); mas[1, 5] = new Drob(-79, 1);
             mas[2, 0] = new Drob(-5, 1); mas[2, 1] = new Drob(11, 1); mas[2, 2] = new Drob(5, 1); mas[2, 3] = new Drob(-9, 1); mas[2, 4] = new Drob(10, 1); mas[2, 5] = new Drob(-6, 1);
             mas[3, 0] = new Drob(13, 1); mas[3, 1] = new Drob(-5, 1); mas[3, 2] = new Drob(-1, 1); mas[3, 3] = new Drob(11, 1); mas[3, 4] = new Drob(3, 1); mas[3, 5] = new Drob(-27, 1);
             mas[4, 0] = new Drob(15, 1); mas[4, 1] = new Drob(4, 1); mas[4, 2] = new Drob(-3, 1); mas[4, 3] = new Drob(-1, 1); mas[4, 4] = new Drob(3, 1); mas[4, 5] = new Drob(-4, 1);
             */
            masOld = mas;
            initilaizeHeaders();
            fillTable();
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

    }
}
////second case: one of the middle rows is resolving
//if(rRow > 0 && rRow < n1 - 1)
//{
//    int x0 = 0, y0 = 0, x1 = 0, y1 = 1;
//    int x2 = 1, y2 = 1, x3 = 1, y3 = 0;
//    for (; x2 < n1 || x3 < n1;)
//    {
//        masOld[x2, y2] = //колонка всегда начинается с колонки разрешающего элемента
//                d.sub(
//                    d.mul(masOld[x0, y0], masOld[x2, y2]), //first diagonal multiplied
//                    d.mul(masOld[x1, y1], masOld[x3, y3]));
//        x2++; x3++;
//    }
//}


//untoucheableRow = rRow;//this rRow is needed to skip during the solving

//temp1 = masOld[rRow, rColumn];//the reneved solving element(1/1)// these rRow & rColumn will stay... 
////I can rely on these coordinates
//for (int rowS = 0, columnS = rColumn; rowS < n1-1; rowS++)
//{
//    //int rowT = rowS + 1;
//    int columnT = rColumn + 1;
//    int x0 = rowS, y0 = rColumn, x1 = rowS, y1 = columnS;
//    int x2 = rowS + 1, y2 = columnS + 1, x3 = rowS + 1, y3 = rColumn + 1;
//    if (rowS == untoucheableRow) continue;//пытаюсь проскочить через разрешающий ряд
//    //if()
//    else masOld[rowS, columnS] = //колонка всегда начинается с колонки разрешающего элемента
//            d.sub(
//                d.mul(masOld[x0, y0], masOld[x2, y2]), //first diagonal multiplied
//                d.mul(masOld[x1, y1], masOld[x3, y3]));
//}
