namespace SameLayerSample
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
            this.textBox1StringToCheck = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox2Alphabet = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox3FinalSubString = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox4SymbolForKratnost = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.numericUpDown1Kratnost = new System.Windows.Forms.NumericUpDown();
            this.button2 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1Kratnost)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1StringToCheck
            // 
            this.textBox1StringToCheck.Location = new System.Drawing.Point(208, 114);
            this.textBox1StringToCheck.Name = "textBox1StringToCheck";
            this.textBox1StringToCheck.Size = new System.Drawing.Size(232, 20);
            this.textBox1StringToCheck.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 114);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(118, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Строка для проверки:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(125, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Алфавит через пробел:";
            // 
            // textBox2Alphabet
            // 
            this.textBox2Alphabet.Location = new System.Drawing.Point(208, 62);
            this.textBox2Alphabet.Name = "textBox2Alphabet";
            this.textBox2Alphabet.Size = new System.Drawing.Size(232, 20);
            this.textBox2Alphabet.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 88);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(195, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Обязательная конечная подцепочка:";
            // 
            // textBox3FinalSubString
            // 
            this.textBox3FinalSubString.Location = new System.Drawing.Point(208, 88);
            this.textBox3FinalSubString.Name = "textBox3FinalSubString";
            this.textBox3FinalSubString.Size = new System.Drawing.Size(232, 20);
            this.textBox3FinalSubString.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(7, 140);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(167, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Кратность появления символа:";
            // 
            // textBox4SymbolForKratnost
            // 
            this.textBox4SymbolForKratnost.Location = new System.Drawing.Point(208, 140);
            this.textBox4SymbolForKratnost.Name = "textBox4SymbolForKratnost";
            this.textBox4SymbolForKratnost.Size = new System.Drawing.Size(47, 20);
            this.textBox4SymbolForKratnost.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(284, 147);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(40, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "равна:";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(333, 167);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(107, 23);
            this.button1.TabIndex = 10;
            this.button1.Text = "Построить ДКА";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // numericUpDown1Kratnost
            // 
            this.numericUpDown1Kratnost.Location = new System.Drawing.Point(330, 141);
            this.numericUpDown1Kratnost.Name = "numericUpDown1Kratnost";
            this.numericUpDown1Kratnost.Size = new System.Drawing.Size(110, 20);
            this.numericUpDown1Kratnost.TabIndex = 11;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(208, 33);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(232, 23);
            this.button2.TabIndex = 12;
            this.button2.Text = "инициализировать тестовый сценарий";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 196);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 60;
            this.dataGridView1.Size = new System.Drawing.Size(428, 433);
            this.dataGridView1.TabIndex = 13;
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(928, 13);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(403, 647);
            this.richTextBox1.TabIndex = 14;
            this.richTextBox1.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1337, 672);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.numericUpDown1Kratnost);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox4SymbolForKratnost);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox3FinalSubString);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox2Alphabet);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1StringToCheck);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1Kratnost)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1StringToCheck;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox2Alphabet;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox3FinalSubString;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox4SymbolForKratnost;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.NumericUpDown numericUpDown1Kratnost;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.RichTextBox richTextBox1;
    }
}

