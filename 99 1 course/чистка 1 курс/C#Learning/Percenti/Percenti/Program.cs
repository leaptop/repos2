using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Percenti
{
    class Program
    {
        public static double Calculate(string threeNumbers)
        {
            Char delimiter = ' ';
            String[] substrings = threeNumbers.Split(delimiter);

            double amount = double.Parse(substrings[0]);
            double percentage = double.Parse(substrings[1]);
            int months = int.Parse(substrings[2]);

            for (int i = 0; i < months; i++)
            {
                amount += (amount * (percentage / 12)) / 100;
            }
            return amount;
        }
        //public static double Calculate(string threeNumbers)
        //{
        //    Char delimiter = ' ';
        //    String[] substrings = threeNumbers.Split(delimiter);

        //    double amount = double.Parse(substrings[0]);
        //    double percentage = double.Parse(substrings[1]);
        //    int months = int.Parse(substrings[2]);

        //    for (int i = 0; i < months; i++)
        //    {
        //        amount += (amount * (percentage / 12)) / 100;
        //    }

        //    Console.WriteLine(amount);
        //    return amount;
        //}
        public static void Main()
        {
            string threeNumbers = (Console.ReadLine());
            Calculate(threeNumbers);
            Console.WriteLine(Calculate(threeNumbers));
            Console.ReadLine();
        }
    }
}

//        static void Main(string[] args)
//        {
//            string threeNumbers = (Console.ReadLine());
//            Char delimiter = ' ';
//            String[] substrings = threeNumbers.Split(delimiter);

//            double amount = double.Parse(substrings[0]);
//            double percentage = double.Parse(substrings[1]);
//            int months = int.Parse(substrings[2]);

//            Console.WriteLine(Calculate(amount, percentage, months));

//            Console.ReadLine();
//        }
//        static double Calculate(double amount, double percentage, int months)
//        {
//            for (int i = 0; i < months; i++)
//            {
//                amount += (amount * (percentage / 12)) / 100;
//            }
//            return amount;
//        }
//    }
//}
