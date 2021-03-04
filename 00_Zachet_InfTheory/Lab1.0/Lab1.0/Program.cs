using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Lab1._0
{               //Не понятен пункт 2 задания. Сказано передать массив(список) вероятностей в функцию. Однако использовать не его, а заново
                //подсчитанные частоты отдельных символов(отношений числа определённых символов к общему числу символов).
                //Зачем тогда передавать массив в функцию, если он не используется? Или нужно посчитать теоретическую и фактическую энтропию?
                //Но как это сделать для пар символов? Ведь вероятности пар не заданы.
    class Program
    {
        static int numberOfChars = 10000;
        // static double[] probabilities = {(double) 1 / (double)5, (double)1 / (double)3, (double)1 / (double)2 };
        static string[] alphabet = { "a", "b", "c" };
        static double[] probabilities = { 0.1, 0.3, 0.6 };//this needs to be sorted in ascending order. The above array of probabilities 
        //should also be sorted, so that the indexes of symbols and their probabilities are the same.
        static void Main(string[] args)
        {
            fileCreation_1();
            fileCreation_2();
            countShennon_1_way(probabilities);
        }
        static double countShennon_1_way(double[] probs)
        {
            string path1 = @"C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F1.txt";
            string path2 = @"C:/Users/stepa/repos2/00_Zachet_InfTheory/Lab1.0/F2.txt";
            string[] str = new string[numberOfChars];
            string s = "";
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
                            sum += probabilities[j];
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
