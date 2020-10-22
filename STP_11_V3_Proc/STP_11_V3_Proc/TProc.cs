using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_11_V3_Proc
{
    public class TProc<T> where T : InterfaceForNumbers<T>, new()
    {
      private  string processorState;
        T Lop_Res;//Эти два надо инициализировать значениями по умолчанию в конструкторе по умолчнаию
        T Rop;
        public TProc()
        {
            Lop_Res = new T();
            Rop = new T();
            processorState = "None";
        }
        public TProc(T a, T b)
        {
            if (a == null || b == null) throw new NullPointer();
            Lop_Res = a;
            Rop = b;
            processorState = "None";
        }
        public void ReloadProcessor()
        {
            Lop_Res = new T();
            Rop = new T();
            processorState = "None";
        }
        public void DropOperation()
        {
            processorState = "None";
        }
        public void executeOperation()
        {
            switch (processorState)
            {
                case "None": break;
                case "add": Lop_Res = Lop_Res.add(Lop_Res, Rop); break;
                case "sub": Lop_Res = Lop_Res.sub(Lop_Res, Rop); break;
                case "mul": Lop_Res = Lop_Res.mul(Lop_Res, Rop); break;
                case "dvd": Lop_Res = Lop_Res.dvd(Lop_Res, Rop); break;
                default:
                    throw new WrongInput();
                    break;
            }
        }
        public void executeFunction(string func)
        {
            switch (func)
            {
                case "None": break;
                case "rev": Lop_Res = Lop_Res.rev(Lop_Res); break;
                case "sqr": Lop_Res = Lop_Res.sqr(Lop_Res); break;
                default: throw new WrongInput();
                    break;
            }
        }
        public T readLeftOperand()
        {
            return (T)Lop_Res.Clone();
        }
        public void writeLeftOperand(T Operand)
        {
            Lop_Res = (T) Operand.Clone();
        }
        public T readRightOperand()
        {
            return (T)Rop.Clone();
        }
        public void writeRightOperand(T Operand)
        {
            Rop = (T)Operand.Clone();
        }
        public string readState()
        {
            return processorState;
        }
        public void writeState(string newState)
        {
            processorState = newState;
        }

        public T add(T a, T b)
        {
            T t = a.add(a, b);

            return t;
        }
        public T mul(T a, T b)
        {
            T t = a.mul(a, b);
            return t;
        }
        public T sub(T a, T b)
        {
            T t = a.sub(a, b);

            return t;
        }
        public T dvd(T a, T b)
        {
            T t = a.dvd(a, b);
            return t;
        }
        public T none(T a, T b)
        {
            T t = a.add(a, b);

            return t;
        }
        public T rev(T a)
        {
            T t = a.rev(a);
            return t;
        }
        public T sqr(T a)
        {
            T t = a.sqr(a);

            return t;
        }
        public class WrongInput : Exception
        {
            public WrongInput()
            {
                Console.WriteLine("wrong input");
            }
        }
        public class NullPointer : Exception
        {
            public NullPointer()
            {
                Console.WriteLine("wrong link");
            }
        }

    }
}
