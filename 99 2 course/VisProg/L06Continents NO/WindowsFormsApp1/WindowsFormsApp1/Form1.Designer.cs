namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.названиеСтраныDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.столицаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.континентDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.населениеDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.страныBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.countryDataSet = new WindowsFormsApp1.CountryDataSet();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.button6 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.страныTableAdapter = new WindowsFormsApp1.CountryDataSetTableAdapters.СтраныTableAdapter();
            this.countryDataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.страныBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.countryDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.countryDataSetBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(144, 48);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(115, 49);
            this.button1.TabIndex = 0;
            this.button1.Text = "Северная Америка";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.названиеСтраныDataGridViewTextBoxColumn,
            this.столицаDataGridViewTextBoxColumn,
            this.континентDataGridViewTextBoxColumn,
            this.населениеDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.страныBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(12, 217);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(627, 387);
            this.dataGridView1.TabIndex = 1;
            // 
            // названиеСтраныDataGridViewTextBoxColumn
            // 
            this.названиеСтраныDataGridViewTextBoxColumn.DataPropertyName = "Название страны";
            this.названиеСтраныDataGridViewTextBoxColumn.HeaderText = "Название страны";
            this.названиеСтраныDataGridViewTextBoxColumn.Name = "названиеСтраныDataGridViewTextBoxColumn";
            // 
            // столицаDataGridViewTextBoxColumn
            // 
            this.столицаDataGridViewTextBoxColumn.DataPropertyName = "Столица";
            this.столицаDataGridViewTextBoxColumn.HeaderText = "Столица";
            this.столицаDataGridViewTextBoxColumn.Name = "столицаDataGridViewTextBoxColumn";
            // 
            // континентDataGridViewTextBoxColumn
            // 
            this.континентDataGridViewTextBoxColumn.DataPropertyName = "Континент";
            this.континентDataGridViewTextBoxColumn.HeaderText = "Континент";
            this.континентDataGridViewTextBoxColumn.Name = "континентDataGridViewTextBoxColumn";
            // 
            // населениеDataGridViewTextBoxColumn
            // 
            this.населениеDataGridViewTextBoxColumn.DataPropertyName = "Население";
            this.населениеDataGridViewTextBoxColumn.HeaderText = "Население";
            this.населениеDataGridViewTextBoxColumn.Name = "населениеDataGridViewTextBoxColumn";
            // 
            // страныBindingSource
            // 
            this.страныBindingSource.DataMember = "Страны";
            this.страныBindingSource.DataSource = this.countryDataSet;
            // 
            // countryDataSet
            // 
            this.countryDataSet.DataSetName = "CountryDataSet";
            this.countryDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(35, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Название";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(159, 18);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(79, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Континент";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(144, 103);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(115, 49);
            this.button2.TabIndex = 4;
            this.button2.Text = "Южная Америка";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(12, 48);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(115, 49);
            this.button3.TabIndex = 5;
            this.button3.Text = "Всё";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(12, 103);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(115, 49);
            this.button4.TabIndex = 6;
            this.button4.Text = "Начинается с \"К\"";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(12, 158);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(115, 49);
            this.button5.TabIndex = 7;
            this.button5.Text = "Содержит \"к\"";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(293, 18);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(81, 17);
            this.label3.TabIndex = 8;
            this.label3.Text = "Население";
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(276, 48);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(115, 49);
            this.button6.TabIndex = 9;
            this.button6.Text = "Сортировать";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 610);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(138, 34);
            this.textBox1.TabIndex = 10;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // страныTableAdapter
            // 
            this.страныTableAdapter.ClearBeforeFill = true;
            // 
            // countryDataSetBindingSource
            // 
            this.countryDataSetBindingSource.DataSource = this.countryDataSet;
            this.countryDataSetBindingSource.Position = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(650, 652);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "База данных";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.страныBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.countryDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.countryDataSetBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private CountryDataSet countryDataSet;
        private System.Windows.Forms.BindingSource страныBindingSource;
        private CountryDataSetTableAdapters.СтраныTableAdapter страныTableAdapter;
        private System.Windows.Forms.BindingSource countryDataSetBindingSource;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.DataGridViewTextBoxColumn названиеСтраныDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn столицаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn континентDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn населениеDataGridViewTextBoxColumn;
        private System.Windows.Forms.TextBox textBox1;
    }
}

