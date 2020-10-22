using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_04_ADT_TFrac;
using STP_05_ComplexNumber;
using STP_06_TPNumber;
//using InterfaceForNumbers;
namespace STP_10_ADT_TMemory
{
    //public class ADT_TMemory<T> where T : InterfaceForNumbers<T>, new()//   where T : InterfaceForNumbers<T>,  new() //<T> просто объявляет, что в классе есть параметризованный тип
     public class ADT_TMemory<T> where T : InterfaceForNumbers<T>, new()
         //так в строчке  ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(); TFrac подчёркнуто красным,
         //а здесь FNumber = FNumber.add(e); ошибки нет

         //public abstract class ADT_TMemory<T> where T :  new()

         // public  class ADT_TMemory<T> where T : new()// так строчка ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(); срабатывает,
         ////но здесь FNumber = FNumber.add(e); add подчёркнуто красным
    {
        public T FNumber;
        string FState = "";//Memory state

         static void Main(string[] args)
        {
           // ADT_TMemory<TFrac> newNumber = /*(InterfaceForNumbers<TFrac>)*/new ADT_TMemory<TFrac>();
            Console.WriteLine("hello");
            Console.ReadLine();
        }
        public ADT_TMemory()
        {
            //T = new TFrac();
            ADT_TMemory<TFrac> newNumber = /*(InterfaceForNumbers<TFrac>)*/new ADT_TMemory<TFrac>();//               Как создать объект?
            //ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>();
            newNumber.FNumber = new TFrac();
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
            T  t = new T();
            return t;
        }
        public void add(T e)
        {
            FNumber = FNumber.add(e);
            FState = "_On";
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
