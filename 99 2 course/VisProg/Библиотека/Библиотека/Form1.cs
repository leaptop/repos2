using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace Библиотека
{
    public partial class Form1 : Form
    {
        private OleDbConnection connection = new OleDbConnection();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "библиотекаDataSet1.Книги". При необходимости она может быть перемещена или удалена.
            this.книгиTableAdapter1.Fill(this.библиотекаDataSet1.Книги);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "библиотекаDataSet1.Читатели". При необходимости она может быть перемещена или удалена.
            this.читателиTableAdapter1.Fill(this.библиотекаDataSet1.Читатели);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "библиотекаDataSet1.Кому_выдано". При необходимости она может быть перемещена или удалена.
            this.кому_выданоTableAdapter1.Fill(this.библиотекаDataSet1.Кому_выдано);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "библиотекаDataSet.Читатели". При необходимости она может быть перемещена или удалена.
          

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.RowCount - 1; i++)
            {
                string str = dataGridView1.Rows[i].Cells[1].Value.ToString();
                if (str.Contains(textBox1.Text) == true) dataGridView1.Rows[i].Selected = true;
                else dataGridView1.Rows[i].Selected = false;
                if (textBox1.Text == "") dataGridView1.Rows[i].Selected = false;
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.RowCount  - 3; i++)
            {
                string str = dataGridView1.Rows[i].Cells[3].Value.ToString();
                if (str.Contains(textBox2.Text) == true) dataGridView1.Rows[i].Selected = true;
                else dataGridView1.Rows[i].Selected = false;
                if (textBox2.Text == "") dataGridView1.Rows[i].Selected = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //читателиTableAdapter1.Update(библиотекаDataSet1.Читатели);
            this.книгиBindingSource2.EndEdit();
            this.книгиTableAdapter1.Update(this.библиотекаDataSet1.Книги);

            this.читателиBindingSource1.EndEdit();
            this.читателиTableAdapter1.Update(this.библиотекаDataSet1.Читатели);

            this.комуВыданоBindingSource1.EndEdit();
            this.кому_выданоTableAdapter1.Update(this.библиотекаDataSet1.Кому_выдано);
        }

        

    }
}
