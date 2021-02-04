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
            this.components = new System.ComponentModel.Container();
            this.textBox1StringToCheck = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox2Alphabet = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox3FinalSubString = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox4SymbolForMultiplicity = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.numericUpDown1Multiplicity = new System.Windows.Forms.NumericUpDown();
            this.button2 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.richTextBox1Helper = new System.Windows.Forms.RichTextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.richTextBox2CheckResults = new System.Windows.Forms.RichTextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.textBoxInitialState = new System.Windows.Forms.TextBox();
            this.textBoxFinalState = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8InitialState = new System.Windows.Forms.Label();
            this.label9FinalState = new System.Windows.Forms.Label();
            this.richTextBox1M = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1Multiplicity)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1StringToCheck
            // 
            this.textBox1StringToCheck.Location = new System.Drawing.Point(219, 124);
            this.textBox1StringToCheck.Name = "textBox1StringToCheck";
            this.textBox1StringToCheck.Size = new System.Drawing.Size(93, 20);
            this.textBox1StringToCheck.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 130);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(118, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Строка для проверки:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 84);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(125, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Алфавит через пробел:";
            // 
            // textBox2Alphabet
            // 
            this.textBox2Alphabet.Location = new System.Drawing.Point(219, 77);
            this.textBox2Alphabet.Name = "textBox2Alphabet";
            this.textBox2Alphabet.Size = new System.Drawing.Size(95, 20);
            this.textBox2Alphabet.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(18, 104);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(195, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Обязательная конечная подцепочка:";
            // 
            // textBox3FinalSubString
            // 
            this.textBox3FinalSubString.Location = new System.Drawing.Point(219, 101);
            this.textBox3FinalSubString.Name = "textBox3FinalSubString";
            this.textBox3FinalSubString.Size = new System.Drawing.Size(93, 20);
            this.textBox3FinalSubString.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 162);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(167, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Кратность появления символа:";
            // 
            // textBox4SymbolForMultiplicity
            // 
            this.textBox4SymbolForMultiplicity.Location = new System.Drawing.Point(186, 155);
            this.textBox4SymbolForMultiplicity.Name = "textBox4SymbolForMultiplicity";
            this.textBox4SymbolForMultiplicity.Size = new System.Drawing.Size(27, 20);
            this.textBox4SymbolForMultiplicity.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(216, 162);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(40, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "равна:";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(271, 753);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(94, 37);
            this.button1.TabIndex = 10;
            this.button1.Text = "Построить ДКА пример";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Visible = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // numericUpDown1Multiplicity
            // 
            this.numericUpDown1Multiplicity.Location = new System.Drawing.Point(262, 155);
            this.numericUpDown1Multiplicity.Name = "numericUpDown1Multiplicity";
            this.numericUpDown1Multiplicity.Size = new System.Drawing.Size(37, 20);
            this.numericUpDown1Multiplicity.TabIndex = 11;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(135, 33);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(143, 38);
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
            this.dataGridView1.Location = new System.Drawing.Point(12, 217);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 60;
            this.dataGridView1.Size = new System.Drawing.Size(399, 370);
            this.dataGridView1.TabIndex = 13;
            // 
            // richTextBox1Helper
            // 
            this.richTextBox1Helper.Location = new System.Drawing.Point(1101, 33);
            this.richTextBox1Helper.Name = "richTextBox1Helper";
            this.richTextBox1Helper.Size = new System.Drawing.Size(345, 422);
            this.richTextBox1Helper.TabIndex = 14;
            this.richTextBox1Helper.Text = "";
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(318, 124);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(78, 42);
            this.button3.TabIndex = 15;
            this.button3.Text = "Проверить цепочку";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // richTextBox2CheckResults
            // 
            this.richTextBox2CheckResults.Location = new System.Drawing.Point(14, 667);
            this.richTextBox2CheckResults.Name = "richTextBox2CheckResults";
            this.richTextBox2CheckResults.Size = new System.Drawing.Size(378, 71);
            this.richTextBox2CheckResults.TabIndex = 16;
            this.richTextBox2CheckResults.Text = "";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(77, 34);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(52, 23);
            this.button4.TabIndex = 19;
            this.button4.Text = "Тема";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(19, 33);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(52, 24);
            this.button5.TabIndex = 20;
            this.button5.Text = "Автор";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(186, 753);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(79, 37);
            this.button6.TabIndex = 21;
            this.button6.Text = "сохранить результаты вычислений";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(318, 50);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(93, 47);
            this.button7.TabIndex = 22;
            this.button7.Text = "Построить ДКА по интерфейсу";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // textBoxInitialState
            // 
            this.textBoxInitialState.Location = new System.Drawing.Point(1060, 9);
            this.textBoxInitialState.Name = "textBoxInitialState";
            this.textBoxInitialState.Size = new System.Drawing.Size(3, 20);
            this.textBoxInitialState.TabIndex = 24;
            this.textBoxInitialState.Visible = false;
            // 
            // textBoxFinalState
            // 
            this.textBoxFinalState.Location = new System.Drawing.Point(1070, 9);
            this.textBoxFinalState.Name = "textBoxFinalState";
            this.textBoxFinalState.Size = new System.Drawing.Size(3, 20);
            this.textBoxFinalState.TabIndex = 25;
            this.textBoxFinalState.Visible = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(18, 618);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(121, 13);
            this.label6.TabIndex = 26;
            this.label6.Text = "Начальное состояние:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(183, 618);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(114, 13);
            this.label7.TabIndex = 27;
            this.label7.Text = "Конечное состояние:";
            // 
            // label8InitialState
            // 
            this.label8InitialState.AutoSize = true;
            this.label8InitialState.Location = new System.Drawing.Point(145, 618);
            this.label8InitialState.Name = "label8InitialState";
            this.label8InitialState.Size = new System.Drawing.Size(13, 13);
            this.label8InitialState.TabIndex = 28;
            this.label8InitialState.Text = "_";
            // 
            // label9FinalState
            // 
            this.label9FinalState.AutoSize = true;
            this.label9FinalState.Location = new System.Drawing.Point(303, 618);
            this.label9FinalState.Name = "label9FinalState";
            this.label9FinalState.Size = new System.Drawing.Size(13, 13);
            this.label9FinalState.TabIndex = 29;
            this.label9FinalState.Text = "_";
            // 
            // richTextBox1M
            // 
            this.richTextBox1M.Location = new System.Drawing.Point(14, 634);
            this.richTextBox1M.Name = "richTextBox1M";
            this.richTextBox1M.Size = new System.Drawing.Size(378, 27);
            this.richTextBox1M.TabIndex = 30;
            this.richTextBox1M.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1458, 792);
            this.Controls.Add(this.richTextBox1M);
            this.Controls.Add(this.label9FinalState);
            this.Controls.Add(this.label8InitialState);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBoxFinalState);
            this.Controls.Add(this.textBoxInitialState);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.richTextBox2CheckResults);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.richTextBox1Helper);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.numericUpDown1Multiplicity);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox4SymbolForMultiplicity);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox3FinalSubString);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox2Alphabet);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1StringToCheck);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1Multiplicity)).EndInit();
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
        private System.Windows.Forms.TextBox textBox4SymbolForMultiplicity;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.NumericUpDown numericUpDown1Multiplicity;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.RichTextBox richTextBox1Helper;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.RichTextBox richTextBox2CheckResults;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.TextBox textBoxInitialState;
        private System.Windows.Forms.TextBox textBoxFinalState;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8InitialState;
        private System.Windows.Forms.Label label9FinalState;
        private System.Windows.Forms.RichTextBox richTextBox1M;
    }
}

