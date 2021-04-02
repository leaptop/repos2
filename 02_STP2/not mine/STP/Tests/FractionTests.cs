using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Numbers;

namespace Tests
{
    [TestClass]
    public class FractionTests
    {
        [TestMethod]
        public void TestParameterlessCtor()
        {
            var frac = new Fraction();
            Assert.AreEqual(0, frac.Numerator);
            Assert.AreEqual(1, frac.Denominator);
        }

        [TestMethod]
        public void TestSingleWholeNumberCtor()
        {
            DoTest(1);
            DoTest(2);
            DoTest(2222);
            DoTest(0);
            DoTest(-1);
            DoTest(-751);

            void DoTest(long whole)
            {
                var frac = new Fraction(whole);
                Assert.AreEqual(whole, frac.Numerator);
                Assert.AreEqual(1, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestCtorConsistency()
        {
            DoTest(1, 8);
            DoTest(10, 1);
            DoTest(3, 7);
            DoTest(-7, 3);
            DoTest(0, 1);
            DoTest(long.MaxValue, long.MaxValue - 1);

            void DoTest(long n, long d)
            {
                var frac = new Fraction(n, d);
                Assert.AreEqual(n, frac.Numerator);
                Assert.AreEqual(d, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestCtorReducing()
        {
            DoTest(1, 4, 10);
            DoTest(777, 1, 666);
            DoTest(3, 5, 2);
            DoTest(-9, 2, 400);
            DoTest(0, 1, 999);

            void DoTest(long n, long d, long k)
            {
                var frac = new Fraction(k * n, k * d);
                Assert.AreEqual(n, frac.Numerator);
                Assert.AreEqual(d, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestCtorInvertsSignsWhenDenominatorIsNegative()
        {
            DoTest(7, -9);
            DoTest(-5, -28);
            DoTest(0, -1);

            void DoTest(long a, long b)
            {
                var frac = new Fraction(a, b);
                Assert.AreEqual(-a, frac.Numerator);
                Assert.AreEqual(-b, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestTwoFractionsCtor()
        {
            DoTest(1, 1, new Fraction(1, 1), new Fraction(1, 1));
            DoTest(40, 21, new Fraction(10, 3), new Fraction(7, 4));
            DoTest(1, 1, new Fraction(6, 11), new Fraction(6, 11));
            DoTest(-40, 21, new Fraction(-10, 3), new Fraction(7, 4));
            DoTest(0, 1, new Fraction(0, 1), new Fraction(1000, 9999));

            void DoTest(long expectedN, long expectedD, Fraction a, Fraction b)
            {
                var frac = new Fraction(a, b);
                Assert.AreEqual(expectedN, frac.Numerator);
                Assert.AreEqual(expectedD, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestCtorThrowsExceptionWhenDenominatorIsZero()
        {
            DoTest(1);
            DoTest(500);
            DoTest(0);
            DoTest(-1);

            void DoTest(long n)
            {
                Assert.ThrowsException<ArgumentException>(() => new Fraction(n, 0));
            }
        }

        [TestMethod]
        public void TestSquared()
        {
            DoTest(1, 1);
            DoTest(10, 3);
            DoTest(0, 1);
            DoTest(-4, 9);

            void DoTest(long a, long b)
            {
                var frac = new Fraction(a, b).Squared;
                Assert.AreEqual(a * a, frac.Numerator);
                Assert.AreEqual(b * b, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestInverted()
        {
            DoTest(1, 1);
            DoTest(10, 3);
            DoTest(-4, 9);

            void DoTest(long a, long b)
            {
                var frac = new Fraction(a, b).Inverted;
                if (a < 0 || b < 0)
                {
                    a = -a;
                    b = -b;
                }
                Assert.AreEqual(b, frac.Numerator);
                Assert.AreEqual(a, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestParse()
        {
            DoTest(1, 1, "1");
            DoTest(1, 1, "1/1");
            DoTest(10, 89, "10/89");
            DoTest(0, 1, "0");
            DoTest(0, 1, "0/1");
            DoTest(-51, 4, "-51/4");

            void DoTest(long n, long d, string s)
            {
                var frac = Fraction.Parse(s);
                Assert.AreEqual(n, frac.Numerator);
                Assert.AreEqual(d, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestParseThrowsExceptionOnInvalidInput()
        {
            Assert.ThrowsException<ArgumentNullException>(() => Fraction.Parse(null));
            DoTest("");
            DoTest("10/");
            DoTest("1j#");
            DoTest("/1/1");
            DoTest("a/b");

            void DoTest(string s)
            {
                Assert.ThrowsException<FormatException>(() => Fraction.Parse(s));
            }
        }

        [TestMethod]
        public void TestEquals()
        {
            DoTest(1, 1);
            DoTest(0, 1);
            DoTest(10, 943);
            DoTest(-4, 59);

            void DoTest(long n, long d)
            {
                var frac1 = new Fraction(n, d);
                var frac2 = new Fraction(n, d);
                Assert.IsTrue(frac1.Equals(frac2));
            }
        }

        [TestMethod]
        public void TestCompareTo()
        {
            Assert.IsTrue(Compare(3, 4, 2, 3) > 0);
            Assert.IsTrue(Compare(5, 2, -1, 8) > 0);
            Assert.IsTrue(Compare(0, 1, 1, 1) < 0);
            Assert.IsTrue(Compare(2, 1, 2, 1) == 0);

            int Compare(long n1, long d1, long n2, long d2)
            {
                return new Fraction(n1, d1).CompareTo(new Fraction(n2, d2));
            }
        }

        [TestMethod]
        public void TestNegate()
        {
            DoTest(1, 1);
            DoTest(1, 4);
            DoTest(-7, 5);

            var f = new Fraction(0, 1).Negated;
            Assert.AreEqual(0, f.Numerator);
            Assert.AreEqual(1, f.Denominator);

            void DoTest(long n, long d)
            {
                var frac = new Fraction(n, d).Negated;
                Assert.AreEqual(-n, frac.Numerator);
                Assert.AreEqual(d, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestAdd()
        {
            DoTest(2, 1, 1, 1, 1, 1);
            DoTest(17, 12, 2, 3, 3, 4);
            DoTest(9, 7, 9, 7, 0, 1);
            DoTest(27, 56, 6, 7, -3, 8);
            DoTest(0, 1, 5, 7, -5, 7);

            void DoTest(long expectedN, long expectedD, long n1, long d1, long n2, long d2)
            {
                var frac = new Fraction(n1, d1).Add(new Fraction(n2, d2));
                Assert.AreEqual(expectedN, frac.Numerator);
                Assert.AreEqual(expectedD, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestSubtract()
        {
            DoTest(1, 1, 2, 1, 1, 1);
            DoTest(-1, 12, 2, 3, 3, 4);
            DoTest(0, 1, 5, 7, 5, 7);
            DoTest(9, 7, 9, 7, 0, 1);
            DoTest(13, 14, 3, 7, -1, 2);

            void DoTest(long expectedN, long expectedD, long n1, long d1, long n2, long d2)
            {
                var frac = new Fraction(n1, d1).Subtract(new Fraction(n2, d2));
                Assert.AreEqual(expectedN, frac.Numerator);
                Assert.AreEqual(expectedD, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestMultiply()
        {
            DoTest(3, 2, 3, 1, 1, 2);
            DoTest(20, 27, 5, 9, 4, 3);
            DoTest(9, 7, 9, 7, 1, 1);
            DoTest(1, 1, 5, 7, 7, 5);
            DoTest(-4, 9, 2, 3, -2, 3);

            void DoTest(long expectedN, long expectedD, long n1, long d1, long n2, long d2)
            {
                var frac = new Fraction(n1, d1).Multiply(new Fraction(n2, d2));
                Assert.AreEqual(expectedN, frac.Numerator);
                Assert.AreEqual(expectedD, frac.Denominator);
            }
        }

        [TestMethod]
        public void TestDivide()
        {
            DoTest(1, 1, 1, 1, 1, 1);
            DoTest(40, 21, 10, 3, 7, 4);
            DoTest(1, 1, 6, 11, 6, 11);
            DoTest(7, 8, 7, 8, 1, 1);
            DoTest(-40, 21, -10, 3, 7, 4);
            DoTest(0, 1, 0, 1, 1000, 9999);

            void DoTest(long expectedN, long expectedD, long n1, long d1, long n2, long d2)
            {
                var frac = new Fraction(n1, d1).Divide(new Fraction(n2, d2));
                Assert.AreEqual(expectedN, frac.Numerator);
                Assert.AreEqual(expectedD, frac.Denominator);
            }
        }
    }
}
