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

namespace TYAP_Lab1_01
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            dataGridView1.RowCount = rowCount;
            dataGridView1.ColumnCount = 2;
            dataGridView1.Columns[0].HeaderCell.Value = "left part";
            dataGridView1.Columns[1].HeaderCell.Value = "right part";
            nonterminalCombs = new ArrayList();
            terminalCombs = new ArrayList();
            tempNonterminalCombs = new ArrayList();
            tempTerminalCombs = new ArrayList();
            numericUpDownMax.Value = 10;
            numericUpDownMin.Value = 1;
            iterNum = 10;//a number of times to iterate the deriving cycle

            /*  dataGridView1.Rows[0].Cells[0].Value = "A";
              dataGridView1.Rows[0].Cells[1].Value = "aB";
              dataGridView1.Rows[1].Cells[0].Value = "B";
              dataGridView1.Rows[1].Cells[1].Value = "aC";
              dataGridView1.Rows[2].Cells[0].Value = "C";
              dataGridView1.Rows[2].Cells[1].Value = "aD";
              dataGridView1.Rows[3].Cells[0].Value = "C";
              dataGridView1.Rows[3].Cells[1].Value = "0D";
              dataGridView1.Rows[4].Cells[0].Value = "C";
              dataGridView1.Rows[4].Cells[1].Value = "1D";

              dataGridView1.Rows[5].Cells[0].Value = "D";
              dataGridView1.Rows[5].Cells[1].Value = "aE";
              dataGridView1.Rows[6].Cells[0].Value = "D";
              dataGridView1.Rows[6].Cells[1].Value = "0E";
              dataGridView1.Rows[7].Cells[0].Value = "D";
              dataGridView1.Rows[7].Cells[1].Value = "1E";
              dataGridView1.Rows[8].Cells[0].Value = "D";
              dataGridView1.Rows[8].Cells[1].Value = "bE";

              dataGridView1.Rows[9].Cells[0].Value = "E";
              dataGridView1.Rows[9].Cells[1].Value = "aF";
              dataGridView1.Rows[10].Cells[0].Value = "E";
              dataGridView1.Rows[10].Cells[1].Value = "0F";
              dataGridView1.Rows[11].Cells[0].Value = "E";
              dataGridView1.Rows[11].Cells[1].Value = "1F";*/

            /*            numericUpDownMax.Value = 10;
                        textBoxForStartingSymbol.Text = "S";//Чётность как объясняла Бах
                                                            //
                        dataGridView1.Rows[0].Cells[0].Value = "S";
                        dataGridView1.Rows[0].Cells[1].Value = "A";//B instead of A here will derive strings of odd length
                        dataGridView1.Rows[1].Cells[0].Value = "A";
                        dataGridView1.Rows[1].Cells[1].Value = "0B";
                        dataGridView1.Rows[2].Cells[0].Value = "A";
                        dataGridView1.Rows[2].Cells[1].Value = "1B";

                        dataGridView1.Rows[3].Cells[0].Value = "A";
                        dataGridView1.Rows[3].Cells[1].Value = "";
                        dataGridView1.Rows[4].Cells[0].Value = "B";
                        dataGridView1.Rows[4].Cells[1].Value = "0A";
                        dataGridView1.Rows[5].Cells[0].Value = "B";
                        dataGridView1.Rows[5].Cells[1].Value = "1A";*/

            //Контрольная вариант 15 №2// a & b всегда рядом, цепочки вида ссаааbaabbbb не получить, поэтому не правильно сделал
            //КС грамматика строящая L = {c^(2k)w|w belongs to {a,b}*, a number of a's is equal to a number of b's, k>0}
            /*iterNum = 12;
            numericUpDownMax.Value = 14;
            textBoxForStartingSymbol.Text = "F"; dataGridView1.Rows[0].Cells[0].Value = "F";
            dataGridView1.Rows[0].Cells[1].Value = "ccLW";
            dataGridView1.Rows[1].Cells[0].Value = "L";
            dataGridView1.Rows[1].Cells[1].Value = "FF";
            dataGridView1.Rows[2].Cells[0].Value = "L";
            dataGridView1.Rows[2].Cells[1].Value = "";

            dataGridView1.Rows[3].Cells[0].Value = "W";
            dataGridView1.Rows[3].Cells[1].Value = "AB";
            dataGridView1.Rows[4].Cells[0].Value = "A";
            dataGridView1.Rows[4].Cells[1].Value = "ab";
            dataGridView1.Rows[5].Cells[0].Value = "A";
            dataGridView1.Rows[5].Cells[1].Value = "AA";

            dataGridView1.Rows[6].Cells[0].Value = "B";
            dataGridView1.Rows[6].Cells[1].Value = "ba";
            dataGridView1.Rows[7].Cells[0].Value = "B";
            dataGridView1.Rows[7].Cells[1].Value = "BB";

            dataGridView1.Rows[8].Cells[0].Value = "A";
            dataGridView1.Rows[8].Cells[1].Value = "bAa";

            dataGridView1.Rows[9].Cells[0].Value = "B";
            dataGridView1.Rows[9].Cells[1].Value = "aBb";

            dataGridView1.Rows[10].Cells[0].Value = "A";
            dataGridView1.Rows[10].Cells[1].Value = "bBa";

            dataGridView1.Rows[11].Cells[0].Value = "B";
            dataGridView1.Rows[11].Cells[1].Value = "aAb";*/


            /*  iterNum = 8;
              numericUpDownMax.Value = 5;
              textBoxForStartingSymbol.Text = "A";//exercise number 17 к) (all chains of {0, 1, a, b}
              //starting from "aa" and their length is didvided by 3
              dataGridView1.Rows[0].Cells[0].Value = "A";
              dataGridView1.Rows[0].Cells[1].Value = "aB";
              dataGridView1.Rows[1].Cells[0].Value = "B";
              dataGridView1.Rows[1].Cells[1].Value = "aC";
              dataGridView1.Rows[2].Cells[0].Value = "C";
              dataGridView1.Rows[2].Cells[1].Value = "aD";
              dataGridView1.Rows[3].Cells[0].Value = "C";
              dataGridView1.Rows[3].Cells[1].Value = "0D";
              dataGridView1.Rows[4].Cells[0].Value = "C";
              dataGridView1.Rows[4].Cells[1].Value = "1D";

              dataGridView1.Rows[5].Cells[0].Value = "D";
              dataGridView1.Rows[5].Cells[1].Value = "aE";
              dataGridView1.Rows[6].Cells[0].Value = "D";
              dataGridView1.Rows[6].Cells[1].Value = "0E";
              dataGridView1.Rows[7].Cells[0].Value = "D";
              dataGridView1.Rows[7].Cells[1].Value = "1E";
              dataGridView1.Rows[8].Cells[0].Value = "D";
              dataGridView1.Rows[8].Cells[1].Value = "bE";

              dataGridView1.Rows[9].Cells[0].Value = "E";
              dataGridView1.Rows[9].Cells[1].Value = "aF";
              dataGridView1.Rows[10].Cells[0].Value = "E";
              dataGridView1.Rows[10].Cells[1].Value = "0F";
              dataGridView1.Rows[11].Cells[0].Value = "E";
              dataGridView1.Rows[11].Cells[1].Value = "1F";
              dataGridView1.Rows[12].Cells[0].Value = "E";
              dataGridView1.Rows[12].Cells[1].Value = "bF";

              dataGridView1.Rows[13].Cells[0].Value = "F";
              dataGridView1.Rows[13].Cells[1].Value = "aD";
              dataGridView1.Rows[14].Cells[0].Value = "F";
              dataGridView1.Rows[14].Cells[1].Value = "0D";
              dataGridView1.Rows[15].Cells[0].Value = "F";
              dataGridView1.Rows[15].Cells[1].Value = "1D";
              dataGridView1.Rows[16].Cells[0].Value = "F";
              dataGridView1.Rows[16].Cells[1].Value = "bD";

              dataGridView1.Rows[17].Cells[0].Value = "D";
              dataGridView1.Rows[17].Cells[1].Value = "";

              dataGridView1.Rows[18].Cells[0].Value = "C";
              dataGridView1.Rows[18].Cells[1].Value = "bD";



          /*  iterNum = 8;
            numericUpDownMax.Value = 5;
            textBoxForStartingSymbol.Text = "A";//вариант 15 номер 1
                                                //containing "aab" and having even number of characters).       DOESN'T WORK FOR SOME REASON
            dataGridView1.Rows[0].Cells[0].Value = "A";
            dataGridView1.Rows[0].Cells[1].Value = "aB";
            dataGridView1.Rows[1].Cells[0].Value = "A";
            dataGridView1.Rows[1].Cells[1].Value = "aB";
            dataGridView1.Rows[2].Cells[0].Value = "A";
            dataGridView1.Rows[2].Cells[1].Value = "bF";
            dataGridView1.Rows[3].Cells[0].Value = "A";
            dataGridView1.Rows[3].Cells[1].Value = "1F";

            dataGridView1.Rows[4].Cells[0].Value = "B";
            dataGridView1.Rows[4].Cells[1].Value = "aC";
            dataGridView1.Rows[5].Cells[0].Value = "B";
            dataGridView1.Rows[5].Cells[1].Value = "bA";
            dataGridView1.Rows[6].Cells[0].Value = "B";
            dataGridView1.Rows[6].Cells[1].Value = "1A";

            dataGridView1.Rows[7].Cells[0].Value = "C";
            dataGridView1.Rows[7].Cells[1].Value = "1F";
            dataGridView1.Rows[8].Cells[0].Value = "C";
            dataGridView1.Rows[8].Cells[1].Value = "aH";
            dataGridView1.Rows[9].Cells[0].Value = "C";
            dataGridView1.Rows[9].Cells[1].Value = "bD";

            dataGridView1.Rows[10].Cells[0].Value = "D";
            dataGridView1.Rows[10].Cells[1].Value = "1E";
            dataGridView1.Rows[11].Cells[0].Value = "D";
            dataGridView1.Rows[11].Cells[1].Value = "aE";
            dataGridView1.Rows[12].Cells[0].Value = "D";
            dataGridView1.Rows[12].Cells[1].Value = "bE";

            dataGridView1.Rows[13].Cells[0].Value = "E";
            dataGridView1.Rows[13].Cells[1].Value = "";
            dataGridView1.Rows[14].Cells[0].Value = "E";
            dataGridView1.Rows[14].Cells[1].Value = "1D";
            dataGridView1.Rows[15].Cells[0].Value = "E";
            dataGridView1.Rows[15].Cells[1].Value = "aD";
            dataGridView1.Rows[16].Cells[0].Value = "E";
            dataGridView1.Rows[16].Cells[1].Value = "bD";

            dataGridView1.Rows[17].Cells[0].Value = "F";
            dataGridView1.Rows[17].Cells[1].Value = "1A";
            dataGridView1.Rows[18].Cells[0].Value = "F";
            dataGridView1.Rows[18].Cells[1].Value = "bA";
            dataGridView1.Rows[19].Cells[0].Value = "F";
            dataGridView1.Rows[19].Cells[1].Value = "aG";

            dataGridView1.Rows[20].Cells[0].Value = "G";
            dataGridView1.Rows[20].Cells[1].Value = "1F";
            dataGridView1.Rows[21].Cells[0].Value = "G";
            dataGridView1.Rows[21].Cells[1].Value = "bF";
            dataGridView1.Rows[22].Cells[0].Value = "G";
            dataGridView1.Rows[22].Cells[1].Value = "aH";

            dataGridView1.Rows[23].Cells[0].Value = "H";
            dataGridView1.Rows[23].Cells[1].Value = "1A";
            dataGridView1.Rows[24].Cells[0].Value = "H";
            dataGridView1.Rows[24].Cells[1].Value = "bE";
            dataGridView1.Rows[25].Cells[0].Value = "H";
            dataGridView1.Rows[25].Cells[1].Value = "aCdat";*/


            /*iterNum = 6;
            numericUpDownMax.Value = 5;
            textBoxForStartingSymbol.Text = "A";//exercise number 17 ж) (all chains of {0, 1, a, b, c}
                                                //where the number of '0' is even). 
            dataGridView1.Rows[0].Cells[0].Value = "A";
            dataGridView1.Rows[0].Cells[1].Value = "1A";
            dataGridView1.Rows[1].Cells[0].Value = "A";
            dataGridView1.Rows[1].Cells[1].Value = "aA";
            dataGridView1.Rows[2].Cells[0].Value = "A";
            dataGridView1.Rows[2].Cells[1].Value = "bA";
            dataGridView1.Rows[3].Cells[0].Value = "A";
            dataGridView1.Rows[3].Cells[1].Value = "cA";
            dataGridView1.Rows[4].Cells[0].Value = "A";
            dataGridView1.Rows[4].Cells[1].Value = "";
            dataGridView1.Rows[5].Cells[0].Value = "A";
            dataGridView1.Rows[5].Cells[1].Value = "0B";

            dataGridView1.Rows[6].Cells[0].Value = "B";
            dataGridView1.Rows[6].Cells[1].Value = "0A";
            dataGridView1.Rows[7].Cells[0].Value = "B";
            dataGridView1.Rows[7].Cells[1].Value = "1B";
            dataGridView1.Rows[8].Cells[0].Value = "B";
            dataGridView1.Rows[8].Cells[1].Value = "aB";
            dataGridView1.Rows[9].Cells[0].Value = "B";
            dataGridView1.Rows[9].Cells[1].Value = "bB";
            dataGridView1.Rows[10].Cells[0].Value = "B";
            dataGridView1.Rows[10].Cells[1].Value = "cB";*/


            /* iterNum = 8;
             numericUpDownMax.Value = 6;
             textBoxForStartingSymbol.Text = "A";//exercise number 17 k) (all chains of {0, 1, a, b}
             //starting from 'aa' and divided by 3). 
             dataGridView1.Rows[0].Cells[0].Value = "A";
             dataGridView1.Rows[0].Cells[1].Value = "aB";

             dataGridView1.Rows[1].Cells[0].Value = "B";
             dataGridView1.Rows[1].Cells[1].Value = "aC";

             dataGridView1.Rows[2].Cells[0].Value = "C";
             dataGridView1.Rows[2].Cells[1].Value = "aD";
             dataGridView1.Rows[3].Cells[0].Value = "C";
             dataGridView1.Rows[3].Cells[1].Value = "0D";
             dataGridView1.Rows[4].Cells[0].Value = "C";
             dataGridView1.Rows[4].Cells[1].Value = "1D";//
             dataGridView1.Rows[5].Cells[0].Value = "C";
             dataGridView1.Rows[5].Cells[1].Value = "bD";

             dataGridView1.Rows[6].Cells[0].Value = "D";
             dataGridView1.Rows[6].Cells[1].Value = "aE";
             dataGridView1.Rows[7].Cells[0].Value = "D";
             dataGridView1.Rows[7].Cells[1].Value = "0E";
             dataGridView1.Rows[8].Cells[0].Value = "D";
             dataGridView1.Rows[8].Cells[1].Value = "1E";
             dataGridView1.Rows[9].Cells[0].Value = "D";
             dataGridView1.Rows[9].Cells[1].Value = "bE";

             dataGridView1.Rows[10].Cells[0].Value = "E";
             dataGridView1.Rows[10].Cells[1].Value = "aF";
             dataGridView1.Rows[11].Cells[0].Value = "E";
             dataGridView1.Rows[11].Cells[1].Value = "0F";
             dataGridView1.Rows[12].Cells[0].Value = "E";
             dataGridView1.Rows[12].Cells[1].Value = "1F";
             dataGridView1.Rows[13].Cells[0].Value = "E";
             dataGridView1.Rows[13].Cells[1].Value = "bF";

             dataGridView1.Rows[14].Cells[0].Value = "F";
             dataGridView1.Rows[14].Cells[1].Value = "aD";
             dataGridView1.Rows[15].Cells[0].Value = "F";
             dataGridView1.Rows[15].Cells[1].Value = "0D";
             dataGridView1.Rows[16].Cells[0].Value = "F";
             dataGridView1.Rows[16].Cells[1].Value = "1D";
             dataGridView1.Rows[17].Cells[0].Value = "F";
             dataGridView1.Rows[17].Cells[1].Value = "bD";

             dataGridView1.Rows[18].Cells[0].Value = "D";
             dataGridView1.Rows[18].Cells[1].Value = "";*/
            /*            textBoxForStartingSymbol.Text = "s";
                        dataGridView1.Rows[0].Cells[0].Value = "s";
                        dataGridView1.Rows[0].Cells[1].Value = "a";
                        dataGridView1.Rows[1].Cells[0].Value = "n";
                        dataGridView1.Rows[1].Cells[1].Value = "n0";
                        dataGridView1.Rows[2].Cells[0].Value = "a";
                        dataGridView1.Rows[2].Cells[1].Value = "1";
                        dataGridView1.Rows[3].Cells[0].Value = "a";
                        dataGridView1.Rows[3].Cells[1].Value = "n1a1";*/
            /*            dataGridView1.Rows[0].Cells[0].Value = "a";
                        dataGridView1.Rows[0].Cells[1].Value = "b01";
                        dataGridView1.Rows[1].Cells[0].Value = "a";
                        dataGridView1.Rows[1].Cells[1].Value = "0b";
                        dataGridView1.Rows[2].Cells[0].Value = "a";
                        dataGridView1.Rows[2].Cells[1].Value = "";
                        dataGridView1.Rows[3].Cells[0].Value = "b";
                        dataGridView1.Rows[3].Cells[1].Value = "2";
                        dataGridView1.Rows[4].Cells[0].Value = "b";
                        dataGridView1.Rows[4].Cells[1].Value = "3";*/
            /*textBoxForStartingSymbol.Text = "b";
            dataGridView1.Rows[0].Cells[0].Value = "a";
            dataGridView1.Rows[0].Cells[1].Value = "ab01";
            dataGridView1.Rows[1].Cells[0].Value = "a";
            dataGridView1.Rows[1].Cells[1].Value = "0b";
            dataGridView1.Rows[2].Cells[0].Value = "a";
            dataGridView1.Rows[2].Cells[1].Value = "";
            dataGridView1.Rows[3].Cells[0].Value = "b";
            dataGridView1.Rows[3].Cells[1].Value = "2b";
            dataGridView1.Rows[4].Cells[0].Value = "b";
            dataGridView1.Rows[4].Cells[1].Value = "3";*/
        }
        public string[] nonTerminals;
        public int rowCount = 100;
        public string[] rulesIE_rightParts;//правые части правил
        public int minLetters, maxLetters;
        public string startingSymbol;
        int sizeOfRules;
        ArrayList nonterminalCombs;
        char[] nontermsInChars;
        ArrayList terminalCombs;
        ArrayList tempNonterminalCombs;
        ArrayList tempTerminalCombs;
        public int iterNum;
        private void buttonLaunchGenerationAndPrintingOfAllCombinations(object sender, EventArgs e)
        {
            buttonCleanRichTextBox(sender, e);
            initMinMax_StartingSymbol();
            checkKSGrammarAndFillTerminalsNonterminalsArrays();
            correctLaunchOfTheReplacingMethod();

        }//не нужна рекурсия... Тупо строить цепочки можно и автоматическим вызовом функций
        public void correctLaunchOfTheReplacingMethod()
        {//Метод с самым длинным названием можно запустить ещё раз и он заменит во всех строках первый слева 
            //нетерминал на строку из правой части его правила, а также добавит получившиеся строки в 
            //nonterminalCombs и в terminalCombs. В первый запуск гарантированно будет подан нетерминал,
            //и в terminalCombs
            //ничего добавлено не будет. При последующих запусках могут появиться нетерминальные цепочки.
            nonterminalCombs.Add(startingSymbol);
            //Строки минимальной длины будут добавляться по умолчанию. Пока не понятно, как зафиксировать момент,
            //когда все строки максимальной длины будут добавлены. Видимо, когда после очередного цикла
            //все добавленные терминальные строки будут длины большей, чем максимально допустимая пользователем.
            //Что это за очередной цикл? Не понятно. У меня есть известное число правил. Когда все эти правила 
            //пройдутся по строкам, и не появится терминальной строки, короче максимально допустимой, можно 
            //заканчивать. Но сколько это раз? Это число нетерминальных строк в nonterminalCombs умноженное на 
            //число правил? Похоже на то.
            //Начал со стартового символа и вывел результат:
            /*replaceTheLeftmostNontermWithAllItsRulesAndAddToArrayLists(startingSymbol);
            addANonTerminalStringOrACollectionToArrayListWithNoDuplicates(tempNonterminalCombs, nonterminalCombs);       
            addATerminalStringOrACollectionToArrayListWithNoDuplicates(tempTerminalCombs, terminalCombs);
            //terminalCombs.AddRange(tempTerminalCombs);
            tempTerminalCombs.Clear();
            tempNonterminalCombs.Clear();
            printAllCombinationsAndAllTerminalStringsToRichTextBox();*/
            //Конец первого прохода со стартовым символом.

            for (int i = 0; i < iterNum; i++)// от ограничивающего числа зависит число возможной длины строки из скобочек
                                             //Эта длина примерно на 2 меньше числа. На 18 и выше программа заметно загружает процессор. 
            {//Хотя на другом задании нормально вывело 27 символов при 20 установленных здесь...              
                //Можно попробовать склонировать nonterminalCombs и работать с клоном, потом в конце цикла
                //добавить ... Нет. Лучше просто при работе метода добавлять результаты во временные ArrayList-ы.
                foreach (var item in nonterminalCombs)
                {
                    replaceTheLeftmostNontermWithAllItsRulesAndAddToArrayLists(item.ToString());
                }
                nonterminalCombs.Clear();//экспериментальная рационализация
                addANonTerminalStringOrACollectionToArrayListWithNoDuplicates(tempNonterminalCombs, nonterminalCombs);
                addATerminalStringOrACollectionToArrayListWithNoDuplicates(tempTerminalCombs, terminalCombs);
                tempTerminalCombs.Clear();
                tempNonterminalCombs.Clear();

                //экспериментальная рационализация)) :
                /*                if(nonterminalCombs.Count > 3)
                                nonterminalCombs.RemoveRange(0, nonterminalCombs.Count - 4);*/
            }

            printAllCombinationsAndAllTerminalStringsToRichTextBox();
            /*           IEnumerator e = nonterminalCombs.GetEnumerator();
              while (e.MoveNext())
               {
                   cnt++;
                   string s = e.Current.ToString();
                   replaceTheLeftmostNontermWithAllItsRulesAndAddToArrayLists(s);
                   tempNonterminalCombs.Clear();
                   tempTerminalCombs.Clear();
                   if (cnt == 3)
                   {
                       break;
                   }
               }*/
        }
        public void addATerminalStringOrACollectionToArrayListWithNoDuplicates(ArrayList arrFrom, ArrayList arrTo)
        {
            foreach (string aString in arrFrom)
            {
                if (!arrTo.Contains(aString) && aString.Length >= minLetters && aString.Length <= maxLetters)
                {
                    arrTo.Add(aString);
                }
            }
        }
        public void addATerminalStringOrACollectionToArrayListWithNoDuplicates(string strFrom, ArrayList arrTo)
        {
            if (!arrTo.Contains(strFrom) && strFrom.Length >= minLetters && strFrom.Length <= maxLetters)
            {
                arrTo.Add(strFrom);
            }
        }
        public void addANonTerminalStringOrACollectionToArrayListWithNoDuplicates(ArrayList arrFrom, ArrayList arrTo)
        {
            foreach (string aString in arrFrom)
            {
                if (!arrTo.Contains(aString))
                {
                    arrTo.Add(aString);
                }
            }
        }
        public void addANonTerminalStringOrACollectionToArrayListWithNoDuplicates(string strFrom, ArrayList arrTo)
        {
            if (!arrTo.Contains(strFrom))
            {
                arrTo.Add(strFrom);
            }
        }
        public void replaceTheLeftmostNontermWithAllItsRulesAndAddToArrayLists(string str)
        {
            string res = "";
            char[] strInChars = str.ToCharArray();
            int index = getTheLeftMostStringsNonTerminalIndex(str);
            if (index > -1)
            {
                for (int i = 0; i < index; i++)//если index равен нулю, то цикл не сработает ни разу
                {//сначала запишу в результат то, что было до индекса нетерминала
                    res += strInChars[i].ToString();
                }//теперь надо вставить правую часть правила для найденного нетерминала... 
                //таких правых частей м.б. несколько...
                for (int i = 0; i < sizeOfRules; i++)//Т.о. для каждого правила:
                {
                    if (nontermsInChars[i] == strInChars[index])
                    //нахожу в правилах правые части правил для
                    //нетерминала, представленного символом strInChars[index]. Индекс этих нетерминалов: i.
                    //теперь надо по очереди подставить в res все найденные значения вместо нетерминала
                    //при этом каждая из этих получившихся строк может оказаться подходящей для сохранения
                    //попробую просто сохранять эти строки в nonterminalCombs
                    {
                        string tempRes = res;//копируется значение, а не ссылка
                        tempRes += rulesIE_rightParts[i];//прописываю правую часть правила. Теперь 
                        //надо дописать оставшиеся символы строки str:
                        for (int j = index + 1; j < strInChars.Length; j++)
                        //добавляю начиная с index + 1, т.к. index - индекс нетерминала в строке, 
                        //который я заменил
                        {
                            tempRes += strInChars[j].ToString();//дописал оставшиеся симвлы строки str
                            //теперь это всё можно добавить в nonterminalCombs                            
                        }//Хотя, если полученная цепочка терминальная, то её лучше сразу добавить в 
                        //terminalCombs, а в nonterminalCombs добавлять только нетерминальные.
                        //Если к нетерминалу было применено последнее правило и получилась терминальная цепочка,
                        //то, видимо, строку надо удалить из nonterminalCombs... Но, видимо, отсюда это сделать
                        //не получится.
                        if (getTheLeftMostStringsNonTerminalIndex(tempRes) == -1)
                        {
                            //почему-то досюда не доходит...
                            //tempTerminalCombs.Add(tempRes);
                            addATerminalStringOrACollectionToArrayListWithNoDuplicates(tempRes, tempTerminalCombs);
                        }
                        else
                        {
                            //tempNonterminalCombs.Add(tempRes);
                            addANonTerminalStringOrACollectionToArrayListWithNoDuplicates(tempRes, tempNonterminalCombs);
                            //В итоге добавлены все комбинации с заменённым первым слева нетерминалом
                        }
                    }
                }
            }
            else
            {//в цепочке поданной в метод не обнаружено нетерминалов и её можно добавить в terminalCombs:
                //terminalCombs.Add(str);
                addATerminalStringOrACollectionToArrayListWithNoDuplicates(str, tempTerminalCombs);
            }
            //Теперь у меня есть все цепочки с заменённым первым слева нетерминалом в nonterminalCombs
            //Начинал я со стартового нетереминала при вызове applyRulesStartingFromLeftAndReturnTheString(string str)
            //в buttonLaunchGenerationAndPrintingOfAllCombinations();
            //Теперь, кажется, надо продолжить делать то же самое, но уже с содержимым nonterminalCombs.
            //Это содержимое при этом иногда будет содержать терминальные цепочки, а иногда не будет.
            //Надеюсь, что мой метод getTheLeftMostStringsNonTerminalIndex будет помогать находить
            //нетерминальные символы, заменять их, и, т.о. получать в итоге все комбинации цепочек,
            //содержащих только терминальные символы. 
            //Проблема в том, что я не знаю, как остановить эту работу с nonterminalCombs...
            //Может просто после работы со строкой заменять её на произведённую в текущем методе? Видимо, так
            //и надо делать. Осталось понять как это реализовать.
            //Хотя, не факт, что текущую... Может 
        }
        public void printAllCombinationsAndAllTerminalStringsToRichTextBox()
        {
            //  richTextBox1.AppendText("\nОставшиеся нетерминальные комбинации:\n");
            for (int i = 0; i < nonterminalCombs.Count; i++)
            {
                // richTextBox1.AppendText(nonterminalCombs[i].ToString() + "\n");
            }
            richTextBox1.AppendText("\nТерминальные цепочки:\n");
            for (int i = 0; i < terminalCombs.Count; i++)
            {
                richTextBox1.AppendText(terminalCombs[i].ToString() + "\n");
            }
        }
        public void BuildAllStringsCombinationsByLeftRule_WRONGMETHOD(string str)
        {
            nonterminalCombs.Add(startingSymbol);//проблема в том, что я не знаю сколько будет нетерминалов
            //и, соответственно, сколько циклов заложить в программе. Но я знаю сколько у меня правил...
            string st0 = "";
            foreach (var item in nonTerminals)
            {
                if (item == startingSymbol)
                {
                    //richTextBox1.Text = item;
                }
                else continue;
            }

            if (getTheLeftMostStringsNonTerminalIndex(str) == -1)
            {//в строке больше нет нетерминалов
                //return "";
            }//иначе ищем нетерминалы и заменяем их дальше
             // else return (buildAllStringsCombinationsByLeftRule(str));
        }
        public int getTheLeftMostStringsNonTerminalIndex(string str)
        {
            char[] charStr = str.ToCharArray();
            for (int i = 0; i < charStr.Length; i++)
            {//сначала выбираем чар из проверяемой строки
                for (int j = 0; j < sizeOfRules; j++)
                {//потом сравниваем этот чар со всеми нетерминалами
                    if (charStr[i].ToString().CompareTo(nonTerminals[j]) == 0)
                    {//если нашёлся хотя бы один нетерминал равный чару в строке, в строке есть нетерминал
                        //возвращаем его индекс в строке
                        return i;
                    }
                }
            }
            return -1;
        }
        public void initMinMax_StartingSymbol()
        {
            minLetters = Convert.ToInt32(numericUpDownMin.Value);
            maxLetters = Convert.ToInt32(numericUpDownMax.Value);
            if (textBoxForStartingSymbol.Text.Length == 1)
            {
                startingSymbol = textBoxForStartingSymbol.Text.ToString();
            }
            else
            {
                MessageBox.Show("Стартовый символ м.б. только длины 1");
                textBoxForStartingSymbol.Text = "";
            }
        }

        private void buttonCleanRichTextBox(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            nonterminalCombs.Clear();
            terminalCombs.Clear();
        }

        private bool checkKSGrammarAndFillTerminalsNonterminalsArrays()
        {//метод проверяет ячейки первого столбца. Если они не пустые и их длина равна 1, то 
         //добавляем их в массив нетерминалов

            string[] nonTerminalsTemp = new string[rowCount];
            sizeOfRules = 0;
            string[] terminalsTemp = new string[rowCount];
            for (int i = 0; i < rowCount; i++)
            {
                try
                {
                    if (dataGridView1.Rows[i].Cells[0].Value != DBNull.Value &&
                        dataGridView1.Rows[i].Cells[0].Value != null)
                    {
                        nonTerminalsTemp[i] = dataGridView1.Rows[i].Cells[0].Value.ToString();
                        sizeOfRules++;
                        //проверяю терминалы на наличие пустой строки(Укорачивающая КС грамматика)
                        if (dataGridView1.Rows[i].Cells[1].Value == DBNull.Value ||
                        dataGridView1.Rows[i].Cells[1].Value == null)
                        {
                            terminalsTemp[i] = "";
                        }
                        else
                        {
                            terminalsTemp[i] = dataGridView1.Rows[i].Cells[1].Value.ToString();
                        }

                        //если поле не пустое, но таки имеет длину больше 1, это не соответствует 
                        //Контекстно Свободной грамматике, поэтому прерываем выполнение
                        if (dataGridView1.Rows[i].Cells[0].Value.ToString().Length > 1)
                        {
                            dataGridView1.Rows[i].Cells[0].Value = "";
                            throw new Exception();
                        }

                    }
                }
                catch (Exception ee)
                {
                    MessageBox.Show("Значениями ячеек первого столбца м.б. только строки длины 1");
                }
            }
            nonTerminals = new string[sizeOfRules];
            rulesIE_rightParts = new string[sizeOfRules];
            nontermsInChars = new char[sizeOfRules];
            for (int i = 0; i < sizeOfRules; i++)
            {
                nontermsInChars[i] = nonTerminalsTemp[i].ToCharArray()[0];
                nonTerminals[i] = nonTerminalsTemp[i];
                rulesIE_rightParts[i] = terminalsTemp[i];
                // richTextBox1.AppendText("\n" + "nonTerminals[i] = " + nonTerminals[i]);
                // richTextBox1.AppendText(", terminals[i] = " + rulesIE_rightParts[i]);
            }
            return true;
        }
    }
}
