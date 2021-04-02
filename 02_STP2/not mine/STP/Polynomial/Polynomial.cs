using System;
using System.Linq;
using System.Collections.Generic;

namespace Polynomials
{
    public class Polynomial
    {
        private SortedDictionary<int, int> coefficients;

        public int Count => coefficients.Count;

        public int Degree
        {
            get
            {
                // Loop goes in degree descending order cuz the dictionary is sorted
                foreach (var pair in coefficients)
                {
                    int coefficient = pair.Value;
                    if (coefficient != 0)
                    {
                        int degree = pair.Key;
                        return degree;
                    }
                }
                return 0;
            }
        }

        public Polynomial Negate
        {
            get
            {
                var result = new Polynomial();
                foreach (var pair in coefficients)
                {
                    int degree = pair.Key;
                    int coefficient = pair.Value;
                    result[degree] = -coefficient;
                }
                return result;
            }
        }

        public Polynomial Derivative
        {
            get
            {
                var result = new Polynomial();
                foreach (var pair in coefficients)
                {
                    int degree = pair.Key;
                    if (degree != 0)
                    {
                        int coefficient = pair.Value;
                        result[degree - 1] = coefficient * degree;
                    }
                }
                return result;
            }
        }

        public int this[int degree]
        {
            get
            {
                if (degree < 0)
                {
                    throw new ArgumentOutOfRangeException("Degree cannot be negative");
                }
                return coefficients.GetValueOrDefault(degree, defaultValue: 0);
            }
            set {
                if (degree < 0) 
                {
                    throw new ArgumentOutOfRangeException("Degree cannot be negative");
                }
                if (value == 0)
                {
                    coefficients.Remove(degree);
                }
                else
                {
                    coefficients[degree] = value;
                }
            }
        }


        public Polynomial()
        {
            var descComparer = Comparer<int>.Create((x, y) => y.CompareTo(x));
            coefficients = new SortedDictionary<int, int>(descComparer);
        }

        public Polynomial(int coefficient, int degree)
            : this()
        {
            this[degree] = coefficient;
        }

        public void Clear()
        {
            coefficients.Clear();
        }

        public Polynomial Add(Polynomial other)
        {
            var resultDegrees = this.coefficients.Keys.Union(other.coefficients.Keys);
            var result = new Polynomial();
            foreach (var degree in resultDegrees)
            {
                result[degree] = this[degree] + other[degree];
            }
            return result;
        }

        public Polynomial Subtract(Polynomial other)
        {
            var resultDegrees = this.coefficients.Keys.Union(other.coefficients.Keys);
            var result = new Polynomial();
            foreach (var degree in resultDegrees)
            {
                result[degree] = this[degree] - other[degree];
            }
            return result;
        }

        public Polynomial Multiply(Polynomial other)
        {
            var result = new Polynomial();
            foreach (var thisPair in this.coefficients)
            {
                foreach (var thatPair in other.coefficients)
                {
                    int degree = thisPair.Key + thatPair.Key;
                    int coefficient = thisPair.Value * thatPair.Value;
                    result[degree] += coefficient;
                }
            }
            return result;
        }

        public double Evaluate(double x)
        {
            double result = 0;
            foreach (var pair in coefficients)
            {
                int degree = pair.Key;
                int coefficient = pair.Value;
                result += coefficient * Math.Pow(x, degree);
            }
            return result;
        }

        public override bool Equals(object obj)
        {
            if (!(obj is Polynomial other))
            {
                return false;
            }
            var degrees = this.coefficients.Keys.Union(other.coefficients.Keys);
            return degrees.All(degree => this[degree] == other[degree]);
        }

        public override string ToString()
        {
            var members = coefficients.Select(MemberToString);
            return string.Join(" + ", members);
        }

        private static string MemberToString(KeyValuePair<int, int> pair)
        {
            int degree = pair.Key;
            int coefficient = pair.Value;
            if (degree == 0)
            {
                return coefficient.ToString();
            }
            if (degree == 1)
            {
                return $"{coefficient}x";
            }
            if (coefficient == 1)
            {
                return $"x^{degree}";
            }
            return $"{coefficient}x^{degree}";
        }
    }
}
