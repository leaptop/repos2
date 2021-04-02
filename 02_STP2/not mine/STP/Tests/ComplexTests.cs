using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using Numbers;

namespace Tests
{
    [TestClass]
    public class ComplexTests
    {
        private const double delta = 0.001;
        private static void AreDoublesEqual(double expected, double actual)
        {
            Assert.AreEqual(expected, actual, delta);
        }

        [TestMethod]
        public void TestCtor()
        {
            DoTest(1.1, 5);
            DoTest(-2, 10.15);
            DoTest(3, -51.9041);
            DoTest(-923.129, 190.3);

            void DoTest(double r, double i)
            {
                var c = new Complex(r, i);
                AreDoublesEqual(r, c.Re);
                AreDoublesEqual(i, c.Im);
            }
        }

        [TestMethod]
        public void TestParse()
        {
            DoTest("1+i*1", 1, 1);
            DoTest("-2+i*-4", -2, -4);
            DoTest("5+i*9", 5, 9);
            DoTest("102+i*-290123", 102, -290123);
            DoTest("0", 0, 0);
            DoTest("-501231", -501231, 0);
            DoTest("9512409", 9512409, 0);

            void DoTest(string s, double r, double i)
            {
                Complex c = Complex.Parse(s);
                AreDoublesEqual(r, c.Re);
                AreDoublesEqual(i, c.Im);
            }
        }

        [TestMethod]
        public void TestParsingInvalidStringsThrowsExceptions()
        {
            Assert.ThrowsException<ArgumentNullException>(() => Complex.Parse(null));

            DoTest("");
            DoTest("2++i*2");
            DoTest("3+*2");
            DoTest("2+i4");

            void DoTest(string s)
            {
                Assert.ThrowsException<FormatException>(() => Complex.Parse(s));
            }
        }

        [TestMethod]
        public void TestMultiply()
        {
            DoTest(-17, 33, 2, 3, 5, 9);
            DoTest(-17, 33, 5, 9, 2, 3);
            DoTest(0, 0, 0, 0, 0, 0);
            DoTest(9, 0, 3, 0, 3, 0);
            DoTest(49, 1, 49, 1, 1, 0);

            void DoTest(double expectedR, double expectedI, double r1, double i1, double r2, double i2)
            {
                var c = new Complex(r1, i1).Multiply(new Complex(r2, i2));
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestSqr()
        {
            DoTest(-5, 12, 2, 3);
            DoTest(1, 0, 1, 0);
            DoTest(0, 0, 0, 0);

            void DoTest(double expectedR, double expectedI, double r, double i)
            {
                var c = new Complex(r, i).Squared;
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestInverted()
        {
            DoTest(0.1, -0.2, 2, 4);
            DoTest(1, 0, 1, 0);

            void DoTest(double expectedR, double expectedI, double r, double i)
            {
                var c = new Complex(r, i).Inverted;
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestSubtract()
        {
            DoTest(1, 5, 9, 4, 8, -1);
            DoTest(0, 0, 29, 9, 29, 9);

            void DoTest(double expectedR, double expectedI, double r1, double i1, double r2, double i2)
            {
                var c = new Complex(r1, i1).Subtract(new Complex(r2, i2));
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestDivide()
        {
            DoTest(-1.6, 1.8, 2, 5, 1, -2);
            DoTest(59, 19, 59, 19, 1, 0);

            void DoTest(double expectedR, double expectedI, double r1, double i1, double r2, double i2)
            {
                var c = new Complex(r1, i1).Divide(new Complex(r2, i2));
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestMagnitude()
        {
            DoTest(Math.Sqrt(29), 2, 5);
            DoTest(0, 0, 0);
            DoTest(1, 0, 1);
            DoTest(5, 4, 3);

            void DoTest(double expectedMagnitude, double r, double i)
            {
                AreDoublesEqual(expectedMagnitude, new Complex(r, i).Magnitude);
            }
        }

        [TestMethod]
        public void TestPhase()
        {
            DoTest(1.1902899496825317, 2, 5);
            DoTest(0, 1, 0);
            DoTest(-1.570796326794896, 0, -4);

            void DoTest(double expectedPhase, double r, double i)
            {
                AreDoublesEqual(expectedPhase, new Complex(r, i).Phase);
            }
        }

        [TestMethod]
        public void TestPow()
        {
            DoTest(16159899, -12631900, 2, 5, 10);
            DoTest(2, 5, 2, 5, 1);
            DoTest(1, 0, 5, 9, 0);

            void DoTest(double expectedR, double expectedI, double r, double i, int pow)
            {
                var c = new Complex(r, i).Pow(pow);
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestRoot()
        {
            DoTest(1.9216, 1.301, 2, 5, 2, 0);
            DoTest(-1.4567, 0.6121, 4, 9, 5, 2);
            DoTest(29, 190, 29, 190, 1, 0);

            void DoTest(double expectedR, double expectedI, double r, double i, int deg, int k)
            {
                var c = new Complex(r, i).Root(deg, k);
                AreDoublesEqual(expectedR, c.Re);
                AreDoublesEqual(expectedI, c.Im);
            }
        }

        [TestMethod]
        public void TestEquals()
        {
            var a1 = new Complex(10, 5);
            var a2 = new Complex(10, 5);
            var c = new Complex(2, 2);
            
            Assert.IsTrue(a1.Equals(a1));
            Assert.IsTrue(a1.Equals(a2));
            Assert.IsTrue(a2.Equals(a1));
            Assert.IsFalse(a1.Equals(c));
            Assert.IsFalse(c.Equals(a1));

            Assert.IsFalse(!a1.Equals(a1));
            Assert.IsFalse(!a1.Equals(a2));
            Assert.IsFalse(!a2.Equals(a1));
            Assert.IsTrue(!a1.Equals(c));
            Assert.IsTrue(!c.Equals(a1));
        }
    }
}
