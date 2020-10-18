using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_06_TPNumber;
namespace STP_07TEditor
{
    public class TEditor
    {
        public TEditor()
        {

        }
        static void Main(string[] args)
        {
            TPNumber tp = new TPNumber(546.164, 16, 7);
            Console.WriteLine("tp.n = " + tp.n);
            TEditor te = new TEditor();
            te.multiplyByMinus(tp);
            te.addADigitOrALetter(tp, "B", 3);
            Console.WriteLine("tp.n = " + tp.n);

            TPNumber tp1 = new TPNumber("0,0", 3, 7);
            Console.WriteLine("tp1.n = " + tp1.n);
            Console.ReadLine();
        }
        public void addADigitOrALetter(TPNumber tp, string newElement, int position)
        {
            if (tp.alphabet.Contains(newElement))
                tp.n = tp.n.Insert(position, newElement);
            else
            {
                Console.WriteLine("The newElement is not in the alphabet of the number");
                throw new WrongInput();
            }
        }
        public void multiplyByMinus(TPNumber tp)
        {
            if (tp.n.Substring(0, 1) == "-")
                tp.n = tp.n.Substring(1);//если уже стоит минус, то убираем его
            else
            {
                tp.n = "-" + tp.n;
            }
        }
        public void addADelimeterOfIntAndFrac(TPNumber tp, int index)
        {
            int ind = tp.n.IndexOf(",");
            tp.n = tp.n.Remove(ind, 1);
            tp.n = tp.n.Insert(index, ",");
        }
        public void backSpace(TPNumber tp)
        {
            tp.n = tp.n.Remove(tp.n.Length - 1, 1);
        }
        public void Clear(TPNumber tp)
        {
            tp.n = "0,0";
        }
        public string get_nString(TPNumber tp)
        {
            return tp.getn();
        }
        public void set_nString(TPNumber tp, string newN)
        {
            tp.n = newN;
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

