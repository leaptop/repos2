using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public struct Complex
{
    public double Re { get; set; }
    public double Im { get; set; }

    public static readonly Complex I = new Complex(0, 1);

    public Complex(double re, double im)
    {
        Re = re;
        Im = im;
    }

    public Complex Squared => this * this;

    public Complex Inverted => new Complex(Re, -Im) / (Re * Re + Im * Im);

    public double Magnitude => Math.Sqrt(Re * Re + Im * Im);

    public double Phase => Math.Atan2(Im, Re);

    public override string ToString() => $"{Re} + i*{Im}";

    public static Complex Parse(string s)
    {
        if (s == null)
        {
            throw new ArgumentNullException(nameof(s));
        }
            
        string[] reAndImParts = s.Split('+');
        if (reAndImParts.Length != 2)
        {
            const string msg = "Failed to parse the complex string: " +
                "there must be exactly one '+' char in the string";
            throw new FormatException(msg);
        }
        string reStr = reAndImParts[0];
        string imStr = reAndImParts[1];

        int iStarIdx = imStr.IndexOf("i*");
        if (iStarIdx < 0)
        {
            throw new FormatException("Failed to parse the complex string: no 'i*' part found");
        }
        imStr = imStr.Substring(iStarIdx + 2);

        double re = double.Parse(reStr.Trim());
        double im = double.Parse(imStr.Trim());

        return new Complex(re, im);
    }

    public static Complex Pow(Complex c, int power)
    {
        double magnitude = Math.Pow(c.Magnitude, power);
        double phase = c.Phase * power;
        return magnitude * new Complex(Math.Cos(phase), Math.Sin(phase));
    }

    public static Complex Root(Complex c, int degree, int k)
    {
        double magnitude = Math.Pow(c.Magnitude, 1d / degree);
        double phase = (c.Phase + 2 * Math.PI * k) / degree;
        return magnitude * new Complex(Math.Cos(phase), Math.Sin(phase));
    }

    public override bool Equals(object obj)
    {
        return obj is Complex c && (this == c);
    }

    public override int GetHashCode() => (Re, Im).GetHashCode();

    public static implicit operator Complex(double d) => new Complex(d, 0);

    public static bool operator ==(Complex a, Complex b) => a.Re == b.Re && a.Im == b.Im;
    public static bool operator !=(Complex a, Complex b) => !(a == b);

    public static Complex operator +(Complex a, Complex b) => new Complex(a.Re + b.Re, a.Im + b.Im);
    public static Complex operator -(Complex c) => new Complex(-c.Re, -c.Im);
    public static Complex operator -(Complex a, Complex b) => a + -b;
    public static Complex operator *(double d, Complex c) => new Complex(d * c.Re, d * c.Im);
    public static Complex operator *(Complex c, double d) => d * c;
    public static Complex operator *(Complex a, Complex b) => 
        new Complex(a.Re * b.Re - a.Im * b.Im, a.Re * b.Im + a.Im * b.Re);
    public static Complex operator /(Complex c, double d) => new Complex(c.Re / d, c.Im / d);
    public static Complex operator /(Complex a, Complex b) => a * b.Inverted;
}

class Program
{
    static void Main(string[] args)
    {

    }
}