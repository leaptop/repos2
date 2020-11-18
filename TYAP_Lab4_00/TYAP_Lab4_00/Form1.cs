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
            f1.dataGridViewInit();
        }
        public string[] LanguageAlphabet;
        public string[] StackAlphabet;
        public string[] states;
        public string[] finalStates;
        public string stringToCheck;
        public string nextCharacterOfTheString;
        public string topOfTheStack;
        public string stringToAttachToStack;
        public string[] stringToAttachToStackInArrayOfSymbols;
        public Stack stack;// I will fill the initial stack from left to right
        public string[,] mainMatrix;
        char[] stringTocheckInChars;
        public string[] stringToCheckInStringArray;
        public string initialStackInString;
        public string[] initialstackInStringArray;
        public string currentState = "";
        public string initialState = "";
        public string newState = "";
        public string currentSymbolOfTheCheckedString = "";
        public bool initializationIsInProgress = true;

        private void buttonCheckTheChain(object sender, EventArgs e)
        {
            richTextBox2Output.Clear();
            readConditionsFromTheInterface();
            if ((stack.Count == 0))//эта проверка уже есть внизу... куда её поставить лучше?
            {
                richTextBox2Output.AppendText("Стек пуст. Следующий такт невозможен. Цепочка не принята\n");
                return;
            }
            int usedRule = -1;
            int stringsLength = stringToCheckInStringArray.Length;
            for (int i = 0; i < stringToCheckInStringArray.Length + stack.Count; i++)
            {
                string ith_stringToCheckInStringArray;
                if (i >= (stringsLength))
                {
                    ith_stringToCheckInStringArray = "";
                }
                else
                {
                    ith_stringToCheckInStringArray = stringToCheckInStringArray[i];
                }
                //output in parentheses:
                richTextBox2Output.AppendText("(" + currentState + ", ");
                for (int m = i; m < stringToCheckInStringArray.Length; m++)
                {
                    richTextBox2Output.AppendText(stringToCheckInStringArray[m]);
                }
                richTextBox2Output.AppendText(", ");
                // richTextBox2Output.AppendText("stack.ToString() = " + stack.);//outputs the name of the class
                Stack stackToPrint = (Stack)stack.Clone();
                PrintStack(stackToPrint);
                richTextBox2Output.AppendText(")\n");

                //now it's time to go through the rules in datagridview1
                for (int j = 0; j < dataGridView1.RowCount; j++)
                {
                    if (currentState.Equals(dataGridView1.Rows[j].Cells[0].Value.ToString()) &&
                        ith_stringToCheckInStringArray.Equals(dataGridView1.Rows[j].Cells[1].Value.ToString()) &&
                        stack.Peek().ToString().Equals(dataGridView1.Rows[j].Cells[2].Value.ToString()))
                    {
                        usedRule = j;
                        stack.Pop();
                        currentState = dataGridView1.Rows[j].Cells[4].Value.ToString();
                        stringToAttachToStack = dataGridView1.Rows[j].Cells[5].Value.ToString();
                        if (!stringToAttachToStack.Equals(""))
                        {
                            //need to push the string to stack: symbol by symbol from right to left
                            stringToAttachToStackInArrayOfSymbols = stringToArrayOfStrings(stringToAttachToStack);
                            for (int k = stringToAttachToStack.Length - 1; k >= 0; k--)
                            {
                                stack.Push(stringToAttachToStackInArrayOfSymbols[k]);
                            }
                        }//else nothing to push                     

                        break;//have found the rule and applied it, so have to brake the search of the rule
                    }
                    if (j == dataGridView1.RowCount - 1)
                    {
                        richTextBox2Output.AppendText("Правило для текущего состояния, символа цепочки и " +
                        "вершины стека не найдено. Цепочка не принимается\n");
                        return;//надо сделать холостые такты для остатка цепочки даже если цепочка не принята? Сомневаюсь, что надо, 
                        //т.к. это приведёт к неверному выводу. Можно сделать, просто в случае не нахождения правила, нужно тупо опустошить стек, оставив 
                        //цепочку недочитанной.
                    }
                }
                richTextBox2Output.AppendText("Номер используемого правила: " + usedRule + ", новая конфигурация:\n");
                //output in parentheses:
                richTextBox2Output.AppendText("(" + currentState + ", ");// + stringToCheckInStringArray[i] + ", " + stack.Peek() + ")\n");
                for (int m = i + 1; m < stringToCheckInStringArray.Length; m++)
                {
                    richTextBox2Output.AppendText(stringToCheckInStringArray[m]);
                }
                richTextBox2Output.AppendText(", ");
                // richTextBox2Output.AppendText("stack.ToString() = " + stack.);//outputs the name of the class
                stackToPrint = (Stack)stack.Clone();
                PrintStack(stackToPrint);
                richTextBox2Output.AppendText(")\n\n");

                if (i < (stringsLength - 1) && stack.Count == 0)
                {
                    richTextBox2Output.AppendText("Цепочка не прочитана, а стек уже пуст, значит цепочка не принимается");
                }
            }//ЦЕПОЧКА М.Б. ПРОЧИТАНА, ПРИ ЭТОМ В СТЕКЕ ВСЁ ЕЩЁ МОГУТ БЫТЬ СИМВОЛЫ И ДЛЯ ЭТИХ 
             //КОНФИГУРАЦИЙ МОГУТ БЫТЬ ПРАВИЛА
            if (finalStates.Contains(currentState) && stack.Count == 0)
            {
                richTextBox2Output.AppendText("Цепочка прочитана, находимся в конечном состоянии " + currentState +
                    ", стек пуст, значит цепочка принята и является цепочкой КС языка, описываемого данным ДМПА\n");
                return;
            }
            else
            {
                if (stack.Count > 0)
                {
                    richTextBox2Output.AppendText("Цепочка не принята, т.к. стек не пуст\n");
                }
            }
        }

        public void dataGridViewInit()
        {
            dataGridView1.ColumnHeadersVisible = true;
            dataGridView1.RowHeadersVisible = true;

            // readConditionsFromTheInterface();//need to call it twice to initialize LanguageAlphabet and
            //opthers with something
            dataGridView1.ColumnCount = 6;

            dataGridView1.TopLeftHeaderCell.Value = "правило № ";
            int sd = dataGridView1.TopLeftHeaderCell.ColumnIndex;
            dataGridView1.Columns[0].HeaderText = "состояние(q)";
            dataGridView1.Columns[1].HeaderText = "след. символ";
            dataGridView1.Columns[2].HeaderCell.Value = "удаляемая вершина стека";
            dataGridView1.Columns[3].HeaderCell.Value = "такт";
            dataGridView1.Columns[4].HeaderCell.Value = "новое состояние";
            dataGridView1.Columns[5].HeaderCell.Value = "новые символы для записи в стек";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());

            }
            foreach (DataGridViewColumn column in dataGridView1.Columns)
            {
                column.SortMode = DataGridViewColumnSortMode.NotSortable;
            }
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
            dataGridView1.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
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
            stringToCheckInStringArray = stringToArrayOfStringsPlusEmptyStringAtTheEnd(stringToCheck);
            initializationIsInProgress = false;
        }
        public void task20aInit()
        {
            textBox1AlphabetOfTheLanguage.Text = "0 1";
            textBox2AlphabetOfTheStack.Text = "0 1 z";
            textBox3States.Text = "q0 q1 q2";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "q2";
            stringToCheck = textBox7StringToCheck.Text = "0011";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 6;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "0";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q0";
            dataGridView1.Rows[0].Cells[5].Value = "0z";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "0";
            dataGridView1.Rows[1].Cells[2].Value = "0";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q0";
            dataGridView1.Rows[1].Cells[5].Value = "00";

            dataGridView1.Rows[2].Cells[0].Value = "q0";
            dataGridView1.Rows[2].Cells[1].Value = "1";
            dataGridView1.Rows[2].Cells[2].Value = "0";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q1";
            dataGridView1.Rows[2].Cells[5].Value = "";

            dataGridView1.Rows[3].Cells[0].Value = "q1";
            dataGridView1.Rows[3].Cells[1].Value = "1";
            dataGridView1.Rows[3].Cells[2].Value = "0";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q1";
            dataGridView1.Rows[3].Cells[5].Value = "";

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
            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void task20bInit()
        {
            textBox1AlphabetOfTheLanguage.Text = "0 1";
            textBox2AlphabetOfTheStack.Text = "0 1 z";
            textBox3States.Text = "q0 q1 q2";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "q2";
            stringToCheck = textBox7StringToCheck.Text = "011";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 6;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "0";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q0";
            dataGridView1.Rows[0].Cells[5].Value = "0z";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "0";
            dataGridView1.Rows[1].Cells[2].Value = "0";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q0";
            dataGridView1.Rows[1].Cells[5].Value = "00";

            dataGridView1.Rows[2].Cells[0].Value = "q0";
            dataGridView1.Rows[2].Cells[1].Value = "1";
            dataGridView1.Rows[2].Cells[2].Value = "0";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q1";
            dataGridView1.Rows[2].Cells[5].Value = "";

            dataGridView1.Rows[3].Cells[0].Value = "q1";
            dataGridView1.Rows[3].Cells[1].Value = "1";
            dataGridView1.Rows[3].Cells[2].Value = "0";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q1";
            dataGridView1.Rows[3].Cells[5].Value = "";

            dataGridView1.Rows[4].Cells[0].Value = "q1";
            dataGridView1.Rows[4].Cells[1].Value = "1";
            dataGridView1.Rows[4].Cells[2].Value = "z";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q1";
            dataGridView1.Rows[4].Cells[5].Value = "z";

            dataGridView1.Rows[5].Cells[0].Value = "q1";
            dataGridView1.Rows[5].Cells[1].Value = "";
            dataGridView1.Rows[5].Cells[2].Value = "z";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q2";
            dataGridView1.Rows[5].Cells[5].Value = "";
            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void task20vInit()
        {
            textBox1AlphabetOfTheLanguage.Text = "a b";
            textBox2AlphabetOfTheStack.Text = "a b z";
            textBox3States.Text = "q0 q1 q5";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "q5";
            stringToCheck = textBox7StringToCheck.Text = "ababaaabbb";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 9;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q5";
            dataGridView1.Rows[0].Cells[5].Value = "";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "a";
            dataGridView1.Rows[1].Cells[2].Value = "z";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q0";
            dataGridView1.Rows[1].Cells[5].Value = "az";

            dataGridView1.Rows[2].Cells[0].Value = "q0";
            dataGridView1.Rows[2].Cells[1].Value = "a";
            dataGridView1.Rows[2].Cells[2].Value = "a";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q0";
            dataGridView1.Rows[2].Cells[5].Value = "aa";

            dataGridView1.Rows[3].Cells[0].Value = "q0";
            dataGridView1.Rows[3].Cells[1].Value = "b";
            dataGridView1.Rows[3].Cells[2].Value = "a";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q0";
            dataGridView1.Rows[3].Cells[5].Value = "";

            dataGridView1.Rows[4].Cells[0].Value = "q0";
            dataGridView1.Rows[4].Cells[1].Value = "b";
            dataGridView1.Rows[4].Cells[2].Value = "z";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q1";
            dataGridView1.Rows[4].Cells[5].Value = "bz";

            dataGridView1.Rows[5].Cells[0].Value = "q1";
            dataGridView1.Rows[5].Cells[1].Value = "b";
            dataGridView1.Rows[5].Cells[2].Value = "b";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q1";
            dataGridView1.Rows[5].Cells[5].Value = "bb";

            dataGridView1.Rows[6].Cells[0].Value = "q1";
            dataGridView1.Rows[6].Cells[1].Value = "a";
            dataGridView1.Rows[6].Cells[2].Value = "b";
            dataGridView1.Rows[6].Cells[3].Value = "|--";
            dataGridView1.Rows[6].Cells[4].Value = "q1";
            dataGridView1.Rows[6].Cells[5].Value = "";

            dataGridView1.Rows[7].Cells[0].Value = "q1";
            dataGridView1.Rows[7].Cells[1].Value = "";
            dataGridView1.Rows[7].Cells[2].Value = "z";
            dataGridView1.Rows[7].Cells[3].Value = "|--";
            dataGridView1.Rows[7].Cells[4].Value = "q5";
            dataGridView1.Rows[7].Cells[5].Value = "";

            dataGridView1.Rows[8].Cells[0].Value = "q1";
            dataGridView1.Rows[8].Cells[1].Value = "a";
            dataGridView1.Rows[8].Cells[2].Value = "z";
            dataGridView1.Rows[8].Cells[3].Value = "|--";
            dataGridView1.Rows[8].Cells[4].Value = "q0";
            dataGridView1.Rows[8].Cells[5].Value = "az";
            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void task20gInit()
        {
            textBox1AlphabetOfTheLanguage.Text = "0 1";
            textBox2AlphabetOfTheStack.Text = "0 1 z";
            textBox3States.Text = "q0 q1 q5";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "q5";
            stringToCheck = textBox7StringToCheck.Text = "01";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 4;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q5";
            dataGridView1.Rows[0].Cells[5].Value = "";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "0";
            dataGridView1.Rows[1].Cells[2].Value = "z";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q0";
            dataGridView1.Rows[1].Cells[5].Value = "0z";

            dataGridView1.Rows[2].Cells[0].Value = "q0";
            dataGridView1.Rows[2].Cells[1].Value = "1";
            dataGridView1.Rows[2].Cells[2].Value = "0";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q0";
            dataGridView1.Rows[2].Cells[5].Value = "";

            dataGridView1.Rows[3].Cells[0].Value = "q0";
            dataGridView1.Rows[3].Cells[1].Value = "0";
            dataGridView1.Rows[3].Cells[2].Value = "1";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q0";
            dataGridView1.Rows[3].Cells[5].Value = "";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void task22_1_Init()
        {
            textBox1AlphabetOfTheLanguage.Text = "a b c";
            textBox2AlphabetOfTheStack.Text = "a b c z";
            textBox3States.Text = "q0 q1 q2 q3 q5";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "q5";
            stringToCheck = textBox7StringToCheck.Text = "acc";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 8;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "a";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q0";
            dataGridView1.Rows[0].Cells[5].Value = "az";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "a";
            dataGridView1.Rows[1].Cells[2].Value = "a";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q0";
            dataGridView1.Rows[1].Cells[5].Value = "aa";

            dataGridView1.Rows[2].Cells[0].Value = "q0";
            dataGridView1.Rows[2].Cells[1].Value = "b";
            dataGridView1.Rows[2].Cells[2].Value = "a";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q0";
            dataGridView1.Rows[2].Cells[5].Value = "a";

            dataGridView1.Rows[3].Cells[0].Value = "q0";
            dataGridView1.Rows[3].Cells[1].Value = "c";
            dataGridView1.Rows[3].Cells[2].Value = "a";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q1";
            dataGridView1.Rows[3].Cells[5].Value = "a";

            dataGridView1.Rows[4].Cells[0].Value = "q1";
            dataGridView1.Rows[4].Cells[1].Value = "c";
            dataGridView1.Rows[4].Cells[2].Value = "a";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q2";
            dataGridView1.Rows[4].Cells[5].Value = "";

            dataGridView1.Rows[5].Cells[0].Value = "q2";
            dataGridView1.Rows[5].Cells[1].Value = "c";
            dataGridView1.Rows[5].Cells[2].Value = "a";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q3";
            dataGridView1.Rows[5].Cells[5].Value = "a";

            dataGridView1.Rows[6].Cells[0].Value = "q3";
            dataGridView1.Rows[6].Cells[1].Value = "c";
            dataGridView1.Rows[6].Cells[2].Value = "a";
            dataGridView1.Rows[6].Cells[3].Value = "|--";
            dataGridView1.Rows[6].Cells[4].Value = "q2";
            dataGridView1.Rows[6].Cells[5].Value = "";

            dataGridView1.Rows[7].Cells[0].Value = "q2";
            dataGridView1.Rows[7].Cells[1].Value = "";
            dataGridView1.Rows[7].Cells[2].Value = "z";
            dataGridView1.Rows[7].Cells[3].Value = "|--";
            dataGridView1.Rows[7].Cells[4].Value = "q5";
            dataGridView1.Rows[7].Cells[5].Value = "";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void task22_2_Init()
        {
            textBox1AlphabetOfTheLanguage.Text = "a b c";
            textBox2AlphabetOfTheStack.Text = "a b c z";
            textBox3States.Text = "q0 q1 q2 q3 q4 q5 q6 qf";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "qf";
            stringToCheck = textBox7StringToCheck.Text = "aabccc";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 14;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "b";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q0";
            dataGridView1.Rows[0].Cells[5].Value = "bz";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "c";
            dataGridView1.Rows[1].Cells[2].Value = "b";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q6";
            dataGridView1.Rows[1].Cells[5].Value = "";

            dataGridView1.Rows[2].Cells[0].Value = "";
            dataGridView1.Rows[2].Cells[1].Value = "";
            dataGridView1.Rows[2].Cells[2].Value = "";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "";
            dataGridView1.Rows[2].Cells[5].Value = "";

            dataGridView1.Rows[3].Cells[0].Value = "q0";
            dataGridView1.Rows[3].Cells[1].Value = "a";
            dataGridView1.Rows[3].Cells[2].Value = "z";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q1";
            dataGridView1.Rows[3].Cells[5].Value = "az";

            dataGridView1.Rows[4].Cells[0].Value = "q1";
            dataGridView1.Rows[4].Cells[1].Value = "a";
            dataGridView1.Rows[4].Cells[2].Value = "a";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q1";
            dataGridView1.Rows[4].Cells[5].Value = "aa";

            dataGridView1.Rows[5].Cells[0].Value = "q1";
            dataGridView1.Rows[5].Cells[1].Value = "b";
            dataGridView1.Rows[5].Cells[2].Value = "a";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q2";
            dataGridView1.Rows[5].Cells[5].Value = "a";

            dataGridView1.Rows[6].Cells[0].Value = "q2";
            dataGridView1.Rows[6].Cells[1].Value = "c";
            dataGridView1.Rows[6].Cells[2].Value = "a";
            dataGridView1.Rows[6].Cells[3].Value = "|--";
            dataGridView1.Rows[6].Cells[4].Value = "q3";
            dataGridView1.Rows[6].Cells[5].Value = "";

            dataGridView1.Rows[7].Cells[0].Value = "q3";
            dataGridView1.Rows[7].Cells[1].Value = "c";
            dataGridView1.Rows[7].Cells[2].Value = "z";
            dataGridView1.Rows[7].Cells[3].Value = "|--";
            dataGridView1.Rows[7].Cells[4].Value = "q3";
            dataGridView1.Rows[7].Cells[5].Value = "z";

            dataGridView1.Rows[8].Cells[0].Value = "q4";
            dataGridView1.Rows[8].Cells[1].Value = "c";
            dataGridView1.Rows[8].Cells[2].Value = "z";
            dataGridView1.Rows[8].Cells[3].Value = "|--";
            dataGridView1.Rows[8].Cells[4].Value = "q5";
            dataGridView1.Rows[8].Cells[5].Value = "z";

            dataGridView1.Rows[9].Cells[0].Value = "q5";
            dataGridView1.Rows[9].Cells[1].Value = "";
            dataGridView1.Rows[9].Cells[2].Value = "z";
            dataGridView1.Rows[9].Cells[3].Value = "|--";
            dataGridView1.Rows[9].Cells[4].Value = "qf";
            dataGridView1.Rows[9].Cells[5].Value = "";

            dataGridView1.Rows[10].Cells[0].Value = "q3";
            dataGridView1.Rows[10].Cells[1].Value = "c";
            dataGridView1.Rows[10].Cells[2].Value = "a";
            dataGridView1.Rows[10].Cells[3].Value = "|--";
            dataGridView1.Rows[10].Cells[4].Value = "q4";
            dataGridView1.Rows[10].Cells[5].Value = "";

            dataGridView1.Rows[11].Cells[0].Value = "q4";
            dataGridView1.Rows[11].Cells[1].Value = "c";
            dataGridView1.Rows[11].Cells[2].Value = "a";
            dataGridView1.Rows[11].Cells[3].Value = "|--";
            dataGridView1.Rows[11].Cells[4].Value = "q3";
            dataGridView1.Rows[11].Cells[5].Value = "";

            dataGridView1.Rows[12].Cells[0].Value = "q2";
            dataGridView1.Rows[12].Cells[1].Value = "b";
            dataGridView1.Rows[12].Cells[2].Value = "a";
            dataGridView1.Rows[12].Cells[3].Value = "|--";
            dataGridView1.Rows[12].Cells[4].Value = "q2";
            dataGridView1.Rows[12].Cells[5].Value = "a";

            dataGridView1.Rows[13].Cells[0].Value = "q6";
            dataGridView1.Rows[13].Cells[1].Value = "";
            dataGridView1.Rows[13].Cells[2].Value = "z";
            dataGridView1.Rows[13].Cells[3].Value = "|--";
            dataGridView1.Rows[13].Cells[4].Value = "qf";
            dataGridView1.Rows[13].Cells[5].Value = "";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void task711_ProtectionInit()
        {
            textBox1AlphabetOfTheLanguage.Text = "0 1";
            textBox2AlphabetOfTheStack.Text = "0 1 z";
            textBox3States.Text = "A B";
            currentState = initialState = textBox4InitialState.Text = "A";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "B";
            stringToCheck = textBox7StringToCheck.Text = "011";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 5;

            dataGridView1.Rows[0].Cells[0].Value = "A";
            dataGridView1.Rows[0].Cells[1].Value = "0";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "A";
            dataGridView1.Rows[0].Cells[5].Value = "0z";

            dataGridView1.Rows[1].Cells[0].Value = "A";
            dataGridView1.Rows[1].Cells[1].Value = "0";
            dataGridView1.Rows[1].Cells[2].Value = "0";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "A";
            dataGridView1.Rows[1].Cells[5].Value = "";

            dataGridView1.Rows[2].Cells[0].Value = "A";
            dataGridView1.Rows[2].Cells[1].Value = "";
            dataGridView1.Rows[2].Cells[2].Value = "z";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "B";
            dataGridView1.Rows[2].Cells[5].Value = "z";

            dataGridView1.Rows[3].Cells[0].Value = "B";
            dataGridView1.Rows[3].Cells[1].Value = "1";
            dataGridView1.Rows[3].Cells[2].Value = "z";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "B";
            dataGridView1.Rows[3].Cells[5].Value = "z";

            dataGridView1.Rows[4].Cells[0].Value = "B";
            dataGridView1.Rows[4].Cells[1].Value = "";
            dataGridView1.Rows[4].Cells[2].Value = "z";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "B";
            dataGridView1.Rows[4].Cells[5].Value = "";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }
        public void taskKR_2_exampleInit()
        {
            textBox1AlphabetOfTheLanguage.Text = "a b c";
            textBox2AlphabetOfTheStack.Text = "a b c z";
            textBox3States.Text = "q0 q1 q2 q3 q4 q5 q6 q7 q8 q9 q10 q11 q12 q13 qf";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "qf";
            stringToCheck = textBox7StringToCheck.Text = "aaaaacccb";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 19;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "a";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q1";
            dataGridView1.Rows[0].Cells[5].Value = "az";

            dataGridView1.Rows[1].Cells[0].Value = "q1";
            dataGridView1.Rows[1].Cells[1].Value = "c";
            dataGridView1.Rows[1].Cells[2].Value = "a";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q2";
            dataGridView1.Rows[1].Cells[5].Value = "a";

            dataGridView1.Rows[2].Cells[0].Value = "q2";
            dataGridView1.Rows[2].Cells[1].Value = "c";
            dataGridView1.Rows[2].Cells[2].Value = "a";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q3";
            dataGridView1.Rows[2].Cells[5].Value = "a";

            dataGridView1.Rows[3].Cells[0].Value = "q3";
            dataGridView1.Rows[3].Cells[1].Value = "c";
            dataGridView1.Rows[3].Cells[2].Value = "a";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q4";
            dataGridView1.Rows[3].Cells[5].Value = "a";

            dataGridView1.Rows[4].Cells[0].Value = "q4";
            dataGridView1.Rows[4].Cells[1].Value = "c";
            dataGridView1.Rows[4].Cells[2].Value = "a";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q4";
            dataGridView1.Rows[4].Cells[5].Value = "a";

            dataGridView1.Rows[5].Cells[0].Value = "q4";
            dataGridView1.Rows[5].Cells[1].Value = "";
            dataGridView1.Rows[5].Cells[2].Value = "a";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q5";
            dataGridView1.Rows[5].Cells[5].Value = "";

            dataGridView1.Rows[6].Cells[0].Value = "q5";
            dataGridView1.Rows[6].Cells[1].Value = "";
            dataGridView1.Rows[6].Cells[2].Value = "z";
            dataGridView1.Rows[6].Cells[3].Value = "|--";
            dataGridView1.Rows[6].Cells[4].Value = "qf";
            dataGridView1.Rows[6].Cells[5].Value = "";

            dataGridView1.Rows[7].Cells[0].Value = "q1";
            dataGridView1.Rows[7].Cells[1].Value = "a";
            dataGridView1.Rows[7].Cells[2].Value = "a";
            dataGridView1.Rows[7].Cells[3].Value = "|--";
            dataGridView1.Rows[7].Cells[4].Value = "q6";
            dataGridView1.Rows[7].Cells[5].Value = "aa";

            dataGridView1.Rows[8].Cells[0].Value = "q6";
            dataGridView1.Rows[8].Cells[1].Value = "a";
            dataGridView1.Rows[8].Cells[2].Value = "a";
            dataGridView1.Rows[8].Cells[3].Value = "|--";
            dataGridView1.Rows[8].Cells[4].Value = "q7";
            dataGridView1.Rows[8].Cells[5].Value = "aa";

            dataGridView1.Rows[9].Cells[0].Value = "q7";
            dataGridView1.Rows[9].Cells[1].Value = "c";
            dataGridView1.Rows[9].Cells[2].Value = "a";
            dataGridView1.Rows[9].Cells[3].Value = "|--";
            dataGridView1.Rows[9].Cells[4].Value = "q8";
            dataGridView1.Rows[9].Cells[5].Value = "";
            /*
                        dataGridView1.Rows[9].Cells[0].Value = "q7";
                        dataGridView1.Rows[9].Cells[1].Value = "c";
                        dataGridView1.Rows[9].Cells[2].Value = "a";
                        dataGridView1.Rows[9].Cells[3].Value = "|--";
                        dataGridView1.Rows[9].Cells[4].Value = "q7";
                        dataGridView1.Rows[9].Cells[5].Value = "a";*/

            dataGridView1.Rows[10].Cells[0].Value = "q8";
            dataGridView1.Rows[10].Cells[1].Value = "c";
            dataGridView1.Rows[10].Cells[2].Value = "a";
            dataGridView1.Rows[10].Cells[3].Value = "|--";
            dataGridView1.Rows[10].Cells[4].Value = "q9";
            dataGridView1.Rows[10].Cells[5].Value = "";

            dataGridView1.Rows[11].Cells[0].Value = "q9";
            dataGridView1.Rows[11].Cells[1].Value = "c";
            dataGridView1.Rows[11].Cells[2].Value = "a";
            dataGridView1.Rows[11].Cells[3].Value = "|--";
            dataGridView1.Rows[11].Cells[4].Value = "q10";
            dataGridView1.Rows[11].Cells[5].Value = "";

            dataGridView1.Rows[12].Cells[0].Value = "q10";
            dataGridView1.Rows[12].Cells[1].Value = "";
            dataGridView1.Rows[12].Cells[2].Value = "z";
            dataGridView1.Rows[12].Cells[3].Value = "|--";
            dataGridView1.Rows[12].Cells[4].Value = "qf";
            dataGridView1.Rows[12].Cells[5].Value = "";

            dataGridView1.Rows[13].Cells[0].Value = "q7";
            dataGridView1.Rows[13].Cells[1].Value = "a";
            dataGridView1.Rows[13].Cells[2].Value = "a";
            dataGridView1.Rows[13].Cells[3].Value = "|--";
            dataGridView1.Rows[13].Cells[4].Value = "q11";
            dataGridView1.Rows[13].Cells[5].Value = "";

            dataGridView1.Rows[14].Cells[0].Value = "q11";
            dataGridView1.Rows[14].Cells[1].Value = "a";
            dataGridView1.Rows[14].Cells[2].Value = "a";
            dataGridView1.Rows[14].Cells[3].Value = "|--";
            dataGridView1.Rows[14].Cells[4].Value = "q12";
            dataGridView1.Rows[14].Cells[5].Value = "";

            dataGridView1.Rows[15].Cells[0].Value = "q12";
            dataGridView1.Rows[15].Cells[1].Value = "b";
            dataGridView1.Rows[15].Cells[2].Value = "a";
            dataGridView1.Rows[15].Cells[3].Value = "|--";
            dataGridView1.Rows[15].Cells[4].Value = "q13";
            dataGridView1.Rows[15].Cells[5].Value = "";

            dataGridView1.Rows[16].Cells[0].Value = "q13";
            dataGridView1.Rows[16].Cells[1].Value = "";
            dataGridView1.Rows[16].Cells[2].Value = "z";
            dataGridView1.Rows[16].Cells[3].Value = "|--";
            dataGridView1.Rows[16].Cells[4].Value = "qf";
            dataGridView1.Rows[16].Cells[5].Value = "";

            dataGridView1.Rows[17].Cells[0].Value = "q13";
            dataGridView1.Rows[17].Cells[1].Value = "b";
            dataGridView1.Rows[17].Cells[2].Value = "a";
            dataGridView1.Rows[17].Cells[3].Value = "|--";
            dataGridView1.Rows[17].Cells[4].Value = "q13";
            dataGridView1.Rows[17].Cells[5].Value = "";

            dataGridView1.Rows[18].Cells[0].Value = "q12";
            dataGridView1.Rows[18].Cells[1].Value = "c";
            dataGridView1.Rows[18].Cells[2].Value = "a";
            dataGridView1.Rows[18].Cells[3].Value = "|--";
            dataGridView1.Rows[18].Cells[4].Value = "q12";
            dataGridView1.Rows[18].Cells[5].Value = "a";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }

        public void task22_8_Init()
        {
            textBox1AlphabetOfTheLanguage.Text = "a b c";
            textBox2AlphabetOfTheStack.Text = "a b c z";
            textBox3States.Text = "q0 q1 q2 q3 q4 q5 q6 q7 q8 qf";
            currentState = initialState = textBox4InitialState.Text = "q0";
            initialStackInString = textBox5InitialStackContents.Text = "z";
            textBox6FinalStates.Text = "qf";
            stringToCheck = textBox7StringToCheck.Text = "aaabcbcaacc";
            stringTocheckInChars = stringToCheck.ToCharArray();
            readConditionsFromTheInterface();

            dataGridView1.RowCount = 11;

            dataGridView1.Rows[0].Cells[0].Value = "q0";
            dataGridView1.Rows[0].Cells[1].Value = "a";
            dataGridView1.Rows[0].Cells[2].Value = "z";
            dataGridView1.Rows[0].Cells[3].Value = "|--";
            dataGridView1.Rows[0].Cells[4].Value = "q0";
            dataGridView1.Rows[0].Cells[5].Value = "az";

            dataGridView1.Rows[1].Cells[0].Value = "q0";
            dataGridView1.Rows[1].Cells[1].Value = "a";
            dataGridView1.Rows[1].Cells[2].Value = "a";
            dataGridView1.Rows[1].Cells[3].Value = "|--";
            dataGridView1.Rows[1].Cells[4].Value = "q1";
            dataGridView1.Rows[1].Cells[5].Value = "aa";

            dataGridView1.Rows[2].Cells[0].Value = "q1";
            dataGridView1.Rows[2].Cells[1].Value = "a";
            dataGridView1.Rows[2].Cells[2].Value = "a";
            dataGridView1.Rows[2].Cells[3].Value = "|--";
            dataGridView1.Rows[2].Cells[4].Value = "q0";
            dataGridView1.Rows[2].Cells[5].Value = "aa";

            dataGridView1.Rows[3].Cells[0].Value = "q0";
            dataGridView1.Rows[3].Cells[1].Value = "b";
            dataGridView1.Rows[3].Cells[2].Value = "a";
            dataGridView1.Rows[3].Cells[3].Value = "|--";
            dataGridView1.Rows[3].Cells[4].Value = "q2";
            dataGridView1.Rows[3].Cells[5].Value = "ba";

            dataGridView1.Rows[4].Cells[0].Value = "q2";
            dataGridView1.Rows[4].Cells[1].Value = "c";
            dataGridView1.Rows[4].Cells[2].Value = "b";
            dataGridView1.Rows[4].Cells[3].Value = "|--";
            dataGridView1.Rows[4].Cells[4].Value = "q3";
            dataGridView1.Rows[4].Cells[5].Value = "";

            dataGridView1.Rows[5].Cells[0].Value = "q3";
            dataGridView1.Rows[5].Cells[1].Value = "b";
            dataGridView1.Rows[5].Cells[2].Value = "a";
            dataGridView1.Rows[5].Cells[3].Value = "|--";
            dataGridView1.Rows[5].Cells[4].Value = "q2";
            dataGridView1.Rows[5].Cells[5].Value = "ba";

            dataGridView1.Rows[6].Cells[0].Value = "q3";
            dataGridView1.Rows[6].Cells[1].Value = "";
            dataGridView1.Rows[6].Cells[2].Value = "a";
            dataGridView1.Rows[6].Cells[3].Value = "|--";
            dataGridView1.Rows[6].Cells[4].Value = "q4";
            dataGridView1.Rows[6].Cells[5].Value = "";

            dataGridView1.Rows[7].Cells[0].Value = "q4";
            dataGridView1.Rows[7].Cells[1].Value = "";
            dataGridView1.Rows[7].Cells[2].Value = "z";
            dataGridView1.Rows[7].Cells[3].Value = "|--";
            dataGridView1.Rows[7].Cells[4].Value = "qf";
            dataGridView1.Rows[7].Cells[5].Value = "";

            dataGridView1.Rows[8].Cells[0].Value = "q3";
            dataGridView1.Rows[8].Cells[1].Value = "a";
            dataGridView1.Rows[8].Cells[2].Value = "a";
            dataGridView1.Rows[8].Cells[3].Value = "|--";
            dataGridView1.Rows[8].Cells[4].Value = "q3";
            dataGridView1.Rows[8].Cells[5].Value = "";

            dataGridView1.Rows[9].Cells[0].Value = "q3";
            dataGridView1.Rows[9].Cells[1].Value = "c";
            dataGridView1.Rows[9].Cells[2].Value = "a";
            dataGridView1.Rows[9].Cells[3].Value = "|--";
            dataGridView1.Rows[9].Cells[4].Value = "q3";
            dataGridView1.Rows[9].Cells[5].Value = "";

            dataGridView1.Rows[10].Cells[0].Value = "q3";
            dataGridView1.Rows[10].Cells[1].Value = "c";
            dataGridView1.Rows[10].Cells[2].Value = "z";
            dataGridView1.Rows[10].Cells[3].Value = "|--";
            dataGridView1.Rows[10].Cells[4].Value = "q3";
            dataGridView1.Rows[10].Cells[5].Value = "";

            int i = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                dataGridView1.Rows[i].HeaderCell.Value = (i++.ToString());
            }
        }

        public void PrintStack(Stack s)
        {
            // If stack is empty then return 
            if (s.Count == 0)
                return;

            var x = s.Peek();

            // Pop the top element of the stack 
            s.Pop();

            string result = "";

            richTextBox2Output.AppendText(x.ToString());

            // Recursively call the function PrintStack 
            PrintStack(s);

            // Print the stack element starting 
            // from the bottom 


            // Push the same element onto the stack 
            // to preserve the order 
            s.Push(x);
        }

        private void textBox7_TextChangedStringToCheck(object sender, EventArgs e)
        {
            if (!initializationIsInProgress)
            {
                string[] stringInArray = stringToArrayOfStrings(textBox7StringToCheck.Text);
                for (int i = 0; i < stringInArray.Length; i++)
                {
                    if (!LanguageAlphabet.Contains(stringInArray[i]))
                    {
                        richTextBox2Output.AppendText("Введённый символ (" + stringInArray[i] + ") " +
                           "не является частью алфавита языка. Цепочка не принимается.\n");
                        textBox7StringToCheck.Text = stringToCheck;
                        return;
                    }
                }
            }
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
        public string[] stringToArrayOfStringsPlusEmptyStringAtTheEnd(string stringToCheck)
        {//this method doesn't fit because of parsing to chars... no it fits... yet
            char[] stringTocheckInChars = stringToCheck.ToCharArray();
            string[] stringToCheckInStringArray = new string[stringTocheckInChars.Length + 1];
            for (int i = 0; i < stringTocheckInChars.Length; i++)
            {
                stringToCheckInStringArray[i] = stringTocheckInChars[i].ToString();
            }
            stringToCheckInStringArray[stringTocheckInChars.Length] = "";
            return stringToCheckInStringArray;
        }
        private void textBox5_TextChangedStackInitChanged(object sender, EventArgs e)
        {
            if (!initializationIsInProgress)
            {
                string[] stringInArray = stringToArrayOfStrings(textBox5InitialStackContents.Text);
                for (int i = 0; i < stringInArray.Length; i++)
                {
                    if (!StackAlphabet.Contains(stringInArray[i]))
                    {
                        richTextBox2Output.AppendText("\n\nВведённый символ (" + stringInArray[i] + ") " +
                           "не является частью алфавита стека.\n");
                        textBox5InitialStackContents.Text = initialStackInString;
                        return;
                    }
                }
            }
            initialStackInString = textBox5InitialStackContents.Text;


            // string initialStackInString = textBox5InitialStackContents.Text;
            initialStackInString = textBox5InitialStackContents.Text;
            richTextBox1.AppendText("stack was changed. InitialStackInString now is = " + initialStackInString + "\n");
            initialstackInStringArray = stringToArrayOfStrings(initialStackInString);
            stack = new Stack();
            for (int i = initialstackInStringArray.Length - 1; i >= 0; i--)
            {
                stack.Push(initialstackInStringArray[i]);
            }
            richTextBox1.AppendText("stack was changed. it's contents now are: ");
            Stack stackCopy = (Stack)stack.Clone();
            for (int i = 0; i < stack.Count; i++)
            {
                richTextBox1.AppendText(stackCopy.Peek().ToString());
                stackCopy.Pop();
            }
            richTextBox1.AppendText("\n");
        }
        private void textBox5_TextChangedStackInitChanged0(object sender, EventArgs e)
        {
            if (!initializationIsInProgress)
            {
                string[] stringInArray = stringToArrayOfStrings(textBox5InitialStackContents.Text);
                for (int i = 0; i < stringInArray.Length; i++)
                {
                    if (!StackAlphabet.Contains(stringInArray[i]))
                    {
                        richTextBox2Output.AppendText("\n\nВведённый символ (" + stringInArray[i] + ") " +
                           "не является частью алфавита стека.\n");
                        textBox5InitialStackContents.Text = initialStackInString;
                        return;
                    }
                }
            }
            initialStackInString = textBox5InitialStackContents.Text;


            // string initialStackInString = textBox5InitialStackContents.Text;
            initialStackInString = textBox5InitialStackContents.Text;
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
        private void buttonCheckTheChain0(object sender, EventArgs e)
        {
            readConditionsFromTheInterface();
            int usedRule = -1;
            int stringsLength = stringToCheckInStringArray.Length;
            for (int i = 0; i < stringToCheckInStringArray.Length + stack.Count - 1; i++)//-1 добавил от балды
            {
                if (i > (stringsLength - 1))
                {
                    stringToCheckInStringArray = new string[stringToCheckInStringArray.Length + stack.Count];
                    for (int p = 0; p < stringToCheckInStringArray.Length; p++)
                    {
                        stringToCheckInStringArray[p] = "";
                    }
                }
                richTextBox2Output.AppendText("Текущее состояние:          " + currentState + "\n");

                richTextBox2Output.AppendText("Провер-й симв. цепочки:  " + stringToCheckInStringArray[i] + "\n");
                richTextBox2Output.AppendText("Вершина стека:                 " + stack.Peek() + "\n");
                richTextBox2Output.AppendText("Остаток цепочки: ");
                for (int m = i; m < stringToCheckInStringArray.Length; m++)
                {
                    richTextBox2Output.AppendText(stringToCheckInStringArray[m]);
                }
                richTextBox2Output.AppendText("\n");

                if ((stack.Count == 0))//эта проверка уже есть внизу... куда её поставить лучше?
                {
                    richTextBox2Output.AppendText("Стек пуст. Следующий такт невозможен. Цепочка не принята\n");
                    return;
                }


                //output in parentheses:
                richTextBox2Output.AppendText("(" + currentState + ", ");// + stringToCheckInStringArray[i] + ", " + stack.Peek() + ")\n");
                for (int m = i; m < stringToCheckInStringArray.Length; m++)
                {
                    richTextBox2Output.AppendText(stringToCheckInStringArray[m]);
                }
                richTextBox2Output.AppendText(", ");
                // richTextBox2Output.AppendText("stack.ToString() = " + stack.);//outputs the name of the class
                Stack stackToPrint = (Stack)stack.Clone();
                PrintStack(stackToPrint);
                richTextBox2Output.AppendText(")\n");

                // richTextBox2Output.AppendText("Стек: " +   //Do I need to print the whole stack?     YES PRINT THE WHOLE STACK
                //if the curr... now it's time to go through the rules in datagridview1
                for (int j = 0; j < dataGridView1.RowCount; j++)
                {

                    if (currentState.Equals(dataGridView1.Rows[j].Cells[0].Value.ToString()) &&
                        stringToCheckInStringArray[i].Equals(dataGridView1.Rows[j].Cells[1].Value.ToString()) &&
                        stack.Peek().ToString().Equals(dataGridView1.Rows[j].Cells[2].Value.ToString()))
                    {
                        usedRule = j;

                        stack.Pop();
                        currentState = dataGridView1.Rows[j].Cells[4].Value.ToString();

                        stringToAttachToStack = dataGridView1.Rows[j].Cells[5].Value.ToString();
                        if (!stringToAttachToStack.Equals(""))
                        {
                            //need to push the string to stack: symbol by symbol from right to left
                            stringToAttachToStackInArrayOfSymbols = stringToArrayOfStrings(stringToAttachToStack);
                            for (int k = stringToAttachToStack.Length - 1; k >= 0; k--)
                            {
                                // stringToAttachToStackInArrayOfSymbols[k] = 
                                stack.Push(stringToAttachToStackInArrayOfSymbols[k]);
                            }
                        }//else nothing to push                     

                        break;//have found the rule and applied it, so have to brake the search of the rule
                    }
                    if (j == dataGridView1.RowCount - 1)
                    {
                        richTextBox2Output.AppendText("Правило для текущего состояния, символа цепочки и " +
                        "вершины стека не найдено. Цепочка не принимается\n");
                        return;//надо сделать холостые такты для остатка цепочки даже если цепочка не принята?
                        //но как тогда определять, прочитана цепочка или нет? Добавить флаг?
                    }

                }
                richTextBox2Output.AppendText("Номер используемого правила: " + usedRule + ", новая конфигурация:\n");
                //output in parentheses:
                richTextBox2Output.AppendText("(" + currentState + ", ");// + stringToCheckInStringArray[i] + ", " + stack.Peek() + ")\n");
                for (int m = i + 1; m < stringToCheckInStringArray.Length; m++)
                {
                    richTextBox2Output.AppendText(stringToCheckInStringArray[m]);
                }
                richTextBox2Output.AppendText(", ");
                // richTextBox2Output.AppendText("stack.ToString() = " + stack.);//outputs the name of the class
                stackToPrint = (Stack)stack.Clone();
                PrintStack(stackToPrint);
                richTextBox2Output.AppendText(")\n\n");


                if (i < (stringsLength - 1) && stack.Count == 0)
                {
                    richTextBox2Output.AppendText("Цепочка не прочитана, а стек уже пуст, значит цепочка не принимается");
                }

                if (i >= (stringsLength - 1) && finalStates.Contains(currentState) &&
                    stack.Count == 0)
                {
                    richTextBox2Output.AppendText("Цепочка прочитана, находимся в конечном состоянии " + currentState +
                        ", стек пуст, значит цепочка принята и является цепочкой КС языка, описываемого данным ДМПА\n");
                    break;
                }
                else
                {
                    if (//i >= (stringsLength)  &&//это должно гарантироваться правилами. Т.е. даже при пустом символе цепочки 
                        //работа со стеком может идти
                        i >= (stringToCheckInStringArray.Length + stack.Count) &&
                    stack.Count > 0)
                    {
                        richTextBox2Output.AppendText("Цепочка не принята, т.к. стек не пуст\n");
                    }
                    // richTextBox2Output.AppendText("Цепочка не принята\n");
                    //break;
                }
            }//ЦЕПОЧКА М.Б. ПРОЧИТАНА, ПРИ ЭТОМ В СТЕКЕ ВСЁ ЕЩЁ МОГУТ БЫТЬ СИМВОЛЫ И ДЛЯ ЭТИХ 
             //КОНФИГУРАЦИЙ МОГУТ БЫТЬ ПРАВИЛА

        }


        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox2Output.Clear();
        }

        private void textBox6FinalStates_Leave(object sender, EventArgs e)
        {
            finalStates = textBox6FinalStates.Text.Split(' ');
        }

        private void textBox1AlphabetOfTheLanguage_Leave(object sender, EventArgs e)
        {
            LanguageAlphabet = textBox1AlphabetOfTheLanguage.Text.Split(' ');
        }

        private void textBox2AlphabetOfTheStack_Leave(object sender, EventArgs e)
        {
            StackAlphabet = textBox2AlphabetOfTheStack.Text.Split(' ');
        }

        private void textBox3States_Leave(object sender, EventArgs e)
        {
            states = textBox3States.Text.Split(' ');
            string[] statesCopy = (string[])states.Clone();
            if (textBox3States.Text.Split(' ').Intersect(finalStates).Any())
            {

            }
            else
            {
                richTextBox2Output.AppendText("\n Введённые состояния не содержат в себе финальных\n\n");
                textBox6FinalStates.Text = "";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            task20aInit();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            task20bInit();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            task20vInit();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            task20gInit();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            task22_1_Init();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            task22_2_Init();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            task711_ProtectionInit();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            taskKR_2_exampleInit();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            task22_8_Init();
        }
    }

}
/* richTextBox1.AppendText("currentState is: " + currentState + "\n");
                    richTextBox1.AppendText("dataGridView1.Rows[j].Cells[0].Value.ToString() is: " + dataGridView1.Rows[j].Cells[0].Value.ToString() + "\n");
                    richTextBox1.AppendText("stringToCheckInStringArray[i] is: " + stringToCheckInStringArray[i] + "\n");
                    richTextBox1.AppendText("dataGridView1.Rows[j].Cells[1].Value.ToString() is: " + dataGridView1.Rows[j].Cells[1].Value.ToString() + "\n");
                    richTextBox1.AppendText("stack.Peek().ToString() is: " + stack.Peek().ToString() + "\n");
                    richTextBox1.AppendText("dataGridView1.Rows[j].Cells[2].Value.ToString() is: " + dataGridView1.Rows[j].Cells[2].Value.ToString() + "\n");
                    richTextBox1.AppendText("\n");*/


/* richTextBox2Output.AppendText("Новое состояние: " + currentState + "\n");
 richTextBox2Output.AppendText("Символ, удаляемый из стека: " + stack.Peek().ToString() + "\n");
 richTextBox2Output.AppendText("Цепочка добавляемая в стек: " + stringToAttachToStack + "\n\n");*/

/*          richTextBox1.AppendText("states are assigned:\n");
                     states = new string[dataGridView1.RowCount];
                     for (int j = 0; j < states.Length; j++)
                     {
                         states[j] = dataGridView1.Rows[j].Cells[0].Value.ToString();
                         richTextBox1.AppendText("states[" + j + "] = " + states[j]+", ");
                         //the problem is that states are not always unique and that the left parts of the rules not always
                         //contain all the states, so maybe it's better to work directly with datagridview...
                     }*/