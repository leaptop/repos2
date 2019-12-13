namespace RGR05
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.названиеФильмаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.годВыходаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.длительностьDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.movieIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.moviesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.base1DataSet = new RGR05.Base1DataSet();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.кодDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.movieDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.moviesUsersBindingSource3 = new System.Windows.Forms.BindingSource(this.components);
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            this.фамилияDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.имяDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.телефонDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.пользователиBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.moviesUsersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.moviesUsersTableAdapter = new RGR05.Base1DataSetTableAdapters.MoviesUsersTableAdapter();
            this.moviesTableAdapter = new RGR05.Base1DataSetTableAdapters.MoviesTableAdapter();
            this.moviesUsersBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.пользователиTableAdapter = new RGR05.Base1DataSetTableAdapters.ПользователиTableAdapter();
            this.moviesUsersBindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            this.button3 = new System.Windows.Forms.Button();
            this.base1DataSet2 = new RGR05.Base1DataSet2();
            this.moviesUsersBindingSource4 = new System.Windows.Forms.BindingSource(this.components);
            this.moviesUsersTableAdapter1 = new RGR05.Base1DataSet2TableAdapters.MoviesUsersTableAdapter();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.moviesMoviesUsersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.moviesMoviesUsersBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.dataGridView4 = new System.Windows.Forms.DataGridView();
            this.button7 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.base1DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.пользователиBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.base1DataSet2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesMoviesUsersBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesMoviesUsersBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView4)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.названиеФильмаDataGridViewTextBoxColumn,
            this.годВыходаDataGridViewTextBoxColumn,
            this.длительностьDataGridViewTextBoxColumn,
            this.movieIDDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.moviesBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(13, 13);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(449, 150);
            this.dataGridView1.TabIndex = 0;
            // 
            // названиеФильмаDataGridViewTextBoxColumn
            // 
            this.названиеФильмаDataGridViewTextBoxColumn.DataPropertyName = "Название фильма";
            this.названиеФильмаDataGridViewTextBoxColumn.HeaderText = "Название фильма";
            this.названиеФильмаDataGridViewTextBoxColumn.Name = "названиеФильмаDataGridViewTextBoxColumn";
            // 
            // годВыходаDataGridViewTextBoxColumn
            // 
            this.годВыходаDataGridViewTextBoxColumn.DataPropertyName = "Год выхода";
            this.годВыходаDataGridViewTextBoxColumn.HeaderText = "Год выхода";
            this.годВыходаDataGridViewTextBoxColumn.Name = "годВыходаDataGridViewTextBoxColumn";
            // 
            // длительностьDataGridViewTextBoxColumn
            // 
            this.длительностьDataGridViewTextBoxColumn.DataPropertyName = "Длительность";
            this.длительностьDataGridViewTextBoxColumn.HeaderText = "Длительность";
            this.длительностьDataGridViewTextBoxColumn.Name = "длительностьDataGridViewTextBoxColumn";
            // 
            // movieIDDataGridViewTextBoxColumn
            // 
            this.movieIDDataGridViewTextBoxColumn.DataPropertyName = "Movie_ID";
            this.movieIDDataGridViewTextBoxColumn.HeaderText = "Movie_ID";
            this.movieIDDataGridViewTextBoxColumn.Name = "movieIDDataGridViewTextBoxColumn";
            // 
            // moviesBindingSource
            // 
            this.moviesBindingSource.DataMember = "Movies";
            this.moviesBindingSource.DataSource = this.base1DataSet;
            // 
            // base1DataSet
            // 
            this.base1DataSet.DataSetName = "Base1DataSet";
            this.base1DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.кодDataGridViewTextBoxColumn,
            this.userDataGridViewTextBoxColumn,
            this.movieDataGridViewTextBoxColumn});
            this.dataGridView2.DataSource = this.moviesUsersBindingSource3;
            this.dataGridView2.Location = new System.Drawing.Point(469, 13);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.Size = new System.Drawing.Size(453, 150);
            this.dataGridView2.TabIndex = 1;
            // 
            // кодDataGridViewTextBoxColumn
            // 
            this.кодDataGridViewTextBoxColumn.DataPropertyName = "Код";
            this.кодDataGridViewTextBoxColumn.HeaderText = "Код";
            this.кодDataGridViewTextBoxColumn.Name = "кодDataGridViewTextBoxColumn";
            // 
            // userDataGridViewTextBoxColumn
            // 
            this.userDataGridViewTextBoxColumn.DataPropertyName = "User";
            this.userDataGridViewTextBoxColumn.HeaderText = "User";
            this.userDataGridViewTextBoxColumn.Name = "userDataGridViewTextBoxColumn";
            // 
            // movieDataGridViewTextBoxColumn
            // 
            this.movieDataGridViewTextBoxColumn.DataPropertyName = "Movie";
            this.movieDataGridViewTextBoxColumn.HeaderText = "Movie";
            this.movieDataGridViewTextBoxColumn.Name = "movieDataGridViewTextBoxColumn";
            // 
            // moviesUsersBindingSource3
            // 
            this.moviesUsersBindingSource3.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource3.DataSource = this.base1DataSet;
            // 
            // dataGridView3
            // 
            this.dataGridView3.AutoGenerateColumns = false;
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.фамилияDataGridViewTextBoxColumn,
            this.имяDataGridViewTextBoxColumn,
            this.телефонDataGridViewTextBoxColumn,
            this.userIDDataGridViewTextBoxColumn});
            this.dataGridView3.DataSource = this.пользователиBindingSource;
            this.dataGridView3.Location = new System.Drawing.Point(13, 170);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.Size = new System.Drawing.Size(449, 150);
            this.dataGridView3.TabIndex = 2;
            // 
            // фамилияDataGridViewTextBoxColumn
            // 
            this.фамилияDataGridViewTextBoxColumn.DataPropertyName = "Фамилия";
            this.фамилияDataGridViewTextBoxColumn.HeaderText = "Фамилия";
            this.фамилияDataGridViewTextBoxColumn.Name = "фамилияDataGridViewTextBoxColumn";
            // 
            // имяDataGridViewTextBoxColumn
            // 
            this.имяDataGridViewTextBoxColumn.DataPropertyName = "Имя";
            this.имяDataGridViewTextBoxColumn.HeaderText = "Имя";
            this.имяDataGridViewTextBoxColumn.Name = "имяDataGridViewTextBoxColumn";
            // 
            // телефонDataGridViewTextBoxColumn
            // 
            this.телефонDataGridViewTextBoxColumn.DataPropertyName = "Телефон";
            this.телефонDataGridViewTextBoxColumn.HeaderText = "Телефон";
            this.телефонDataGridViewTextBoxColumn.Name = "телефонDataGridViewTextBoxColumn";
            // 
            // userIDDataGridViewTextBoxColumn
            // 
            this.userIDDataGridViewTextBoxColumn.DataPropertyName = "User_ID";
            this.userIDDataGridViewTextBoxColumn.HeaderText = "User_ID";
            this.userIDDataGridViewTextBoxColumn.Name = "userIDDataGridViewTextBoxColumn";
            // 
            // пользователиBindingSource
            // 
            this.пользователиBindingSource.DataMember = "Пользователи";
            this.пользователиBindingSource.DataSource = this.base1DataSet;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(606, 243);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "Выдать Фильм";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_MoviesUsers);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(606, 191);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 5;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(606, 217);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(545, 191);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "UserID";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(545, 217);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "MovieID";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(468, 329);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 10;
            this.button2.Text = "Message";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Sostavit);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(13, 329);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(449, 208);
            this.textBox1.TabIndex = 11;
            // 
            // moviesUsersBindingSource
            // 
            this.moviesUsersBindingSource.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource.DataSource = this.base1DataSet;
            // 
            // moviesUsersTableAdapter
            // 
            this.moviesUsersTableAdapter.ClearBeforeFill = true;
            // 
            // moviesTableAdapter
            // 
            this.moviesTableAdapter.ClearBeforeFill = true;
            // 
            // moviesUsersBindingSource1
            // 
            this.moviesUsersBindingSource1.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource1.DataSource = this.base1DataSet;
            // 
            // пользователиTableAdapter
            // 
            this.пользователиTableAdapter.ClearBeforeFill = true;
            // 
            // moviesUsersBindingSource2
            // 
            this.moviesUsersBindingSource2.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource2.DataSource = this.base1DataSet;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(853, 169);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 12;
            this.button3.Text = "Renew";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Renew);
            // 
            // base1DataSet2
            // 
            this.base1DataSet2.DataSetName = "Base1DataSet2";
            this.base1DataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // moviesUsersBindingSource4
            // 
            this.moviesUsersBindingSource4.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource4.DataSource = this.base1DataSet2;
            // 
            // moviesUsersTableAdapter1
            // 
            this.moviesUsersTableAdapter1.ClearBeforeFill = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(759, 226);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 23);
            this.button4.TabIndex = 14;
            this.button4.Text = "newMovie";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_NewMovie);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(549, 329);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 23);
            this.button5.TabIndex = 15;
            this.button5.Text = "UsersDolg";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Visible = false;
            this.button5.Click += new System.EventHandler(this.button5_UsersDolg);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(646, 329);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(75, 23);
            this.button6.TabIndex = 16;
            this.button6.Text = "btn6Select";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Visible = false;
            this.button6.Click += new System.EventHandler(this.button6_Select);
            // 
            // moviesMoviesUsersBindingSource
            // 
            this.moviesMoviesUsersBindingSource.DataMember = "MoviesMoviesUsers";
            this.moviesMoviesUsersBindingSource.DataSource = this.moviesBindingSource;
            // 
            // moviesMoviesUsersBindingSource1
            // 
            this.moviesMoviesUsersBindingSource1.DataMember = "MoviesMoviesUsers";
            this.moviesMoviesUsersBindingSource1.DataSource = this.moviesBindingSource;
            // 
            // dataGridView4
            // 
            this.dataGridView4.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView4.Location = new System.Drawing.Point(494, 387);
            this.dataGridView4.Name = "dataGridView4";
            this.dataGridView4.Size = new System.Drawing.Size(448, 150);
            this.dataGridView4.TabIndex = 17;
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(853, 358);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(89, 23);
            this.button7.TabIndex = 18;
            this.button7.Text = "ShowMovies";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(701, 364);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(40, 13);
            this.label1.TabIndex = 20;
            this.label1.Text = "UserID";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(747, 361);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 19;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(954, 549);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.dataGridView4);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView3);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.base1DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.пользователиBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.base1DataSet2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesMoviesUsersBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesMoviesUsersBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView4)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.DataGridView dataGridView3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBox1;
        private Base1DataSet base1DataSet;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource;
        private Base1DataSetTableAdapters.MoviesUsersTableAdapter moviesUsersTableAdapter;
        private System.Windows.Forms.BindingSource moviesBindingSource;
        private Base1DataSetTableAdapters.MoviesTableAdapter moviesTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn названиеФильмаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn годВыходаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn длительностьDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn movieIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource1;
        private System.Windows.Forms.BindingSource пользователиBindingSource;
        private Base1DataSetTableAdapters.ПользователиTableAdapter пользователиTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn фамилияDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn имяDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn телефонDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn кодDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn movieDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource2;
        private System.Windows.Forms.BindingSource moviesMoviesUsersBindingSource;
        private System.Windows.Forms.BindingSource moviesMoviesUsersBindingSource1;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource3;
        private System.Windows.Forms.Button button3;
        private Base1DataSet2 base1DataSet2;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource4;
        private Base1DataSet2TableAdapters.MoviesUsersTableAdapter moviesUsersTableAdapter1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.DataGridView dataGridView4;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox4;
    }
}

