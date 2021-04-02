using System;
using System.Collections.Generic;
using System.Text;
using Numbers;

namespace Calculator
{
    struct Settings : IFormatSettings
    {
        public bool OmitFractionDenominatorOfOne { get; set; }
        public bool OmitComplexImPartOfZero { get; set; }
        public bool DisallowFractionalPNumbers { get; set; }
    }
}
