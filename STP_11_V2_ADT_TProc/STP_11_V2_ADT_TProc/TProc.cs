using STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_11_V2_ADT_TProc
{
    class TProc<T> where T : InterfaceForNumbers<T>, new()
    {
        T Lop_Res;//Эти два надо инициализировать значениями по умолчанию в конструкторе по умолчнаию
        T Rop;
        static void Main(string[] args)
        {
            TComplex tc = new TComplex();
        }


        public T add(T a, T b)
        {
            T t = a.add(a, b);

            return t;
        }
    }
}
