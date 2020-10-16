namespace TYAP_Lab2_00
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
            this.textBox1Alphabet = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox2States = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox3StartingState = new System.Windows.Forms.TextBox();
            this.textBox4FinalStates = new System.Windows.Forms.TextBox();
            this.button1CreateTheTable = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox5ChainToCheck = new System.Windows.Forms.TextBox();
            this.button2CheckTheChain = new System.Windows.Forms.Button();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.button2ClearTheRichTextBoxes = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1Alphabet
            // 
            this.textBox1Alphabet.Location = new System.Drawing.Point(282, 46);
            this.textBox1Alphabet.Name = "textBox1Alphabet";
            this.textBox1Alphabet.Size = new System.Drawing.Size(240, 22);
            this.textBox1Alphabet.TabIndex = 1;
            this.textBox1Alphabet.TextChanged += new System.EventHandler(this.textBox1Alphabet_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 46);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(252, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Введите алфавит ДКА через пробел";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(2, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(336, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Выясняю, принадлежит ли цепочка данному ДКА";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 72);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(264, 17);
            this.label3.TabIndex = 4;
            this.label3.Text = "Введите состояния ДКА через пробел";
            // 
            // textBox2States
            // 
            this.textBox2States.Location = new System.Drawing.Point(282, 72);
            this.textBox2States.Name = "textBox2States";
            this.textBox2States.Size = new System.Drawing.Size(240, 22);
            this.textBox2States.TabIndex = 5;
            this.textBox2States.TextChanged += new System.EventHandler(this.textBox2States_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(703, 72);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(241, 17);
            this.label4.TabIndex = 6;
            this.label4.Text = "конечные состояния через пробел";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(786, 41);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(152, 17);
            this.label5.TabIndex = 7;
            this.label5.Text = "начальное состояние";
            // 
            // textBox3StartingState
            // 
            this.textBox3StartingState.Location = new System.Drawing.Point(944, 41);
            this.textBox3StartingState.Name = "textBox3StartingState";
            this.textBox3StartingState.Size = new System.Drawing.Size(57, 22);
            this.textBox3StartingState.TabIndex = 8;
            this.textBox3StartingState.TextChanged += new System.EventHandler(this.textBox3StartingState_TextChanged);
            // 
            // textBox4FinalStates
            // 
            this.textBox4FinalStates.Location = new System.Drawing.Point(945, 72);
            this.textBox4FinalStates.Name = "textBox4FinalStates";
            this.textBox4FinalStates.Size = new System.Drawing.Size(144, 22);
            this.textBox4FinalStates.TabIndex = 9;
            this.textBox4FinalStates.TextChanged += new System.EventHandler(this.textBox4FinalStates_TextChanged);
            // 
            // button1CreateTheTable
            // 
            this.button1CreateTheTable.Location = new System.Drawing.Point(272, 203);
            this.button1CreateTheTable.Name = "button1CreateTheTable";
            this.button1CreateTheTable.Size = new System.Drawing.Size(300, 46);
            this.button1CreateTheTable.TabIndex = 10;
            this.button1CreateTheTable.Text = "0 сформировать dataGridView";
            this.button1CreateTheTable.UseVisualStyleBackColor = true;
            this.button1CreateTheTable.Click += new System.EventHandler(this.button1_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(610, 103);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(334, 17);
            this.label6.TabIndex = 11;
            this.label6.Text = "Введите цепочку для проверки принадлежности ";
            // 
            // textBox5ChainToCheck
            // 
            this.textBox5ChainToCheck.Location = new System.Drawing.Point(945, 103);
            this.textBox5ChainToCheck.Name = "textBox5ChainToCheck";
            this.textBox5ChainToCheck.Size = new System.Drawing.Size(290, 22);
            this.textBox5ChainToCheck.TabIndex = 12;
            this.textBox5ChainToCheck.TextChanged += new System.EventHandler(this.textBox5ChainToCheck_TextChanged);
            // 
            // button2CheckTheChain
            // 
            this.button2CheckTheChain.Location = new System.Drawing.Point(607, 174);
            this.button2CheckTheChain.Name = "button2CheckTheChain";
            this.button2CheckTheChain.Size = new System.Drawing.Size(295, 23);
            this.button2CheckTheChain.TabIndex = 13;
            this.button2CheckTheChain.Text = "5 проверить цепочку";
            this.button2CheckTheChain.UseVisualStyleBackColor = true;
            this.button2CheckTheChain.Click += new System.EventHandler(this.button2CheckTheChain_Click);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(1040, 174);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(450, 557);
            this.richTextBox1.TabIndex = 14;
            this.richTextBox1.Text = "";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 153);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(254, 44);
            this.button1.TabIndex = 15;
            this.button1.Text = "1a считать матрицу из памяти,\r\nсостояния полей с экрана";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1ReadMatrixFromTheMemoryFieldsfromTheScreen);
            // 
            // richTextBox2
            // 
            this.richTextBox2.Location = new System.Drawing.Point(607, 203);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.Size = new System.Drawing.Size(412, 528);
            this.richTextBox2.TabIndex = 17;
            this.richTextBox2.Text = "";
            // 
            // button2ClearTheRichTextBoxes
            // 
            this.button2ClearTheRichTextBoxes.Location = new System.Drawing.Point(834, 737);
            this.button2ClearTheRichTextBoxes.Name = "button2ClearTheRichTextBoxes";
            this.button2ClearTheRichTextBoxes.Size = new System.Drawing.Size(203, 23);
            this.button2ClearTheRichTextBoxes.TabIndex = 18;
            this.button2ClearTheRichTextBoxes.Text = "очистить";
            this.button2ClearTheRichTextBoxes.UseVisualStyleBackColor = true;
            this.button2ClearTheRichTextBoxes.Click += new System.EventHandler(this.button2ClearTheRichTextBoxes_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 100);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(254, 47);
            this.button2.TabIndex = 19;
            this.button2.Text = "-1 считать состояние задачи 15,\r\nпостроить всё";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2ReadATaskAndBuildAll);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(1040, 145);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(203, 23);
            this.button3.TabIndex = 20;
            this.button3.Text = "вывести все данные";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(12, 203);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(254, 48);
            this.button4.TabIndex = 21;
            this.button4.Text = "1b считать матрицу с экрана,\r\nсостояния полей с экрана";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4ReadMatrixFromScreenAndFieldsFromScreen);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowDrop = true;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.dataGridView1.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.dataGridView1.BorderStyle = global::TYAP_Lab2_00.Properties.Settings.Default.a;
            this.dataGridView1.ClipboardCopyMode = System.Windows.Forms.DataGridViewClipboardCopyMode.EnableAlwaysIncludeHeaderText;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.DataBindings.Add(new System.Windows.Forms.Binding("BorderStyle", global::TYAP_Lab2_00.Properties.Settings.Default, "a", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.dataGridView1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.dataGridView1.Location = new System.Drawing.Point(5, 347);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 49;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(577, 364);
            this.dataGridView1.TabIndex = 0;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(272, 153);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(254, 47);
            this.button5.TabIndex = 22;
            this.button5.Text = "-1 считать состояние задачи 17a,\r\nпостроить всё";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5InitExercise17a);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(272, 100);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(254, 47);
            this.button6.TabIndex = 23;
            this.button6.Text = "-1 считать состояние задачи 16а,\r\nпостроить всё";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6InitTask16a);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(272, 257);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(300, 46);
            this.button7.TabIndex = 24;
            this.button7.Text = "0 считать символы из матрицы";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7ReadMatrixSymbols);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1502, 793);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button2ClearTheRichTextBoxes);
            this.Controls.Add(this.richTextBox2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.button2CheckTheChain);
            this.Controls.Add(this.textBox5ChainToCheck);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.button1CreateTheTable);
            this.Controls.Add(this.textBox4FinalStates);
            this.Controls.Add(this.textBox3StartingState);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox2States);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1Alphabet);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox textBox1Alphabet;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox2States;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox3StartingState;
        private System.Windows.Forms.TextBox textBox4FinalStates;
        private System.Windows.Forms.Button button1CreateTheTable;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBox5ChainToCheck;
        private System.Windows.Forms.Button button2CheckTheChain;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.Button button2ClearTheRichTextBoxes;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
    }
}

