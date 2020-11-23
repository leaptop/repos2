
using Microsoft.Msagl.Drawing;
using Microsoft.Msagl.GraphViewerGdi;
using Microsoft.Msagl.Layout.Layered;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace SameLayerSample {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
            formForTheInputs = this;

            initializeTestCase_abcdefg_3a_bfg_();

            buildDFA();

            //CreatClusteredLayout();
        }
        public string stringToCheck = "";
        public string finalSubstring = "";
        public string symbolKratnost = "";
        public string[] alphabet;
        public int kratnost = 0;
        Form1 formForTheInputs;
        public string[] stringTocheckInArrayOfStrings;
        string initialState = "q0";
        string finalState = "";
        string currentState = "";

        public void initializeTestCase_abcdefg_3a_bfg_() {
            textBox1StringToCheck.Text = "bcadacabfg";
            textBox2Alphabet.Text = "a b c d e f g";
            textBox3FinalSubString.Text = "bfg";
            textBox4SymbolForKratnost.Text = "a";
            numericUpDown1Kratnost.Value = 3;

        }
        public void buildDFA() {
            readInformationFromTheInterface();
            GViewer gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            Graph graph = new Graph();
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
                foreach (Edge edge in node.Edges) {
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


            for (int i = 0; i < graph.NodeCount; i++) {
                //dataGridView1.Columns[i].HeaderCell.Value = graph.
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
        public void checkAStringByDataGridview1() {
            richTextBox2.Clear();
            stringToCheck = textBox1StringToCheck.Text;
            alphabet = textBox2Alphabet.ToString().Split(' ');
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
                                        richTextBox2.AppendText("Текущее состояние: " + currentState + ", ");
                                        currentState = dataGridView1.Columns[k].HeaderText;
                                        richTextBox2.AppendText("новое состояние: " + currentState + ", перешли по символу: " + symbolsOfCurrentCell[m] +
                                            ", остаток цепочки: ");
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
        public string[] stringToArrayOfStrings(string stringToCheck) {
            char[] stringTocheckInChars = stringToCheck.ToCharArray();
            string[] stringToCheckInStringArray = new string[stringTocheckInChars.Length];
            for (int i = 0; i < stringTocheckInChars.Length; i++) {
                stringToCheckInStringArray[i] = stringTocheckInChars[i].ToString();
            }
            return stringToCheckInStringArray;
        }
        public void readInformationFromTheInterface() {
            stringToCheck = textBox1StringToCheck.Text;
            finalSubstring = textBox3FinalSubString.Text;
            symbolKratnost = textBox4SymbolForKratnost.Text;
            kratnost = (int)numericUpDown1Kratnost.Value;
            alphabet = textBox2Alphabet.Text.Split(' ');
        }

        private void button2_Click(object sender, System.EventArgs e) {
            initializeTestCase_abcdefg_3a_bfg_();
        }

        private void button1_Click(object sender, System.EventArgs e) {
            // formForTheGraph = new Form2ForGraph(formForTheInputs);
            buildDFA();
        }

        private void button3_Click(object sender, System.EventArgs e) {
            checkAStringByDataGridview1();
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