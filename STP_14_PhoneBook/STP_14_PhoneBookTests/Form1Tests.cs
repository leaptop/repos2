using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_14_PhoneBook;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace STP_14_PhoneBook.Tests
{
    [TestClass()]
    public class Form1Tests
    {
        public Dictionary<string, long> dict;
        public string[] stringsToSplit = { "n/", "t/", " ", "  " };
        string path = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/bookTest.txt";
        public string path6 = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/bookButton6.txt";
        public string path7 = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/book7.txt";
        public string path7_ = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/book7_.txt";

        [TestMethod()]
        public void ReadFromAFileAndWriteTo_dictTest()
        {
            Form1 f1 = new Form1(path);
            f1.ReadFromAFileAndWriteTo_dict(path);
            Assert.IsTrue(f1.dict.ContainsKey("Bob"));
        }

        [TestMethod()]
        public void Sort_dictAndWriteToFileFrom_dictTest()
        {
            string pathIn = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/bookTestToSortIn.txt";
            string pathOut = "C:/Users/stepa/repos2/STP_14_PhoneBook/STP_14_PhoneBook/bookTestToSortOut.txt";
            Form1 f1 = new Form1(path);
            f1.ReadFromAFileAndWriteTo_dict(pathIn);
            f1.Sort_dictAndWriteToFileFrom_dict(pathOut);
            string line = "";
            using (StreamReader sr = new StreamReader(pathOut, System.Text.Encoding.Default))
                try
                {//читаю первую строку и удостоверяюсь, что наименьшее имя оказалось первым
                    line = sr.ReadLine().Split(stringsToSplit, 2, StringSplitOptions.RemoveEmptyEntries)[0];
                    sr.Close();
                }
                catch (Exception e) { }
            File.Delete(pathOut);
            Assert.AreEqual(line, "Alex");
        }

        [TestMethod()]
        public void ForButton6AddANewWritingTo_dictAndToRichtexboxAndToFileTest()
        {
            Form1 f1 = new Form1(path6);
            f1.textBox1.Text = "Carla";
            f1.textBox2.Text = "79563434";
            f1.forButton6AddANewWritingTo_dictAndToRichtexboxAndToFile();
            Assert.IsTrue(f1.dict.ContainsKey("Carla"));
            f1.textBox3.Text = "Carla";
            f1.forButton3Delete();
        }

        [TestMethod()]
        public void forButton1ClearFileAnd_dictAndRtbTest()
        {
            Form1 f1 = new Form1(path7);
            f1.forButton1ClearFileAnd_dictAndRtb();
            Assert.IsNull(f1.dict);
            f1.Close();
            File.Copy(path7_, path7, true);//true разрешает перезаписать существующий файл
        }

        [TestMethod()]
        public void forButton3DeleteTest()
        {
            Form1 f1 = new Form1(path7);
            f1.textBox3.Text = "Bob";
            f1.forButton3Delete();
            Assert.IsFalse(f1.dict.ContainsKey("Bob"));
            f1.dict.Add("Bob", 1847834);
        }

        [TestMethod()]
        public void forButton7FindTest()
        {
            Form1 f1 = new Form1(path7);
            f1.textBox1.Text = "Cris";
            f1.forButton7Find();           
            Assert.AreEqual(f1.textBox2.Text, "76546546");           
        }
    }
}