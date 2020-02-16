using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace L1_2
{
    public class Drob
    {
        public int numerator;//chislitel
        public int denominator;//znamenatel

        public Drob()
        {
            this.numerator = 0;
            this.denominator = 0;
        }
        public Drob(int numerator, int denominator)
        {
            this.numerator = numerator;
            this.denominator = denominator;
        }
        public Drob mul(Drob a, Drob b)
        {
            return new Drob(a.numerator * b.numerator, a.denominator * b.denominator);
        }
        public void printDrob()
        {
            Console.WriteLine(numerator + "/" + denominator);
        }
        public void test()
        {
            Drob d1 = new Drob(1, 2);
            Drob d2 = new Drob(1, 3);
            Drob d3 = new Drob();
            d3 = mul(d1, d2);
            d3.printDrob();
        }

    }
}
