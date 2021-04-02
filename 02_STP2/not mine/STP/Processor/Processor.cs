using System;
using Numbers;

namespace Processor
{
    public class Processor<T> where T : INumber<T>, new()
    {
        private T leftOp;
        private T rightOp;

        public T LeftOperand
        {
            get => leftOp;
            set => leftOp = value ?? throw new ArgumentNullException();
        }

        public T RightOperand
        {
            get => rightOp;
            set => rightOp = value ?? throw new ArgumentNullException();
        }

        public BinaryOperation BinaryOperation { get; set; }

        public Processor()
        {
            ResetAll();
        }

        public void ResetAll()
        {
            leftOp = new T();
            rightOp = new T();
            ResetBinaryOperation();
        }

        public void ResetBinaryOperation()
        {
            BinaryOperation = BinaryOperation.None;
        }

        public void ApplyBinaryOperation()
        {
            switch (BinaryOperation)
            {
                case BinaryOperation.Add:
                    leftOp = leftOp.Add(rightOp);
                    break;

                case BinaryOperation.Subtract:
                    leftOp = leftOp.Subtract(rightOp);
                    break;

                case BinaryOperation.Multiply:
                    leftOp = leftOp.Multiply(rightOp);
                    break;

                case BinaryOperation.Divide:
                    leftOp = leftOp.Divide(rightOp);
                    break;
            }
        }

        public void ApplyUnaryOperationToRightOperand(UnaryOperation operation)
        {
            switch (operation)
            {
                case UnaryOperation.Inverse:
                    rightOp = rightOp.Inverted;
                    break;

                case UnaryOperation.Square:
                    rightOp = rightOp.Squared;
                    break;
            }
        }
    }
}
