using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NaNCheck
{
    class Program
    {
        public static void Main(string[] args)
        {
            int N = 100;
            int[] A = { 1, 3, 5, 7, 9, 7 };
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (A[i] == A[j])
                    {
                        for (int k = i; k < N - 1; k++)
                        {
                            A[k] = A[k + 1];
                        }
                    }
                }
            }
            //char[] arAlphabet = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };     // используемый алфавит
            //int n = 6;      // количество мест в комбинации
            //char[] arBuffer = new char[n];
            //string fileName = "ResultGenerate.txt";

            //StreamWriter writer = File.CreateText(fileName);    // файл при каждом запуске должен создаваться заново
            //writer.Close();

            //RecursionGenerateCombinationsToFile(arAlphabet, arBuffer, 0, fileName);
        }

        // Рекурсивный медод
        static void RecursionGenerateCombinationsToFile(char[] arAlphabet, char[] arBuffer, int order, string fileName)
        {
            if (order < arBuffer.Length)
                for (int i = 0; i < arAlphabet.Length; i++)
                {
                    arBuffer[order] = arAlphabet[i];
                    RecursionGenerateCombinationsToFile(arAlphabet, arBuffer, order + 1, fileName);
                }
            else
            {
                StreamWriter writer = File.AppendText(fileName);
                for (int i = 0; i < arBuffer.Length; i++)
                    writer.Write(arBuffer[i]);
                writer.WriteLine();
                writer.Close();
            }
        }
    }
}