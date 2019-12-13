using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form 
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "countryDataSet.Страны". При необходимости она может быть перемещена или удалена.
            this.страныTableAdapter.Fill(this.countryDataSet.Страны);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            { 
                this.страныTableAdapter.FillByContinent(this.countryDataSet.Страны,"Северная Америка");
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {

                this.страныTableAdapter.FillByContinent(this.countryDataSet.Страны, "Южная Америка");
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.страныTableAdapter.Fill(this.countryDataSet.Страны);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                this.страныTableAdapter.FillByK(this.countryDataSet.Страны);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            try
            { 
                this.страныTableAdapter.FillWithK(this.countryDataSet.Страны);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SortOrder == SortOrder.Ascending)
                dataGridView1.Sort(dataGridView1.Columns[3], ListSortDirection.Descending);
            else
                dataGridView1.Sort(dataGridView1.Columns[3], ListSortDirection.Ascending);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            try
            {
                this.страныTableAdapter.Find(this.countryDataSet.Страны,textBox1.Text);
            }
            catch (System.Exception ex) 
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }
    }
}
