using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L05DB2Final
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.Fill(this.continentsDataSet.Countries);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'continentsDataSet.Countries' table. You can move, or remove it, as needed.
            this.countriesTableAdapter.Fill(this.continentsDataSet.Countries);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.FillByStartsWithK(this.continentsDataSet.Countries);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.FillByContainsK(this.continentsDataSet.Countries);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.FillByContinentEqualsSmth(this.continentsDataSet.Countries, "Северная Америка");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.FillByContinentEqualsSmth(this.continentsDataSet.Countries, "Южная Америка");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SortOrder == SortOrder.Ascending)
                dataGridView1.Sort(dataGridView1.Columns[4], ListSortDirection.Descending);
            else
                dataGridView1.Sort(dataGridView1.Columns[4], ListSortDirection.Ascending);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            {
                try
                {
                    this.countriesTableAdapter.Find(this.continentsDataSet.Countries, textBox1.Text);
                }
                catch (System.Exception ex)
                {
                    System.Windows.Forms.MessageBox.Show(ex.Message);
                }
            }
        }
    }
}
