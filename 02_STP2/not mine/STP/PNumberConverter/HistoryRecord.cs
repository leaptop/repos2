using System;
using System.Collections.Generic;
using System.Text;
using Numbers;

namespace Lab1
{
    struct HistoryRecord
    {
        public PNumber Input { get; set; }
        public PNumber Output { get; set; }

        public HistoryRecord(PNumber input, PNumber output)
        {
            Input = input;
            Output = output;
        }

        public override string ToString()
            => $"{Input} ({Input.Base}) -> {Output} ({Output.Base})";
    }
}
