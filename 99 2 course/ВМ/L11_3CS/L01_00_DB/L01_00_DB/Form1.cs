using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L01_00_DB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database11DataSet.Факультет' table. You can move, or remove it, as needed.
            this.факультетTableAdapter.Fill(this.database11DataSet.Факультет);
            // TODO: This line of code loads data into the 'database11DataSet.Студенты' table. You can move, or remove it, as needed.
            this.студентыTableAdapter.Fill(this.database11DataSet.Студенты);
            // TODO: This line of code loads data into the 'database11DataSet.Группа' table. You can move, or remove it, as needed.
            this.группаTableAdapter.Fill(this.database11DataSet.Группа);

        }

        private void database11DataSetBindingSource_CurrentChanged(object sender, EventArgs e)
        {

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void bindingNavigator1_RefreshItems(object sender, EventArgs e)
        {

        }

        private void факультетГруппаBindingSource1_CurrentChanged(object sender, EventArgs e)
        {

        }
    }
}
