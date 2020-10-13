using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_04_ADT_TFrac
{
    public class ZeroDenominatorException : Exception
    {
        public ZeroDenominatorException()//Можно ли как в джаве подписывать справа от объявления метода throws SomeException и т.о. избавиться от 
        {//необходимости писать try catch всё время? Что такое UFrac? Это д.б. класс, в котором будут реализованы все методы? А TFrac д.б. абстрактным классом?
            Console.WriteLine("You've probably created a denominator equal to zero");
        }
    }
    public class WrongStringException : Exception
    {
        public WrongStringException()
        {
            Console.WriteLine("Something wrong with the input string");
        }
    }
   public class TFrac : ICloneable, IEnumerable<int>
    {
        static void Main(string[] args)
        {
            TFrac tf;
            try
            {
                tf = new TFrac(0, 100);
                Console.WriteLine("tf.numerator = " + tf.numerator + ", tf.denominator = " + tf.denominator);
                tf.test();
            }
            catch (ZeroDenominatorException e)
            {

            }

            Console.ReadLine();
        }
        public int numerator;//chislitel
        public int denominator;//znamenatel
        public string f = "";//a fraction in shape of a string
        public string aStr = "";
        public string bStr = "";

        //public TFrac()
        //{// it would be difficult to implement some actions like addition for example. So such default constructor is undesirable.
        //    this.numerator = 0;
        //    this.denominator = 1;
        //}
        public TFrac(int numerator, int denominator)// : throws ZeroDenominator;
        {
            if(denominator == 0)
            {
                throw new ZeroDenominatorException();
            }
            
/*            if (numerator < 0 && denominator < 0)//сокращаю минусы в числителе и знаменталел
            {
                numerator *= -1;
                denominator *= -1;
            }*/
            if (denominator < 0)//переношу минус из знаменателя в числитель
            {
                numerator *= -1;
                denominator *= -1;
            }
            if (denominator != 0)
            {
                int t = GCD(numerator, denominator);//сразу сокращаю дробь если это возможно
                this.numerator = numerator / t;
                this.denominator = denominator / t;
            }
           else
            {
                //this.numerator = numerator;
                //this.denominator = denominator;
            }
            aStr = numerator.ToString();
            bStr = denominator.ToString();
            f = aStr + "/" + bStr;

            /* if (numerator == 0) denominator = 0;
             if (denominator == 0) numerator = 0;*/
        }

        public TFrac(string str)
        {//Дробь в виде строки вводится в виде 123/456, иначе кидается исключение
            string[] strToArray = str.Split('/');
            if (strToArray.Length > 2)
            {
                throw new WrongStringException();
            }
            int a;
            int b;
            if (!Int32.TryParse(strToArray[0], out a)) throw new WrongStringException();
            if (strToArray.Length == 2)
            {
                if (!Int32.TryParse(strToArray[1], out b)) throw new WrongStringException();
            }
            else b = 1;
            if (b == 0) throw new ZeroDenominatorException();
            int t = GCD(a, b);//сразу сокращаю дробь если это возможно
            this.numerator = a / t;
            this.denominator = b / t;
            if (denominator < 0)//удаляю минус из знаменателей если они там были
            {
                denominator *= -1;
                numerator *= -1;
            }
            aStr = this.numerator.ToString();
            bStr = this.denominator.ToString();
            f += aStr + "/" + aStr;
        }
        public object Clone()//Копировать
        {
            // return new TFrac(numerator, denominator) { numerator = this.numerator, denominator = this.denominator };
            return this.MemberwiseClone();
        }

        public TFrac add(TFrac a, TFrac b)
        {
            TFrac aa = (TFrac)a.Clone();//Клонирование нужно, чтобы сохранить оригинальные дроби в исходном виде
            TFrac bb = (TFrac)b.Clone();
            transformToOneDenominator(ref aa, ref bb);
            return new TFrac(aa.numerator + bb.numerator, aa.denominator);
        }
        public void transformToOneDenominator(ref TFrac a, ref TFrac b)//привести дроби к общему знаменателю
        {
 /*           if (a.denominator < 0)//удаляю минус из знаменателей если они там были
            {
                a.denominator *= -1;
                a.numerator *= -1;
            }*/
            if (b.denominator < 0)
            {
                b.denominator *= -1;
                b.numerator *= -1;
            }
            int multiplierA = 1;
            int multiplierB = 1;
            int newDenominator = 1;
            if ((a.denominator != b.denominator))//if denominators aren't equal, we need to find Least(lowest) common multiple (наименьшее общее кратное)
            {
                if (a.denominator != 0 && b.denominator != 0)
                {
                    newDenominator = LCM(a.denominator, b.denominator);//нашёл наименьшее общее кратное знаменателей
                    multiplierA = newDenominator / a.denominator;//нашёл во сколько раз надо увеличить числитель a, чтобы привести дробь а к 
                    multiplierB = newDenominator / b.denominator;//новому знаменателю newDenominator. Аналогично для b                  
                }
            }
            else newDenominator = a.denominator;//если знаменатели уже были равны, то новым просто делаю первый
            a.numerator *= multiplierA; b.numerator *= multiplierB; a.denominator = b.denominator = newDenominator;//привожу к общему знаменателю и 
        }//соответствующим числителям
        public TFrac mul(TFrac a, TFrac b)//this function returns a result of multiplication of сommon fractions a & b
        {
            return new TFrac(a.numerator * b.numerator, a.denominator * b.denominator);
        }

        public TFrac sub(TFrac a, TFrac b)
        {
            TFrac aa = (TFrac)a.Clone();//Клонирование нужно, чтобы сохранить оригинальные дроби в исходном виде
            TFrac bb = (TFrac)b.Clone();
            transformToOneDenominator(ref aa, ref bb);
            return new TFrac(aa.numerator - bb.numerator, aa.denominator);
        }
        public TFrac div(TFrac a, TFrac b)//divides a by b
        {
            //return new TFrac(a.numerator * b.denominator, a.denominator * b.numerator);
            return mul(a, new TFrac(b.denominator, b.numerator));
        }
        public TFrac square(TFrac a)
        {
            return new TFrac(a.numerator * a.numerator, a.denominator * a.denominator);
        }
        public TFrac fractionsReciprocal(TFrac a)//нахождение обратной дроби
        {
            if (a.numerator != 0)
                return new TFrac(a.denominator, a.numerator);
            else
            {
                Console.WriteLine("Дробь с нулём в числителе пытается породить дробь с нулём в знаменателе...");
                return null;
            }
        }
        public TFrac minus()//вычитание нашей дроби из нуля или, что то же самое, умножение её на -1
        {
            return sub(new TFrac(0, 1), this);
        }
        public bool thisEqualToParameter_d(TFrac d)
        {
            TFrac dd = (TFrac)d.Clone();//Клонирование нужно, чтобы сохранить оригинальные дроби в исходном виде
            TFrac aa = (TFrac)this.Clone();
            transformToOneDenominator(ref dd, ref aa);
            if (aa.numerator == dd.numerator)
            {
                return true;
            }
            else return false;
        }
        public bool isMoreThanParameter_d(TFrac d)
        {
            TFrac dd = (TFrac)d.Clone();//Клонирование нужно, чтобы сохранить оригинальные дроби в исходном виде
            TFrac aa = (TFrac)this.Clone();
            transformToOneDenominator(ref dd, ref aa);
            if (aa.numerator >= dd.numerator)
            {
                return true;
            }
            else return false;
        }
        public int getNumerator()
        {
            return numerator;
        }
        public int getDenominator()
        {
            return denominator;
        }
        public string getNumeratorString()
        {
            return aStr;
        }
        public string getDenominatorString()
        {
            return bStr;
        }
        public string getFractionString()
        {
            return f;
        }
        public String ToString()
        {
            if (denominator == 0 && numerator != 0) return Double.PositiveInfinity.ToString();
            else
            if (numerator == 0) return "0";
            else
            if (denominator == 1) return (numerator.ToString());
            else
                return (numerator.ToString() + "/" + denominator.ToString());
        }

        // Use Euclid's algorithm to calculate the greatest common divisor (GCD) of two numbers
        private int GCD(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);

            // Pull out remainders
            for (; ; )
            {
                int remainder = a % b;
                if (remainder == 0) return b;
                a = b;
                b = remainder;
            };
        }
        // Return the least common multiple (LCM) of two numbers
        private int LCM(int a, int b)
        {
            return a * b / GCD(a, b);
        }
        public void printDrob()//in console
        {
            Console.WriteLine(numerator + "/" + denominator);
        }
        public void test()
        {
            TFrac d1 = new TFrac(1, 2);
            TFrac d2 = new TFrac(1, 3);
            TFrac d3;
            TFrac d4;
            TFrac d5 = add(d1, d2);
            d3 = mul(d1, d2);
            d3.printDrob();
            d4 = add(d1, d2);
            d4.printDrob();
            Console.WriteLine("d4 = " + d4.ToString());
            Console.WriteLine("d5 = " + d5.ToString());
        }

        IEnumerator<int> IEnumerable<int>.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
