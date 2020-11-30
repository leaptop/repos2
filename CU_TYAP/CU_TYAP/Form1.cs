using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CU_TYAP
{
    public partial class grammar_generator : Form
    {
        public grammar_generator()
        {
            InitializeComponent();
            textBoxMultiplicity.Text = "3";
            radioButton1.Checked = true;//left
            textBoxAlphabet.Text = "a,b,c";
            textBoxParameter.Text = "b";
            textBoxSubstring.Text = "ab";
            radioButton3.Checked = true;
            nonTerminals = new List<NonTerminal>();
            listFinished = new List<Chain>();
            nonTermSequenceMaxLength.Value = 5;
        }


        public List<NonTerminal> grammar_generator_one(List<char> alphabet, string finalSubstring,
            char symbol, int multiplicity, string typeGrammar)
        {
            int n = 0;
            for (int i = 0; i < finalSubstring.Length; i++)
            {
                if (finalSubstring[i] == symbol) n++;
            }
            if (n > multiplicity) n %= multiplicity;
            if (typeGrammar == "left")
            {
                if (finalSubstring.Length != 0)
                {
                    NonTerminal pt;
                    pt = new NonTerminal('S');
                    pt.AddReplacement("B" + finalSubstring);
                    nonTerminals.Add(pt);
                }
                for (int i = 1; i <= multiplicity; i++)
                {
                    NonTerminal pt1;
                    pt1 = new NonTerminal((char)('A' + (char)i));
                    foreach (char c in alphabet)
                    {
                        char nonT;
                        if (c == symbol)
                        {
                            if (i == multiplicity - n + 1)
                            {
                                pt1.AddReplacement("");
                            }
                            nonT = (char)('A' + (char)((i) % multiplicity + 1));
                            pt1.AddReplacement("" + nonT + c);
                            if (i == 1 && n == 0)
                            {
                                pt1.AddReplacement("");
                            }
                            continue;
                        }
                        nonT = (char)('A' + (char)i);
                        pt1.AddReplacement("" + nonT + c);
                    }
                    nonTerminals.Add(pt1);
                }
            }
            if (typeGrammar == "right")
            {
                for (int i = 1; i <= multiplicity; i++)
                {
                    NonTerminal pt1;
                    pt1 = new NonTerminal((char)('A' + (char)i));
                    foreach (char c in alphabet)
                    {
                        char nonT;
                        if (c == symbol)
                        {
                            if (i == multiplicity - n + 1)
                            {
                                pt1.AddReplacement(finalSubstring);

                            }
                            nonT = (char)('A' + (char)((i) % multiplicity + 1));
                            pt1.AddReplacement("" + c + nonT);
                            if (i == 1 && n == 0)
                            {
                                pt1.AddReplacement(finalSubstring);
                            }
                            continue;
                        }
                        nonT = (char)('A' + (char)i);
                        pt1.AddReplacement("" + c + nonT);
                    }
                    nonTerminals.Add(pt1);
                }
            }
            return nonTerminals;

        }

        public void button_process_Click(object sender, EventArgs e)
        {
            if (listBox_nonterminals.Items.Count == 0)
            {
                MessageBox.Show("Постройте правила");
                return;
            }
            listFinished.Clear();
            NonTerminal nt = null;
            nt = nonTerminals.Find(n => n.Symbol == label9.Text[0]);
            Chain ch = new Chain("" + nt.Symbol);
            Language_chains_generator pt = new Language_chains_generator(ch, nonTerminals);
            pt.GenerateChains((int)nonTermSequenceMinLength.Value,
           (int)nonTermSequenceMaxLength.Value, typeGrammar);// was typeGrammar);
            listBox_sequences.Items.Clear();
            foreach (Chain ch1 in pt.resultChain)
            {
                listBox_sequences.Items.Add(ch1.chain);
                listFinished.Add(ch1);
            }
            label11.Text = pt.resultChain.Count.ToString();
        }

        public void buttonSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Текстовый документ (*.txt)|*.txt|Все файлы (*.*) | *.* ";
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                StreamWriter streamWriter = new StreamWriter(saveFileDialog.FileName);
                string sym = "";
                foreach (NonTerminal nt in nonTerminals)
                {
                    sym += nt.Symbol;
                    sym += ",";
                }
                sym = sym.Remove(sym.Length - 1);
                if (radioButton3.Checked == true)
                    streamWriter.WriteLine(label4.Text + " : " + alp + "; " + label5.Text
                   + " : " + finalSubstring + "; " + label6.Text + " : " + symbol + "; " + label7.Text + " : " +
                   multiplicity + "; ");
                if (radioButton4.Checked == true)
                    streamWriter.WriteLine(label4.Text + " : " + alp + "; " + label5.Text + " : " +
                        initialSubstring + "; " + label6.Text + " : " + finalSubstring + ";" + label7.Text + " : " +
                        multiplicity + "; ");
                if (radioButton5.Checked == true)
                    streamWriter.WriteLine(label4.Text + " : " + alp + "; " + label5.Text + " : " +
                        substring + "; " + label6.Text + " : " + multiplicity + "; ");
                streamWriter.WriteLine("G(" + "{" + alp + "}" + "," + "{" + sym + "}" +
               "," + label9.Text + "," + "P)");
                foreach (var item in listBox_nonterminals.Items)
                    streamWriter.WriteLine(item.ToString());
                foreach (var item in listBox_sequences.Items)
                    streamWriter.WriteLine(item.ToString());
                streamWriter.Close();
            }
        }
        string substring;
        int multiplicity;
        string finalSubstring;
        string initialSubstring;
        string alp;
        char symbol;
        public List<NonTerminal> nonTerminals;
        public List<Chain> listFinished;
        string typeGrammar = "left";

        private void grammar_generation_Click(object sender, EventArgs e)       //HERE
        {
            List<char> alphabet = new List<char>();
            nonTerminals = new List<NonTerminal>();
            grammar_generator grammar = new grammar_generator();
            listBox_nonterminals.Items.Clear();
            string reading_alp;
            reading_alp = textBoxAlphabet.Text.ToString();
            if (reading_alp.Length == 0) { MessageBox.Show("введите алфавит"); return; }
            textBoxAlphabet.Clear();
            string pattern = @"[\s\p{P}]";
            string clearalp = Regex.Replace(reading_alp, pattern, string.Empty);
            alp = new string(clearalp.Distinct().ToArray());
            if (alp.Length == 0) { MessageBox.Show("введите алфавит"); return; }
            int amount = 0; string replaceSymbols = "";
            if (clearalp != alp)
            {
                foreach (char c in alp)
                {
                    amount = new Regex("" + c).Matches(clearalp).Count;
                    if (amount > 1) replaceSymbols += " " + c;
                }
                MessageBox.Show("Из алфавита были удалены дубликаты символа(ов):" + replaceSymbols);
            }
            alphabet.AddRange(alp);
            for (int i = 0; i < alphabet.Count - 1; i++)
            { textBoxAlphabet.Text += alphabet[i] + ","; }
            textBoxAlphabet.Text += alphabet[alphabet.Count() - 1];
            alp = textBoxAlphabet.Text;
            if (radioButton3.Checked == true)
            {
                if (textBoxSubstring.TextLength == 0) finalSubstring = " ";
                else
                {
                    finalSubstring = textBoxSubstring.Text.ToString();
                    for (int i = 0; i < finalSubstring.Length; i++)
                    {
                        if (!alphabet.Contains(finalSubstring[i]))
                        {
                            MessageBox.Show("Неверный конец цепочки. Символ " + "'" + finalSubstring[i] + "'" +
                                " не является символом алфавита."); return;
                        }
                    }
                }
                if (textBoxParameter.TextLength == 0)
                {

                    MessageBox.Show("введите символ"); return;
                }
                symbol = textBoxParameter.Text[0];
                if (!alphabet.Contains(symbol))
                {
                    MessageBox.Show("Неверный символ. " + "'" + symbol + "'" + " не является символом алфавита.");
                    return;
                }
                int n = 0; Int32.TryParse(textBoxMultiplicity.Text, out multiplicity);
                if (multiplicity > 10 || multiplicity <= 0)
                {
                    MessageBox.Show("введите кратность в диапазоне от 1 до 10"); return;
                }
                if (radioButton1.Checked == true)
                {
                    if (finalSubstring.Length != 0)
                    {
                        label9.Text = "S";
                    }
                    else label9.Text = "B"; typeGrammar = "left";
                }
                else { typeGrammar = "right"; label9.Text = "B"; }
                nonTerminals = grammar.grammar_generator_one(alphabet, finalSubstring,
                    symbol, multiplicity, typeGrammar);
            }
            if (radioButton4.Checked == true)
            {
                label9.Text = "S";
                if (textBoxSubstring.TextLength == 0) initialSubstring = "";
                else
                {
                    initialSubstring = textBoxSubstring.Text.ToString();
                    for (int i = 0; i < initialSubstring.Length; i++)
                    {
                        if (!alphabet.Contains(initialSubstring[i]))
                        {
                            MessageBox.Show("Неверная начальная подцепочка. Символ " + "'"
                                + initialSubstring[i] + "'" + " не является символом алфавита."); return;
                        }
                    }
                }
                if (textBoxParameter.TextLength == 0) finalSubstring = "";
                else
                {
                    finalSubstring = textBoxParameter.Text.ToString();
                    for (int i = 0; i < finalSubstring.Length; i++)
                    {
                        if (!alphabet.Contains(finalSubstring[i]))
                        {
                            MessageBox.Show("Неверная конечная подцепочка. Символ " + "'" +
                                finalSubstring[i] + "'" + " не является символом алфавита.");
                            return;
                        }
                    }
                }
                Int32.TryParse(textBoxMultiplicity.Text, out multiplicity);
                if (multiplicity > 10 || multiplicity <= 0)
                {
                    MessageBox.Show("введите кратность в диапазоне от 1 до 10"); return;
                }
                if (radioButton1.Checked == true) typeGrammar = "left";
                else typeGrammar = "right";


               // nonTerminals = grammar.grammar_generator_two(alphabet, initialSubstring, finalSubstring, multiplicity, typeGrammar);
            }
            if (radioButton5.Checked == true)
            {
                label9.Text = "A";
                if (textBoxSubstring.TextLength == 0) substring = "";
                else
                {
                    substring = textBoxSubstring.Text.ToString();
                    for (int i = 0; i < substring.Length; i++)
                    {
                        if (!alphabet.Contains(substring[i]))
                        {
                            MessageBox.Show("Неверная фиксированная подцепочка. Символ " +
                                "'" + substring[i] + "'" + " не является символом алфавита."); return;
                        }
                    }
                }
                if (radioButton1.Checked == true) typeGrammar = "left";
                else typeGrammar = "right"; Int32.TryParse(textBoxParameter.Text, out multiplicity);
                if (multiplicity > 10 || multiplicity <= 0)
                {
                    MessageBox.Show("введите кратность в диапазоне от 1 до 10"); return;
                }
                //nonTerminals = grammar.grammar_generator_three(alphabet, substring, multiplicity, typeGrammar);
            }
            foreach (NonTerminal nt in nonTerminals) listBox_nonterminals.Items.Add(nt.ToString());

        }



    }
}
