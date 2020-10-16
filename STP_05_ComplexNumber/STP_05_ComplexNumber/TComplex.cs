using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Channels;
using System.Text;
using System.Threading.Tasks;

namespace STP_05_ComplexNumber
{
    public class TComplex : ICloneable
    {
        static void Main(string[] args)
        {
            TComplex tc = new TComplex("-6   -  i*3");
            Console.WriteLine("tc.ToString() = " + tc.ToString());
            TComplex tc2 = new TComplex(5, 8);
            TComplex res = tc2.power(4);
            Console.WriteLine("tc2.power(4) =  " + res.ToString());
            TComplex tc3 = new TComplex(1, 0);
            TComplex res2 = tc3.root(5, 2);
            Console.WriteLine("the i-th complex number is " + res2.ToString());
            Console.ReadLine();
        }
        private double a;
        private double b;
        private char signOfb;

        public TComplex(double a, double b)
        {
            this.a = a;
            this.b = b;
        }
        public TComplex(string str)//Вызов возможен в виде "6+i*3", "-5 + i*2"
        {
            str = str.Replace(" ", "");
            string[] stringsToAvoid = { "/", "+", "*", " ", "-i" };
            string[] strSplit = str.Split(stringsToAvoid, 6, StringSplitOptions.RemoveEmptyEntries);
            if (!Double.TryParse(strSplit[0], out a)) Console.WriteLine("first number is in bad shape");
            if (!Double.TryParse(strSplit[1], out b)) Console.WriteLine("second number is in bad shape");
            char[] strToChars = str.ToCharArray();
            if (str.Contains("-i")) b *= -1;
        }
        public object Clone()
        {
            return this.MemberwiseClone();
        }
        public TComplex add(TComplex d)
        {
            return new TComplex(a + d.getRealDouble(), b + d.getImaginaryDouble());
        }
        public double getRealDouble()
        {
            return a;
        }
        public double getImaginaryDouble()
        {
            return b;
        }
        public TComplex multiply(TComplex d)
        {
            double a1 = a;
            double a2 = d.getRealDouble();
            double b1 = b;
            double b2 = d.getImaginaryDouble();
            return new TComplex(a1 * a2 - b1 * b2, a1 * b2 + a2 * b1);
        }
        public TComplex square()
        {
            return new TComplex(a * a - b * b, a * b + a * b);
        }
        public TComplex reciprocal()//Обратное Создаёт и возвращает комплексное число (тип TComplex), полученное делением единицы на само число
        {
            return new TComplex(a / (a * a + b * b), -(b / (a * a + b * b)));
        }
        public TComplex subtractParameter_d(TComplex d)
        {
            double a1 = a;
            double a2 = d.getRealDouble();
            double b1 = b;
            double b2 = d.getImaginaryDouble();
            return new TComplex(a1 - a2, b1 - b2);
        }
        public TComplex divideBy_d(TComplex d)
        {
            double a1 = a;
            double a2 = d.getRealDouble();
            double b1 = b;
            double b2 = d.getImaginaryDouble();
            return new TComplex((a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2), (a2 * b1 - a1 * b2) / (a2 * a2 + b2 * b2));
        }
        public TComplex minus()
        {
            return new TComplex(0 - a, 0 - b);
        }
        public double module()
        {
            return Math.Sqrt(a * a + b * b);
        }
        public double angleRadians()//Возвращает аргумент fi самого комплексного числа q(в радианах).
        {//could be done like Math.Atan2(b, a); ?
            if (a > 0) return Math.Atan(b / a);
            else if (a == 0 && b > 0) return Math.PI / 2;
            else if (a < 0) return Math.Atan(b / a);
            else /*if (a == 0 && b < 0)*/ return -Math.PI / 2;
        }
        public double angleDegrees()
        {
            if (a > 0) return Math.Atan(b / a) * 57.29577951308;// 57.29577951308 - столько градусов в радиане
            else if (a == 0 && b > 0) return Math.PI / 2 * 57.29577951308;
            else if (a < 0) return Math.Atan(b / a) * 57.29577951308;
            else /*if (a == 0 && b < 0)*/ return -Math.PI / 2 * 57.29577951308;
        }

        public TComplex power(int n)//Степень. Возвращает целую положительную степень n самого комплексного числа q. 
                                    //q^n = r^n * (cos (n * fi) + i * sin (n * fi)).// https://math.semestr.ru/math/complex.php
        {
            double module = this.module();
            double modulePowered = Math.Pow(module, n);
            return new TComplex(modulePowered * Math.Cos(n * angleRadians()), modulePowered * Math.Sin(n * angleRadians()));
        }
        public TComplex root(int n, int i)//Возвращает i-ый корень целой положительной
                                          //степени n самого комплексного числа q. sqrt_^n(q) = sqrt_^n(r) * (cos ((fi + 2*k* pi)/n)+ i* sin((fi +2*k* pi)/n)). 
                                          //При этом коэфициенту k придается последовательно n значений: k = 0,1,2…, n - 1 и
                                          //получают n значений корня, т.е.ровно столько, каков показатель корня.

        //Корень n-й степени из всякого комплексного числа имеет n различных значений. Все они имеют одинаковые модули
        //https://www.fxyz.ru/%D1%84%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D1%8B_%D0%BF%D0%BE_%D0%BC%D0%B0%D1%82%D0%B5%D0%BC%D0%B0%D1%82%D0%B8%D0%BA%D0%B5/%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%B0/%D0%B8%D0%B7%D0%B2%D0%BB%D0%B5%D1%87%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BA%D0%BE%D1%80%D0%BD%D1%8F_%D0%B8%D0%B7_%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D0%BE%D0%B3%D0%BE_%D1%87%D0%B8%D1%81%D0%BB%D0%B0/

        {
            double modulePowered = Math.Pow(module(), 1d / n);//типа вычисляю таким образом корень модуля//получил корень энной степени из модуля
            double phase = (angleRadians() + 2 * Math.PI * i) / n;
            return new TComplex(modulePowered * Math.Cos(phase), modulePowered * Math.Sin(phase));
        }

        public bool isEqualTo_d(TComplex d)
        {
            if (a == d.getRealDouble() && b == d.getImaginaryDouble()) return true;
            else return false;
        }
        public bool isNotEqualTo_d(TComplex d)
        {
            if (a != d.getRealDouble() || b != d.getImaginaryDouble()) return true;
            else return false;
        }
        public string getRealString()
        {
            return a.ToString();
        }
        public string getImaginaryString()
        {
            return b.ToString();
        }
        public string ToString()
        {
            if (Math.Sign(b) == -1)
                return a + "-i*" + b * (-1);
            else if (Math.Sign(b) == 1)
                return a + "+i*" + b;
            else
                return a.ToString();
        }

    }
}
