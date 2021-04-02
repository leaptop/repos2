using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Processor;
using Numbers;

namespace Tests
{
    [TestClass]
    public class ProcessorTests
    {
        [TestMethod]
        public void TestCtorSetsPropertiesToDefaults()
        {
            var p = new Processor<Complex>();
            Assert.AreEqual(new Complex(), p.LeftOperand);
            Assert.AreEqual(new Complex(), p.RightOperand);
            Assert.AreEqual(BinaryOperation.None, p.BinaryOperation);
        }

        [TestMethod]
        public void TestOperandPropertiesThrowExceptionOnNullValue()
        {
            var p = new Processor<PNumber>();
            Assert.ThrowsException<ArgumentNullException>(() => p.LeftOperand = null);
            Assert.ThrowsException<ArgumentNullException>(() => p.RightOperand = null);
        }

        [TestMethod]
        public void TestResetAllMethodSetsPropertiesToDefaults()
        {
            var p = new Processor<Fraction>();
            p.LeftOperand = new Fraction(10, 21);
            p.RightOperand = new Fraction(49, 19);
            p.BinaryOperation = BinaryOperation.Multiply;

            p.ResetAll();
            Assert.AreEqual(new Fraction(), p.LeftOperand);
            Assert.AreEqual(new Fraction(), p.RightOperand);
            Assert.AreEqual(BinaryOperation.None, p.BinaryOperation);
        }

        [TestMethod]
        public void TestResetBinaryOperationMethodSetsBinaryOperationToNone()
        {
            var p = new Processor<PNumber>();
            p.BinaryOperation = BinaryOperation.Subtract;
            p.ResetBinaryOperation();
            Assert.AreEqual(BinaryOperation.None, p.BinaryOperation);
        }

        [TestMethod]
        public void TestAddProducesCorrectResult()
        {
            var a = new PNumber(10, 10, 5);
            var b = new PNumber(20, 10, 5);
            var r = new PNumber(30, 10, 5);
            DoBinOpTest(r, BinaryOperation.Add, a, b);
        }

        [TestMethod]
        public void TestSubtractProducesCorrectResult()
        {
            var a = new Complex(2, 5);
            var b = new Complex(6, 10);
            var r = new Complex(-4, -5);
            DoBinOpTest(r, BinaryOperation.Subtract, a, b);
        }

        [TestMethod]
        public void TestMultiplyProducesCorrectResult()
        {
            var a = new Fraction(3, 5);
            var b = new Fraction(6, 11);
            var r = new Fraction(18, 55);
            DoBinOpTest(r, BinaryOperation.Multiply, a, b);
        }

        [TestMethod]
        public void TestDivideProducesCorrectResult()
        {
            var a = new Fraction(8, 9);
            var b = new Fraction(4, 15);
            var r = new Fraction(10, 3);
            DoBinOpTest(r, BinaryOperation.Divide, a, b);
        }

        [TestMethod]
        public void TestInverseProducesCorrectResult()
        {
            var p = new Processor<Fraction>();
            p.RightOperand = new Fraction(2, 7);
            p.ApplyUnaryOperationToRightOperand(UnaryOperation.Inverse);
            Assert.AreEqual(new Fraction(7, 2), p.RightOperand);
        }

        [TestMethod]
        public void TestSquareProducesCorrectResult()
        {
            var p = new Processor<Fraction>();
            p.RightOperand = new Fraction(8, 13);
            p.ApplyUnaryOperationToRightOperand(UnaryOperation.Square);
            Assert.AreEqual(new Fraction(64, 169), p.RightOperand);
        }

        private void DoBinOpTest<T>(T expectedResult, BinaryOperation op, T a, T b) 
            where T : INumber<T>, new ()
        {
            var p = new Processor<T>
            {
                BinaryOperation = op,
                LeftOperand = a,
                RightOperand = b
            };
            p.ApplyBinaryOperation();
            Assert.AreEqual(expectedResult, p.LeftOperand);
        }
    }
}
