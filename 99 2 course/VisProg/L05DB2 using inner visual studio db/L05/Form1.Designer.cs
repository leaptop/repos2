namespace L05
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
            this.button1 = new System.Windows.Forms.Button();
            this.idDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.countryNameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.capitolDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.continentDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.populationDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tableBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.database1DataSet2 = new L05.Database1DataSet2();
            this.tableTableAdapter = new L05.Database1DataSet2TableAdapters.TableTableAdapter();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tableBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet2)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idDataGridViewTextBoxColumn,
            this.countryNameDataGridViewTextBoxColumn,
            this.capitolDataGridViewTextBoxColumn,
            this.continentDataGridViewTextBoxColumn,
            this.populationDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.tableBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(94, 178);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(514, 270);
            this.dataGridView1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(289, 32);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(168, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Северная Америка";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // idDataGridViewTextBoxColumn
            // 
            this.idDataGridViewTextBoxColumn.DataPropertyName = "Id";
            this.idDataGridViewTextBoxColumn.HeaderText = "Id";
            this.idDataGridViewTextBoxColumn.Name = "idDataGridViewTextBoxColumn";
            // 
            // countryNameDataGridViewTextBoxColumn
            // 
            this.countryNameDataGridViewTextBoxColumn.DataPropertyName = "CountryName";
            this.countryNameDataGridViewTextBoxColumn.HeaderText = "CountryName";
            this.countryNameDataGridViewTextBoxColumn.Name = "countryNameDataGridViewTextBoxColumn";
            // 
            // capitolDataGridViewTextBoxColumn
            // 
            this.capitolDataGridViewTextBoxColumn.DataPropertyName = "Capitol";
            this.capitolDataGridViewTextBoxColumn.HeaderText = "Capitol";
            this.capitolDataGridViewTextBoxColumn.Name = "capitolDataGridViewTextBoxColumn";
            // 
            // continentDataGridViewTextBoxColumn
            // 
            this.continentDataGridViewTextBoxColumn.DataPropertyName = "Continent";
            this.continentDataGridViewTextBoxColumn.HeaderText = "Continent";
            this.continentDataGridViewTextBoxColumn.Name = "continentDataGridViewTextBoxColumn";
            // 
            // populationDataGridViewTextBoxColumn
            // 
            this.populationDataGridViewTextBoxColumn.DataPropertyName = "Population";
            this.populationDataGridViewTextBoxColumn.HeaderText = "Population";
            this.populationDataGridViewTextBoxColumn.Name = "populationDataGridViewTextBoxColumn";
            // 
            // tableBindingSource
            // 
            this.tableBindingSource.DataMember = "Table";
            this.tableBindingSource.DataSource = this.database1DataSet2;
            // 
            // database1DataSet2
            // 
            this.database1DataSet2.DataSetName = "Database1DataSet2";
            this.database1DataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tableTableAdapter
            // 
            this.tableTableAdapter.ClearBeforeFill = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(289, 71);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(168, 25);
            this.button2.TabIndex = 2;
            this.button2.Text = "Южная Америка";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(482, 32);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(168, 25);
            this.button3.TabIndex = 3;
            this.button3.Text = "Сортировать";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(68, 72);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(168, 25);
            this.button4.TabIndex = 5;
            this.button4.Text = "Начинается с \'к\'";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(68, 33);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(168, 23);
            this.button5.TabIndex = 4;
            this.button5.Text = "Всё";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(68, 112);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(168, 25);
            this.button6.TabIndex = 6;
            this.button6.Text = "Содержит \'к\'";
            this.button6.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(770, 473);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tableBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private Database1DataSet2 database1DataSet2;
        private System.Windows.Forms.BindingSource tableBindingSource;
        private Database1DataSet2TableAdapters.TableTableAdapter tableTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn countryNameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn capitolDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn continentDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn populationDataGridViewTextBoxColumn;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
    }
}

