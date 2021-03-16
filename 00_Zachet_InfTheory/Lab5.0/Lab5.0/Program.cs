using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.IO;

namespace Lab5._0
{
    public class Program//making a ternary Huffman coding. Тернарный вроде как субоптимальный(по отношению к бинарному), т.к. надо делать тройки.
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
            string path = "C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab5.0/Program.txt";
            using (StreamReader sr = File.OpenText(path))
            {
                input = sr.ReadToEnd();
            }
            // input = "hi hippie";
            HuffmanTree huffmanTree = new HuffmanTree();
            huffmanTree.Build(input);
            codeWordAverageLength = huffmanTree.printTreeAndCountAverageLength();
            // codeWordAverageLength = huffmanTree.printTreeAndCountAverageLengthOriginal();
            //BitArray encoded = huffmanTree.EncodeOriginal(input);
            List<int> encoded = huffmanTree.Encode(input);
            /* Console.WriteLine("encoded symbols:");
             foreach (var item in encoded)
             {
                 Console.Write(item);
             }*/

            string path2 = "C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab5.0/TextConverted.txt";
            using (StreamWriter sw = File.CreateText(path2))
            {
                foreach (int bit in encoded)
                {
                    sw.Write(bit);
                }
            }
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab5.0/TextConverted.txt", dicti1, numberOfLettersInABlock);
            double first = ShennonFormulaForEnthropy(dicti1, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 1:        " + first);

            numberOfLettersInABlock = 2;
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab5.0/TextConverted.txt", dicti2, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 2:        " + ShennonFormulaForEnthropy(dicti2, numberOfLettersInABlock));

            numberOfLettersInABlock = 3;
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab5.0/TextConverted.txt", dicti3, numberOfLettersInABlock);
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
                    dict[block] += ((double)1 / ((double)numberOfChars));
                }
                else
                    dict.Add(block, ((double)1 / ((double)numberOfChars)));
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
            //Для тернарного дерева число листьев д.б. нечётным, чтобы дерево построилось:
            if (nodes.Count % 2 == 0)
                nodes.Add(new Node() { Symbol = '₵', Frequency = 0 });

            while (nodes.Count > 1)
            {
                List<Node> orderedNodes = nodes.OrderBy(node => node.Frequency).ToList<Node>();//После каждого создания нового родителя сортирую узлы по частотам. По возрастанию.
                //В итоге дерево собирается так как надо(по правилам построения дерева Хаффмана)(новые узлы сортируются по частотам(вероятностям появления символов) и только потом дерево продолжает построение).
                if (orderedNodes.Count >= 3)
                {
                    List<Node> taken = orderedNodes.Take(3).ToList<Node>();//берём 3 элемента из начала и делаем из них List
                    // Create a parent node by combining the frequencies:
                    Node parent = new Node()
                    {
                        Symbol = '*',//У нас 2 или более узлов, соотвтетсвенно данный узел не будет листом и его называем звёздочкой. 
                        Frequency = taken[0].Frequency + taken[1].Frequency + taken[2].Frequency,//Складываю частоты. В начале - это наименьшие частоты
                        Left = taken[0],
                        Center = taken[1],
                        Right = taken[2]
                    };
                    nodes.Remove(taken[0]);
                    nodes.Remove(taken[1]);
                    nodes.Remove(taken[2]);
                    nodes.Add(parent);
                }
                this.Root = nodes.FirstOrDefault();//Корнем дерева назначаю просто первый или null из nodes
            }
        }

        public double printTreeAndCountAverageLength()
        {
            double L = 0;
            foreach (var item in Frequencies)
            {
                List<int> bitarr = Encode(item.Key.ToString());
                Console.Write(item.Key.ToString() + " - ");
                string codeWord = "";
                foreach (int itemInner in bitarr)
                {
                    if (itemInner == 0)
                        codeWord += "0";
                    else if (itemInner == 1) codeWord += "1";
                    else codeWord += "2";
                }
                Console.WriteLine(codeWord);
                L += codeWord.Length;
            }
            return L / (double)Frequencies.Count;
        }

        public List<int> Encode(string source)
        {
            List<int> encodedSource = new List<int>();

            for (int i = 0; i < source.Length; i++)
            {
                List<int> encodedSymbol = this.Root.Traverse(source[i], new List<int>());//В метод Traverse передаю символ для поиска и новый
                //список для хранения кодового слова. Он у меня интовый, т.к. алфавит небинарный и требуется больше, чем 2 символа(в отличие от массива BitArray).
                //Возвращается ссылка на этот же список, но уже заполненный естественно.
                encodedSource.AddRange(encodedSymbol);
            }

            List<int> bits = new List<int>();
            return encodedSource;
        }
        public string Decode(List<int> bits)
        {
            Node current = this.Root;
            string decoded = "";

            foreach (int bit in bits)
            {
                if (bit == 2)
                {
                    if (current.Right != null)
                    {
                        current = current.Right;
                    }
                }
                else if (bit == 1)
                {
                    if (current.Center != null)
                    {
                        current = current.Center;
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
        public char Symbol { get; set; }//a symbol of this Node
        public int Frequency { get; set; }
        public Node Right { get; set; }
        public Node Left { get; set; }
        public Node Center { get; set; }

        public List<int> Traverse(char symbol, List<int> data)
        {
            // Leaf
            if (Right == null && Center == null && Left == null)
            {
                if (symbol.Equals(this.Symbol))//Ищем символы, проходя по дереву
                {
                    return data;//Если дошли до листа и его символ равен искомому, то возвращаем переданный сюда как параметр List<int> data
                }
                else
                {
                    return null;
                }
            }
            else
            {
                List<int> left = null;
                List<int> center = null;
                List<int> right = null;

                if (Left != null)
                {
                    List<int> leftPath = new List<int>();
                    leftPath.AddRange(data);
                    leftPath.Add(0);//пририсовываем циферки к рёбрам(стрелкам на нижние узлы)

                    left = Left.Traverse(symbol, leftPath);//В Traverse передаю уже сохранённый leftPath, а там(в следующем рекурсивном вызове Traverse) создаётся ещё один leftPath и
                    //к нему опять же приписывается тот leftPath, который был передан при вызове Traverse (leftPath.AddRange(data);), а также пририсовывается соответствующее пути название ребра
                    //(для leftPath это 0, для centerPath это 1 и т.д.). Если дерево построено правильно, то только один из путей закончится тем, что ссылки на Right, Center, Left будут null,
                    //и symbol.Equals(this.Symbol) выполнится для данного узла, и вернётся data(список символов, описывающих путь к данному узлу).

                }//В итоге все узлы, не содержащие искомый символ, вернут null, в самом конце этого метода, соответственно, произойдёт отбор и возврат единственного полученного пути, который будет не null, 
                //а то, что вернул лист, содержащий искомый символ.

                if (Center != null)
                {
                    List<int> centerPath = new List<int>();
                    centerPath.AddRange(data);
                    centerPath.Add(1);

                    center = Center.Traverse(symbol, centerPath);
                }

                if (Right != null)
                {
                    List<int> rightPath = new List<int>();
                    rightPath.AddRange(data);
                    rightPath.Add(2);

                    right = Right.Traverse(symbol, rightPath);
                }

                if (left != null)
                {
                    return left;
                }
                else if (center != null)
                {
                    return center;
                }
                else
                {
                    return right;
                }
            }
        }

    }
}
