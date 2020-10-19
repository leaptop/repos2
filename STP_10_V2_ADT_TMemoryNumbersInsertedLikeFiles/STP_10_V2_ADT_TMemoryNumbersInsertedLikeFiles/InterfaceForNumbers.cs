//using STP_04_ADT_TFrac;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles
{
    public interface InterfaceForNumbers<T> where T : new()
    {
        //TFrac FNumber { get; set; }

        T add(T e);
        T add(T a, T b);
        // T FNumber;
    }
}
