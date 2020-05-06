﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CW3
{
    public class Drob : ICloneable
    {
        
        public int numerator;//chislitel
        public int denominator;//znamenatel

        //public Drob()
        //{// it would be difficult to implement some actions like addition for example. So such default constructor is undesirable.
        //    this.numerator = 0;
        //    this.denominator = 1;
        //}
        public Drob(int numerator, int denominator)
        {
            if (numerator < 0 && denominator < 0)//сокращаю минусы в числителе и знаменталел
            {
                numerator *= -1;
                denominator *= -1;
            }
            if(denominator < 0)//переношу минус из знаменателя в числитель
            {
                numerator *= -1;
                denominator *= -1;
            }
                if (denominator != 0)
            {
                int t = GCD(numerator, denominator);
                this.numerator = numerator / t;
                this.denominator = denominator / t;
            }
            else
            {
                this.numerator = numerator;
                this.denominator = denominator;
            }
            if (numerator == 0) denominator = 0;
            if (denominator == 0) numerator = 0;

        }
        public Drob mul(Drob a, Drob b)//this fun returns a result of multiplication of сommon fractions a & b
        {
            return new Drob(a.numerator * b.numerator, a.denominator * b.denominator);
        }
        public void printDrob()//in console
        {
            Console.WriteLine(numerator + "/" + denominator);
        }
        public void test()
        {
            Drob d1 = new Drob(1, 2);
            Drob d2 = new Drob(1, 3);
            Drob d3;
            Drob d4;
            d3 = mul(d1, d2);
            d3.printDrob();
            d4 = add(d1, d2);
            d4.printDrob();
        }
        public String toStr()
        {
            if (denominator == 0 && numerator != 0) return Double.PositiveInfinity.ToString();
            else
            if (numerator == 0) return "0";
            else
            if (denominator == 1) return (numerator.ToString());
            else
                return (numerator.ToString() + "/" + denominator.ToString());
        }
        public Drob div(Drob a, Drob b)//divides a by b
        {
            //return new Drob(a.numerator * b.denominator, a.denominator * b.numerator);
            return mul(a, new Drob(b.denominator, b.numerator));
        }
        public Drob add(Drob a, Drob b)
        {
            if (a.denominator == 0 || b.denominator == 0)
            {
                if (a.denominator != 0)
                {
                    return new Drob(a.numerator, a.denominator);
                }
                else
                    return new Drob(b.numerator, b.denominator);
            }
            int multiplierA = 1;
            int multiplierB = 1;
            int newDenominator = 1;
            if ((a.denominator != b.denominator))//if denominators aren't equal, we need to find Least(lowest) common multiple (наимееьшее общее кратное)
            {
                if (a.denominator != 0 && b.denominator != 0)
                {
                    newDenominator = LCM(a.denominator, b.denominator);
                    multiplierA = newDenominator / a.denominator;//нашёл во сколько раз надо увеличить числитель a
                    multiplierB = newDenominator / b.denominator;//нашёл во сколько раз надо увеличить числитель b                    
                }
            }
            else newDenominator = a.denominator;
            return new Drob(a.numerator * multiplierA + b.numerator * multiplierB, newDenominator);
        }
        public Drob sub(Drob a, Drob b)
        {
            if (a.denominator == 0 || b.denominator == 0)
            {
                if (a.denominator != 0)
                {
                    return new Drob(a.numerator, a.denominator);
                }
                else
                    return new Drob(-b.numerator, b.denominator);
            }
            int multiplierA = 1;
            int multiplierB = 1;
            int newDenominator = 1;
            if ((a.denominator != b.denominator))//if denominators aren't equal, we need to find Least(lowest) common multiple (наимееьшее общее кратное)
            {
                if (a.denominator != 0 && b.denominator != 0)
                {
                    newDenominator = LCM(a.denominator, b.denominator);
                    multiplierA = newDenominator / a.denominator;//нашёл во сколько раз надо увеличить числитель a
                    multiplierB = newDenominator / b.denominator;//нашёл во сколько раз надо увеличить числитель b                   
                }
            }
            else newDenominator = a.denominator;
            return new Drob(a.numerator * multiplierA - b.numerator * multiplierB, newDenominator);
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
        public object Clone()
        {
            // return new Drob(numerator, denominator) { numerator = this.numerator, denominator = this.denominator };
            return this.MemberwiseClone();
        }

    }
}
