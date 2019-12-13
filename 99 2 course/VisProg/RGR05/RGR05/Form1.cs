using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace RGR05
{
    public partial class Form1 : Form
    {
        public OleDbConnection connection = new OleDbConnection();
        public Form1()
        {
            InitializeComponent();
            connection.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Stepan\source\repos\VisProg\RGR05\RGR05\Base1.accdb; Persist Security Info=False;";
        }

        public void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'base1DataSet2.MoviesUsers' table. You can move, or remove it, as needed.
            this.moviesUsersTableAdapter1.Fill(this.base1DataSet2.MoviesUsers);
            // TODO: This line of code loads data into the 'base1DataSet.Пользователи' table. You can move, or remove it, as needed.
            this.пользователиTableAdapter.Fill(this.base1DataSet.Пользователи);
            // TODO: This line of code loads data into the 'base1DataSet.Movies' table. You can move, or remove it, as needed.
            this.moviesTableAdapter.Fill(this.base1DataSet.Movies);
            // TODO: This line of code loads data into the 'base1DataSet.MoviesUsers' table. You can move, or remove it, as needed.


            // this.reportViewer1.RefreshReport();
        }

        public void button1_MoviesUsers(object sender, EventArgs e)
        {
            try
            {
                connection.Open();
                OleDbCommand command = new OleDbCommand();
                command.Connection = connection;
                command.CommandText = "INSERT INTO [MoviesUsers] ([User], [Movie]) VALUES('"
                    + Convert.ToDecimal(textBox2.Text) + "','" + Convert.ToDecimal(textBox3.Text) + "')";
                command.ExecuteNonQuery();
                MessageBox.Show("Data Saved");
                //command.Dispose();
                //как обновить инфу сразу после добавления? Вот это:                 
                //не работает
                //Как выводить названия вместо айдишников в MoviesUsers? Виртуальная таблица нужна. Или отчеты.(Report) Sub подотчет
                // как сохранять БД в аксесе, чтобы это стало видно в Вижуал Студио?(при изменении структуры БД)
                // OleDbDataReader reader = command.ExecuteReader();//for reading(for SELECT)}
                connection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error " + ex);
                connection.Close();
            }
        }

        public void label1_Click(object sender, EventArgs e)
        {

        }

        public void button2_Sostavit(object sender, EventArgs e)
        {
            string movIds = dataGridView2.SelectedCells[2].Value.ToString();
            int movIdi = Convert.ToInt32(movIds);
            string usrIds = dataGridView2.SelectedCells[1].Value.ToString();
            int usrIdi = Convert.ToInt32(usrIds);
            //int row = dataGridView2.SelectedCells[0].RowIndex;

            /* connection.Open();
             OleDbCommand command = new OleDbCommand();
             command.Connection = connection;
             command.CommandText = "SELECT FROM [MoviesUsers] ([User], [Movie]) VALUES('"
                 + Convert.ToDecimal(textBox2.Text) + "','" + Convert.ToDecimal(textBox3.Text) + "')";
             command.ExecuteNonQuery();*/

            string film = dataGridView1.Rows[movIdi - 1].Cells[0].Value.ToString();
            string first_name = dataGridView3.Rows[usrIdi - 1].Cells[0].Value.ToString();
            string second_name = dataGridView3.Rows[usrIdi - 1].Cells[1].Value.ToString();
            textBox1.Text = new string(' ', 100) + "Кому: " + second_name + " " + first_name;
            textBox1.Text += "\n" + new string(' ', 120);
            textBox1.Text += "\n" + new string(' ', 60) + "Уважаемый(-ая) " + first_name + " " + second_name + "!";
            textBox1.Text += "\r\n\r\n" + "Убедительно прошу Вас вернуть фильм " + film + ", который Вы взяли ";
            textBox1.Text += "\r\n\r\n\r\n" + new string(' ', 50) + "Заранее спасибо";
            textBox1.Text += "\r\n\r\n" + new string(' ', 100) + "Подпись" + "\r\n\r\n" + new string(' ', 100) + DateTime.Now.ToString("dd.MM.yyyy") + " г.";
        }

        public void button3_Renew(object sender, EventArgs e)
        {
            this.пользователиTableAdapter.Fill(this.base1DataSet.Пользователи);
            // TODO: This line of code loads data into the 'base1DataSet.Movies' table. You can move, or remove it, as needed.
            this.moviesTableAdapter.Fill(this.base1DataSet.Movies);
            this.moviesUsersTableAdapter.Fill(this.base1DataSet.MoviesUsers);
        }

        public void button4_NewMovie(object sender, EventArgs e)
        {
            Form2 secForm = new Form2();
            secForm.Owner = this;
            secForm.Show();

        }

        private void button5_UsersDolg(object sender, EventArgs e)
        {
            // Form3 fr3 = new Form3();
            // fr3.ShowDialog();
        }
        private void button6_Select(object sender, EventArgs e)
        {            /*Теперь мы хотим увидеть названия (не обязательно уникальные)
             * всех книг Дэна Брауна, которые были взяты из библиотеки, и 
             * когда эти книги нужно вернуть:


SELECT books.title AS "Title", borrowings.returndate AS "Return Date"
FROM borrowings JOIN books ON borrowings.bookid=books.bookid
WHERE books.author='Dan Brown';*/
            connection.Open();
            OleDbCommand command = new OleDbCommand();
            command.Connection = connection;
            //command.CommandText = "SELECT Movies.[Название фильма] FROM MoviesUsers JOIN Movies ON MoviesUsers.User=Пользователи.User_ID WHERE Пользователи.User_ID=5";
            command.CommandText = "SELECT * FROM Movies";
            OleDbDataReader reader = command.ExecuteReader();//for reading(for SELECT)}
            while (reader.Read())
            {
                Console.Write("\nGOTCHA\n");
                Console.Write(reader.ToString());
            }
            connection.Close();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            OleDbConnectionStringBuilder sb = new OleDbConnectionStringBuilder();
            sb.Provider = "Microsoft.ACE.OLEDB.12.0";
            sb.PersistSecurityInfo = false;
            sb.Add("Jet OLEDB:Database Password", "");
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Accdb files (*.accdb)|*.accdb";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                sb.DataSource = ofd.FileName;
                connection = new OleDbConnection(sb.ConnectionString);        
            }
            /*
            OleDbCommand cmd = connection.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "SELECT * FROM Movies WHERE Movie_ID IN (SELECT Movie FROM MoviesUsers WHERE User = ?)";
            OleDbParameter param = cmd.CreateParameter();
            param.OleDbType = OleDbType.Integer;
            param.Value = 4;
            cmd.Parameters.Add(param);
            //SqlDataReader reader = cmd.ExecuteReader();//так на сайте. Но в моём случае используется
             OleDbDataAdapter, а я не знаю как туда это всё подставить.*/

            DataTable table = new DataTable();
            string sel = "SELECT * FROM Movies WHERE Movie_ID IN (SELECT Movie FROM MoviesUsers WHERE User = "+textBox4.Text+")";
            Console.WriteLine(sel);
            if (!String.IsNullOrEmpty(connection.ConnectionString))
            {
                table = FillTable(sel);
                //table = FillTable("SELECT * FROM Movies WHERE Movie_ID IN (SELECT Movie FROM MoviesUsers WHERE User = 4)");
            }
            dataGridView4.DataSource = table;
        }
        private DataTable FillTable(String sql)
        {
            DataTable table = new DataTable();
            using (OleDbDataAdapter da = new OleDbDataAdapter(sql, connection))
            {
                da.Fill(table);
            }
            return table;
        }
    }
}
