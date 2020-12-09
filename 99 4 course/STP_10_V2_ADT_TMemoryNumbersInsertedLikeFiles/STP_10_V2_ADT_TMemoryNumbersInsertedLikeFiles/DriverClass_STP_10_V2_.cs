using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles
{
    class DriverClass_STP_10_V2_
    {
        static void Main(string[] args)
        {
            ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(new TFrac(1, 13));
            ADT_TMemory<TFrac> newNumber2 = new ADT_TMemory<TFrac>(new TFrac(1, 13));
           // TFrac tf = newNumber.add(newNumber.FNumber, newNumber2.FNumber);
            newNumber.FNumber = newNumber.add(newNumber.FNumber, newNumber2.FNumber);
            Console.WriteLine("newNumber.FNumber.ToString() = " + newNumber.FNumber.ToString());
           // Console.WriteLine("hello");
            Console.ReadLine();
        }
    }
}
