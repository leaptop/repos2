using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace Numbers
{
    [Serializable]
    public class PNumber : INumber<PNumber>
    {
        private const int InversionResultMinFracDigits = 10;

        public const string DigitChars = "0123456789ABCDEF";
        public static readonly string DecimalSeparator =
            CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator;


        public readonly double Number;
        public readonly int Base;
        public readonly int FractionalDigits;

        private string str = null;

        public PNumber() : this(0, 10, 0)
        {
        }

        public PNumber(double number, int @base, int numFracDigits)
        {
            AssertValidBase(@base);
            if (numFracDigits < 0)
            {
                const string msg = "The number of fractional digits cannot be negative";
                throw new ArgumentOutOfRangeException(nameof(numFracDigits), numFracDigits, msg);
            }

            Number = number;
            Base = @base;
            FractionalDigits = numFracDigits;
        }

        public PNumber Squared => new PNumber(Number * Number, Base, FractionalDigits);

        public PNumber Inverted => 
            new PNumber(1.0 / Number, Base, Math.Max(FractionalDigits, InversionResultMinFracDigits));

        public PNumber Negated => new PNumber(-Number, Base, FractionalDigits);

        public PNumber Add(PNumber other)
        {
            AssertBasesAreSame(other);
            int fracDigits = Math.Max(FractionalDigits, other.FractionalDigits);
            return new PNumber(this.Number + other.Number, Base, fracDigits);
        }

        public PNumber Subtract(PNumber other)
        {
            AssertBasesAreSame(other);
            int fracDigits = Math.Max(FractionalDigits, other.FractionalDigits);
            return new PNumber(this.Number - other.Number, Base, fracDigits);
        }

        public PNumber Multiply(PNumber other)
        {
            AssertBasesAreSame(other);
            int fracDigits = Math.Max(FractionalDigits, other.FractionalDigits);
            return new PNumber(this.Number * other.Number, Base, fracDigits);

        }

        public PNumber Divide(PNumber other)
        {
            AssertBasesAreSame(other);
            int fracDigits = Math.Max(FractionalDigits, other.FractionalDigits);
            return new PNumber(this.Number / other.Number, Base, fracDigits);
        }

        public override bool Equals(object obj)
        {
            return obj != null && obj is PNumber other ? this.Equals(other) : false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Number, Base, FractionalDigits);
        }

        public bool Equals(PNumber other)
        {
            return other != null &&
                this.Number == other.Number &&
                this.Base == other.Base &&
                this.FractionalDigits == other.FractionalDigits;
        }

        public string ToStringFormatted(IFormatSettings format) => ToString();

        public override string ToString() => str ??= NonLazyToString();

        public static void AssertValidBase(int @base)
        {
            if (@base < 2 || @base > 16)
            {
                const string msg = "The base must be in range [2; 16]";
                throw new ArgumentOutOfRangeException(nameof(@base), @base, msg);
            }
        }

        public static void AssertValidFormat(string s, int @base)
        {
            if (s == null)
            {
                throw new ArgumentNullException(nameof(s));
            }

            string validDigits = DigitChars.Substring(0, @base);
            string sep = Regex.Escape(DecimalSeparator);
            var regex = new Regex(@$"^-?[{validDigits}]+{sep}?[{validDigits}]*$");
            if (!regex.IsMatch(s))
            {
                throw new FormatException("Input string was not in correct format.");
            }
        }
        
        public static PNumber Parse(string s, int @base)
        {
            if (@base < 2 || @base > 16)
            {
                const string msg = "The base must be in range [2; 16]";
                throw new ArgumentOutOfRangeException(nameof(@base), @base, msg);
            }
            AssertValidFormat(s, @base);

            bool isNegative = false;
            if (s[0] == '-')
            {
                s = s.Substring(1);
                isNegative = true;
            }

            string[] parts = s.Split(DecimalSeparator);

            string wholeStr = parts[0];
            double result = ParseWhole(wholeStr, @base);

            int numFracDigits = 0;
            bool noFractional = parts.Length == 1 || parts[1].Length == 0;
            if (!noFractional)
            {
                string fracStr = parts[1];
                numFracDigits = fracStr.Length;
                result += ParseFractional(fracStr, @base);
            }

            if (isNegative) {
                result = -result;
            }

            return new PNumber(result, @base, numFracDigits);
        }

        private string NonLazyToString()
        {
            var sb = new StringBuilder();

            if (Number < 0)
            {
                sb.Append('-');
            }

            sb.Append(DigitsToString(GetWholeDigits()));

            if (FractionalDigits > 0)
            {
                sb.Append(DecimalSeparator);
                sb.Append(DigitsToString(GetFractionalDigits()));
            }

            return sb.ToString();
        }

        private byte[] GetWholeDigits()
        {
            double x = Math.Abs(Number);
            x = Math.Truncate(x);
            var digits = new Stack<byte>();
            do
            {
                double div = Math.Truncate(x / Base);
                double rem = x - div * Base;
                digits.Push(Convert.ToByte(rem));
                x = div;
            } while (x > 0);
            return digits.ToArray();
        }

        private byte[] GetFractionalDigits()
        {
            double x = Math.Abs(Number);
            x = x - Math.Truncate(x);
            var digits = new byte[FractionalDigits];
            for (int i = 0; i < FractionalDigits; i++)
            {
                x *= Base;
                double whole = Math.Truncate(x);
                digits[i] = Convert.ToByte(whole);
                x -= whole;
            }
            return digits;
        }

        private void AssertBasesAreSame(PNumber other)
        {
            if (this.Base != other.Base)
            {
                throw new ArgumentException("The bases must be equal " +
                    $"(this = {this.Base}, that = {other.Base})");
            }
        }

        private static string DigitsToString(byte[] digits)
        {
            return string.Concat(digits.Select(x => DigitChars[x]));
        }

        private static double ParseWhole(string s, int @base)
        {
            double result = 0;
            double e = 1;
            for (int i = s.Length - 1; i >= 0; i--)
            {
                int digit = DigitChars.IndexOf(s[i]);
                result += digit * e;
                e *= @base;
            }
            return result;
        }

        private static double ParseFractional(string s, int @base)
        {
            if (s.Length == 0)
            {
                return 0;
            }

            double result = 0;
            double e = 1;
            for (int i = 0; i < s.Length; i++)
            {
                int digit = DigitChars.IndexOf(s[i]);
                e /= @base;
                result += digit * e;
            }
            return result;
        }
    }
}
