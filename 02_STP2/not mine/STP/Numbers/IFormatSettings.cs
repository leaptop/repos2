using System;
using System.Collections.Generic;
using System.Text;

namespace Numbers
{
    public interface IFormatSettings
    {
        bool OmitFractionDenominatorOfOne { get; }
        bool OmitComplexImPartOfZero { get; }
    }
}
