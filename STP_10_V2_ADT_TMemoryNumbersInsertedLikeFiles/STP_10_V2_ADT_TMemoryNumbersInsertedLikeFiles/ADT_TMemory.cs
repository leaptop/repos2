using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles
{  
    public class ADT_TMemory<T> where T : InterfaceForNumbers<T>, new()
    {
        public T FNumber;
        string FState;//Memory state


        public ADT_TMemory()
        {
            //ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>();
            //newNumber.FNumber = new TFrac();
            FState = "_Off";
        }
        public ADT_TMemory(T t)
        {
            FNumber = t;
        }
        public void write(T e)
        {
            FNumber = e;
            FState = "_On";
        }
        public T get()
        {
            FState = "_On";
            T t = new T();
            return t;
        }
        public void add(T e)
        {
            FNumber = FNumber.add(e);
            FState = "_On";
        }
        public T add(T a, T b)
        {
            FNumber = FNumber.add(a, b);
            FState = "_On";
            return FNumber;
        }
        public void Clear()
        {
            FNumber = new T();
            FState = "_Off";
        }
        public string readMemoryState()
        {
            return FState;
        }
        public T readNumber()
        {
            return FNumber;
        }
    }
}
