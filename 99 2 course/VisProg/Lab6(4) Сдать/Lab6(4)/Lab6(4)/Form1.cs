using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab6_4_
{
    public partial class Form1 : Form
    {
        public Form1()

        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void driveListBox1_SelectionChangeCommitted(object sender, EventArgs e)
        {
            try
            {
                dirListBox1.Path = driveListBox1.Drive;
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }

        }

        private void dirListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            fileListBox1.Path = dirListBox1.Path;
            toolStripStatusLabel1.Width = dirListBox1.Path.Length * 7;
            toolStripStatusLabel1.Text = dirListBox1.Path.ToString(); 
        }

        private void radioButton1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right) radioButton1.Checked = false;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                label3.Text = DateTime.Now.ToLongTimeString();
            }
            else label3.Text = "Время";
        }

        private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
        {
            try
            {
                if (comboBox1.Text == comboBox1.Items[0].ToString())
                {
                    fileListBox1.Pattern = "*.*";
                }
                else if (comboBox1.Text == comboBox1.Items[1].ToString())
                {
                    fileListBox1.Pattern = "*.jpg";
                }
                else if (comboBox1.Text == comboBox1.Items[2].ToString())
                {
                    fileListBox1.Pattern = "*.bmp";
                }
                else if (comboBox1.Text == comboBox1.Items[3].ToString())
                {
                    fileListBox1.Pattern = "*.gif";
                }
                else if (comboBox1.Text == comboBox1.Items[4].ToString())
                {
                    fileListBox1.Pattern = "*.png";
                }
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
            
        }

        private void fileListBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            if (fileListBox1.get_Items(0).ToString() != null)
            {
                FileInfo file = new FileInfo((fileListBox1.Path.ToString() + "\\" + fileListBox1.SelectedItem.ToString()));
                toolStripStatusLabel2.Width = file.Name.Length * 20;
            }

            if (fileListBox1.SelectedItem.ToString().Contains(".jpg") || fileListBox1.SelectedItem.ToString().Contains(".bmp") ||
                fileListBox1.SelectedItem.ToString().Contains(".gif") || fileListBox1.SelectedItem.ToString().Contains(".png"))
                pictureBox1.Load(fileListBox1.Path.ToString() + "\\" + fileListBox1.SelectedItem.ToString());

            if (fileListBox1.SelectedItem.ToString() != "") {
                double size_of_file;
                FileInfo file = new FileInfo((fileListBox1.Path.ToString() + "\\" + fileListBox1.SelectedItem.ToString()));
                size_of_file = file.Length / 1024;
          
                toolStripStatusLabel2.Text = fileListBox1.SelectedItem.ToString() + "  " + size_of_file.ToString() + " Kbytes";
            }
        }

        private void fileListBox1_Enter(object sender, EventArgs e)
        {
            if (fileListBox1.get_Items(0).ToString() != null) fileListBox1.SetSelected(0, true);
        }
    }
}
