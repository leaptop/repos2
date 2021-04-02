using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using Numbers;

namespace Editors
{
    public class ComplexEditor : IEditor<Complex>
    {
        private static readonly string DefaultValue = "0";
        private static readonly Regex ReLeadingZerosPattern = new Regex(@"^(-?)(0*)(\d+)");
        private static readonly Regex ImLeadingZerosPattern 
            = new Regex(@$"({Regex.Escape(Complex.ImDelimiter)}-?)(0*)(\d+)");

        private string value = DefaultValue;

        public string Value
        {
            get => value;
            set
            {
                Complex.AssertValidFormat(value);
                this.value = RemoveLeadingZeros(value);
            }
        }

        public Complex ValueAsNumber
        {
            get => Complex.Parse(value);
            set => this.value = value.ToString();
        }

        public bool IsZero => value == DefaultValue;

        public string AddDigit(int digit)
        {
            if (digit < 0 || digit > 9)
            {
                throw new ArgumentOutOfRangeException(nameof(digit), digit, "Invalid digit");
            }

            value += (char)(digit + '0');
            value = RemoveLeadingZeros(value);
            return value;
        }

        public string ToggleReSign()
        {
            if (value[0] == '-')
            {
                value = value.Substring(1);
            }
            else
            {
                value = '-' + value;
            }
            return value;
        }

        public string ToggleImSign()
        {
            int i = value.IndexOf(Complex.ImDelimiter);
            if (i == -1)
            {
                return value;
            }

            i += Complex.ImDelimiter.Length;
            if (value.Length == i || value[i] != '-')
            {
                if (value.Length == i)
                    value += "0";

                value = value.Insert(i, "-");
            }
            else
            {
                value = value.Remove(i, 1);
            }
            return value;
        }

        public string AddDecimalSeparator()
        {
            int i = value.IndexOf(Complex.ImDelimiter);
            if (i != -1)
            {
                string imPart = value.Substring(i + Complex.ImDelimiter.Length);
                if (!imPart.Contains(Complex.DecimalSeparator))
                {
                    if (imPart.Length == 0)
                        value += "0";

                    value += Complex.DecimalSeparator;
                }
            }
            else
            {
                if (!value.Contains(Complex.DecimalSeparator))
                {
                    value += Complex.DecimalSeparator;
                }
            }
            return value;
        }

        public string AddImDelimiter()
        {
            if (!value.Contains(Complex.ImDelimiter))
            {
                value += Complex.ImDelimiter;
            }
            return value;
        }

        public string Backspace()
        {
            int nCharsToRemove = 1;
            if (value.EndsWith(Complex.ImDelimiter))
            {
                nCharsToRemove = Complex.ImDelimiter.Length;
            }
            else if (value.EndsWith(Complex.DecimalSeparator))
            {
                nCharsToRemove = Complex.DecimalSeparator.Length;
            }

            value = value.Remove(value.Length - nCharsToRemove);

            if (value.Length == 0 || value == "-")
            {
                return value = DefaultValue;
            }
            else if (value.EndsWith("-"))
            {
                return Backspace();
            }

            return value;
        }

        public string Clear()
        {
            return value = DefaultValue;
        }


        private static string RemoveLeadingZeros(string s)
        {
            string t = ReLeadingZerosPattern.Replace(s, "$1$3");
            t = ImLeadingZerosPattern.Replace(t, "$1$3");
            return t;
        }
    }
}
