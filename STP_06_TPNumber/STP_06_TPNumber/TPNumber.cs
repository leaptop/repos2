using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_06_TPNumber
/*Р-ичное число TPNumber - это действительное число (n) со знаком в системе
счисления с основанием (base) (в диапазоне 2..16), содержащее целую и дробную части.
Точность представления числа – (c >= 0). Р-ичные числа изменяемые.
*/
{//реализую p-ичное число. base - основание(base) 2 <= base <= 16  ВОПРОС по КонструкторЧисло - каким образом передать в этот конструктор, например 
 // шестнадцатиричное число в виде вещественного? Понял. Передаётся вещественно число, например double, а потом переделывается в число с тем же 
 //значением, но с основанием b
    /*Например:
NCreate(s2,3,3) = число s2 в системе
счисления 3 с тремя разрядами после
троичной точки.
NCreate(s2,3,2) = число s2 в системе
счисления 3 с двумя разрядами после
троичной точки.*/
    public class TPNumber : ICloneable
    {
        public double nDecimal;
        public string aToStrInteger;
        public string aToStrFractional;
        public int aToIntInt;
        public int aToIntFrac;
        public int b;
        public int c;
        public string na = "";//В случае числа в системе счисления больше 10 храню числа в виде строк. na - целая часть, nb - дробная, n - всё вместе
        public string nb = "";
        public string n = "";
        static void Main(string[] args)
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            //tp.sToInt_bBase_2(tp.aToStrInteger, tp.aToStrFractional, 3);
        }
        public void setCString(string newc)
        {
            c = Int32.Parse(newc);
        }
        public void setCInteger(int newc)
        {
            c = newc;
        }
        public void setBaseString(string bs)
        {
            int bas = Int32.Parse(bs);
            if (bas >= 2 && bas <= 16)
            {
                b = bas;
            }
        }
        public void setBaseInteger(int newb)
        {
            if (newb >= 2 && newb <= 16)
            {
                b = newb;
            }
        }
        public string getCString()
        {
            return c.ToString();
        }
        public int getC()
        {
            return c;
        }
        public string getBaseString()
        {
            return b.ToString();
        }
        public int getBase()
        {
            return b;
        }
        public string getn()
        {
            return n;
        }
        public double getnDecimal()
        {
            return nDecimal;
        }
        public TPNumber square()
        {
            return new TPNumber(nDecimal * nDecimal, b, c);
        }
        public TPNumber add(TPNumber tpn)
        {
            if (b == tpn.b)
                return new TPNumber(nDecimal + tpn.nDecimal, b, c);
            else
            {
                Console.WriteLine("Bases don't match");
                return null;
            }
        }
        public object Clone()
        {
            return this.MemberwiseClone();
        }
        public TPNumber(double a, int b, int c)
        {
            if (b < 2 || b > 16 || c < 0)
            {
                throw new WrongInputInConstructor();
            }
            string aToStrInteger = a.ToString().Split(',')[0];
            string aToStrFractional = a.ToString().Split(',')[1];
            Console.WriteLine("aToStrInteger = " + aToStrInteger);
            Console.WriteLine("aToStrFractional = " + aToStrFractional);
            aToIntInt = Int32.Parse(aToStrInteger);
            aToIntFrac = Int32.Parse(aToStrFractional);
            Console.WriteLine("aToIntInt = " + aToIntInt);
            Console.WriteLine("aToIntFrac = " + aToIntFrac);
            // Console.ReadLine();
            this.b = b;
            this.c = c;
            nDecimal = a;
            translateFromDecimalAandB(aToIntInt, aToIntFrac, b, c);
            Console.WriteLine("na = " + na);
            //Console.ReadLine();
        }
        //Вещественное число (s2). Система счисления(base), точность представления числа(c) – целые числа.


        public void translateFromDecimalAandB(int a, int b, int bas, int c)
        {
            na = "";
            nb = "";
            n = "";
            ArrayList ostatki = new ArrayList();
            int chastnoe;
            int ostatok;
            do
            {
                chastnoe = a / bas;
                ostatok = a % bas;
                ostatki.Add(ostatok);
                a = chastnoe;
            } while (chastnoe > 0);
            if (bas < 10)
            {
                for (int i = ostatki.Count - 1; i >= 0; i--)
                {
                    na += ostatki[i];
                }//это всё сработает для основания меньше 10. Если основание больше 10, надо будет числа большие 10 в ostatki превратить в буквы A, B, C и т.д. 
            }
            else
            {
                for (int i = ostatki.Count - 1; i >= 0; i--)
                {
                    if (ostatki[i].ToString() == "10")
                    {
                        na += "A";
                    }
                    else if (ostatki[i].ToString() == "11")
                    {
                        na += "B";
                    }
                    else if (ostatki[i].ToString() == "12")
                    {
                        na += "C";
                    }
                    else if (ostatki[i].ToString() == "13")
                    {
                        na += "D";
                    }
                    else if (ostatki[i].ToString() == "14")
                    {
                        na += "E";
                    }
                    else if (ostatki[i].ToString() == "15")
                    {
                        na += "F";
                    }
                    else
                    {
                        na += ostatki[i].ToString();
                    }
                }
            }//end of integer translation. Now Fractional:
            int celoe;
            double drobnoe;
            string bstr = "0," + b.ToString();
            ArrayList integerParts = new ArrayList();
            //Console.WriteLine("bstr = " + bstr);
            double bdouble = drobnoe = Double.Parse(bstr);
            //Console.WriteLine("bdouble = " + bdouble);
            //Console.ReadLine();

            for (int i = 0; i < c; i++)
            {
                double multiplication = drobnoe * (double)bas;
                string strInt = multiplication.ToString().Split(',')[0];//0101110

                celoe = Int32.Parse(strInt);
                string strFrac = multiplication.ToString().Split(',')[1];
                drobnoe = multiplication - (double)celoe;
                integerParts.Add(celoe);
            }
            if (bas < 10)
            {
                for (int i = 0; i < integerParts.Count; i++)
                {
                    nb += integerParts[i];
                }//это всё сработает для основания меньше 10. Если основание больше 10, надо будет числа большие 10 в ostatki превратить в буквы A, B, C и т.д. 
            }
            else
            {
                for (int i = 0; i < integerParts.Count; i++)
                {
                    if (integerParts[i].ToString() == "10")
                    {
                        nb += "A";
                    }
                    else if (integerParts[i].ToString() == "11")
                    {
                        nb += "B";
                    }
                    else if (integerParts[i].ToString() == "12")
                    {
                        nb += "C";
                    }
                    else if (integerParts[i].ToString() == "13")
                    {
                        nb += "D";
                    }
                    else if (integerParts[i].ToString() == "14")
                    {
                        nb += "E";
                    }
                    else if (integerParts[i].ToString() == "15")
                    {
                        nb += "F";
                    }
                    else
                    {
                        nb += integerParts[i].ToString();
                    }
                }
            }
            n += (na + "," + nb);
        }
        public TPNumber(string a, int b, int c){
            string naa = a.Split('.')[0];
            string nbb = a.Split('.')[1];
            for (int i = 0; i < naa.Length; i++)
            {

            }
            char[] sToCharArr = nbb.ToCharArray();//работаю с дробной частью
            int numOfchars = sToCharArr.Length;
            int[] sToCharArrToInt = new int[numOfchars];//decimal representations of chars of s
            for (int i = 0; i < numOfchars; i++)
            {
                if (sToCharArr[i] == 'A')
                    sToCharArrToInt[i] = 10;
                else if (sToCharArr[i] == 'B')
                    sToCharArrToInt[i] = 11;
                else if (sToCharArr[i] == 'C')
                    sToCharArrToInt[i] = 12;
                else if (sToCharArr[i] == 'D')
                    sToCharArrToInt[i] = 13;
                else if (sToCharArr[i] == 'E')
                    sToCharArrToInt[i] = 14;
                else if (sToCharArr[i] == 'F')
                    sToCharArrToInt[i] = 15;
                else sToCharArrToInt[i] = sToCharArr[i] - '0';//it's kinda ugly way of converting char to int
            }
            double sum = 0;
            for (int i = 1; i < numOfchars + 1; i++)
            {
                sum += Math.Pow(b, -i) * sToCharArrToInt[i - 1];
            }
            aToIntFrac = Int32.Parse( sum.ToString().Substring(2, c));

        }

    }
    public class WrongInputInConstructor : Exception
    {
        public WrongInputInConstructor()
        {
            Console.WriteLine("wrong input in constructor exception");
        }
    }
}
