using System;
using Numbers;
using Editors;
using Polynomials;

namespace Running
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Polynomial();
            p[5] = 1;
            p[1] = 15;
            p[2] = 4;
            p[7] = 10;
            p[0] = 14;
            p[4] = 0;
            p[4] = 2;
            Console.WriteLine(p);
        }
    }
}
