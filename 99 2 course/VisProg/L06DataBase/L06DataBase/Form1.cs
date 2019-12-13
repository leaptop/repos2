using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L06DataBase
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'continentsDataSet.Countries' table. You can move, or remove it, as needed.
            this.countriesTableAdapter.Fill(this.continentsDataSet.Countries);

        }

        private void button2_Click(object sender, EventArgs e)
        {//здесь такую ошибку выдаёт(нет метода с двумя аргументами)
         //в ргр то же самое было. В вижуал студио 2017 то же самое... 
         //Видимо аксесс2016 косячит. Но это единственная программа, к-рую мне удалось установить
         //(аксес 2016)//Ошибка была в том, что интерфейс создания запроса интуитивно 
         //не определяется. Чтобы сделать выборку нужно ставить 
         //галочку Fill a DataTable, а не Return a DataTable. А я ставил всегда Return a DataTable
         //можно зарегистрировать себя через почту преподавателя, чтобы получить аксес официально?
            this.countriesTableAdapter.Z22(this.continentsDataSet.Countries, "Северная Америка");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.Z22(this.continentsDataSet.Countries, "Северная Америка");
        }
    }
}
