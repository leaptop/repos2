using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_03_tests3;
namespace UnitTestProject3
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1arrangeXYZ_inDescendingOrder()
        {
            int[] expected = { 2, 5, 1 };
            Program.arrangeXYZ_inDescendingOrder(ref expected);
            int[] actual = { 5, 2, 1 };
            CollectionAssert.AreEqual(expected, actual);
        }
        [TestMethod]

        public void TestMethod2calculateGCD_Euclid()
        {
            int a = 6, b = 27, res = 3;
            int gcdProg = Program.calculateGCD_Euclid(a, b);

            Assert.AreEqual(gcdProg, res);
        }
        [TestMethod]
        public void TestMethod3createANumberOfEvenDigitsOf_a()
        {
            int a = 123456, x = 135;
            int derivedProg = Program.createANumberOfEvenDigitsOf_a(a);

            Assert.AreEqual(derivedProg, x);
        }
        [TestMethod]
        public void TestMethod3createANumberOfEvenDigitsOf_StringLengthLessThan2()
        {
            int a = 7, x = Int32.MaxValue;
            int derivedProg = Program.createANumberOfEvenDigitsOf_a(a);

            Assert.AreEqual(derivedProg, x);
        }
        [TestMethod]
        public void TestMethod4getSumOfOddDoublesAboveMainDiagonal()
        {
            double[,] arr = new double[,] { { 23.7,   10000,   10.4,  56,   56 },
                                            { 38.5,   5,     89,   190,  343},
                                            { 13,     564,   100,  767,  23 },
                                            { 2000,   10,    374,  56,   5 },
                                            { 38.5,   5,     89,   190,  343},
                                            { 1300,   564,   100,  767,  23000 }
            };
            double expected = 1227;
            double actual = Program.getSumOfOddDoublesAboveMainDiagonal(arr);
            Assert.AreEqual(expected, actual);
        }
        [TestMethod]
        public void TestMethod4getSumOfOddDoublesAboveMainDiagonalRowLengthLessThan2()
        {
            double[,] arr = new double[,] {{2},{3},{4}
            };
            double expected = Double.NaN;
            double actual = Program.getSumOfOddDoublesAboveMainDiagonal(arr);
            Assert.AreEqual(expected, actual);
        }
    }
    
}
