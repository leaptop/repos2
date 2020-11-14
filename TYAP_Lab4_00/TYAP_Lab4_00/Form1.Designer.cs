namespace TYAP_Lab4_00
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox1AlphabetOfTheLanguage = new System.Windows.Forms.TextBox();
            this.textBox2AlphabetOfTheStack = new System.Windows.Forms.TextBox();
            this.textBox3States = new System.Windows.Forms.TextBox();
            this.textBox4InitialState = new System.Windows.Forms.TextBox();
            this.textBox5InitialStackContents = new System.Windows.Forms.TextBox();
            this.textBox6FinalStates = new System.Windows.Forms.TextBox();
            this.textBox7StringToCheck = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.label8 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.richTextBox2Output = new System.Windows.Forms.RichTextBox();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Алфавит языка:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(30, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Состояния:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(30, 62);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "Алфавит стека:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(30, 114);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(121, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "Начальное состояние:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(27, 140);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(164, 13);
            this.label5.TabIndex = 5;
            this.label5.Text = "Начальное содержимое стека:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(27, 166);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(116, 13);
            this.label6.TabIndex = 6;
            this.label6.Text = "Конечные состояния:";
            // 
            // textBox1AlphabetOfTheLanguage
            // 
            this.textBox1AlphabetOfTheLanguage.Location = new System.Drawing.Point(213, 36);
            this.textBox1AlphabetOfTheLanguage.Name = "textBox1AlphabetOfTheLanguage";
            this.textBox1AlphabetOfTheLanguage.Size = new System.Drawing.Size(100, 20);
            this.textBox1AlphabetOfTheLanguage.TabIndex = 7;
            this.textBox1AlphabetOfTheLanguage.Leave += new System.EventHandler(this.textBox1AlphabetOfTheLanguage_Leave);
            // 
            // textBox2AlphabetOfTheStack
            // 
            this.textBox2AlphabetOfTheStack.Location = new System.Drawing.Point(213, 62);
            this.textBox2AlphabetOfTheStack.Name = "textBox2AlphabetOfTheStack";
            this.textBox2AlphabetOfTheStack.Size = new System.Drawing.Size(100, 20);
            this.textBox2AlphabetOfTheStack.TabIndex = 8;
            this.textBox2AlphabetOfTheStack.Leave += new System.EventHandler(this.textBox2AlphabetOfTheStack_Leave);
            // 
            // textBox3States
            // 
            this.textBox3States.Location = new System.Drawing.Point(213, 88);
            this.textBox3States.Name = "textBox3States";
            this.textBox3States.Size = new System.Drawing.Size(100, 20);
            this.textBox3States.TabIndex = 9;
            this.textBox3States.Leave += new System.EventHandler(this.textBox3States_Leave);
            // 
            // textBox4InitialState
            // 
            this.textBox4InitialState.Location = new System.Drawing.Point(213, 114);
            this.textBox4InitialState.Name = "textBox4InitialState";
            this.textBox4InitialState.Size = new System.Drawing.Size(100, 20);
            this.textBox4InitialState.TabIndex = 10;
            this.textBox4InitialState.Leave += new System.EventHandler(this.textBox4InitialState_TextChanged);
            // 
            // textBox5InitialStackContents
            // 
            this.textBox5InitialStackContents.Location = new System.Drawing.Point(213, 140);
            this.textBox5InitialStackContents.Name = "textBox5InitialStackContents";
            this.textBox5InitialStackContents.Size = new System.Drawing.Size(100, 20);
            this.textBox5InitialStackContents.TabIndex = 11;
            this.textBox5InitialStackContents.TextChanged += new System.EventHandler(this.textBox5_TextChangedStackInitChanged);
            // 
            // textBox6FinalStates
            // 
            this.textBox6FinalStates.Location = new System.Drawing.Point(213, 166);
            this.textBox6FinalStates.Name = "textBox6FinalStates";
            this.textBox6FinalStates.Size = new System.Drawing.Size(100, 20);
            this.textBox6FinalStates.TabIndex = 12;
            this.textBox6FinalStates.Leave += new System.EventHandler(this.textBox6FinalStates_Leave);
            // 
            // textBox7StringToCheck
            // 
            this.textBox7StringToCheck.Location = new System.Drawing.Point(213, 192);
            this.textBox7StringToCheck.Name = "textBox7StringToCheck";
            this.textBox7StringToCheck.Size = new System.Drawing.Size(100, 20);
            this.textBox7StringToCheck.TabIndex = 13;
            this.textBox7StringToCheck.TextChanged += new System.EventHandler(this.textBox7_TextChangedStringToCheck);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(328, 36);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(54, 13);
            this.label7.TabIndex = 14;
            this.label7.Text = "Правила:";
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Cursor = System.Windows.Forms.Cursors.SizeAll;
            this.dataGridView1.Location = new System.Drawing.Point(388, 36);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(578, 506);
            this.dataGridView1.TabIndex = 15;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(30, 192);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(125, 13);
            this.label8.TabIndex = 16;
            this.label8.Text = "Цепочка для проверки:";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(972, 36);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(312, 506);
            this.richTextBox1.TabIndex = 17;
            this.richTextBox1.Text = "";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(30, 227);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(161, 23);
            this.button1.TabIndex = 18;
            this.button1.Text = "Проверить цепочку";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.buttonCheckTheChain);
            // 
            // richTextBox2Output
            // 
            this.richTextBox2Output.Location = new System.Drawing.Point(30, 256);
            this.richTextBox2Output.Name = "richTextBox2Output";
            this.richTextBox2Output.Size = new System.Drawing.Size(352, 466);
            this.richTextBox2Output.TabIndex = 19;
            this.richTextBox2Output.Text = "";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(197, 227);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(161, 23);
            this.button2.TabIndex = 20;
            this.button2.Text = "Очистить";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1334, 734);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.richTextBox2Output);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBox7StringToCheck);
            this.Controls.Add(this.textBox6FinalStates);
            this.Controls.Add(this.textBox5InitialStackContents);
            this.Controls.Add(this.textBox4InitialState);
            this.Controls.Add(this.textBox3States);
            this.Controls.Add(this.textBox2AlphabetOfTheStack);
            this.Controls.Add(this.textBox1AlphabetOfTheLanguage);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBox1AlphabetOfTheLanguage;
        private System.Windows.Forms.TextBox textBox2AlphabetOfTheStack;
        private System.Windows.Forms.TextBox textBox3States;
        private System.Windows.Forms.TextBox textBox4InitialState;
        private System.Windows.Forms.TextBox textBox5InitialStackContents;
        private System.Windows.Forms.TextBox textBox6FinalStates;
        private System.Windows.Forms.TextBox textBox7StringToCheck;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RichTextBox richTextBox2Output;
        private System.Windows.Forms.Button button2;
    }
}

