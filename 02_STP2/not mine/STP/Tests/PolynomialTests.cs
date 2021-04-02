using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Polynomials;

namespace Tests
{
    [TestClass]
    public class PolynomialTests
    {
        [TestMethod]
        public void TestIndexerStoresValuesCorrectly()
        {
            var p = new Polynomial();
            p[0] = 1;
            p[15] = -11;
            p[4] = 8;
            Assert.AreEqual(1, p[0]);
            Assert.AreEqual(-11, p[15]);
            Assert.AreEqual(8, p[4]);

            p[15] = 3;
            Assert.AreEqual(3, p[15]);
        }

        [TestMethod]
        public void TestIndexerReturnsZeroForMembersThatHaveNotBeenExplicitlySet()
        {
            var p = new Polynomial();
            Assert.AreEqual(0, p[1]);
            Assert.AreEqual(0, p[10]);
            Assert.AreEqual(0, p[100]);

            p[5] = 5;
            p[8] = 10;
            Assert.AreEqual(0, p[6]);
            Assert.AreEqual(0, p[9]);
            Assert.AreEqual(0, p[10]);
            Assert.AreEqual(0, p[100]);
        }

        [TestMethod]
        public void TestIndexerThrowsWhenIndexIsNegative()
        {
            var p = new Polynomial();
            int temp;
            Assert.ThrowsException<ArgumentOutOfRangeException>(() => temp = p[-1]);
            Assert.ThrowsException<ArgumentOutOfRangeException>(() => p[-1] = 10);
            Assert.ThrowsException<ArgumentOutOfRangeException>(() => temp = p[-500]);
            Assert.ThrowsException<ArgumentOutOfRangeException>(() => p[-500] = 999);
        }

        [TestMethod]
        public void TestParameterlessCtorCreatesZeroPoly()
        {
            var p = new Polynomial();
            Assert.AreEqual(0, p[0]);
        }

        [TestMethod]
        public void TestCtorWithParametersDoesSetValues()
        {
            var p = new Polynomial(5, 10);
            Assert.AreEqual(5, p[10]);
        }

        [TestMethod]
        public void TestDegreePropReturnsDegreeOfMaxNonzeroMember()
        {
            var p = new Polynomial();
            Assert.AreEqual(0, p.Degree);

            p[2] = 4;
            Assert.AreEqual(2, p.Degree);
            p[8] = 8;
            Assert.AreEqual(8, p.Degree);
            
            p[5] = -10;
            Assert.AreEqual(8, p.Degree);

            p[8] = 0;
            Assert.AreEqual(5, p.Degree);

            p[3] = 8;
            p[5] = 0;
            Assert.AreEqual(3, p.Degree);
        }

        [TestMethod]
        public void TestNegatePropReturnsPolyWithNegativeCoeffs()
        {
            var p = new Polynomial();
            p[5] = 10;
            p[8] = 4;
            p[7] = 0;
            p[14] = -7;
            var n = p.Negate;
            Assert.AreEqual(-10, n[5]);
            Assert.AreEqual(-4, n[8]);
            Assert.AreEqual(0, n[7]);
            Assert.AreEqual(7, n[14]);
        }

        [TestMethod]
        public void TestClearDoesResetCoeffs()
        {
            var p = new Polynomial();
            p[5] = 10;
            p[8] = 4;
            p[7] = 0;
            p[14] = -7;
            p.Clear();
            
            Assert.AreEqual(0, p[5]);
            Assert.AreEqual(0, p[8]);
            Assert.AreEqual(0, p[14]);
            Assert.AreEqual(0, p[7]);
        }

        [TestMethod]
        public void TestAdd()
        {
            var a = new Polynomial();
            a[0] = 5;
            a[4] = 3;
            a[8] = -10;

            var b = new Polynomial();
            b[1] = 1000;
            b[4] = 100;
            b[8] = 10;
            b[13] = -20;

            var s = a.Add(b);
            Assert.AreEqual(5, s[0]);
            Assert.AreEqual(1000, s[1]);
            Assert.AreEqual(103, s[4]);
            Assert.AreEqual(0, s[8]);
            Assert.AreEqual(-20, s[13]);
        }

        [TestMethod]
        public void TestSubtract()
        {
            var a = new Polynomial();
            a[0] = 5;
            a[4] = 3;
            a[8] = -10;

            var b = new Polynomial();
            b[1] = 1000;
            b[4] = 100;
            b[8] = 10;
            b[13] = -20;

            var s = a.Subtract(b);
            Assert.AreEqual(5, s[0]);
            Assert.AreEqual(-1000, s[1]);
            Assert.AreEqual(-97, s[4]);
            Assert.AreEqual(-20, s[8]);
            Assert.AreEqual(20, s[13]);
        }

        [TestMethod]
        public void TesMultiply()
        {
            var a = new Polynomial();
            a[5] = 3;
            a[4] = 8;
            a[2] = 2;
            a[1] = 0;
            a[0] = 7;

            var b = new Polynomial();
            b[6] = 6;
            b[5] = 2;
            b[4] = 10;
            b[3] = 8;
            b[2] = 3;
            b[1] = 11;
            b[0] = 10;

            var m = a.Multiply(b);
            Assert.AreEqual(12, m.Count);
            Assert.AreEqual(18, m[11]);
            Assert.AreEqual(54, m[10]);
            Assert.AreEqual(46, m[9]);
            Assert.AreEqual(116, m[8]);
            Assert.AreEqual(77, m[7]);
            Assert.AreEqual(119, m[6]);
            Assert.AreEqual(148, m[5]);
            Assert.AreEqual(156, m[4]);
            Assert.AreEqual(78, m[3]);
            Assert.AreEqual(41, m[2]);
            Assert.AreEqual(77, m[1]);
            Assert.AreEqual(70, m[0]);
        }

        [TestMethod]
        public void TestDerivative()
        {
            var p = new Polynomial();
            p[6] = 6;
            p[5] = 2;
            p[4] = 10;
            p[3] = 8;
            p[2] = 3;
            p[1] = 11;
            p[0] = 10;

            var d = p.Derivative;

            Assert.AreEqual(36, d[5]);
            Assert.AreEqual(10, d[4]);
            Assert.AreEqual(40, d[3]);
            Assert.AreEqual(24, d[2]);
            Assert.AreEqual(6, d[1]);
            Assert.AreEqual(11, d[0]);
        }

        [TestMethod]
        public void TestEvaluate()
        {
            var p = new Polynomial();
            p[6] = 6;
            p[5] = 2;
            p[4] = 10;
            p[3] = 8;
            p[2] = 3;
            p[1] = 11;
            p[0] = 10;

            Assert.AreEqual(107390, p.Evaluate(5));
            Assert.AreEqual(10, p.Evaluate(0));
            Assert.AreEqual(50, p.Evaluate(1));
            Assert.AreEqual(8, p.Evaluate(-1));

            p = new Polynomial();
            Assert.AreEqual(0, p.Evaluate(0));
            Assert.AreEqual(0, p.Evaluate(1));
            Assert.AreEqual(0, p.Evaluate(100000));
            Assert.AreEqual(0, p.Evaluate(-22882100));
        }

        [TestMethod]
        public void TestEquals()
        {
            var a = new Polynomial();
            var b = new Polynomial();
            Assert.IsTrue(a.Equals(b));

            a[10] = 8;
            Assert.IsFalse(a.Equals(b));

            b[10] = 8;
            Assert.IsTrue(a.Equals(b));

            b[5] = 14;
            Assert.IsFalse(a.Equals(b));

            b[5] = 0;
            Assert.IsTrue(a.Equals(b));
        }
    }
}
