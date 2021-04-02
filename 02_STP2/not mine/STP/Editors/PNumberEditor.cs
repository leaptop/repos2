using System;
using System.Text.RegularExpressions;
using Numbers;

namespace Editors
{
    public class PNumberEditor : IEditor<PNumber>
    {
        private static readonly Regex LeadingZerosPattern = new Regex(@"^(-?)(0*)([\dA-F]+)");
        private static readonly string DefaultValue = "0";

        private string value = DefaultValue;

        public readonly int Base;

        public string Value
        {
            get => value;
            set
            {
                PNumber.AssertValidFormat(value, Base);
                this.value = RemoveLeadingZeros(value);
            }
        }

        public PNumber ValueAsNumber
        {
            get => PNumber.Parse(Value, Base);
            set => this.value = value.ToString();
        }

        public bool IsZero => value == DefaultValue;

        public PNumberEditor(int @base)
        {
            PNumber.AssertValidBase(@base);
            Base = @base;
        }

        public string ToggleSign()
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

        public string AddDigit(int digit)
        {
            if (digit < 0)
            {
                throw new ArgumentOutOfRangeException(nameof(digit), digit, "Digit cannot be negative");
            }
            if (digit >= Base)
            {
                string msg = $"Illegal digit for a number of base {Base}";
                throw new ArgumentOutOfRangeException(nameof(digit), digit, msg);
            }

            value += PNumber.DigitChars[digit];
            value = RemoveLeadingZeros(value);
            return value;
        }

        public string AddDecimalSeparator()
        {
            if (!value.Contains(PNumber.DecimalSeparator))
            {
                value += PNumber.DecimalSeparator;
            }
            return value;
        }

        public string Backspace()
        {
            int nCharsToRemove = 1;
            if (value.EndsWith(PNumber.DecimalSeparator))
            {
                nCharsToRemove = PNumber.DecimalSeparator.Length;
            }

            value = value.Remove(value.Length - nCharsToRemove);

            if (value.Length == 0 || value == "-")
            {
                value = DefaultValue;
            }

            return value;
        }

        public string Clear()
        {
            return value = DefaultValue;
        }

        private static string RemoveLeadingZeros(string s)
        {
            return LeadingZerosPattern.Replace(s, "$1$3");
            //bool isNegative = false;
            //if (s[0] == '-')
            //{
            //    isNegative = true;
            //    s = s.Substring(1);
            //}

            //s = s.TrimStart('0');
            //if (s.Length == 0 || s.StartsWith(PNumber.DecimalSeparator))
            //{
            //    s = '0' + s;
            //}

            //if (isNegative)
            //{
            //    s = '-' + s;
            //}

            //return s;
        }
    }
}
