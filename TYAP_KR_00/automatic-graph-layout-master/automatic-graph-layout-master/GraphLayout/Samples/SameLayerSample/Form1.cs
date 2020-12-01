
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using Microsoft.Msagl.Drawing;
using Microsoft.Msagl.GraphViewerGdi;
using Microsoft.Msagl.Layout.Layered;

namespace SameLayerSample {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
            formForTheInputs = this;

            //  BuildDFAFirstCase_multiplicityNotEqualToZeroAndTheSymbolIsntInTheFinalSubstring();

            // buildFirstDFA_AndDatagridviewByIt();

            //CreatClusteredLayout();
        }
        public string stringToCheck = "";
        public string finalSubstring = "";
        public string[] finalSubstringInArrayOfStrings;
        public string symbolForMultiplicity = "";
        int multiplicity;
        public string[] alphabet;
        //public int kratnost = 0;
        Form1 formForTheInputs;
        public string[] stringTocheckInArrayOfStrings;
        string initialState = "q0";
        string finalState = "";
        string currentState = "";
        Graph graph;
        IEnumerable<string> alphabetInIEnumerable;
        public bool finalSubstringContainsSymbolForMultiplicity = false;

        GViewer gViewer;
        string alphabetInString = "";

        public string setExceptParameter(string set, string str) {//returns a string, for example: 
            //set.Except(str) or {a, b, c}/b = {a, c} = "a c". I.e. the returned string is "a c".
            string[] aa = new string[1];
            aa[0] = str;
            string[] setInArray = set.Split(' ');
            IEnumerable<string> setWithout_str = setInArray.Except(aa);
            string setWithout_a_InString = "";
            foreach (object v in setWithout_str) {
                setWithout_a_InString += v + " ";
            }
            return setWithout_a_InString;
        }
        public void buildDFA_UnifiedAlgorythm() {
            //Firstly I need to ensure, that the number of symbols for multiplicity is correct. For that I need to count
            //them in the final substring and then build enough states.
            //I also need to count consequent equal symbols in the beginning of the final 
            //substring(for example in bbbcbdr there are 3 such symbols). If there are such symbols, I need to point 
            //transitions to the last of them from states, reading the final substring.
            //
            //
       /*     gViewer = null;
            graph = null;*/
            if(gViewer != null) {
                gViewer.Dispose();
            }

            int numberOfSymbolsForMultiplicityInFinalSubstring = 0;
            int numberOfEqualSymbolsInTheBeginningOfFinalSubstring = 0;
            if (finalSubstring.Length != 0) {
                for (int i = 0; i < finalSubstringInArrayOfStrings.Length; i++) {
                    if (finalSubstringInArrayOfStrings[i].Equals(symbolForMultiplicity)) {
                        numberOfSymbolsForMultiplicityInFinalSubstring++;
                        finalSubstringContainsSymbolForMultiplicity = true;
                    }
                }

                for (int i = 0; i < finalSubstringInArrayOfStrings.Length; i++) {
                    if (finalSubstringInArrayOfStrings[0].Equals(finalSubstringInArrayOfStrings[i]) && i != 0) {
                        numberOfEqualSymbolsInTheBeginningOfFinalSubstring++;
                    }
                    else if (i > 0) {
                        break;
                    }
                    else if (i == 0) {
                        continue;
                    }
                }
            }
            int numberOfSymbolsForMultiplicityToCreateAdditionalStates = 0;
            if (numberOfSymbolsForMultiplicityInFinalSubstring > 0) {
                while (((numberOfSymbolsForMultiplicityInFinalSubstring + numberOfSymbolsForMultiplicityToCreateAdditionalStates) %
   multiplicity) != 0) {
                    numberOfSymbolsForMultiplicityToCreateAdditionalStates++;
                }
            }else {
                numberOfSymbolsForMultiplicityToCreateAdditionalStates = multiplicity;
            }

            gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            graph = new Graph();
            var sugiyamaSettings = (SugiyamaLayoutSettings)graph.LayoutAlgorithmSettings;
            sugiyamaSettings.NodeSeparation *= 2;

            string setWithout_SymbolForMul_InString = setExceptParameter(alphabetInString, symbolForMultiplicity);
            for (int i = 0; i < numberOfSymbolsForMultiplicityToCreateAdditionalStates; i++) {
                graph.AddEdge("q" + i, "q" + i).LabelText = setWithout_SymbolForMul_InString;
                graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = symbolForMultiplicity;

            }


            graph.Attr.OptimizeLabelPositions = true;
            graph.Attr.SimpleStretch = true;
            gViewer.Graph = graph;

            buildDataGridView1ByGraph();
        }
        public void BuildDFAFinalSubstringIsEmpty_case_3() {

            string a = textBox4SymbolForMultiplicity.Text;
            multiplicity = (int)numericUpDown1Multiplicity.Value;
            string alphabetInString = textBox2Alphabet.Text;
            string setWithout_a_InString = setExceptParameter(alphabetInString, a);
            gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            graph = new Graph();
            var sugiyamaSettings = (SugiyamaLayoutSettings)graph.LayoutAlgorithmSettings;
            sugiyamaSettings.NodeSeparation *= 2;

            for (int i = 0; i < multiplicity; i++) {
                graph.AddEdge("q" + i, "q" + i).LabelText = setWithout_a_InString;
                graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = a;
            }
            graph.AddEdge("q" + multiplicity, "q" + multiplicity).LabelText = setWithout_a_InString;
            graph.AddEdge("q" + (multiplicity), "q1").LabelText = a;

            graph.Attr.OptimizeLabelPositions = true;
            graph.Attr.SimpleStretch = true;
            gViewer.Graph = graph;

            buildDataGridView1ByGraph();
        }
        public void BuildDFAFirstCase_multiplicityNotEqualToZeroAndTheSymbolIsNotInTheFinalSubstring() {

            string a = textBox4SymbolForMultiplicity.Text;

            string setWithout_a_InString = setExceptParameter(alphabetInString, a);

            gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            graph = new Graph();
            var sugiyamaSettings = (SugiyamaLayoutSettings)graph.LayoutAlgorithmSettings;
            sugiyamaSettings.NodeSeparation *= 2;


            for (int i = 0; i < multiplicity; i++) {
                graph.AddEdge("q" + i, "q" + i).LabelText = setWithout_a_InString;
                graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = a;
            }
            string[] finalSubStringInArray = stringToArrayOfStrings(finalSubstring);
            for (int i = multiplicity; i < multiplicity + finalSubStringInArray.Length; i++) {
                graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = finalSubStringInArray[i - multiplicity];
                graph.AddEdge("q" + i, "q1").LabelText = a;
            }
            graph.AddEdge("q" + (multiplicity + finalSubStringInArray.Length), "q1").LabelText = a;

            string[] bb = new string[1];
            bb[0] = finalSubstring.Substring(0, 1);

            string setWithout_a_and_b_InString = setExceptParameter(setWithout_a_InString, bb[0]);

            graph.AddEdge("q" + multiplicity, "q" + multiplicity).LabelText = setWithout_a_and_b_InString;

            if (!finalSubstring.Substring(0, 1).Equals(finalSubstring.Substring(1, 1))) {
                graph.AddEdge("q" + (multiplicity + 1), "q" + (multiplicity + 1)).LabelText = bb[0];//it was added for the case when the first symbol of the finalSubstring differs from the second symbol. When the symbols are the same it breaks the algorythm...
            }
            // 
            for (int i = multiplicity + 2; i < finalSubStringInArray.Length + multiplicity + 1; i++) {
                graph.AddEdge("q" + i, "q" + (multiplicity + 1)).LabelText = bb[0];
            }

            if (finalSubstring.Length > 1) {//in general it can be redone by just adding edges with a set of set/LabelText for each next state
                                            //
                /* string f = finalSubstring.Substring(1, 1);
                 string setWithout_a_and_b_and_f_InString = setExceptParameter(setWithout_a_and_b_InString, f);
                 graph.AddEdge("q" + (multiplicity + 1), "q" + (multiplicity)).LabelText = setWithout_a_and_b_and_f_InString; */
            }

            for (int i = 1; i < finalSubstring.Length + 1; i++) {
                if (i != (finalSubstring.Length)) {
                    string f = finalSubstring.Substring(i, 1);
                    string setWithout_a_and_b_and_f_InString = setExceptParameter(setWithout_a_and_b_InString, f);
                    graph.AddEdge("q" + (multiplicity + i), "q" + (multiplicity)).LabelText = setWithout_a_and_b_and_f_InString;
                }
                else {
                    graph.AddEdge("q" + (multiplicity + i), "q" + (multiplicity)).LabelText = setWithout_a_and_b_InString;
                }
            }


            graph.Attr.OptimizeLabelPositions = true;
            graph.Attr.SimpleStretch = true;
            gViewer.Graph = graph;

            buildDataGridView1ByGraph();
        }

        public void buildFirstDFA_AndDatagridviewByIt() {
            initializeTestCase_abcdefg_3a_bfg_();
            readInformationFromTheInterface();
            gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            graph = new Graph();
            var sugiyamaSettings = (SugiyamaLayoutSettings)graph.LayoutAlgorithmSettings;
            sugiyamaSettings.NodeSeparation *= 2;
            graph.AddEdge("q0", "q0").LabelText = "b c d e f g";
            graph.AddEdge("q0", "q1").LabelText = "a";
            graph.AddEdge("q1", "q1").LabelText = "b c d e f g";
            graph.AddEdge("q1", "q2").LabelText = "a";
            graph.AddEdge("q2", "q2").LabelText = "b c d e f g";
            graph.AddEdge("q2", "q3").LabelText = "a";
            graph.AddEdge("q3", "q1").LabelText = "a";
            graph.AddEdge("q3", "q3").LabelText = "c d e f g";
            graph.AddEdge("q3", "q4").LabelText = "b";
            graph.AddEdge("q4", "q4").LabelText = "b";
            graph.AddEdge("q4", "q3").LabelText = "c d e g";
            graph.AddEdge("q4", "q1").LabelText = "a";
            graph.AddEdge("q4", "q5").LabelText = "f";
            graph.AddEdge("q5", "q4").LabelText = "b";
            graph.AddEdge("q5", "q3").LabelText = "c d e f";
            graph.AddEdge("q5", "q1").LabelText = "a";
            graph.AddEdge("q5", "q6").LabelText = "g";
            graph.AddEdge("q6", "q4").LabelText = "b";
            graph.AddEdge("q6", "q1").LabelText = "a";
            graph.AddEdge("q6", "q3").LabelText = "c d e f g";

            graph.Attr.OptimizeLabelPositions = true;
            graph.Attr.SimpleStretch = true;

            gViewer.Graph = graph;
            IEnumerable<Edge> listOfEdges = graph.Edges;




            buildDataGridView1ByGraph();

            for (int i = 0; i < graph.NodeCount; i++) {
                //dataGridView1.Columns[i].HeaderCell.Value = graph.
            }


        }
        public void checkAStringByDataGridview1() {
            richTextBox2.Clear();
            readInformationFromTheInterface();
            stringTocheckInArrayOfStrings = stringToArrayOfStrings(stringToCheck);
            currentState = initialState;
            for (int i = 0; i < stringTocheckInArrayOfStrings.Length; i++) {
                if (alphabet.Contains(stringTocheckInArrayOfStrings[i])) {
                    for (int j = 0; j < dataGridView1.RowCount; j++) {
                        for (int k = 0; k < dataGridView1.ColumnCount; k++) {
                            if (!dataGridView1.Rows[j].Cells[k].AccessibilityObject.Value.ToString().Equals("null")) {
                                string[] symbolsOfCurrentCell = dataGridView1.Rows[j].Cells[k].AccessibilityObject.Value.ToString().Split(' ');
                                for (int m = 0; m < symbolsOfCurrentCell.Length; m++) {
                                    if (currentState.Equals(dataGridView1.Rows[j].HeaderCell.Value) &&
                                stringTocheckInArrayOfStrings[i].Equals(symbolsOfCurrentCell[m])) {
                                        richTextBox2.AppendText(currentState + " -> ");
                                        currentState = dataGridView1.Columns[k].HeaderText;
                                        richTextBox2.AppendText(currentState + " (" + symbolsOfCurrentCell[m] + ") ");
                                        for (int h = i + 1; h < stringTocheckInArrayOfStrings.Length; h++) {
                                            if (!(h == stringTocheckInArrayOfStrings.Length))
                                                richTextBox2.AppendText(stringTocheckInArrayOfStrings[h]);
                                        }
                                        richTextBox2.AppendText("\n");
                                        m = k = j = Int32.MaxValue - 1;
                                        break;
                                    }
                                }
                            }
                            if (j == dataGridView1.RowCount - 1 && k == dataGridView1.ColumnCount - 1) {
                                richTextBox2.AppendText("Правила перехода для текущего символа и состояния не найдено. Цепочка не принимается. \n");
                                k = j = i = Int32.MaxValue - 1;
                                break;
                            }
                        }
                    }
                }
                else {
                    richTextBox2.AppendText("Символа " + stringTocheckInArrayOfStrings[i] + " нет в алфавите, цепочка не принимается. \n");
                    break;
                }

            }
            if (currentState.Equals(finalState)) {
                richTextBox2.AppendText("Находимся в финальном состоянии, цепочка принята\n");
            }
            else {
                richTextBox2.AppendText("Находимся в состоянии, отличном от финального, цепочка не принята\n");
            }
        }
        public void buildDataGridView1ByGraph() {
            dataGridView1.RowCount = dataGridView1.ColumnCount = graph.NodeCount;

            int p = 0;
            Hashtable hash = graph.NodeMap;
            // Edge edge = graph.EdgeById("q0q1");

            List<string> lst = new List<string>();//normally hashtable isn't sorted, so I had to make a list for sorting
            foreach (var key2 in hash.Keys) {
                lst.Add(key2.ToString());
            }
            lst.Sort();
            string lastNode = "";
            foreach (var item in lst) {
                dataGridView1.Columns[p].HeaderCell.Value = dataGridView1.Rows[p++].HeaderCell.Value = item;
                finalState = lastNode = item;
            }
            foreach (var node in graph.Nodes) {//apparently it's easier to build graph by a table, not vice versa... but I'm lazy...
                foreach (Edge edge in node.Edges) {//building a datagridview by graph
                    for (int i = 0; i < dataGridView1.Rows.Count; i++) {
                        for (int j = 0; j < dataGridView1.Columns.Count; j++) {
                            if (edge.Source.Equals(dataGridView1.Rows[i].HeaderCell.Value) &&
                                edge.Target.Equals(dataGridView1.Columns[j].HeaderCell.Value)) {
                                dataGridView1.Rows[i].Cells[j].Value = edge.LabelText;
                            }
                        }
                    }
                }
            }

            foreach (DictionaryEntry de in hash) {
                richTextBox1.AppendText(de.Key + "\n\n" + de.Value + "\n\n\n");
            }
            foreach (var Node in graph.Nodes) {
                Node.Attr.Shape = Microsoft.Msagl.Drawing.Shape.Circle;
                if (Node.Attr.Id.Equals(lastNode)) {
                    Node.Attr.Shape = Microsoft.Msagl.Drawing.Shape.DoubleCircle;
                    //Node.Attr.Color = Microsoft.Msagl.Drawing.Color.Green;
                }
            }
            foreach (var node in graph.Nodes) {
                richTextBox1.AppendText("node.Id.ToString() = " + node.Id.ToString() + "\n");
                foreach (Edge edge in node.Edges) {
                    richTextBox1.AppendText("edge.LabelText = " + edge.LabelText + "\n");
                }
            }
            foreach (var item in hash) {
                richTextBox1.AppendText(" item.GetType() = " + item.GetType() + "\n");
                richTextBox1.AppendText(" item.GetHashCode() = " + item.GetHashCode() + "\n");
                richTextBox1.AppendText(" item.ToString() = " + item.ToString() + "\n\n");
            }
        }

        public void readInformationFromTheInterface() {
            stringToCheck = textBox1StringToCheck.Text;
            finalSubstring = textBox3FinalSubString.Text;
            finalSubstringInArrayOfStrings = stringToArrayOfStrings(finalSubstring);
            symbolForMultiplicity = textBox4SymbolForMultiplicity.Text;
            if (symbolForMultiplicity.Length != 1) {
                MessageBox.Show("Символ для кратности должен быть один");
                textBox4SymbolForMultiplicity.Text = "";
            }
            multiplicity = (int)numericUpDown1Multiplicity.Value;
            if (multiplicity < 1) {
                MessageBox.Show("Кратность не м.б. меньше одного");
                numericUpDown1Multiplicity.Value = 1;
            }
            alphabet = textBox2Alphabet.Text.Split(' ');
            alphabetInString = textBox2Alphabet.Text;
            stringTocheckInArrayOfStrings = stringToArrayOfStrings(stringToCheck);
            initialState = textBoxInitialState.Text;
            finalState = textBoxFinalState.Text;

        }
        public void initializeTestCase_abcdefg_3a_bfg_() {
            textBox1StringToCheck.Text = "bcadacabfg";
            textBox2Alphabet.Text = "a b c d e f g";
            textBox3FinalSubString.Text = "bfg";
            textBox4SymbolForMultiplicity.Text = "a";
            numericUpDown1Multiplicity.Value = 3;

        }
        public void initVLPKBug() {
            textBox1StringToCheck.Text = "ппллввввпп";
            textBox2Alphabet.Text = "в л п к";
            textBox3FinalSubString.Text = "пп";
            textBox4SymbolForMultiplicity.Text = "в";
            numericUpDown1Multiplicity.Value = 4;
        }
        public string[] stringToArrayOfStrings(string stringToCheck) {
            char[] stringTocheckInChars = stringToCheck.ToCharArray();
            string[] stringToCheckInStringArray = new string[stringTocheckInChars.Length];
            for (int i = 0; i < stringTocheckInChars.Length; i++) {
                stringToCheckInStringArray[i] = stringTocheckInChars[i].ToString();
            }
            return stringToCheckInStringArray;
        }
        private void button2_Click(object sender, System.EventArgs e) {
            initializeTestCase_abcdefg_3a_bfg_();
        }

        private void button1_Click(object sender, System.EventArgs e) {
            // formForTheGraph = new Form2ForGraph(formForTheInputs);
            buildFirstDFA_AndDatagridviewByIt();
        }

        private void button3_Click(object sender, System.EventArgs e) {
            checkAStringByDataGridview1();
        }

        private void заданиеToolStripMenuItem_Click(object sender, EventArgs e) {

        }

        private void button4_Click(object sender, EventArgs e) {
            MessageBox.Show("Вариант № 1\n      Написать программу, которая по предложенному описанию языка построит " +
                "детерминированный конечный автомат, распознающий этот язык, " +
"и проверит вводимые с клавиатуры цепочки на их принадлежность языку. " +
"Предусмотреть возможность поэтапного отображения на экране " +
"процесса проверки цепочек. Функция переходов ДКА может изображаться в виде таблицы и " +
"графа(выбор вида отображения посредством меню). Вариант(первый) задания языка:\n\n" +
"       Алфавит, обязательная конечная подцепочка всех цепочек языка " +
"и кратность вхождения выбранного символа алфавита в любую цепочку языка.");
        }

        private void button5_Click(object sender, EventArgs e) {
            MessageBox.Show("Алексеев Степан Владимрович. Группа ИП-712. Ноябрь 2020");
        }

        private void button6_Click(object sender, EventArgs e) {
            System.IO.File.WriteAllText(@"C:\Users\stepa\repos2\TYAP_KR_00\automatic-graph-layout-master\automatic-graph-layout-master\GraphLayout\Samples\SameLayerSample\WriteText.txt", richTextBox2.Text);
        }

        private void button7_Click(object sender, EventArgs e) {
            readInformationFromTheInterface();
            buildDFA_UnifiedAlgorythm();

        }
        private void button7_Click0(object sender, EventArgs e) {// Not correct way, because there is only one algorithm
            readInformationFromTheInterface();
            if (finalSubstring.Contains(multiplicity.ToString())) {
                //the cases when the final substring contains the multiplicity symbol 

            }
            else if (finalSubstring.Length != 0 && multiplicity != 0 && !finalSubstring.Contains(multiplicity.ToString())) {
                //the case when the final substring is not empty, multiplicity != 0, multiplicity symbol is not in the final substring
                BuildDFAFirstCase_multiplicityNotEqualToZeroAndTheSymbolIsNotInTheFinalSubstring();
            }
            else if (finalSubstring.Length == 0) {
                //the case when the final substring is empty
                BuildDFAFinalSubstringIsEmpty_case_3();
            }

        }

        private void button8_Click(object sender, EventArgs e) {
            initVLPKBug();
        }
    }
}


/*//Original contents
 * 
 * using Microsoft.Msagl.Drawing;
using Microsoft.Msagl.GraphViewerGdi;
using Microsoft.Msagl.Layout.Layered;
using System.Windows.Forms;

namespace SameLayerSample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            GViewer gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            Graph graph = new Graph();
            var sugiyamaSettings = (SugiyamaLayoutSettings)graph.LayoutAlgorithmSettings;
            sugiyamaSettings.NodeSeparation *= 2;
            graph.AddEdge("A", "B");
            graph.AddEdge("A", "C");
            graph.AddEdge("A", "D");
            //graph.LayerConstraints.PinNodesToSameLayer(new[] { graph.FindNode("A"), graph.FindNode("B"), graph.FindNode("C") });
            graph.LayerConstraints.PinNodesToSameLayer(new[] { graph.FindNode("A"), graph.FindNode("B"), graph.FindNode("C") });
            graph.LayerConstraints.AddSameLayerNeighbors(graph.FindNode("A"), graph.FindNode("B"), graph.FindNode("C"));
            gViewer.Graph = graph;

        }
    }
}
*/