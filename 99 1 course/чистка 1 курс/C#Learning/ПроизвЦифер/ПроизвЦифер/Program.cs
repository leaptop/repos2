using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ПроизвЦифер
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a =  { 5, 1 };
            int[] b = { 9, 0 };
            int[] m;
            int y = Math.Max(a.Length, b.Length);
            for (int i = 0; i < 100; i++)//a(n-i)*b(k-i)
            {
                y++;Console.WriteLine("y = " + y);
               // int x = a[a.Length-i] * b[b.Length-i];
                //if (x > 9) { }
                Console.WriteLine("i = " + i);
             if (i == 45) break;
                Console.ReadKey();
            }
            Console.ReadKey();
        }
    }
}
