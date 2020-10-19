using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles { 
//Вещественное число (s2). Система счисления(base), точность представления числа(c) – целые числа.
/*Р-ичное число TPNumber - это действительное число (n) со знаком в системе
счисления с основанием (base) (в диапазоне 2..16), содержащее целую и дробную части.
Точность представления числа – (c >= 0). Р-ичные числа изменяемые.
*/
//реализую p-ичное число. base - основание(base) 2 <= base <= 16  ВОПРОС по КонструкторЧисло - каким образом передать в этот конструктор, например 
 // шестнадцатиричное число в виде вещественного? Понял. Передаётся вещественно число, например double, а потом переделывается в число с тем же 
 //значением, но с основанием b
    /*Например:
NCreate(s2,3,3) = число s2 в системе
счисления 3 с тремя разрядами после
троичной точки.
NCreate(s2,3,2) = число s2 в системе
счисления 3 с двумя разрядами после
троичной точки.*/
    public class TPNumber : ICloneable, InterfaceForNumbers<TPNumber>
    {
        public double nDecimal = 0;
        public string aToStrInteger;//здесь оригинальное распарсенное, переданное в конструктор 
        public string aToStrFractional;//здесь оригинальное распарсенное, переданное в конструктор 
        public int integerPartOfaInIntegerDecimal;
        public int fractionalPartOfaInIntegerDecimal;
        public int b;//base
        public int c;//precision
        public string na = "";//Здесь превращенная в соответствии с введённым основанием b целая часть//В случае числа в системе счисления больше 10 храню числа в виде строк. na - целая часть, nb - дробная, n - всё вместе
        public string nb = "";//Здесь превращенная в соответствии с введённым основанием b дробная часть
        public string n = "";//Здесь просто сконкатенированные через запятую na & nb //число в его оригинальной системе счисления (b-ичное)
        public string[] alphabet;

        public TFrac FNumber { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        static void MainTPNumber(string[] args)//при вводе числа в в иде строки обязательно указывать дробную часть через точку, даже если там ноль
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            TPNumber tp1 = new TPNumber("212,22", 3, 7);
            TPNumber tp2 = new TPNumber("AC,B9A", 15, 7);//AC.B9A(пятнадцатеричная) = 162.776296296(десятичная)
            Console.ReadLine();
        }
        public TPNumber()
        {
            nDecimal = 0;
            b = 10;
            n = "0";

        }
        public TPNumber(double a, int b, int c)
        {
            if (a == 0)
            {
                nDecimal = 0;
                n = "0,0";
                return;
            }
            if (b < 2 || b > 16 || c < 0)
            {
                throw new WrongInput();
            }
            string aToStrInteger = a.ToString().Split(',')[0];
            string aToStrFractional = a.ToString().Split(',')[1];
            integerPartOfaInIntegerDecimal = Int32.Parse(aToStrInteger);
            fractionalPartOfaInIntegerDecimal = Int32.Parse(aToStrFractional);
            this.b = b;
            this.c = c;
            nDecimal = a;
            translateFromDecimalTo_b_basedNumber(integerPartOfaInIntegerDecimal, fractionalPartOfaInIntegerDecimal, b, c);
        }
        public TPNumber(string a, int b, int c)
        {
            if (a == "0" || a == "0,0" || a == "0.0")
            {
                nDecimal = 0;
                n = "0,0";
                return;
            }
            string[] tempAlphabet = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
            alphabet = new string[b];
            for (int i = 0; i < b; i++)
            {//определяю допустимые элементы числа в соответствии с основанием системы счисления b
                alphabet[i] = tempAlphabet[i];
            }
            string naa = a.Split(',')[0];
            string nbb = a.Split(',')[1];
            bool contains = false;
            string naanbb = naa + nbb;
            for (int i = 0; i < naanbb.Length; i++)//проверяю каждый символ числа
            {
                // Console.WriteLine("naa[i] = " + naa[i]);
                for (int j = 0; j < b; j++)
                {
                    if (naanbb[i].ToString() == alphabet[j])
                    {//если символ числа хоть раз совпадёт с одним из символов алфавита, значит он входит в множество допустимых символов
                        contains = true;
                    }
                }
                if (!contains)
                {//если же после прохода по всем символам алавита совпадения не произошло, значит этот символ не принадлежит множеству допустимых
                    //и введённое в конструктор число не соответствует своей системе счисления b
                    throw new WrongInput();
                }
                contains = false;
            }
            na = naa;//после проверок выше становится ясно, что числа в правильном формате и их можно сохранить
            nb = nbb;
            n = na + "," + nb;
            //Дальше просто перевожу число в десятичную систему счисления, для занесения его в nDecimal

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
            if (sum != 0)
            {
                fractionalPartOfaInIntegerDecimal = Int32.Parse(sum.ToString().Substring(2, c));// отрезаю "0," от дробного числа 
                                                                                                // nDecimal += sum;
            }

            else
            {
                fractionalPartOfaInIntegerDecimal = 0;
            }
            //---------------------------------------------------------------------------------
            sToCharArr = naa.ToCharArray();//работаю с целой частью
            numOfchars = sToCharArr.Length;
            sToCharArrToInt = new int[numOfchars];//decimal representations of chars of s
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
            sum = 0;
            for (int i = numOfchars - 1, j = 0; i >= 0; i--, j++)
            {
                sum += Math.Pow(b, i) * sToCharArrToInt[j];
            }
            string temp = sum.ToString();
            integerPartOfaInIntegerDecimal = Int32.Parse(temp);
            nDecimal = Double.Parse(temp + "," + fractionalPartOfaInIntegerDecimal.ToString());
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


        public void translateFromDecimalTo_b_basedNumber(int a, int b, int bas, int c)
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

        public TPNumber add(TPNumber a, TPNumber bb)
        {
            if (a.b == bb.b)
                return new TPNumber(a.nDecimal + bb.nDecimal, b, c);
            else
            {
                Console.WriteLine("Bases don't match");
                return null;
            }
        }
    }

    public class WrongInput : Exception
    {
        public WrongInput()
        {
            Console.WriteLine("wrong input in constructor exception");
        }
    }
}
