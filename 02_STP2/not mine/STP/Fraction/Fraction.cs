using System;

public class Fraction
{
    public readonly long Numerator;
    public readonly long Denominator;

    public Fraction(long whole)
    {
        this.Numerator = whole;
        this.Denominator = 1;
    }

    public Fraction(long numerator, long denominator)
    {
        if (denominator == 0)
        {
            throw new ArgumentException("Attempted to set denominator to 0", nameof(denominator));
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

    public override string ToString()
    {
        if (Denominator == 1)
        {
            return Numerator.ToString();
        }
        return $"{Numerator}/{Denominator}";
    }

    public override int GetHashCode() => (Numerator, Denominator).GetHashCode();

    public override bool Equals(object obj)
    {
        if (obj is Fraction f)
        {
            return this.Numerator == f.Numerator && this.Denominator == f.Denominator;
        }
        return false;
    }
    // sqr, un minus, inver, +, -, *, /, >, ==
    public Fraction Squared => new Fraction(Numerator * Numerator, Denominator * Denominator);
    public Fraction Inverted => new Fraction(Denominator, Numerator);
    

    public static Fraction Parse(string s)
    {
        if (s == null)
        {
            throw new ArgumentNullException(nameof(s));
        }

        string[] parts = s.Split('/');
        if (parts.Length > 2)
        {
            const string msg = "Unable to parse the fraction string: more than one '/' symbol encountered";
            throw new FormatException(msg);
        }
        if (parts.Length == 1)
        {
            return long.Parse(parts[0].Trim());
        }
        return new Fraction(long.Parse(parts[0].Trim()), long.Parse(parts[1].Trim()));
    }

    public static implicit operator Fraction(long whole) => new Fraction(whole);

    public static explicit operator Fraction(string s) => Parse(s);

    public static bool operator ==(Fraction a, Fraction b) => a.Equals(b);
    public static bool operator !=(Fraction a, Fraction b) => !a.Equals(b);

    public static bool operator >(Fraction a, Fraction b)
    {
        return a.Numerator * b.Denominator > b.Numerator * a.Denominator;
    }

    public static bool operator >=(Fraction a, Fraction b) => a == b || a > b;
    public static bool operator <(Fraction a, Fraction b) => !(a >= b);
    public static bool operator <=(Fraction a, Fraction b) => !(a > b);

    public static Fraction operator -(Fraction f) => new Fraction(-f.Numerator, f.Denominator);


    public static Fraction operator +(Fraction a, Fraction b)
    {
        var num = a.Numerator * b.Denominator + a.Denominator * b.Numerator;
        var den = a.Denominator * b.Denominator;
        return new Fraction(num, den);
    }

    public static Fraction operator -(Fraction a, Fraction b)
    {
        var num = a.Numerator * b.Denominator - a.Denominator * b.Numerator;
        var den = a.Denominator * b.Denominator;
        return new Fraction(num, den);
    }

    public static Fraction operator *(Fraction a, Fraction b)
    {
        var num = a.Numerator * b.Numerator;
        var den = a.Denominator * b.Denominator;
        return new Fraction(num, den);
    }

    public static Fraction operator /(Fraction a, Fraction b)
    {
        return new Fraction(a, b);
    }

    private static long GetGCD(long a, long b)
    {
        a = Math.Abs(a);
        b = Math.Abs(b);
        while (b != 0)
            b = a % (a = b);
        return a;
    }
}