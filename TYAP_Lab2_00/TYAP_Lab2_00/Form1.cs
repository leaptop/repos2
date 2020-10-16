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

namespace TYAP_Lab2_00
{
    public partial class Form1 : Form
    {
        public ArrayList columnsIE_Alphabet;
        public ArrayList rowsIE_States;
        int rowsNum = 0;
        int columnsNum = 0;
        string[,] matrixOfTransitions;//here I contain all the steps of the automaton
        string ChainToCheck;
        string startingState;
        string[] finalStates;
        int indexOfTheCurrentRow;
        string[] stringsToAvoid = { " ", "  " };//для подчищения пробелов и разделения(Split) строк
        public Form1()
        {
            InitializeComponent();
            columnsIE_Alphabet = new ArrayList();
            rowsIE_States = new ArrayList();
            //YOU HAVE TO INITIALIZE SOME STATE AFTER THIS LINE
            // minimalDataridViewInitialization();
            // initTableAndNames();
            //initStateTask15();

            //checkTheChain();
        }
        private void button4ReadMatrixFromScreenAndFieldsFromScreen(object sender, EventArgs e)
        {
            try
            {
                initTableRowsColumnsHeadersViaParsingTheTextFieldsForColumnsAndRows();
                readFieldsFromTheScreen_NOT_IncludingTheAlphabetStatesAndMatrix();
                readMatrixFromDataGridViewAndCheckIfItsElementsBelongToArrayOfStates();
            }
            catch (Exception)
            {
                MessageBox.Show("Видимо не все поля заполнены");

            }

        }
        public void minimalDataridViewInitialization()
        {
            dataGridView1.RowCount = 1;
            dataGridView1.ColumnCount = 1;
        }
        public void readFieldsFromTheScreen_NOT_IncludingTheAlphabetStatesAndMatrix()
        {
            ChainToCheck = textBox5ChainToCheck.Text;
            startingState = textBox3StartingState.Text;
            finalStates = textBox4FinalStates.Text.Split(stringsToAvoid, 100, StringSplitOptions.RemoveEmptyEntries);
        }
        private void button2ReadATaskAndBuildAll(object sender, EventArgs e)
        {
            initStateOfTask15();
        }

        public void initStateOfTask15()//loading a state of current automaton
        {
            textBox1Alphabet.Text = "0 1";
            textBox2States.Text = "p q r";
            textBox3StartingState.Text = startingState = "p";
            textBox4FinalStates.Text = "r";
            finalStates = new string[] { "r" };
            textBox5ChainToCheck.Text = ChainToCheck = "0101";
            initTableRowsColumnsHeadersViaParsingTheTextFieldsForColumnsAndRows();//здесь эта инициализация идёт ниже... не вся
            matrixOfTransitions = new string[,] {
                { "q", "p" },
                { "r", "p" },
                { "r", "r" }
            };
            for (int i = 0; i < matrixOfTransitions.GetLength(0); i++)//Заполняю таблицу, ограничившись, естсетвенно, сущетсвующей матрицей, чтобы не выйти за границы
            {
                for (int j = 0; j < matrixOfTransitions.GetLength(1); j++)
                {
                    dataGridView1.Rows[i].Cells[j].Value = matrixOfTransitions[i, j];//ЗДЕСЬ ВВОЖУ ТАБЛИЦУ ИЗ matrixOfTransitions[,]
                }
            }
        }
        public void readMatrixFromDataGridViewAndCheckIfItsElementsBelongToArrayOfStates()
        {
            matrixOfTransitions = new string[rowsNum, columnsNum];
            for (int i = 0; i < rowsNum; i++)
            {
                for (int j = 0; j < columnsNum; j++)
                {
                    string str = dataGridView1.Rows[i].Cells[j].ToString();
                    if (checkIfTheStringBelongsToArrayList(rowsIE_States, str))
                        matrixOfTransitions[i, j] = str;
                    else
                    {
                        MessageBox.Show("Символ в матрице по адресу[" + i + ", " + j + "] не принадлежит списку состояний");
                        matrixOfTransitions = null;
                        return;
                    }
                }
            }

        }
        public void readMatrixFromMemory()
        {
            matrixOfTransitions = new string[,] {
                { "q", "p" },
                { "r", "p" },
                { "r", "r" }
            };
            for (int i = 0; i < matrixOfTransitions.GetLength(0); i++)//Заполняю таблицу, ограничившись, естсетвенно, сущетсвующей матрицей, чтобы не выйти за границы
            {
                for (int j = 0; j < matrixOfTransitions.GetLength(1); j++)
                {
                    dataGridView1.Rows[i].Cells[j].Value = matrixOfTransitions[i, j];//ЗДЕСЬ ВВОЖУ ТАБЛИЦУ ИЗ matrixOfTransitions[,]
                }
            }
        }

