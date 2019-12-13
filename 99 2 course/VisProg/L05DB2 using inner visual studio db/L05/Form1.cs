using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//Лабораторная номер 7
namespace L05
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.tableTableAdapter.Fill(this.database1DataSet2.Table);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.tableTableAdapter.Z22(this.database1DataSet2.Table, "Северная Америка");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.tableTableAdapter.Fill(this.database1DataSet2.Table);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.tableTableAdapter.Z22(this.database1DataSet2.Table, "Южная Америка");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.tableTableAdapter.FillByStartsWithK(this.database1DataSet2.Table);
        }
    }
}
