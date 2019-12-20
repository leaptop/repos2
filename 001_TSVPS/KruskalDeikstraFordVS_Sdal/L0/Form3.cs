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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
            //Button1_Click(null, null);
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            int n = main.n;
            dataGridView1.RowCount = n;
            dataGridView1.ColumnCount = 2;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
            dataGridView1.Columns[0].HeaderCell.Value = "номера вершин";
            dataGridView1.Columns[1].HeaderCell.Value = "минимальные расстояния до V" + main.iskm;
            if (main != null)
            {
                for (int i = 0; i < n; i++)
                {
                    dataGridView1.Rows[i].Cells[0].Value = i;
                    dataGridView1.Rows[i].Cells[1].Value = main.dist[i];
                }
            }
        }
    }
}
