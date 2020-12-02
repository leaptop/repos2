
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
        public bool mulSymbIsTheFirstSymbOfFSSg = false;// multiplicity symbol is the first symbol of the FinalSubstring
        int numEqualInFSSg = 0;//numberOfEqualSymbolsInTheBeginningOfFinalSubstring
        int numSymbInFSSg = 0;//numberOfSymbolsForMultiplicityInFinalSubstring

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
            //пока написано для случая с непустой конечной подстрокой и кратностью больше 1
            //Firstly I need to ensure, that the number of symbols for multiplicity is correct. For that I need to count
            //them in the final substring and then build enough states.
            //I also need to count consequent equal symbols in the beginning of the final 
            //substring(for example in bbbcbdr there are 3 such symbols). If there are such symbols, I need to point 
            //transitions to the last of them from states, reading the final substring.
            //
            //
            numEqualInFSSg = 0;
            numSymbInFSSg = 0;
            if (gViewer != null) {
                gViewer.Dispose();
            }
            gViewer = new GViewer() { Dock = DockStyle.Fill };
            SuspendLayout();
            Controls.Add(gViewer);
            ResumeLayout();
            graph = new Graph();
            var sugiyamaSettings = (SugiyamaLayoutSettings)graph.LayoutAlgorithmSettings;
            sugiyamaSettings.NodeSeparation *= 2;

            for (int i = 0; i < finalSubstringInArrayOfStrings.Length; i++) {
                if (finalSubstringInArrayOfStrings[0].Equals(finalSubstringInArrayOfStrings[i]) && i != 0) {
                    numEqualInFSSg++;//это число повторений. Число одинаковых символов на 1 больше
                }//считаю символы конечной подстроки, начиная слева, одинаковые и смежные с последующими символами подстроки
                else if (i > 0) { break; }
                else if (i == 0) { continue; }
            }
            for (int i = 0; i < finalSubstringInArrayOfStrings.Length; i++) {
                if (finalSubstringInArrayOfStrings[i].Equals(symbolForMultiplicity)) {
                    numSymbInFSSg++;//посчитал символы кратности в конечной подстроке
                    finalSubstringContainsSymbolForMultiplicity = true;
                }
            }

            if (finalSubstring.Length == 0 && multiplicity == 1) {//                            I
                graph.AddEdge("q0", "q0").LabelText = alphabetInString;
                textBoxFinalState.Text = "q0";
                textBoxInitialState.Text = "q0";
            }
            else if (finalSubstring.Length == 0 && multiplicity > 1) {//                        II
                for (int i = 0; i < multiplicity - 1; i++) {
                    graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = symbolForMultiplicity;
                    graph.AddEdge("q" + i, "q" + i).LabelText = setExceptParameter(alphabetInString, symbolForMultiplicity);
                }
                graph.AddEdge("q" + (multiplicity - 1), "q" + 0).LabelText = symbolForMultiplicity;
                graph.AddEdge("q" + (multiplicity - 1), "q" + (multiplicity - 1)).LabelText =
                    setExceptParameter(alphabetInString, symbolForMultiplicity);
                textBoxFinalState.Text = "q0";
                textBoxInitialState.Text = "q0";
            }
            else if (finalSubstring.Length > 0 && multiplicity == 1) {//                        III

                if (numEqualInFSSg == 0) {//                                                    a)   нет повторяющихся символов в начале конечной подстроки
                    if (finalSubstring.Length == 1) {//                                          1)   длина конечной подстроки равна 1
                        graph.AddEdge("q0", "q1").LabelText = finalSubstring;
                        graph.AddEdge("q0", "q0").LabelText = setExceptParameter(alphabetInString, finalSubstring);
                        graph.AddEdge("q1", "q1").LabelText = finalSubstring;
                        graph.AddEdge("q1", "q0").LabelText = setExceptParameter(alphabetInString, finalSubstring);
                        textBoxInitialState.Text = "q0";
                        textBoxFinalState.Text = "q1";
                    }
                    else {//                                                                     2)   длина конечной подстроки больше 1
                        for (int i = 0; i < finalSubstring.Length; i++) {
                            //Добавляю рёбра для всей конечной подстроки:
                            graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = finalSubstringInArrayOfStrings[i];
                        }
                        //Из последнего состояния возвращаемся в нулевое по алфавиту без первого символа конечной подстроки:
                        graph.AddEdge("q" + (finalSubstring.Length), "q0").LabelText =
                            setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]);
                        for (int i = 1; i < finalSubstring.Length; i++) {//по первому символу конечной подстроки все переходят в q1. 
                            //Это не правильно. Возвращаться надо только если сам этот символ не является символом перехода в следующее состояние.
                            if (!finalSubstringInArrayOfStrings[i].Equals(finalSubstringInArrayOfStrings[0]))
                                graph.AddEdge("q" + i, "q1").LabelText = finalSubstringInArrayOfStrings[0];
                        }
                        //то же для последнего состояния:
                        if (!finalSubstringInArrayOfStrings[finalSubstring.Length - 1].Equals(finalSubstringInArrayOfStrings[0]))
                            graph.AddEdge("q" + finalSubstring.Length, "q1").LabelText = finalSubstringInArrayOfStrings[0];
                        //Нулевое состояние замыкается на себя по алфавиту без первого символа конечной подстроки:
                        graph.AddEdge("q0", "q0").LabelText =
                            setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]);
                        //Все состояния кроме нулевого и последнего переходят в нулевое по алфавиту без первого символа конечной подстроки
                        //и без символа, по которому они переходят в следующее состояние:
                        for (int i = 1; i < finalSubstring.Length; i++) {
                            graph.AddEdge("q" + i, "q0").LabelText = setExceptParameter(
                                setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]), finalSubstringInArrayOfStrings[i]);
                        }
                        textBoxInitialState.Text = "q0";
                        textBoxFinalState.Text = "q" + (finalSubstring.Length);
                    }
                }
                else {//                                                                        b)   есть повторяющиеся символы в начале подстроки
                    if ((numEqualInFSSg + 1) == finalSubstring.Length) {//                       1)   вся конечная подстрока состоит из одинаковых символов
                        for (int i = 0; i < finalSubstring.Length; i++) {
                            //Добавляю рёбра для всей конечной подстроки:
                            graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = finalSubstringInArrayOfStrings[i];
                        }
                        //Абсолютно из всех состояний есть ребро в q0 по алфавиту без первого символа конечной подстроки:
                        for (int i = 0; i < finalSubstring.Length + 1; i++) {
                            graph.AddEdge("q" + i, "q0").LabelText =
                                setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]);
                        }
                        //Последнее состояние - финальное и замыкается на себя по первому символу конечной подстроки:
                        graph.AddEdge("q" + finalSubstring.Length, "q" + finalSubstring.Length).LabelText = finalSubstringInArrayOfStrings[0];
                        textBoxInitialState.Text = "q0";
                        textBoxFinalState.Text = "q" + (finalSubstring.Length);

                    }//                                                                         2)   после повторяющихся символов конечной подстроки есть и другой(ие)
                    else {
                        for (int i = 0; i < finalSubstring.Length; i++) {//отсюда доделывать
                            //Добавляю рёбра для всей конечной подстроки:
                            graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = finalSubstringInArrayOfStrings[i];
                        }
                        //Из последнего состояния возвращаемся в нулевое по алфавиту без первого символа конечной подстроки:
                        graph.AddEdge("q" + finalSubstring.Length, "q0").LabelText =
                            setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]);
                        //Из нулевого так же возвращаемся в нулевое по алфавиту без первого символа конечной подстроки:
                        graph.AddEdge("q0", "q0").LabelText =
                            setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]);
                        //Из всех состояний, идущих после состояния, где набрано нужное количество повторяющихся символов конечной подстроки
                        //возвращаемся в состояние q1 по первому символу конечной подстроки:
                        //Это не правильно. Возвращаться нужно толшько если символ перехода в следующее состояние не равен самому первому символу
                        //конечной подстроки(чьё появление возможно и после окончания повторяющихся символов)
                        for (int i = 3; i < finalSubstring.Length; i++) {
                            if (!finalSubstringInArrayOfStrings[i].Equals(finalSubstringInArrayOfStrings[0]))
                                graph.AddEdge("q" + i, "q1").LabelText = finalSubstringInArrayOfStrings[0];
                        }
                        //то же для последнего состояния:
                        if (!finalSubstringInArrayOfStrings[finalSubstring.Length - 1].Equals(finalSubstringInArrayOfStrings[0]))
                            graph.AddEdge("q" + finalSubstring.Length, "q1").LabelText = finalSubstringInArrayOfStrings[0];
                        //Из всех состояний, начиная с индекса 1 и до предпоследнего включительно, возвращаемся в нулевое по алфавиту
                        //без первого символа конечной подстроки и без символа конечной подстроки, по которому происходит
                        //переход из текущего состояния в следующее:
                        for (int i = 1; i < finalSubstring.Length; i++) {
                            graph.AddEdge("q" + i, "q0").LabelText = setExceptParameter(
                                setExceptParameter(alphabetInString, finalSubstringInArrayOfStrings[0]), finalSubstringInArrayOfStrings[i]);
                        }
                        //Закольцовываем на себя последнее состояние, принимающее повторяющийся символ конечной подстроки по нему же:
                        graph.AddEdge("q" + (numEqualInFSSg + 1), "q" + (numEqualInFSSg + 1)).LabelText = finalSubstringInArrayOfStrings[0];
                        textBoxInitialState.Text = "q0";
                        textBoxFinalState.Text = "q" + (finalSubstring.Length);
                    }

                }
            }
            else if (finalSubstring.Length > 0 && multiplicity > 1) {//                               IV
                if (numEqualInFSSg == 0 && numSymbInFSSg == 0) {//                                         a) нет повторяющихся символов в начале конечной подстроки,
                    //                                                                                      а также нет символов кратности в конечной подстроке
                    for (int i = 0; i < multiplicity - 1; i++) {
                        //Строю состояния для символов кратности:
                        graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = symbolForMultiplicity;
                    }
                    //Последнее ребро при подсчёте символов кратности должно вернуться в нулевое состояние:
                    graph.AddEdge("q" + (multiplicity - 1), "q0").LabelText = symbolForMultiplicity;
                    //Строю состояния для считывания конечной подстроки:
                    graph.AddEdge("q0", "q" + multiplicity).LabelText = finalSubstringInArrayOfStrings[0];
                    for (int i = 1; i < finalSubstring.Length; i++) {
                        graph.AddEdge("q" + (multiplicity + i - 1), "q" + (multiplicity + i)).LabelText = finalSubstringInArrayOfStrings[i];
                    }
                    //Первое состояние для приёма конечной подстроки закольцовывается на себя по первому символу конечной подстроки:
                    graph.AddEdge("q" + multiplicity, "q" + multiplicity).LabelText = finalSubstringInArrayOfStrings[0];
                    //Все состояния переходят в первое состояние для приёма конечной подстроки по первому символу конечной
                    //подстроки, только если переход из этих состояний в следующее(для чтения следующего корректного
                    //символа подстроки)не по этому же символу:(это только если длина конечной подстроки больше 1):
                    if (finalSubstring.Length > 1)
                        for (int i = 1; i < finalSubstring.Length; i++) {
                            if (!finalSubstringInArrayOfStrings[0].Equals(finalSubstringInArrayOfStrings[i]))
                                graph.AddEdge("q" + (multiplicity + i), "q" + (multiplicity)).LabelText = finalSubstringInArrayOfStrings[0];
                        }
                    //Из всех состояний, читающих конечную подстроку, есть возврат в q1 по символу кратности:
                    for (int i = 0; i < finalSubstring.Length; i++) {
                        graph.AddEdge("q" + (multiplicity + i), "q1").LabelText = symbolForMultiplicity;
                    }
                    //Все состояния, проверяющие символы кратности, кроме нулевого закольцованы на скбя по алфавиту без символа кратности:
                    for (int i = 1; i < multiplicity; i++) {
                        graph.AddEdge("q" + i, "q" + i).LabelText = setExceptParameter(alphabetInString, symbolForMultiplicity);
                    }
                    //Нулевое и последнее состояния имеют рёбра в нулевое по алфавиту без символа кратности и без
                    //первого символа конечной подстроки:
                    graph.AddEdge("q0", "q0").LabelText = setExceptParameter(
                        setExceptParameter(alphabetInString, symbolForMultiplicity), finalSubstringInArrayOfStrings[0]);
                    graph.AddEdge("q" + (multiplicity + finalSubstring.Length - 1), "q0").LabelText = setExceptParameter(
                        setExceptParameter(alphabetInString, symbolForMultiplicity), finalSubstringInArrayOfStrings[0]);
                    //Из всех состояний, принимающих конечную подцепочку(кроме последнего), есть возврат в q0 по алфавиту без символа кратности,
                    //первого символа конечной подстроки и корректного символа конечной подстроки, по которому состояние переходит
                    //в следующее, считывающее корректный символ:
                    for (int i = 0; i < finalSubstring.Length - 1; i++) {
                        graph.AddEdge("q" + (multiplicity + i), "q0").LabelText = setExceptParameter(setExceptParameter(setExceptParameter(
                            alphabetInString, symbolForMultiplicity), finalSubstringInArrayOfStrings[0]), finalSubstringInArrayOfStrings[i + 1]);
                    }

                }
                else if (numEqualInFSSg > 0 && numSymbInFSSg == 0)//                                 b)  Есть повторяющиеся символы в начале конечной подстроки,
                                                                  //                                     а также нет символов кратности в конечной подстроке
                    {
                    //Строю состояния для подсчёта символов кратности:
                    for (int i = 0; i < multiplicity - 1; i++) {
                        graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = symbolForMultiplicity;
                    }
                    //закольцовываю последнее ребро на нулевое состояние:
                    graph.AddEdge("q" + (multiplicity - 1), "q0").LabelText = symbolForMultiplicity;
                    //Строю состояния для приёма конечной подстроки:
                    graph.AddEdge("q0", "q" + (multiplicity)).LabelText = finalSubstringInArrayOfStrings[0];
                    for (int i = 1; i < finalSubstring.Length; i++) {
                        graph.AddEdge("q" + (multiplicity + i - 1), "q" + (multiplicity + i)).LabelText = finalSubstringInArrayOfStrings[i];
                    }
                    //Состояние, принимающее последний повторяющийся символ конечной подстроки, закольцовывается на себе по этому же символу:
                    graph.AddEdge("q" + (multiplicity + numEqualInFSSg), "q" + (multiplicity + numEqualInFSSg)).LabelText = finalSubstringInArrayOfStrings[0];
                    //Все состояния, принимающие конечную подстроку, должны по первому символу конечной подстроки переходить в состояние, 
                    //принимающее этот символ(с индексом равным multiplicity), если они уже не переходят по нему в состояния, принимающие корректные символы 
                    //конечной подстроки и если это не последнее состояние, принимающее повторяющийся символ в начале конечной 
                    //подстроки(с индексом [numEqualInFSSg]):
                    for (int i = 1; i < finalSubstring.Length; i++) {
                        if (!(finalSubstringInArrayOfStrings[i].Equals(finalSubstringInArrayOfStrings[0])) &&
                            !(finalSubstringInArrayOfStrings[0].Equals(finalSubstringInArrayOfStrings[numEqualInFSSg])))
                            //хотя finalSubstringInArrayOfStrings[numEqualInFSSg] и finalSubstringInArrayOfStrings[0] - это один и тот же символ...
                            //Здесь кривая проверка того, что не находимся в последнем состоянии, зацикленном самим на себя по первому символу 
                            //конечной подстроки
                            graph.AddEdge("q" + (i + multiplicity - 1), "q" + multiplicity).LabelText = finalSubstringInArrayOfStrings[0];
                    }
                    //Из последнего состояния в любом случае будет переход в состояние с индексом multiplicity по первому символу конечной подстроки:
                    graph.AddEdge("q" + (finalSubstring.Length + 1), "q" + multiplicity).LabelText = finalSubstringInArrayOfStrings[0];
                }

            }
            else if (false) {
                //int numSymbInFSSg = 0;//numberOfSymbolsForMultiplicityInFinalSubstring
                // int numEqualInFSSg = 0;//numberOfEqualSymbolsInTheBeginningOfFinalSubstring
                if (finalSubstring.Length != 0) {
                    for (int i = 0; i < finalSubstringInArrayOfStrings.Length; i++) {
                        if (finalSubstringInArrayOfStrings[i].Equals(symbolForMultiplicity)) {
                            numSymbInFSSg++;//посчитал символы кратности в конечной подстроке
                            finalSubstringContainsSymbolForMultiplicity = true;
                        }
                    }

                    for (int i = 0; i < finalSubstringInArrayOfStrings.Length; i++) {
                        if (finalSubstringInArrayOfStrings[0].Equals(finalSubstringInArrayOfStrings[i]) && i != 0) {
                            numEqualInFSSg++;//посчитал символы конечной подстроки, начиная слева, одинаковые и смежные с последующими символами подстроки
                        }
                        else if (i > 0) {
                            break;
                        }
                        else if (i == 0) {
                            continue;
                        }
                    }
                    if (finalSubstringInArrayOfStrings[0].Equals(symbolForMultiplicity)) {
                        mulSymbIsTheFirstSymbOfFSSg = true;//вычислил, является ли символ кратности первым символом конечной подстроки
                    }
                }
                int numOfAdditEdges = 0;//numberOfSymbolsForMultiplicityToCreateAdditionalStates better to say "additional edges"
                if (numSymbInFSSg > 0) {//Если в конечной подстроке есть символы кратности, то нахожу такое число numOfAdditEdges, при котором
                                        //будет выполняться кратность:
                    while (((numSymbInFSSg + numOfAdditEdges) % multiplicity) != 0) {
                        numOfAdditEdges++;
                        //посчитал сколько рёбер для подсчета символа кратности нужно добавить. Если в конечной подстроке
                        //есть такие символы, то нужно добавить число рёбер, равное numOfAdditEdges, такое, что  
                        //((число символов кратности в 
                        //конечной подстроке + число рёбер(инкрементирую его на 1, начиная с нуля)) % кратность) != 0.
                    }
                }
                else {//иначе, если символов кратности нет в конечной подстроке, то числом добавляемых рёбер 
                      //назначаю кратность
                    numOfAdditEdges = multiplicity;
                }
                int indexToStartCheckingFSSg = 0;//если в конечной посдтроке нет символов кратности, то поиск конечной подстроки
                                                 //начинаем с нулевого состояния
                if (numSymbInFSSg > 0) {//Если в конечной подстроке есть символы кратности, то начинать поиск конечной подстроки
                                        //нужно не с нулевого состояния, а с состояния ... С каждым новым символом кратности в конечной подстроке уменьшается число 
                                        //добавляемых в начале состояний... Соответственно, состояние для старта проверки конечной подстроки в случае numSymbInFSSg > 0
                                        //будет всегда в последнем добавленном состоянии для подсчёта символов кратности. (опять же найдено опытным путём).
                    indexToStartCheckingFSSg = numOfAdditEdges;
                }
                int numberToAddEdges = numOfAdditEdges - 1;
                string setWithout_SymbolForMul_InString = setExceptParameter(alphabetInString, symbolForMultiplicity);
                string setWithout_SymbolForMulAndFirstSymbolOfFSSg = setExceptParameter(setWithout_SymbolForMul_InString, finalSubstringInArrayOfStrings[0]);
                for (int i = 0; i < numberToAddEdges; i++) {//Добавляю состояния от нулевого до numOfAdditSts включительно
                                                            //(это индекс последнего состояния). Здесь надо немного не так. numOfAdditSts - это число символов кратности, которые нужно принять 
                                                            //до проверки конечной подстроки. Т.о. это ещё и число рёбер по символу кратности. Последнее из этих рёбер чаще всего 
                                                            //должно возвращаться в нулевое состояние. А в случае, когда первый символ конечной подстроки - это ещё и символ кратности,
                                                            //то, иногда(всегда?) последнее ребро должно переходить сразу к проверке конечной подстроки. А вот возвращаться в нулевое 
                                                            //состояние нужно при получении лишнего символа кратности в конечной подстроке(только если конечная подстрока содержит
                                                            //символы кратности). Если не содержит, то возвращаться по символу кратности надо в состояние с индексом 1.
                                                            //Если кратность равна единице, то состояний создавать не нужно... Точнее, видимо, нужно, но оно по символу кратности д.б.
                                                            //замкнуто на себя. И из него же начинается проверка конечной подстроки.
                    if (i != indexToStartCheckingFSSg)//каждый раз проверяю, не работаю ли с состоянием, из которого надо начинать считывать
                                                      //конечную подстроку
                                                      //добавляю закольцовывание на себе состояний по ходу подсчета символов кратности:
                        graph.AddEdge("q" + i, "q" + i).LabelText = setWithout_SymbolForMul_InString;
                    //если текущее состояние является стартовым для проверки последней подцепочки, то, соотвтетственно убираем из 
                    //его закольцовывания на себя первый символ конечной подстроки:
                    else graph.AddEdge("q" + i, "q" + i).LabelText = setWithout_SymbolForMulAndFirstSymbolOfFSSg;
                    //добавляю следующие состояния для перехода по символу кратности:
                    graph.AddEdge("q" + i, "q" + (i + 1)).LabelText = symbolForMultiplicity;
                }
                if ((numberToAddEdges) != indexToStartCheckingFSSg)
                    //добавляю закольцовывание на себе последнего состояния при подсчете символов кратности:
                    graph.AddEdge("q" + (numberToAddEdges), "q" + (numberToAddEdges)).LabelText = setWithout_SymbolForMul_InString;
                else
                    //если текущее состояние является стартовым для проверки последней подцепочки, то, соотвтетственно,
                    //убираем из его закольцовывания на себя первый символ конечной подстроки
                    graph.AddEdge("q" + (numberToAddEdges), "q" + (numberToAddEdges)).LabelText = setWithout_SymbolForMulAndFirstSymbolOfFSSg;
                //Если превый символ конечной подстроки не является символом кратности, то
                //добавляю возврат по последнему символу кратности в нулевое состояние:
                //Здесь, вероятно, косяк, т.к. если numOfAdditSts будет равно нулю, то следующее ребро замкнётся на себе по символу кратности...
                //Поэтому добавил тупо проверку numberToAddEdges != 0
                if (!mulSymbIsTheFirstSymbOfFSSg && numberToAddEdges != 0) graph.AddEdge("q" + (numberToAddEdges), "q" + 0).LabelText = symbolForMultiplicity;
                // else 
                //Previously the counting was below. But now it's upper.
                //now I need to understand where to attach the finalSubstring checking states. It depends on the number of
                //symbols for multiplicity in finalSubstring. If there are zero symbols, then it's the zeroe's(нулевое) state.

                if (finalSubstring.Length != 0) {
                    graph.AddEdge("q" + indexToStartCheckingFSSg, "q" + (numOfAdditEdges)).LabelText = finalSubstringInArrayOfStrings[0];
                    for (int i = 1; i < finalSubstring.Length; i++) {
                        graph.AddEdge("q" + (numOfAdditEdges + i - 1), "q" + (numOfAdditEdges + i)).LabelText = finalSubstringInArrayOfStrings[i];
                    }
                }//для кратности равной 1 надо делать как-нибудь отдельно, т.к., например, setWithout_SymbolForMul_InString будет уже обманчивым
                 //названием, т.к. в нём в этом случае должен присутствовать символ кратности. Кстати пустую строку автомат должен принимать при 
                 //пустой конечной подстроке... Т.е., видимо, нужно создать нулевое стартовое состояние, которое будет и финальным. Это отдельно
                 //для случая с пустой подстрокой.

                //                      ДО ЭТОГО МОМЕНТА БАЗА ВРОДЕ БЫ ПОСТРОЕНА. ТЕПЕРЬ НУЖНО ОБЕСПЕЧИТЬ ВОЗВРАТЫ
                //Нет. Если кратность равна 1, то строит не то.
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
            richTextBox2CheckResults.Clear();
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
                                        richTextBox2CheckResults.AppendText(currentState + " -> ");
                                        currentState = dataGridView1.Columns[k].HeaderText;
                                        richTextBox2CheckResults.AppendText(currentState + " (" + symbolsOfCurrentCell[m] + ") ");
                                        for (int h = i + 1; h < stringTocheckInArrayOfStrings.Length; h++) {
                                            if (!(h == stringTocheckInArrayOfStrings.Length))
                                                richTextBox2CheckResults.AppendText(stringTocheckInArrayOfStrings[h]);
                                        }
                                        richTextBox2CheckResults.AppendText("\n");
                                        m = k = j = Int32.MaxValue - 1;
                                        break;
                                    }
                                }
                            }
                            if (j == dataGridView1.RowCount - 1 && k == dataGridView1.ColumnCount - 1) {
                                richTextBox2CheckResults.AppendText("Правила перехода для текущего символа и состояния не найдено. Цепочка не принимается. \n");
                                k = j = i = Int32.MaxValue - 1;
                                break;
                            }
                        }
                    }
                }
                else {
                    richTextBox2CheckResults.AppendText("Символа " + stringTocheckInArrayOfStrings[i] + " нет в алфавите, цепочка не принимается. \n");
                    break;
                }

            }
            if (currentState.Equals(finalState)) {
                richTextBox2CheckResults.AppendText("Находимся в финальном состоянии, цепочка принята\n");
            }
            else {
                richTextBox2CheckResults.AppendText("Находимся в состоянии, отличном от финального, цепочка не принята\n");
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
                richTextBox1Helper.AppendText(de.Key + "\n\n" + de.Value + "\n\n\n");
            }
            foreach (var Node in graph.Nodes) {
                Node.Attr.Shape = Microsoft.Msagl.Drawing.Shape.Circle;
                if (Node.Attr.Id.Equals(lastNode)) {
                    // Node.Attr.Shape = Microsoft.Msagl.Drawing.Shape.DoubleCircle;
                    //Node.Attr.Color = Microsoft.Msagl.Drawing.Color.Green;
                }
            }
            foreach (var node in graph.Nodes) {
                richTextBox1Helper.AppendText("node.Id.ToString() = " + node.Id.ToString() + "\n");
                foreach (Edge edge in node.Edges) {
                    // richTextBox1Helper.AppendText("edge.LabelText = " + edge.LabelText + "\n");
                }
            }
            foreach (var item in hash) {
                //  richTextBox1Helper.AppendText(" item.GetType() = " + item.GetType() + "\n");
                //  richTextBox1Helper.AppendText(" item.GetHashCode() = " + item.GetHashCode() + "\n");
                //  richTextBox1Helper.AppendText(" item.ToString() = " + item.ToString() + "\n\n");
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
            textBox3FinalSubString.Text = "bbbfb";
            textBox4SymbolForMultiplicity.Text = "a";
            numericUpDown1Multiplicity.Value = 2;

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
            System.IO.File.WriteAllText(@"C:\Users\stepa\repos2\TYAP_KR_00\automatic-graph-layout-master\automatic-graph-layout-master\GraphLayout\Samples\SameLayerSample\WriteText.txt", richTextBox2CheckResults.Text);
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