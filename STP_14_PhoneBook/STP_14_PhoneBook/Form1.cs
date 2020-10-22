using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace STP_14_PhoneBook
{
    public partial class Form1 : Form
    {
        public Dictionary<string, long> dict;
        public string[] stringsToSplit = { "n/", "t/", " ", "  " };
        string path = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/book.txt";
        public Form1()
        {
            InitializeComponent();
            ReadFromAFileAndWriteTo_dict();//прочитал в dict
            Sort_dictAndWriteToFileFrom_dict();//сортировку запускаю только при запуске
            printFRom_dictToRichTextBox();//распечатал в ртб. Остальное по кнопкам
            textBox1.Text = "A";
            textBox2.Text = "7";
        }
               
        public async void ReadFromAFileAndWriteTo_dict()        //инициализирует начальное состояние
        {
            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
                try
                {
                    dict = new Dictionary<string, long>();
                    string line;
                    while ((line = sr.ReadLine()) != null)      //read from a stream(а file)
                    {
                        if (line != "\n" && line != "\t" && line != "\0" && line != "")
                        {
                            string a = line.Split(stringsToSplit, 2, StringSplitOptions.RemoveEmptyEntries)[0];
                            string b = line.Split(stringsToSplit, 2, StringSplitOptions.RemoveEmptyEntries)[1];
                            long numB = long.Parse(b);
                            dict.Add(a, numB);                  //write to dict
                        }
                    }
                    sr.Close();
                }
                catch (Exception e)
                {

                }
        }
        public async void Sort_dictAndWriteToFileFrom_dict()
        {
            var myList = from entry in dict orderby entry.Key ascending select entry;
            using (StreamWriter sr = new StreamWriter(path))
            {
                foreach (var item in myList)
                {
                    sr.WriteLine(item.Key + " " + item.Value + "\n");
                }
                sr.Close();
            }
        }
        public void printFRom_dictToRichTextBox()
        {
            richTextBox1.AppendText(String.Format("{0, -10} {1, -10}\n\n", "Name ", " Phone "));
            foreach (var item in dict)
            {
                //richTextBox1.AppendText(String.Format("Name: " + item.Key + " phone: " + item.Value + "\n"));
                richTextBox1.AppendText(String.Format("{0, -10} {1, -10}\n", item.Key, item.Value));
            }

        }
        private void button6AddANewWritingTo_dictAndToRichtexboxAndToFile(object sender, EventArgs e)
        {
                        string a = textBox1.Text;
            string b = textBox2.Text;
            long longB = long.Parse(b);
            StreamWriter sr;
            using (sr = new StreamWriter(path, true)) ;//true - to approve appending
            try
            {
                dict.Add(a, longB);
                richTextBox1.AppendText(String.Format("{0, -10} {1, -10}\n", a, b));
                sr = new StreamWriter(path, true);
                sr.WriteLine("\n" + a + " " + b);
                MessageBox.Show("no exceptions during saving");
            }
            catch (Exception ee)
            {
                richTextBox2.AppendText(ee.ToString());

                MessageBox.Show("Problem saving occured: \n" + ee.ToString());
            }
            sr.Close();
            clearRTB();
            Sort_dictAndWriteToFileFrom_dict();
            printFRom_dictToRichTextBox();
        }
        public void clearRTB()
        {
            richTextBox1.Clear();
        }
        private void button1ClearFileAnd_dictAndRtb(object sender, EventArgs e)
        {
            dict = null;
            richTextBox1.Clear();
            StreamWriter sr = new StreamWriter(path); ;
            try
            {               
                sr = new StreamWriter(path);
                sr.WriteLine("");
                MessageBox.Show("no exceptions during saving");
            }
            catch (Exception ee)
            {
                richTextBox2.AppendText(ee.ToString());
                MessageBox.Show("Problem saving occured: \n" + ee.ToString());
            }
            sr.Close();
        }


        public void startingTestingInitializationOfdict()
        {
            dict = new Dictionary<string, long>();
            dict.Add("Stepan", 79133895118);
            dict.Add("Alena", 79234512938);
        }

        private void button3Delete(object sender, EventArgs e)
        {
            string nameToDelete = textBox3.Text;
            dict.Remove(nameToDelete);
            richTextBox1.Clear();
            Sort_dictAndWriteToFileFrom_dict();
            printFRom_dictToRichTextBox();
        }

        private void button7Find(object sender, EventArgs e)
        {
            long phone;
            string nameToFind = textBox1.Text;
            dict.TryGetValue(nameToFind, out phone);
            textBox2.Text = phone.ToString();
        }

        private void button4Edit(object sender, EventArgs e)
        {
            string nameToEdit = textBox1.Text;
            string phoneToedit = textBox2.Text;
            long phoneLong = long.Parse(phoneToedit);

             Form2 f2 = new Form2(ref dict, textBox1.Text, textBox2.Text, this);
             f2.Show();
        }
    }
}
