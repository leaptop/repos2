using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RGR05
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            try
            {
                main.connection.Open();
                OleDbCommand command = new OleDbCommand();
                command.Connection = main.connection;
                command.CommandText = "INSERT INTO [Movies] ([Название фильма], [Год выхода], [Длительность]) VALUES('"
                    + (textBox1.Text) + "','" + (textBox2.Text) + "','" + (textBox3.Text) + "')";
                command.ExecuteNonQuery();
                MessageBox.Show("Data Saved");
                main.connection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error " + ex);
                main.connection.Close();
            }
        }
    }
}
