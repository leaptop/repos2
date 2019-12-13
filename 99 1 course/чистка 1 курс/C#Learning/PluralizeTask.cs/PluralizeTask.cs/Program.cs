using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PluralizeTask
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                int f = int.Parse(Console.ReadLine());
                int n = f % 10;
                int z = f % 100;

                if ((z >= 11 && z <= 14) || n == 0 || (n >= 5 && n <= 9)) { Console.WriteLine("рублей"); }
                else if (n >= 2 && n <= 4) { Console.WriteLine("рубля"); }
                else Console.WriteLine("рубль");
            }
        }
    }
}
