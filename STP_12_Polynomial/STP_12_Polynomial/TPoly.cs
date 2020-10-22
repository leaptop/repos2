using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_12_Polynomial
{
    public class TPoly
    {
        ArrayList arr;
        public TPoly()
        {
            arr = new ArrayList();
            arr.Add(new TMember());
        }
        public TPoly(int c, int n)
        {
            arr = new ArrayList();
            arr.Add(new TMember(c, n));
        }
        public TPoly(ArrayList a)
        {
            arr = new ArrayList();
            arr.AddRange(a);
        }
        static void Main(string[] args)
        {
            TPoly tp = new TPoly();
            tp.arrInit();
            tp.ToString();
            tp.printPoly();
        }
        public int findPolynomesPower()
        {
            int max = 0;
            for (int i = 0; i < arr.Count; i++)
            {
                int current = (((TMember)arr[i]).getPower());
                if (max < current) max = current;
            }
            return max;
        }
        public int findCoefficientByPower(int n)
        {
            for (int i = 0; i < arr.Count; i++)
            {
                int currentPower = (((TMember)arr[i]).getPower());
                if (n == currentPower) return (((TMember)arr[i]).getCoefficient());
            }
            return 0;//=> n > polynome's degree
        }
        public TPoly Clear()
        {
            return new TPoly();
        }
        public void shortenAndSortPolinomial(ref ArrayList arr)
        {//ЭТОТ КОД СОКРАЩАЕТ ПОЛИНОМ(складывает элементы с одинаковыми степенями)
            for (int i = 0; i < arr.Count; i++)
            {
                for (int j = i + 1; j < arr.Count; j++)
                {
                    int pow1 = ((TMember)arr[i]).getPower();
                    int pow2 = ((TMember)arr[j]).getPower();
                    if (pow1 == pow2)
                    {
                        int coef2 = ((TMember)arr[j]).getCoefficient();
                        int coef1 = ((TMember)arr[i]).getCoefficient();
                        coef1 += coef2;
                        ((TMember)arr[i]).setCoefficient(coef1);
                        ((TMember)arr[j]).setCoefficient(0);
                    }
                }
            }
            for (int i = 0; i < arr.Count; i++)
            {
                int coef1 = ((TMember)arr[i]).getCoefficient();
                if (coef1 == 0)
                {
                    arr.RemoveAt(i);
                    i--;//После удаления i будет указывать на 1 число дальше, чем надо, поэтому уменьшаю его
                }
            }
            int tempPow;
            int tempCoef;
            for (int i = 0; i < arr.Count - 1; i++)
            {
                int pow1 = ((TMember)arr[i]).getPower();
                int coef1 = ((TMember)arr[i]).getCoefficient();
                for (int j = i + 1; j < arr.Count; j++)
                {
                    int coef2 = ((TMember)arr[j]).getCoefficient();
                    int pow2 = ((TMember)arr[j]).getPower();
                    if (pow1 > pow2)
                    {
                        tempPow = pow1;
                        ((TMember)arr[i]).setPower(pow2);
                        ((TMember)arr[j]).setPower(pow1);

                        tempCoef = coef1;
                        ((TMember)arr[i]).setCoefficient(coef2);
                        ((TMember)arr[j]).setCoefficient(coef1);
                    }
                }
            }
        }
        public TPoly add(TPoly t)
        {
            arr.AddRange(t.arr);
            shortenAndSortPolinomial(ref arr);
            return this; // new TPoly(arr);//можно было и не возвращать ничего, но в задании написано, что надо возвратить
        }
        public TPoly mul(TPoly t)//на самом деле здесь нужны алгебраические операции уже... 
        {
            ArrayList arrNew = new ArrayList();
            for (int i = 0; i < arr.Count; i++)
            {
                int coef1 = ((TMember)arr[i]).getCoefficient();
                int pow1 = ((TMember)arr[i]).getPower();
                for (int j = 0; j < t.arr.Count; j++)
                {
                    int coef2 = ((TMember)t.arr[j]).getCoefficient();
                    int pow2 = ((TMember)t.arr[j]).getPower();
                    arrNew.Add(new TMember(coef1 * coef2, pow1 + pow2));
                }
            }
            shortenAndSortPolinomial(ref arrNew);

            return new TPoly(arrNew);
        }
        public TPoly sub(TPoly q)
        {
            for (int i = 0; i < q.arr.Count; i++)
            {
                ((TMember)q.arr[i]).setCoefficient(((TMember)q.arr[i]).getCoefficient() * (-1));
            }//домножил все коэффициенты полинома q на -1
            arr.AddRange(q.arr);
            shortenAndSortPolinomial(ref arr);
            return this;
        }
        public TPoly minus()
        {
            for (int i = 0; i < arr.Count; i++)
            {
                ((TMember)arr[i]).setCoefficient(((TMember)arr[i]).getCoefficient() * (-1));
            }
            return this;
        }
        public bool equals(TPoly t)
        {
            shortenAndSortPolinomial(ref arr);
            shortenAndSortPolinomial(ref t.arr);
            if (arr.Count != t.arr.Count) return false;
            else
            {
                for (int i = 0; i < arr.Count; i++)
                {
                    int pow1 = ((TMember)arr[i]).getPower();
                    int coef1 = ((TMember)arr[i]).getCoefficient();
                    int coef2 = ((TMember)t.arr[i]).getCoefficient();
                    int pow2 = ((TMember)t.arr[i]).getPower();
                    if (pow1 != pow2 || coef1 != coef2) return false;
                }
            }
            return true;
        }
        public TPoly diffirentiate()
        {
            for (int i = 0; i < arr.Count; i++)
            {
                ((TMember)arr[i]).differentiate();
            }
            return this;
        }
        public double calculate(double x)
        {
            double result = 0;
            for (int i = 0; i < arr.Count; i++)
            {
                result += ((TMember)arr[i]).calculate(x);
            }
            return result;
        }

        public void arrInit()
        {
            arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 10));
            arr.Add(new TMember(4, 8));

        }
        public string ToString()
        {
            string poly = "";
            for (int i = 0; i < arr.Count; i++)
            {
                poly += "(" + arr[i].ToString() + ") + ";

            }
            return poly.Substring(0, poly.Length - 3);
        }
        public void printPoly()
        {
            for (int i = 0; i < arr.Count; i++)
            {
                Console.Write(arr[i].ToString() + " + ");
            }
            Console.ReadLine();
        }


    }
}