        private void button2CheckTheChain_Click(object sender, EventArgs e)
        {
            checkTheChain();

        }
        public void checkTheChain()
        {
            indexOfTheCurrentRow = rowsIE_States.IndexOf(startingState);//first receiving of the index of the current state
            string nextCharacter;//the next letter from the chain
            string str;
            int columnIndexOfNextCharacter;
            while (ChainToCheck.Length > 0)
            {
                nextCharacter = ChainToCheck.Substring(0, 1);//считываю 1 символ с 0-ой позиции слева
                if (checkIfSymbolBelongsToAlphabet(nextCharacter))//убеждаюсь, что очередная подстрока цепочки является символом алфавита
                {
                    columnIndexOfNextCharacter = columnsIE_Alphabet.IndexOf(nextCharacter);//получаю индекс nextCharacter в массиве columnsIE_Alphabet
                    str = matrixOfTransitions[indexOfTheCurrentRow, columnIndexOfNextCharacter];//получаю содержимое ячейки матрицы по адресу [indexOfTheCurrentRow, columnIndexOfNextCharacter]
                    indexOfTheCurrentRow = rowsIE_States.IndexOf(str);//получаю индекс в rowsIE_States текущего элемента матрицы

                    //элементы матрицы уже проверены на принадлежность множеству состояний, поэтому здесь проверка 
                    //не требуется.
                    //На этом этапе имею адрес элемента в матрице, обозначающий состояние, в которое нужно перейти. 
                    //Символ алфавита цепочки правильный, символ, обозначающий состояние правильный(принадлежат
                    //заданным множествам). Теперь нужно организовать переход. Следующим индексом строки будет индекс
                    //элемента в rowsIE_States, на который указывают текущие индексы матрицы. А индексом
                    //стобца будет индекс элемента в columnsIE_Alphabet, на который укажет следующий
                    //символ цепочки.

                    //Т.о. на данном этапе программа может прерваться если какой-либо символ проверяемой цепочки не принадлежит 
                    //columnsIE_Alphabet. При этом при правильных символах цепочки цикл while закончится. 
                    //Нужно будет просто убедиться, --что последний элемент матрицы, на который указывали-- ...
                    //++ что элемент rowsIE_States[indexOfTheCurrentRow] принадлежит множеству конечных состояний.

                    //richTextBox1.AppendText("\ncolumnIndexOfNextCharacter = " + columnIndexOfNextCharacter);
                }
                else
                {
                    richTextBox2.AppendText("Строка содержит символ " + nextCharacter +
                        ", не являющийся символом алфавита нашего ДКА, а значит не принимается им");
                    MessageBox.Show("Строка содержит символ " + nextCharacter +
                        ", не являющийся символом алфавита нашего ДКА, а значит не принимается им");
                    return;
                }
                ChainToCheck = ChainToCheck.Substring(1);//удаляю считанный символ
                richTextBox2.AppendText("остаток строки: " + ChainToCheck + ", текущее состояние: " +
                    str+"\n");

                // richTextBox1.AppendText("\nnextCharacter = " + nextCharacter);

            }
            richTextBox2.AppendText("\n---------------------------------------------");
            string strFinishing = rowsIE_States[indexOfTheCurrentRow].ToString();
            if (finalStates.Contains(strFinishing))
            {
                MessageBox.Show("Строка принята");
            }
            else
            {
                MessageBox.Show("Строка прочитана. Конечное состояние " + strFinishing + " не входит в множество конечных состояний. Цепочка не принята");
            }
        }
        public bool checkIfSymbolBelongsToAlphabet(string str)
        {
            if (columnsIE_Alphabet.Contains(str)) return true;
            else return false;
        }
        public void initTableRowsColumnsHeadersViaParsingTheTextFieldsForColumnsAndRows()
        {
            Array tempAlphabet = textBox1Alphabet.Text.Split(stringsToAvoid, 100, StringSplitOptions.RemoveEmptyEntries).ToArray();//временные массивы нужны для удаления повторяющихся символов из массивов алфавита и состояний
            Array tempStates = textBox2States.Text.Split(stringsToAvoid, 100, StringSplitOptions.RemoveEmptyEntries).ToArray();
            columnsIE_Alphabet.Clear();//обнуляю алфавит и состояния на случай изменения размеров матрицы
            rowsIE_States.Clear();
            //if (rowsNum > 0 && columnsNum > 0)//если есть что инициалзировать, то сделаем это, а если нет, то не надо, а то будут обращаения за пределы массивов
            {
                foreach (string aString in tempAlphabet)
                {
                    if (!columnsIE_Alphabet.Contains(aString))
                    {
                        columnsIE_Alphabet.Add(aString);//sorting out twins and adding the elements
                    }
                }
                foreach (string aString in tempStates)
                {
                    if (!rowsIE_States.Contains(aString))
                    {
                        rowsIE_States.Add(aString);//sorting out twins and adding the elements
                    }
                }
                dataGridView1.RowCount = rowsNum = rowsIE_States.Count;//создаю/переделываю datagridview
                dataGridView1.ColumnCount = columnsNum = columnsIE_Alphabet.Count;

                for (int i = 0; i < columnsNum; ++i)
                {
                    dataGridView1.Columns[i].HeaderCell.Value = columnsIE_Alphabet[i].ToString();//называю хедеры колонок(столбцов) именами columnsIE_Alphabet
                }
                for (int j = 0; j < rowsNum; ++j)
                {
                    dataGridView1.Rows[j].HeaderCell.Value = rowsIE_States[j].ToString();//называю хедеры рядов(строк) именами elemsRowsIE_States    
                }
            }
        }
        private void printArraysToRichTextBox1JustServiceInfo()
        {
            try
            {
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\n-------------------------------------\n");
                for (int i = columnsIE_Alphabet.Count-1; i >=0 ; i--)
                {//просто вывожу в ричтекстбокс полученные массивы, чтобы проверить, всё ли сохранилось как надо
                    //richTextBox1.AppendText("columnsIE_Alphabet[" + i + "] = " + columnsIE_Alphabet[i] + "\n");
                  richTextBox1.Text =  richTextBox1.Text.Insert(0, "columnsIE_Alphabet[" + i + "] = " + columnsIE_Alphabet[i] + "\n");
                }
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\n");
                for (int i = rowsIE_States.Count-1; i >=0; i--)
                {
                     richTextBox1.Text = richTextBox1.Text.Insert(0, "elemsRowsIE_States[" + i + "] = " + rowsIE_States[i] + "\n");
                    //richTextBox1.AppendText( "elemsRowsIE_States[" + i + "] = " + rowsIE_States[i] + "\n");
                }
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\n");
                for (int i = finalStates.Length-1; i >=0 ; i--)
                {
                    richTextBox1.Text = richTextBox1.Text.Insert(0, "finalStates[" + i + "] = " + finalStates[i] + "\n");
                }
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\n");
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\nindexOfTheCurrentRow = " + indexOfTheCurrentRow + "\n");
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\n");
               
                for (int i = rowsNum-1; i >=0 ; i--)
                {
                    for (int j = columnsNum-1; j >=0 ; j--)
                    {
                        richTextBox1.Text = richTextBox1.Text.Insert(0, matrixOfTransitions[i, j] + "  ");
                    }
                    richTextBox1.Text = richTextBox1.Text.Insert(0, "\n");
                }
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\nAnd the matrix is:");
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\n");
                richTextBox1.Text = richTextBox1.Text.Insert(0, "\nЦепочка: " + ChainToCheck);
            }
            catch (Exception ee)
            {
                richTextBox1.Text = richTextBox1.Text.Insert(0, "NO DATA IN THE ARRAYS");
                //throw;
            }


            
        }
        private void button1_Click(object sender, EventArgs e)//0 сформировать/перезагрузить таблицу по полям состояний и алфавита
        {
            initTableRowsColumnsHeadersViaParsingTheTextFieldsForColumnsAndRows();// не здесь вызовет исключение, т.к. datagridview м.б. ещё не инициализирована
            readMatrixFromDataGridViewAndCheckIfItsElementsBelongToArrayOfStates();

        }
        private void button1ReadMatrixFromTheMemoryFieldsfromTheScreen(object sender, EventArgs e)
        {
            readMatrixFromMemory();
        }

