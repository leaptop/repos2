using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L1_2
{
    
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        public int n1;//число строк
        public int n2;//число столбцов
        public double[,] mas;//матрица

        public string[] elems;//список имён вершин для подписи в матрице       
        public double[,] masBumaga;//массив для хранения матрицы в коде
        public double[,] masBumaga2;//массив для запоминания вводимых матриц
        public bool load;

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
                mas = new double[n1, n2];//the matrix to solve 
                dataGridView1.RowCount = n1;
                dataGridView1.ColumnCount = n2;
                dataGridView1.AutoSizeColumnsMode = 
                    DataGridViewAutoSizeColumnsMode.DisplayedCells;

                fillTable();
            }
            initilaizeHeaders();
        }
        private void button2_Click(object sender, EventArgs e) //                   "Load"
        {
            /* 1 2 3 | 5
             * 4 5 6 | 8
             * 7 8 0 | 2
             */
            load = true;
            n1 = 3; n2 = 4;
            mas = new double[n1, n2];//the matrix to solve 
            masBumaga = new double[n1, n2];//the matrix to solve 
            dataGridView1.RowCount = n1;
            dataGridView1.ColumnCount = n2;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
            masBumaga[0, 0] = 1; masBumaga[0, 1] = 2; masBumaga[0, 2] = 3; masBumaga[0, 3] = 5;
            masBumaga[1, 0] = 4; masBumaga[1, 1] = 5; masBumaga[1, 2] = 6; masBumaga[1, 3] = 8;
            masBumaga[2, 0] = 7; masBumaga[2, 1] = 8; masBumaga[2, 2] = 0; masBumaga[2, 3] = 2;
            mas = masBumaga;
            initilaizeHeaders();
            fillTable();
        }
        private void initilaizeHeaders()
        {
            elems = new string[n2];
            for (int i = 0; i < n2; i++) { 
                elems[i] = "X" + Convert.ToString(i);
                if (i == (n2 - 1)) elems[i] = "= ";
            }
            for (int i = 0; i < n2; i++)
            {                
                dataGridView1.Columns[i].HeaderCell.Value = elems[i];
            }
        }
        private void fillTable()
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
        }

        private void button3_Click(object sender, EventArgs e) //                 "test"
        {
            Drob db = new Drob();
            db.test();
        }
    }
}
