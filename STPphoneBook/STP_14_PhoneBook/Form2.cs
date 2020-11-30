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

namespace STP_14_PhoneBook
{
    public partial class Form2 : Form
    {
        Dictionary<string, long> dict;
        string name;
        string phone;
        Form1 f1;
        string path;
        public Form2(ref Dictionary<string, long> dict, string name, string phone, Form1 f1, string path)
        {
            this.dict = dict;
            this.name = name;
            this.phone = phone;
            this.f1 = f1;
            this.path = path;
            InitializeComponent();
            textBox1.Text = name;
            textBox2.Text = phone;
            textBox3.Text = name;
            textBox4.Text = phone;
        }

        private void button4_Ok(object sender, EventArgs e)
        {
            long newPhone = long.Parse(textBox4.Text);
            string newName = textBox3.Text;
            if (dict.ContainsKey(newName) )
            {
                MessageBox.Show("Такое имя уже существует");
                return;
            }
            else if (dict.ContainsValue(newPhone))
            {
                MessageBox.Show("Такой телефон уже существует");
                return;
            }
            dict.Remove(name);
            dict.Add(newName, newPhone);//пока только записал в dict
            f1.Sort_dictAndWriteToFileFrom_dict(path);
            f1.clearRTB();
            f1.printFRom_dictToRichTextBox();
            this.Close();
        }

        private void button2_Find(object sender, EventArgs e)
        {           

        }

        private void ButtonCancel(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
