using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_13_ParameterizedSet
{
    class DriverClass
    {
        static void Main(string[] args)
        {
            tsetExtendingSet<string> tse = new tsetExtendingSet<string>();
            tse.Add("a string");
            tse.Add("a second string");
            Console.WriteLine("Addition:");
            foreach (var item in tse)
            {
                Console.WriteLine("item in tse = " + item.ToString());
            }
            var tse2 = new tsetExtendingSet<string>();
            tse2.Add("a string");
            tse2.Add("new string");
            foreach (var item in tse2)
            {
                Console.WriteLine("item in tse2 = " + item.ToString());
            }

            var tse3 = tse.Intersect(tse2);
            Console.WriteLine("Intersection:");
            foreach (var item in tse3)
            {
                Console.WriteLine("item in tse3 = " + item.ToString());
            }
            var tse4 = tse.Union(tse2);
            Console.WriteLine("Union:");
            foreach (var item in tse4)
            {
                Console.WriteLine("item in tse4 = " + item.ToString());
            }

            Console.WriteLine("Works");
            Console.ReadLine();
        }
    }
}
