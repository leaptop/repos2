using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L05DataBase
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database3DataSet.Студенты' table. You can move, or remove it, as needed.
            this.студентыTableAdapter.Fill(this.database3DataSet.Студенты);
            // TODO: This line of code loads data into the 'database3DataSet.Группа' table. You can move, or remove it, as needed.
            this.группаTableAdapter.Fill(this.database3DataSet.Группа);
            // TODO: This line of code loads data into the 'database3DataSet.Факультет' table. You can move, or remove it, as needed.
            this.факультетTableAdapter.Fill(this.database3DataSet.Факультет);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (dataGridView3.SortOrder == SortOrder.Ascending)
                dataGridView3.Sort(dataGridView3.Columns[1], ListSortDirection.Descending);
            else dataGridView3.Sort(dataGridView3.Columns[1], ListSortDirection.Ascending);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView3.RowCount - 1; i++)
            {
                string str = dataGridView3.Rows[i].Cells[1].Value.ToString();
                if (str.Contains(textBox1.Text) == true) dataGridView3.Rows[i].Selected = true;
                else dataGridView3.Rows[i].Selected = false;
                if (textBox1.Text == "") dataGridView3.Rows[i].Selected = false;
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView3.RowCount - 1; i++)
            {
                string str = dataGridView3.Rows[i].Cells[1].Value.ToString();
                if (str == textBox2.Text) dataGridView3.Rows[i].Selected = true;
                else dataGridView3.Rows[i].Selected = false;             
            }
        }
    }
}
