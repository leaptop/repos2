using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_05_ComplexNumber;
namespace STP_09_TEditor_ComplexNumbers
{
   public class TEditorForComplexNumbers
    {
        static void Main(string[] args)
        {
            TComplex tc = new TComplex("12+i*3");
            string im = tc.getImaginaryString();
            string re = tc.getRealString();
            Console.WriteLine("tc.ToString() = " + tc.ToString() + ", re = " + re + ", im = " + im);
            Console.ReadLine();
        }
        public TComplex addADigit(TComplex tc, int index, int digit)
        {
            string str = tc.ToString();
            str = str.Insert(index, digit.ToString());
            return new TComplex(str);
        }
        public TComplex change_a_and_b_signsByMultiplyingThemByMinusOne(TComplex tc, int forA, int forB)//forA and forB have to be either 1 or -1
        {
            if ((forA != 1 && forA != -1) || (forB != 1 && forB != -1))
            {
                throw new WrongInputException();
            }
            double a = tc.getRealDouble() * (double)forA;
            double b = tc.getImaginaryDouble() * (double)forB;
            return new TComplex(a, b);
        }
        public TComplex shiftFloatingPointOf_re_or_im(TComplex tc, int newIndexOfCommaforA, int newIndexOfCommaForB)
        {
            string a = tc.getRealString();
            string b = tc.getImaginaryString();
            if (a.Contains(","))
            {
                int ind = a.IndexOf(",");
                a = a.Remove(ind, 1);
            }
            a = a.Insert(newIndexOfCommaforA, ",");
            if (b.Contains(","))
            {
                int ind = b.IndexOf(",");
                b = b.Remove(ind, 1);
            }
            b = b.Insert(newIndexOfCommaForB, ",");
            double aDouble = Double.Parse(a);
            double bDouble = Double.Parse(b);
            return new TComplex(aDouble, bDouble);
        }
        public string backspace(TComplex tc)
        {
           return tc.ToString().Substring(0, tc.ToString().Length - 1);
        }
        public TComplex Clear(TComplex tc)
        {
            return new TComplex(0, 0);
        }
        public string getStringOfTComplex(TComplex tc)
        {
            return tc.ToString();
        }


    }
    public class WrongInputException : Exception
    {
        public WrongInputException()
        {
            Console.WriteLine("wrong input");
        }
    }
}
