using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_04_ADT_TFrac;
namespace STP_08_TEditorForCommonFraction
{
    public class TEditorForCommonFraction
    {
        static void Main(string[] args)
        {
            TEditorForCommonFraction te = new TEditorForCommonFraction();
            TFrac tf2 = new TFrac(49, 3);
            Console.WriteLine("tf2.f = " + tf2.f);
            te.addADelimeterBetweenNumeratorAndDenominator(tf2, 1);
            Console.WriteLine("tf2.f = " + tf2.f);
            te.Clear(ref tf2);
            Console.WriteLine("tf2.f = " + tf2.f);
            tf2 = new TFrac(507, 7);
            te.addADigit(ref tf2, 5, 0);
            Console.WriteLine("tf2.f = " + tf2.f);
            tf2 = te.multiplyByMinus(tf2);
            Console.WriteLine("tf2.f = " + tf2.f);
            Console.ReadLine();
        }
        //в дробь добавляю цифру digit.

        public string addADigit(ref TFrac tf, int digit, int index)
        {
            tf.f = tf.f.Insert(index, digit.ToString());
            return tf.f;
        }
        public TFrac multiplyByMinus(TFrac tf)
        {
            return new TFrac(tf.numerator * (-1), tf.denominator);
        }
        public void addADelimeterBetweenNumeratorAndDenominator(TFrac tf, int index)
        {//В общем перемещает слеш по новому индексу, а если его не было, то просто устанавливает
            if (tf.f.Contains("/"))
            {
                int ind = tf.f.IndexOf("/");
                tf.f = tf.f.Remove(ind, 1);
            }
            tf.f = tf.f.Insert(index, "/");
        }
        public void backSpace(TFrac tf)
        {
            tf.f = tf.f.Remove(tf.f.Length - 1, 1);
        }
        public void Clear(ref TFrac tf)
        {
            if(tf == null)
            {
                throw new WrongInputException();
            }
            /* tf.numerator = 0;
             tf.denominator = 1;
             tf.f = "0/1";*/
            tf = new TFrac(0, 1);
        }
        public string readFractionString(TFrac tf)
        {
            return tf.f;
        }
        public void writeNewFToFraction(ref TFrac tf, string newFR)
        {
            tf = new TFrac(newFR);
        }

    }
    public class WrongInputException : Exception
    {        public WrongInputException()
        {
            Console.WriteLine("wrong input");
        }
    }
}
