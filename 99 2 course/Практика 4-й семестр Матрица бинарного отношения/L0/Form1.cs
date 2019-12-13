using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


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
        int[,] mas;
        public string[] elems;

        private void button1_Click(object sender, EventArgs e)
        {
            n = Convert.ToInt32(numericUpDown1.Value);
            if (n > 26 || n < 0)
            {
                MessageBox.Show("Значение N в множестве по умолчанию не м.б. более 26");
                numericUpDown1.Value = n = 0;
                return;
            }

            elems = new string[26];
            elems[0] = "a"; elems[1] = "b"; elems[2] = "c"; elems[3] = "d"; elems[4] = "e"; elems[5] = "f";
            elems[6] = "g"; elems[7] = "h"; elems[8] = "i"; elems[9] = "j"; elems[10] = "k"; elems[11] = "l";
            elems[12] = "m"; elems[13] = "n"; elems[14] = "o"; elems[15] = "p"; elems[16] = "q"; elems[17] = "r";
            elems[18] = "s"; elems[19] = "t"; elems[20] = "u"; elems[21] = "v"; elems[22] = "w"; elems[23] = "x";
            elems[24] = "y"; elems[25] = "z";

            Random rand = new Random();
            if (n != 0)
            {
                dataGridView1.RowCount = n;
                dataGridView1.ColumnCount = n;
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

                mas = new int[n, n];
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

        private void button3_Click(object sender, EventArgs e)
        {
            int i = 0, j = 0;
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {//двойная некрасивая проверка на правильность матрицы бинарного отношения(проверяет, использованы ли допустимые символы)
                    try
                    {
                        mas[i, j] = Convert.ToInt32(dataGridView1.Rows[i].Cells[j].Value);
                    }
                    catch (Exception ee)
                    {
                        MessageBox.Show("Значения ячеек м.б. только 1 и 0.\n" +
                            "Проверьте ячейку [" + i + "][" + j + "] (" + elems[i] + ", " + elems[j] + ")", "неверный ввод",
     MessageBoxButtons.OK, MessageBoxIcon.Error); return;
                    }

                    if (mas[i, j] != 0 && mas[i, j] != 1)
                    {
                        MessageBox.Show("Значения ячеек м.б. только 1 и 0.\n В ячейке[" + i + "][" + j +
                            "]  (" + elems[i] + ", " + elems[j] + ")" +
                            "установлено: " + mas[i, j], "неверный ввод",
                         MessageBoxButtons.OK, MessageBoxIcon.Error); return;
                    }
                }
            }
            reflexivityCheck();
            antireflexivityCheck();
            symmetryCheck();
            antySymmetryCheck();
            transitivityCheck();
        }
        public void reflexivityCheck()
        {
            int cmp = 1;
            for (int i = 0; i < n; i++) { cmp *= mas[i, i]; }
            if (cmp == 1) textBox1.Text = "Отношение рефлексивно, т.к главаная диагональ состоит из единиц";
            else textBox1.Text = "Отношение не рефлексивно, т.к главная диагональ не состоит из единиц";
            button3.Enabled = true;
        }
        public void antireflexivityCheck()
        {
            int cmp = 0;
            for (int i = 0; i < n; i++)
            {
                cmp += mas[i, i];
                if (cmp == 0) textBox2.Text = "Отношение антирефлексивно, т.к. главная диагональ состоит из нулей";
                else textBox2.Text = "Отношение не антирефлексивно, т.к главная диагональ не состоит из нулей";
            }
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

        private void button4_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = 1;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
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

        private void button5_Click(object sender, EventArgs e)
        {
            button2_Click(sender, e);
            mas[0, 1] = 1;
            dataGridView1.Rows[0].Cells[1].Value = mas[0, 1];
            mas[1, 2] = 1;
            dataGridView1.Rows[1].Cells[2].Value = mas[1, 2];
            mas[0, 2] = 1;
            dataGridView1.Rows[0].Cells[2].Value = mas[0, 2];
        }



        private void button6_Click(object sender, EventArgs e)
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

                mas = new int[n, n];
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
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ФИО: Алексеев С.В. \nГруппа:ИП-712");
        }
        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(
            "Текст 2  Отношения и их свойства \n " +
                "Бинарное отношение R на конечном множестве A: RA2 – задано списком упорядоченных пар вида(a, b), где a, bA." +
                "Исходные множества не должны содержать повторяющихся элементов(при обработке входных данных такие элементы следует удалять)." +
                "Если исходные множества не упорядочены, нужно отсортировать их по возрастанию. " +
                "Программа должна определять свойства заданного отношения: рефлексивность, симметричность, " +
                "антисимметричность, транзитивность(по материалам главы 1 курса Дискретная Математика)." +
                "Проверку свойств выполнять по матрице бинарного отношения, сопровождая необходимыми пояснениями." +
                "Работа программы должна происходить следующим образом: " +
                "Оценка «удовлетворительно»: " +
                "    1.На вход подается множество A из n элементов и список упорядоченных пар, " +
                "задающий отношение R(мощность множества, элементы и пары вводятся с клавиатуры)." +
                "    2.Результаты выводятся на экран(с необходимыми пояснениями) в следующем виде:" +
                "            а) 	матрица бинарного отношения размера nn;" +
                "            б) 	список свойств данного отношения. " +
                "В матрице отношения строки и столбцы должны быть озаглавлены(элементы исходного множества, упорядоченного по возрастанию)." +
                "Оценка «хорошо»: " +
                "В дополнение к предыдущим пунктам:" +
                "            3.После вывода результатов предусмотреть возможность изменения заданного " +
                "бинарного отношения либо выхода из программы.  " +
                "Это изменение может быть реализовано различными способами.Например, вывести на " +
                "экран список пар(с номерами) и по команде пользователя изменить что-либо в этом " +
                "списке(удалить какую - то пару, добавить новую, изменить имеющуюся), " +
                "после чего повторить вычисления, выбрав соответствующий пункт меню." +
                "Другой способ – выполнять редактирование непосредственно самой матрицы отношения, " +
                "после чего также повторить вычисления. Возможным вариантом является автоматический " +
                "пересчет – проверка свойств отношения – после изменения любого элемента матрицы." +
                "Оценка «отлично»: В дополнение к предыдущим пунктам предусмотреть не только изменение отношения, " +
                "но и ввод нового множества(размер нового множества может тоже быть другим).  ");
        }
    }
}
