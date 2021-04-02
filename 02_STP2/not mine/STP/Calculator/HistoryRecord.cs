using System;
using System.Collections.Generic;
using System.Text;
using Numbers;
using Processor;

namespace Calculator
{
    interface IHistoryRecord
    {
        string AsText { get; }
    }

    class BinaryOperationRecord<TNumber> : IHistoryRecord
        where TNumber : INumber<TNumber>, new()
    {
        public TNumber Left { get; set; }
        public TNumber Right { get; set; }
        public BinaryOperation Operation { get; set; }
        public TNumber Result { get; set; }

        public string AsText 
            => $"({Left}) {OperationAsString} ({Right}) = {Result}";

        private string OperationAsString
            => this.Operation switch
            {
                BinaryOperation.Add => "+",
                BinaryOperation.Subtract => "-",
                BinaryOperation.Multiply => "*",
                BinaryOperation.Divide => "/",
                _ => "?"
            };
    }

    class UnaryOperationRecord<TNumber> : IHistoryRecord
        where TNumber : INumber<TNumber>, new()
    {
        public TNumber Input { get; set; }
        public UnaryOperation Operation { get; set; }
        public TNumber Result { get; set; }

        public string AsText
            => $"{string.Format(Left, Input)} = {Result}";

        private string Left
            => this.Operation switch
            {
                UnaryOperation.Inverse => "1/({0})",
                UnaryOperation.Square => "({0})²",
                _ => "{0} ?"
            };
    }
}
