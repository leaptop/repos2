using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_12_Polynomial
{
    public class TMember : IComparable
    {
        private int FCoeff;//FCoeff - целый коэффициент
        private int FDegree;// FDegree - степень одночленного полинома
        public TMember(int c, int n)
        {
            this.FCoeff = c;
            this.FDegree = n;
        }
        public TMember()
        {
            this.FCoeff = 0;
            this.FDegree = 0;
        }
        public int getPower()
        //вообще это для поиска наибольшей степени полинома, в котором может быть несколько 
        //членов(и несколько степеней, соответственно)
        {
            return FDegree;
        }
        public int getCoefficient()
        {
            return FCoeff;
        }
        public void Clear(ref TMember t)
        {
            if (t == null) throw new NullPointer();
            t.FCoeff = 0;
            t.FDegree = 0;
        }
        public void setPower(int n)
        {
            this.FDegree = n;
        }
        public void setCoefficient(int c)
        {
            this.FCoeff = c;
        }
        public bool equals(TMember t)
        {
            if (FCoeff == t.getCoefficient() && FDegree == t.getPower())
                return true;
            else return false;
        }
        public TMember differentiate()
        {
            if (FDegree == 0)
            {
                FCoeff = 0;
                FDegree = 0;
            }
            else
            {
                FCoeff *= FDegree;
                FDegree -= 1;
            }
            return this;
            /* int newCoeff = FCoeff *= FDegree;
             int newDegree = FDegree -= 1;
             if (FDegree == 0)
             {
                 newCoeff = 0;
                 newDegree = 0;
             }           
             return new TMember(newCoeff, newDegree);*/
        }
        public double calculate(double x)
        {
            return FCoeff * Math.Pow(x, FDegree);
        }
        override
        public string ToString()
        {
            return FCoeff.ToString() + "*x^" + FDegree.ToString();
        }

        public int CompareTo(object obj)//такой компаратор нужен для сортировки Tmember-ов в полиноме по убыванию степени
        {
            return FDegree.CompareTo(obj);
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
