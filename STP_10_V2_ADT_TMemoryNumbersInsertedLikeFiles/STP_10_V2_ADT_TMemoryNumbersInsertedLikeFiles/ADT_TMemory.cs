using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles
// THE PROBLEM IN THE FIRST VERSION OF LAB 10 WAS THAT
//I COULDN'T ADD THE InterfaceForNumbers<T> INTERFACE TO SUBPROJECTS(LIKE TFrac). So I decided to 
//collect all code in one project.
{
    public class ADT_TMemory<T> where T : InterfaceForNumbers<T>, new()
    {
        public T FNumber;
        string FState;//Memory state

        public ADT_TMemory()
        {
            ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>();
            newNumber.FNumber = new TFrac();
            FState = "_Off";
        }
        public ADT_TMemory(T t)
        {
            if (t == null) throw new NullPointerException();
            FNumber = t;
            FState = "_On";
        }
        public void write(T e)
        {
            if (e == null) throw new NullPointerException();
            FNumber = e;
            FState = "_On";
        }
        public T get()
        {
            FState = "_On";
            // T t = new T();
            return FNumber;
        }
        public void add(T e)
        {
            if (e == null) throw new NullPointerException();
            FNumber = FNumber.add(e);
            FState = "_On";
        }
        public T add(T a, T b)
        {
            if (a == null || a == null) throw new NullPointerException();
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
        public class NullPointerException : Exception
        {
            public NullPointerException()
            {
                Console.WriteLine("wrong input");
            }
        }
    }
}
