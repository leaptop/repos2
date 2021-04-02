using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Numbers
{
    [Serializable]
    public struct Complex : INumber<Complex>
    {
        private static readonly Regex Pattern;

        static Complex()
        {
            var sep = Regex.Escape(DecimalSeparator);
            var num = $@"-?\d+({sep})?\d*";
            var imDelim = Regex.Escape(ImDelimiter);
            Pattern = new Regex($@"^{num}({imDelim}({num})?)?$");
        }

        public static readonly Complex I = new Complex(0, 1);

        public static readonly string DecimalSeparator =
               CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator;

        public static readonly string ImDelimiter = " + i* ";

        public double Re { get; set; }
        public double Im { get; set; }

        public Complex(double re) : this(re, 0) { }

        public Complex(double re, double im)
        {
            Re = re;
            Im = im;
        }

        public Complex Squared => this.Multiply(this);

        public Complex Inverted => new Complex(Re, -Im) / (Re * Re + Im * Im);

        public Complex Negated => new Complex(-Re, -Im);

        public double Magnitude => Math.Sqrt(Re * Re + Im * Im);

        public double Phase => Math.Atan2(Im, Re);


        public Complex Pow(int power)
        {
            double magnitude = Math.Pow(Magnitude, power);
            double phase = Phase * power;
            return magnitude * new Complex(Math.Cos(phase), Math.Sin(phase));
        }

        public Complex Root(int degree, int k)
        {
            if (degree == 0)
            {
                throw new ArgumentException("Degree cannot be zero");
            }
            double magnitude = Math.Pow(Magnitude, 1d / degree);
            double phase = (Phase + 2 * Math.PI * k) / degree;
            return magnitude * new Complex(Math.Cos(phase), Math.Sin(phase));
        }

        public Complex[] AllRoots(int degree)
        {
            if (degree == 0)
            {
                throw new ArgumentException("Degree cannot be zero");
            }

            int numRoots = Math.Abs(degree);
            var roots = new Complex[numRoots];
            for (int k = 0; k < numRoots; k++)
            {
                roots[k] = this.Root(degree, k);
            }
            return roots;
        }

        public override int GetHashCode() => (Re, Im).GetHashCode();

        public Complex Add(Complex other) => new Complex(this.Re + other.Re, this.Im + other.Im);

        public Complex Subtract(Complex other) => new Complex(this.Re - other.Re, this.Im - other.Im);

        public Complex Multiply(Complex other) =>
            new Complex(this.Re * other.Re - this.Im * other.Im, 
                        this.Re * other.Im + this.Im * other.Re);

        public Complex Divide(Complex other) => this.Multiply(other.Inverted);


        public override bool Equals(object obj)
        {
            return obj != null && obj is Complex other ? this.Equals(other) : false;
        }

        public bool Equals(Complex other)
        {
            return this.Re == other.Re && this.Im == other.Im;
        }
        public string ToStringFormatted(IFormatSettings format)
        {
            if (format.OmitComplexImPartOfZero && Im == 0)
            {
                return Re.ToString();
            }
            return ToString();
        }

        public override string ToString() => $"{Re:0.#########}{ImDelimiter}{Im:0.#########}";

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

        public static Complex Parse(string s)
        {
            AssertValidFormat(s);

            string[] parts = s.Split(ImDelimiter);

            bool noImPart = parts.Length == 1 || parts[1].Length == 0;
            if (noImPart)
            {
                return new Complex(double.Parse(parts[0]));
            }

            double re = double.Parse(parts[0]);
            double im = double.Parse(parts[1]);
            return new Complex(re, im);
        }

        public static implicit operator Complex(double d) => new Complex(d);
        public static Complex operator *(double d, Complex c) => new Complex(d * c.Re, d * c.Im);
        public static Complex operator *(Complex c, double d) => d * c;
        public static Complex operator /(Complex c, double d) => new Complex(c.Re / d, c.Im / d);
    }
}