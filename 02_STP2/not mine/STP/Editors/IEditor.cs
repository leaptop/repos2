using System;
using System.Collections.Generic;
using System.Text;
using Numbers;

namespace Editors
{
    public interface IEditor<TNumber> where TNumber : INumber<TNumber>, new()
    {
        string Value { get; set; }
        TNumber ValueAsNumber { get; set; }
        bool IsZero { get; }

        string AddDigit(int digit);
        string Backspace();
        string Clear();
    }
}
