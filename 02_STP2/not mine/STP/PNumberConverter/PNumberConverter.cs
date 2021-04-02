using System;
using System.Collections.Generic;
using System.Text;
using Numbers;

namespace Lab1
{
    public static class PNumberConverter
    {
        public static PNumber ToAnotherBase(PNumber number, int toBase)
        {
            double decimalValue = PNumberToDecimal(number);
            int destFracDigits = ResultingFracDigits(number.FractionalDigits, number.Base, toBase);
            return DecimalToPNumber(decimalValue, toBase, destFracDigits);
        }

        private static double PNumberToDecimal(PNumber number) 
            => number.Number;

        private static PNumber DecimalToPNumber(double number, int @base, int numFracDigits)
            => new PNumber(number, @base, numFracDigits);

        private static int ResultingFracDigits(
            int srcNumFracDigits,
            int srcBase,
            int destBase
        )
            => (int)Math.Ceiling(srcNumFracDigits * Math.Log(srcBase, destBase));
    }
}
