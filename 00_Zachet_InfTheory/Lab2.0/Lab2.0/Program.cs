using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace Lab2._0
{
    class Program
    {
        static int numberOfChars = 30000;
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
    }
}
