using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3._0
{
    class Program
    {
        static Dictionary<string, double> dicti1 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti2 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti3 = new Dictionary<string, double>();
        static Dictionary<string, double> dicti20 = new Dictionary<string, double>();
        static Dictionary<string, double> dictiMax = new Dictionary<string, double>();
        static int numberOfChars = 0;
        static int numberOfLettersInABlock = 1;
        static void Main(string[] args)
        {
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab3.0/Program.txt", dicti1, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 1:        " + ShennonFormulaForEnthropy(dicti1, numberOfLettersInABlock));

            numberOfLettersInABlock = 2;
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab3.0/Program.txt", dicti2, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 2:        " + ShennonFormulaForEnthropy(dicti2, numberOfLettersInABlock));

            numberOfLettersInABlock = 3;
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab3.0/Program.txt", dicti3, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии 3:        " + ShennonFormulaForEnthropy(dicti3, numberOfLettersInABlock));

            numberOfLettersInABlock = 1;
            foreach (var item in dicti1)
            {
                dictiMax.Add(item.Key, (double)1 / (double)dicti1.Count);
            }
            countProbabilitiesBasedOnRealFrequencyInFile("C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab3.0/Program.txt", dictiMax, numberOfLettersInABlock);
            Console.WriteLine("Оценка энтропии максимально возможной:        " + ShennonFormulaForEnthropy(dictiMax, numberOfLettersInABlock));

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
    }
}
