using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.IO;

namespace Lab4._0
{
    public class Program//codes are read from root to leafs
    {
        static string input;
        static Dictionary<string, double> dicti1 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti2 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti3 = new Dictionary<string, double>();
        static int numberOfChars = 0;
        static int numberOfLettersInABlock = 1;
        static double codeWordAverageLength = 0;
        static void Main(string[] args)
        {
            readAFileToString();
            HuffmanTree huffmanTree = new HuffmanTree();
            huffmanTree.Build(input);
            codeWordAverageLength = huffmanTree.printTreeAndCountAverageLength();
            BitArray encoded = huffmanTree.Encode(input);

            string path2 = "C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab4.0/TextConverted.txt";
            using (StreamWriter sw = File.CreateText(path2))
            {
                foreach (bool bit in encoded)
                {
                    sw.Write((bit ? 1 : 0) + "");
                }
            }
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab4.0/TextConverted.txt", dicti1, numberOfLettersInABlock);
            double first = ShennonFormulaForEnthropy(dicti1, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 1:        " + first);

            numberOfLettersInABlock = 2;
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab4.0/TextConverted.txt", dicti2, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 2:        " + ShennonFormulaForEnthropy(dicti2, numberOfLettersInABlock));

            numberOfLettersInABlock = 3;
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab4.0/TextConverted.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 3:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            Console.WriteLine("Средняя длина кодового слова: " + codeWordAverageLength + " бит");
            Console.WriteLine("Избыточность: " + (codeWordAverageLength - first));

            Console.ReadLine();

        }
        static double ShennonFormulaForEnthropy(Dictionary<string, double> dict, int numberOfLettersInABlock)
        {//Количество информации, которое мы получаем, достигает максимального значения, если события равновероятны... Здесь, видимо,
            //сравниваются значения, полученные применением формулы Хартли...
            //Формула Шеннона позволяет высчитать среднее кол-во информации, передаваемое любым сообщением(блоком символов).
            double sum = 0;
            foreach (var item in dict)
            {
                sum += item.Value * Math.Log(1 / item.Value, 2);
            }
            return sum / numberOfLettersInABlock;
        }
        static void countProbabilitiesBasedOnRealFrequencyInFile(string path, Dictionary<string, double> dict, int numberOfLettersInABlock)
        {
            string str;
            using (StreamReader sr = File.OpenText(path))
            {
                str = sr.ReadToEnd();
            }
            numberOfChars = str.Length;
            char[] str_chars = str.ToCharArray();
            for (int i = 0; i < numberOfChars - numberOfLettersInABlock; i++)
            {
                string block = str_chars[i].ToString();
                for (int j = 1; j < numberOfLettersInABlock; j++)
                {
                    block += str_chars[i + j].ToString();
                }
                if (dict.ContainsKey(block))
                {
                    dict[block] += ((double)1 / ((double)numberOfChars));//   / (double)numberOfLettersInABlock));
                }
                else
                    dict.Add(block, ((double)1 / ((double)numberOfChars)));// / (double)numberOfLettersInABlock))) ;
            }
        }
        public static void readAFileToString()
        {
            string path = "C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab4.0/Hyperion.txt";
            using (StreamReader sr = File.OpenText(path))
            {
                input = sr.ReadToEnd();
            }
        }
    }
    public class HuffmanTree
    {
        private List<Node> nodes = new List<Node>();
        public Node Root { get; set; }
        public Dictionary<char, int> Frequencies = new Dictionary<char, int>();

        public void Build(string source)
        {
            for (int i = 0; i < source.Length; i++)
            {
                if (!Frequencies.ContainsKey(source[i]))
                {
                    Frequencies.Add(source[i], 0);
                }

                Frequencies[source[i]]++;//Считаем кол-во вхождений каждого символа
            }

            foreach (KeyValuePair<char, int> symbol in Frequencies)//для каждого символа алфавита создаём Node
            {
                nodes.Add(new Node() { Symbol = symbol.Key, Frequency = symbol.Value });
            }

            while (nodes.Count > 1)
            {
                List<Node> orderedNodes = nodes.OrderBy(node => node.Frequency).ToList<Node>();//Сортирую узлы по частотам. По возрастанию.

                if (orderedNodes.Count >= 2)
                {
                    // Take first two items
                    List<Node> taken = orderedNodes.Take(2).ToList<Node>();//берём 2 элемента из начала и делаем из них List

                    // Create a parent node by combining the frequencies
                    Node parent = new Node()                
                    {
                        Symbol = '*',//У нас 2 или более узлов, соотвтетсвенно данный узел не будет листом и его называем звёздочкой. 
                        Frequency = taken[0].Frequency + taken[1].Frequency,//Складываю частоты. В начале - это наименьшие частоты
                        Left = taken[0],
                        Right = taken[1]
                    };

                    nodes.Remove(taken[0]);
                    nodes.Remove(taken[1]);
                    nodes.Add(parent);
                }
                this.Root = nodes.FirstOrDefault();
            }
        }

        public double printTreeAndCountAverageLength()
        {
            double L = 0;
            foreach (var item in Frequencies)
            {
                BitArray bitarr = Encode(item.Key.ToString());
                Console.Write(item.Key.ToString() + " - ");
                string codeWord = "";
                foreach (bool itemInner in bitarr)
                {
                    if (itemInner)
                        codeWord += "1";
                    else codeWord += "0";
                }
                Console.WriteLine(codeWord);
                L += codeWord.Length;
            }
            return L / (double)Frequencies.Count;
        }

        public BitArray Encode(string source)
        {
            List<bool> encodedSource = new List<bool>();

            for (int i = 0; i < source.Length; i++)
            {
                List<bool> encodedSymbol = this.Root.Traverse(source[i], new List<bool>());
                encodedSource.AddRange(encodedSymbol);
            }

            BitArray bits = new BitArray(encodedSource.ToArray());

            return bits;
        }

        public string Decode(BitArray bits)
        {
            Node current = this.Root;
            string decoded = "";

            foreach (bool bit in bits)
            {
                if (bit)
                {
                    if (current.Right != null)
                    {
                        current = current.Right;
                    }
                }
                else
                {
                    if (current.Left != null)
                    {
                        current = current.Left;
                    }
                }

                if (IsLeaf(current))
                {
                    decoded += current.Symbol;
                    current = this.Root;
                }
            }

            return decoded;
        }

        public bool IsLeaf(Node node)//(is the last element of a branch)
        {
            return (node.Left == null && node.Right == null);
        }

    }
    public class Node
    {
        public char Symbol { get; set; }
        public int Frequency { get; set; }
        public Node Right { get; set; }
        public Node Left { get; set; }

        public List<bool> Traverse(char symbol, List<bool> data)
        {
            // Leaf
            if (Right == null && Left == null)
            {
                if (symbol.Equals(this.Symbol))
                {
                    return data;
                }
                else
                {
                    return null;
                }
            }
            else
            {
                List<bool> left = null;
                List<bool> right = null;

                if (Left != null)
                {
                    List<bool> leftPath = new List<bool>();
                    leftPath.AddRange(data);
                    leftPath.Add(false);

                    left = Left.Traverse(symbol, leftPath);
                }

                if (Right != null)
                {
                    List<bool> rightPath = new List<bool>();
                    rightPath.AddRange(data);
                    rightPath.Add(true);
                    right = Right.Traverse(symbol, rightPath);
                }

                if (left != null)
                {
                    return left;
                }
                else
                {
                    return right;
                }
            }
        }
    }
}
