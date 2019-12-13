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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        public void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            if (main != null)
            {
                int n = Convert.ToInt32(numericUpDown1.Value);
                int m = Convert.ToInt32(numericUpDown2.Value);
                main.numericUpDown1.Value = n;
                main.numericUpDown2.Value = m;
            }
            this.Close();
        }

      
    }
}
