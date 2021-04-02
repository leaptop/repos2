using System;
using System.Diagnostics.CodeAnalysis;
using System.Text.RegularExpressions;

namespace Numbers
{
    [Serializable]
    public class Fraction : IComparableNumber<Fraction>
    {
        private static readonly Regex Pattern = new Regex(@"^-?\d+/?\d*");

        public readonly long Numerator;
        public readonly long Denominator;

        public Fraction()
        {
            Numerator = 0;
            Denominator = 1;
        }

        public Fraction(long whole)
        {
            Numerator = whole;
            Denominator = 1;
        }

        public Fraction(long numerator, long denominator)
        {
            if (denominator == 0)
            {
                throw new ArgumentException("Denominator must not be zero", nameof(denominator));
            }
            if (denominator < 0)
            {
                numerator = -numerator;
                denominator = -denominator;
            }
            var gcd = GetGCD(numerator, denominator);
            this.Numerator = numerator / gcd;
            this.Denominator = denominator / gcd;
        }

        public Fraction(Fraction numerator, Fraction denominator)
            : this(numerator.Numerator * denominator.Denominator,
                  numerator.Denominator * denominator.Numerator)
        {
        }


        public Fraction Squared => new Fraction(Numerator * Numerator, Denominator * Denominator);

        public Fraction Inverted => new Fraction(Denominator, Numerator);

        public Fraction Negated => new Fraction(-Numerator, Denominator);

        public Fraction Add(Fraction other)
        {
            var num = this.Numerator * other.Denominator + this.Denominator * other.Numerator;
            var den = this.Denominator * other.Denominator;
            return new Fraction(num, den);
        }

        public Fraction Subtract(Fraction other)
        {
            var num = this.Numerator * other.Denominator - this.Denominator * other.Numerator;
            var den = this.Denominator * other.Denominator;
            return new Fraction(num, den);
        }

        public Fraction Multiply(Fraction other)
        {
            var num = this.Numerator * other.Numerator;
            var den = this.Denominator * other.Denominator;
            return new Fraction(num, den);
        }

        public Fraction Divide(Fraction other)
        {
            return new Fraction(this, other);
        }

        public override bool Equals(object obj)
        {
            return obj != null && obj is Fraction other ? this.Equals(other) : false;
        }

        public bool Equals(Fraction other)
        {
            if (other == null)
            {
                return false;
            }
            return this.Numerator == other.Numerator && this.Denominator == other.Denominator;
        }

        public int CompareTo([AllowNull] Fraction other)
        {
            if (other == null)
            {
                throw new ArgumentNullException(nameof(other));
            }
            return (this.Numerator * other.Denominator).CompareTo(other.Numerator * this.Denominator);
        }

        public override int GetHashCode() => (Numerator, Denominator).GetHashCode();

        public string ToStringFormatted(IFormatSettings format)
        {
            if (format.OmitFractionDenominatorOfOne && Denominator == 1)
            {
                return Numerator.ToString();
            }
            return ToString();
        }

        public override string ToString() => $"{Numerator}/{Denominator}";

        // sqr, un minus, inver, +, -, *, /, >, ==

        public static void AssertValidFormat(string s)
        {
            if (s == null)
            {
                throw new ArgumentNullException(nameof(s));
            }

            if (!Pattern.IsMatch(s))
            {
                throw new FormatException("Input string was not in correct format.");
            }
        }

        public static Fraction Parse(string s)
        {
            AssertValidFormat(s);

            string[] parts = s.Split('/');

            bool noDenominator = parts.Length == 1 || parts[1].Length == 0;
            if (noDenominator)
            {
                return new Fraction(long.Parse(parts[0]));
            }

            long numerator = long.Parse(parts[0]);
            long denominator = long.Parse(parts[1]);
            return new Fraction(numerator, denominator);
        }
        
        public static implicit operator Fraction(long whole) => new Fraction(whole);

        private static long GetGCD(long a, long b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            while (b != 0)
                b = a % (a = b);
            return a;
        }
    }
}