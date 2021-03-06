using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace Lab1._0
{               //Не понятен пункт 2 задания. Сказано передать массив(список) вероятностей в функцию. Однако использовать не его, а заново
                //подсчитанные частоты отдельных символов(отношений числа определённых символов к общему числу символов).
                //Зачем тогда передавать массив в функцию, если он не используется? Или нужно посчитать теоретическую и фактическую энтропию?
                //Но как это сделать для пар символов? Ведь вероятности пар не заданы. Или нужно сначала посчитать эти вероятности по
                //фактическому числу символов и потом уже передавать этот список вероятностей?
    class Program
    {
        static int numberOfChars = 30000;
        // static double[] probabilities = {(double) 1 / (double)5, (double)1 / (double)3, (double)1 / (double)2 };
        static string[] alphabet = { "a", "b", "c" };
        static double[] probabilities = { 0.1, 0.3, 0.6 };//this needs to be sorted in ascending order. The above array of probabilities 
        //should also be sorted, so that the indexes of symbols and their probabilities are the same.
        static Dictionary<string, double> dicti1 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti2 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti3 = new Dictionary<string, double>();
        static int numberOfLettersInABlock = 1;

        static void Main(string[] args)
        {
            dicti1.Add("a", (double)1 / (double)3);
            dicti1.Add("b", (double)1 / (double)3);
            dicti1.Add("c", (double)1 / (double)3);
            fileCreation_3(dicti1, "F1");

            dicti2.Add("a", (double)1 / (double)9);
            dicti2.Add("b", (double)2 / (double)9);
            dicti2.Add("c", (double)6 / (double)9);
            fileCreation_3(dicti2, "F2");

            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Файл 1:\n" + "Оценка энтропии 1:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));
            Console.WriteLine("Теоретическая энтропия 1: " + ShennonFormulaForEnthropy(dicti1, numberOfLettersInABlock));

            dicti1 = new Dictionary<string, double>();
            dicti1.Add("aa", (double)2 / (double)9);
            dicti1.Add("ab", (double)2 / (double)9);
            dicti1.Add("ac", (double)2 / (double)9);
            dicti1.Add("ba", (double)2 / (double)9);
            dicti1.Add("bb", (double)2 / (double)9);
            dicti1.Add("bc", (double)2 / (double)9);
            dicti1.Add("ca", (double)2 / (double)9);
            dicti1.Add("cb", (double)2 / (double)9);
            dicti1.Add("cc", (double)2 / (double)9);
            numberOfLettersInABlock = 2;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 2:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));
            Console.WriteLine("Теоретическая энтропия 2: " + ShennonFormulaForEnthropy(dicti1, numberOfLettersInABlock));

            numberOfLettersInABlock = 3;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 3:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            numberOfLettersInABlock = 4;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 4:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            numberOfLettersInABlock = 20;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 20:       " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            //Настраиваемые вероятности:
                        numberOfLettersInABlock = 1;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("\nФайл 2:\nОценка энтропии 1:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));
            Console.WriteLine("Теоретическая энтропия 1: " + ShennonFormulaForEnthropy(dicti2, numberOfLettersInABlock));

            numberOfLettersInABlock = 2;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 2:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));
            dicti2 = new Dictionary<string, double>();
            dicti2.Add("aa", (double)2 / (double)81);
            dicti2.Add("ab", (double)2 * 2 / (double)81);
            dicti2.Add("ac", (double)2 * 2 / (double)27);
            dicti2.Add("ba", (double)2 * 2 / (double)81);
            dicti2.Add("bb", (double)2 * 4 / (double)81);
            dicti2.Add("bc", (double)2 * 12 / (double)81);
            dicti2.Add("ca", (double)2 * 2 / (double)27);
            dicti2.Add("cb", (double)2 * 12 / (double)81);
            dicti2.Add("cc", (double)2 * 36 / (double)81);

            Console.WriteLine("Теоретическая энтропия 2: " + ShennonFormulaForEnthropy(dicti2, numberOfLettersInABlock));

            numberOfLettersInABlock = 3;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 3:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            numberOfLettersInABlock = 4;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 4:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            numberOfLettersInABlock = 20;
            dicti3 = new Dictionary<string, double>();
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 20:       " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));


            Console.ReadKey();
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
            }//1. Apparently I need to split the string by words... No. A whitespace is also a symbol.
             //2. I need to split it on chars. 
             //3. Then to get words of needed length by hand
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
                    dict[block] += ((double)1 / ((double)numberOfChars / (double)numberOfLettersInABlock));
                }
                else
                    dict.Add(block, ((double)1 / ((double)numberOfChars / (double)numberOfLettersInABlock)));
            }//up to here all occurences of blocks are counted and frequencies(counted probabilities) are counted.
            //Time to use Shennon's formula                      
        }
        static void fileCreation_3(Dictionary<string, double> dict, string fileName)
        {
            var rand = new Random();
            string path = @"C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/" + fileName + ".txt";
            {
                using (StreamWriter sw = File.CreateText(path))
                {
                    for (int i = 0; i < numberOfChars; i++)
                    {
                        double num = rand.NextDouble();//here the randomity occures
                        double sum = 0;
                        foreach (var item in dict)
                        {
                            sum += item.Value;
                            if (num <= sum)//have found the position of the random number among the probabilities
                            {
                                sw.Write(item.Key);
                                break;
                            }
                        }
                    }
                }
            }
        }
        static double[] CountProbabilities(string path, double[] probs)//here and below are wrong way functions 
                                                                       //counting probabilities based on existing files with text
        {
            double[] result = new double[10];

            return result;
        }

        static double countShennon_1_way(double[] probs)
        {
            string path1 = @"C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt";
            string[] str = new string[numberOfChars];
            using (StreamReader sr = File.OpenText(path1))
            {
                for (int i = 0; i < numberOfChars; i++)
                {
                    str[i] = sr.ReadLine();
                }
            }
            // string[] str_in_chars = str.Split('');
            double sum = 0;
            for (int i = 0; i < str.Length; i++)
            {
                for (int j = 0; j < probs.Length; j++)
                {
                    if (String.Compare(str[i], alphabet[j]) == 0)
                    {

                    }
                }
            }
            return sum;
        }

        static void fileCreation_2()
        {
            // Instantiate random number generator using system-supplied value as seed.
            var rand = new Random();
            string path = @"C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt";//C:\Users\stepa\repos2\00_Zachet_InfTheory\Lab1.0
                                                                                     // if (!File.Exists(path))
            {
                // Create a file to write to.
                using (StreamWriter sw = File.CreateText(path))
                {
                    /*                    Array.Sort(probabilities);//have sorted
                                        for (int i = 0; i < probabilities.Length; i++)
                                        {
                                            Console.WriteLine(probabilities[i]);
                                        }*/
                    // Console.ReadLine();
                    int index = 0;
                    for (int i = 0; i < numberOfChars; i++)
                    {
                        double num = rand.NextDouble();//here the randomity occures
                        double sum = 0;
                        for (int j = 0; j < probabilities.Length; j++)
                        {
                            sum += probabilities[j];//It doesn't matter if the array of probabilities is sorted or not, so this function 
                            //needs to be rewritten
                            if (num <= sum)//have found the position of the random number among the probabilities
                            {
                                sw.Write(alphabet[j] + "\n");
                                //index = j;
                                break;
                            }
                        }
                    }
                }
            }
        }
        static void fileCreation_1()
        {
            // Instantiate random number generator using system-supplied value as seed.
            var rand = new Random();
            string path = @"C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt";//C:\Users\stepa\repos2\00_Zachet_InfTheory\Lab1.0
                                                                                     // if (!File.Exists(path))
            {
                // Create a file to write to.
                using (StreamWriter sw = File.CreateText(path))
                {
                    for (int i = 0; i < numberOfChars; i++)
                    {
                        int index = rand.Next(0, 3);
                        sw.Write(alphabet[index] + "\n");//Has written letters with equal probabilities
                    }
                }
            }
        }
    }
}