        private void button2ClearTheRichTextBoxes_Click(object sender, EventArgs e)
        {
            richTextBox2.Clear();
            richTextBox1.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            printArraysToRichTextBox1JustServiceInfo();
        }

        private void dataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {
            // checkIfTheNewCellContentBelongsToStatesList(e.RowIndex, e.ColumnIndex);
            // MessageBox.Show("   e.ToString()");
        }
        public bool checkIfTheStringBelongsToArrayList(ArrayList list, string str)
        {
            if (list.Contains(str))
            {
                //richTextBox1.AppendText("rowsIE_States.Contains(str) = " + rowsIE_States.Contains(str));
                return true;
            }

            else return false;
        }

        private void textBox5ChainToCheck_TextChanged(object sender, EventArgs e)
        {
            ChainToCheck = textBox5ChainToCheck.Text;
        }

        private void textBox4FinalStates_TextChanged(object sender, EventArgs e)
        {
            finalStates = textBox4FinalStates.Text.Split(stringsToAvoid, 100, StringSplitOptions.RemoveEmptyEntries);
        }

        private void textBox3StartingState_TextChanged(object sender, EventArgs e)
        {
            startingState = textBox3StartingState.Text;
        }

        private void textBox1Alphabet_TextChanged(object sender, EventArgs e)
        {//after these changes the dataGridView has to be rebuilt
            columnsIE_Alphabet.Clear();
            string[] str = textBox1Alphabet.Text.Split(stringsToAvoid, 100, StringSplitOptions.RemoveEmptyEntries);
            string[] strDist = str.Distinct().ToArray();//ONE MORE WAY TO DELETE DUPLICATES
            for (int i = 0; i < str.Length; i++)
            {
                columnsIE_Alphabet.Add(strDist[i]);
            }
        }
        private void textBox2States_TextChanged(object sender, EventArgs e)
        {//after these changes the dataGridView has to be rebuilt
            rowsIE_States.Clear();
            string[] str = textBox2States.Text.Split(stringsToAvoid, 100, StringSplitOptions.RemoveEmptyEntries);
            string[] strDist = str.Distinct().ToArray();//ONE MORE WAY TO DELETE DUPLICATES
            for (int i = 0; i < str.Length; i++)
            {
                rowsIE_States.Add(strDist[i]);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {

        }
    }
}
