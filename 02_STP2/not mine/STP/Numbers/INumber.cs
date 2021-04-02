using System;
using System.Collections.Generic;
using System.Text;

namespace Numbers
{
    public interface IFormattableNumber
    {
        string ToStringFormatted(IFormatSettings format);
    }

    public interface INumber<T> : IFormattableNumber, IEquatable<T> where T : new()
    {
        T Squared { get; }
        T Inverted { get; }
        T Negated { get; }

        T Add(T other);
        T Subtract(T other);
        T Multiply(T other);
        T Divide(T other);
    }

    public interface IComparableNumber<T> : INumber<T>, IComparable<T> where T : new()
    {
    }
}
