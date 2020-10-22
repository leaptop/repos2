using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_11_ADT_TProc
{
   public class ADT_TProc<T> : Interface1<T> where T  :  new()
    {
        T Lop_Res;//Эти два надо инициализировать значениями по умолчанию в конструкторе по умолчнаию
        T Rop;
        static void Main(string[] args)
        {
        }


        public T add(T a, T b)
        {
            T t = a.add(a, b);
            
            return t;
        }

        public T mul(T a, T b)
        {
            throw new NotImplementedException();
        }

        public T sub(T a, T b)
        {
            throw new NotImplementedException();
        }

        public T dvd(T a, T b)
        {
            throw new NotImplementedException();
        }

        public T none(T a, T b)
        {
            throw new NotImplementedException();
        }

        public T rev(T a)
        {
            throw new NotImplementedException();
        }

        public T sqr(T a)
        {
            throw new NotImplementedException();
        }

        public ADT_TProc()
        {
            Lop_Res = new T();
            Rop = new T();
        }
    }
}
