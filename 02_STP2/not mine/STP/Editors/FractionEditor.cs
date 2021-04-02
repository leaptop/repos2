using System;
using System.Text.RegularExpressions;
using Numbers;

namespace Editors
{
    public class FractionEditor : IEditor<Fraction>
    {
        private static readonly string DefaultValue = "0";
        private static readonly Regex LeadingZerosPattern = new Regex(@"^(-?)(0*)(\d+)");

        private string value = DefaultValue;

        public string Value
        {
            get => value;
            set
            {
                Fraction.AssertValidFormat(value);
                this.value = RemoveLeadingZeros(value);
            }
        }

        public Fraction ValueAsNumber
        {
            get => Fraction.Parse(value);
            set => this.value = value.ToString();
        }

        public bool IsZero => value == DefaultValue;

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
            if (digit < 0 || digit > 9)
            {
                throw new ArgumentOutOfRangeException(nameof(digit), digit, "Invalid digit");
            }

            value += (char)(digit + '0');
            value = RemoveLeadingZeros(value);
            return value;
        }

        public string AddSlash()
        {
            if (!value.Contains('/'))
            {
                value += '/';
            }
            return value;
        }

        public string Backspace()
        {
            value = value.Remove(value.Length - 1);

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
            //if (s.Length == 0 || s[0] == '/')
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
