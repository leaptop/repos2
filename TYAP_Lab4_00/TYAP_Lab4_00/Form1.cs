using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TYAP_Lab4_00
{
    public partial class Form1 : Form
    {
        static Form1 f1;
        public Form1()
        {
            InitializeComponent();
            f1 = this;
            f1.dataGridViewTask20aInit();
        }
        public string[] LanguageAlphabet;
        public string[] StackAlphabet;
        public string[] states;
        public string[] finalStates;
        public string stringToCheck;
        public string nextCharacterOfTheString;
        public string topOfTheStack;
        public string stringToAttachToStack;
        public Stack stack;// I will fill the initial stack from left to right
        public string[,] mainMatrix;
        char[] stringTocheckInChars;
        public string[] stringToCheckInStringArray;
         public string initialStackInString;
        public string[] initialstackInStringArray;
        public string currentState = "";
        public string initialState = "";
        public string newState = "";
        public void dataGridViewTask20aInit()
        {
            dataGridView1.ColumnHeadersVisible = true;
            dataGridView1.RowHeadersVisible = true;
            
            textBox1AlphabetOfTheLanguage.Text = "0 1";
            textBox2AlphabetOfTheStack.Text = "0 1 z";
            textBox3States.Text = "q0 q1 q2";
            currentState = initialState = textBox4InitialState.Text = "q0";
            textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "q2";
            stringToCheck = textBox7StringToCheck.Text = "01";
            stringTocheckInChars = stringToCheck.ToCharArray();

            dataGridView1.RowCount = 6;
            dataGridView1.ColumnCount = 6;
            dataGridView1.Columns[0].HeaderText = "state(q)";
            dataGridView1.Columns[1].HeaderText = "nextSymbol";
            dataGridView1.Columns[2].HeaderCell.Value = "topOfTheStack";
            dataGridView1.Columns[3].HeaderCell.Value = "tact";
            dataGridView1.Columns[4].HeaderCell.Value = "newState";
            dataGridView1.Columns[5].HeaderCell.Value = "newSymbolsForStack";

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "0";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q0";
            dataGridView1.Rows[0].Cells[5].Value = "0z";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "1";
            dataGridView1.Rows[1].Cells[2].Value = "0";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q1";
            dataGridView1.Rows[1].Cells[5].Value = "0";

            dataGridView1.Rows[2].Cells[0].Value = "q1";
            dataGridView1.Rows[2].Cells[1].Value = "1";
            dataGridView1.Rows[2].Cells[2].Value = "0";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q1";
            dataGridView1.Rows[2].Cells[5].Value = "";

            dataGridView1.Rows[3].Cells[0].Value = "q0";
            dataGridView1.Rows[3].Cells[1].Value = "0";
            dataGridView1.Rows[3].Cells[2].Value = "0";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q0";
            dataGridView1.Rows[3].Cells[5].Value = "00";

            dataGridView1.Rows[4].Cells[0].Value = "q1";
            dataGridView1.Rows[4].Cells[1].Value = "";
            dataGridView1.Rows[4].Cells[2].Value = "0";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q1";
            dataGridView1.Rows[4].Cells[5].Value = "";

            dataGridView1.Rows[5].Cells[0].Value = "q1";
            dataGridView1.Rows[5].Cells[1].Value = "";
            dataGridView1.Rows[5].Cells[2].Value = "z";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q2";
            dataGridView1.Rows[5].Cells[5].Value = "";

            /*          richTextBox1.AppendText("states are assigned:\n");
                      states = new string[dataGridView1.RowCount];
                      for (int j = 0; j < states.Length; j++)
                      {
                          states[j] = dataGridView1.Rows[j].Cells[0].Value.ToString();
                          richTextBox1.AppendText("states[" + j + "] = " + states[j]+", ");
                          //the problem is that states are not always unique and that the left parts of the rules not always
                          //contain all the states, so maybe it's better to work directly with datagridview
                      }*/
            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = i++.ToString();
            }
            foreach (DataGridViewColumn column in dataGridView1.Columns)
            {
                column.SortMode = DataGridViewColumnSortMode.NotSortable;
            }
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
            dataGridView1.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;


        }

        private void textBox7_TextChangedStringToCheck(object sender, EventArgs e)
        {
            stringToCheck = textBox7StringToCheck.Text;
            richTextBox1.AppendText("stringToCheck now is:" + stringToCheck + "\n");
            stringToCheckInStringArray = stringToArrayOfStrings(stringToCheck);

            /*   richTextBox1.AppendText("chars now are:\n");
               for (int i = 0; i < stringTocheckInChars.Length; i++)
               {
                   richTextBox1.AppendText(stringTocheckInChars[i].ToString());
               }*/
            richTextBox1.AppendText("\nstringToCheckInStringArray now is:\n");
            for (int i = 0; i < stringToCheckInStringArray.Length; i++)
            {
                richTextBox1.AppendText(stringToCheckInStringArray[i]);
            }
            richTextBox1.AppendText("\n");
        }
        public string[] stringToArrayOfStrings(string stringToCheck)
        {//this method doesn't fit because of parsing to chars... no it fits... yet
            char[] stringTocheckInChars = stringToCheck.ToCharArray();
            string[] stringToCheckInStringArray = new string[stringTocheckInChars.Length];
            for (int i = 0; i < stringTocheckInChars.Length; i++)
            {
                stringToCheckInStringArray[i] = stringTocheckInChars[i].ToString();
            }
            return stringToCheckInStringArray;
        }

        private void buttonCheckTheChain(object sender, EventArgs e)
        {
            readConditionsFromTheInterface();

            for (int i = 0; i < stringToCheck.Length; i++)
            {
                richTextBox2Output.AppendText("Текущее состояние: " + currentState + "\n");
                richTextBox2Output.AppendText("Остаток цепочки: " + stringToCheckInStringArray[i]+"\n");
                richTextBox2Output.AppendText("Вершина стека: " + stack.Peek() + "\n");
                // richTextBox2Output.AppendText("Стек: " +   //Do I need to print the whole stack?
                //if the curr
                richTextBox2Output.AppendText("Новое состояние: " + newState + "\n");
                richTextBox2Output.AppendText("Цепочка добавляемая в стек: " + stringToAttachToStack + "\n\n");

            }


        }
        public void readConditionsFromTheInterface()
        {//one of the problems is what to consider correct: textBoxes or the rules... Let it be the textBoxes
            LanguageAlphabet = textBox1AlphabetOfTheLanguage.Text.Split(' ');
            StackAlphabet = textBox2AlphabetOfTheStack.Text.Split(' ');
            states = textBox3States.Text.Split(' ');
            initialState = currentState = textBox4InitialState.Text;
            stack = new Stack();
            initialStackInString = textBox5InitialStackContents.Text;
            initialstackInStringArray = stringToArrayOfStrings(initialStackInString);
            for (int i = 0; i < initialstackInStringArray.Length; i++)
            {
                stack.Push(initialstackInStringArray[i]);
            }
            finalStates = textBox6FinalStates.Text.Split(' ');
            stringToCheck = textBox7StringToCheck.Text;

        }

        private void textBox5_TextChangedStackInitChanged(object sender, EventArgs e)
        {
            string initialStackInString = textBox5InitialStackContents.Text;
            richTextBox1.AppendText("stack was changed. InitialStackInString now is = " + initialStackInString + "\n");
            initialstackInStringArray = stringToArrayOfStrings(initialStackInString);
            stack = new Stack();
            for (int i = 0; i < initialstackInStringArray.Length; i++)
            {
                stack.Push(initialstackInStringArray[i]);
            }
            richTextBox1.AppendText("stack was changed. it's contents now are:\n");
            Stack stackCopy = (Stack)stack.Clone();
            for (int i = 0; i < stack.Count; i++)
            {
                richTextBox1.AppendText(stackCopy.Peek().ToString());
                stackCopy.Pop();
            }
            richTextBox1.AppendText("\n");
        }

        private void textBox4InitialState_TextChanged(object sender, EventArgs e)
        {
            bool newStateIsCorrect = false;
            for (int i = 0; i < dataGridView1.RowCount; i++)
            {
                if (textBox4InitialState.Text.Equals(dataGridView1.Rows[i].Cells[0].Value) ||
                    textBox4InitialState.Text.Equals(dataGridView1.Rows[i].Cells[4].Value))
                {
                    initialState = textBox4InitialState.Text;
                    newStateIsCorrect = true;
                    break;
                }

            }
            if (newStateIsCorrect)
            {
                richTextBox1.AppendText("initialState was changed and now it's:" + initialState + "\n");
            }
            else
            {
                richTextBox1.AppendText("inseted state " + textBox4InitialState.Text + " doesn't belong to states in the rules\n");
                textBox4InitialState.Text = "q0";
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox2Output.Clear();
        }
    }

}
