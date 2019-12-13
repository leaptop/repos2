using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Permutations
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "ABCDE";
            char[] charArry = str.ToCharArray();
            permute(charArry, 0, str.Length - 1);
            Console.ReadKey();
        }

        static void permute(char[] arry, int i, int n)
        {
            int j;
            if (i == n)
            { Console.Write(arry); Console.WriteLine(" arry"); }
            else
            {
                for (j = i; j <= n; j++)
                {
                    swap(ref arry[i], ref arry[j]);
                    permute(arry, i + 1, n);
                    swap(ref arry[i], ref arry[j]); //backtrack
                }
            }
        }

        static void swap(ref char a, ref char b)
        {
            char tmp;
            tmp = a;
            a = b;
            b = tmp;
        }
    }
}