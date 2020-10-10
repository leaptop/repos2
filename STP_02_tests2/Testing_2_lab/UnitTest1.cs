using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_02_tests2;
namespace Testing_2_lab
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1AreEqual()
        {
            int a = 10;
            int b = 6;
            int min = b;
            int programsMin = Program.minimumOfAAndB(a, b);
            Assert.AreEqual(programsMin, min);
        }
        [TestMethod]
        public void TestMethod2maximumOf2DArray()
        {
            double[,] arr = new double[,] { { 23.7d,  10}, { 38.5d, 5 } };

            double max = 38.5d;
            double programsMax = Program.maximumOf2DArray(arr);
            Assert.AreEqual(programsMax, max);
        }
        [TestMethod]
        public void TestMethod3maximumOf2DArrayOnAndAboveSecondaryDiagonal()
        {
            double[,] arr = new double[,] { { 23.7,   100,   374,  56,   56 }, 
                                            { 38.5,   5,     89,   190,  343},
                                            { 13,     564,   100,  767,  23 },
                                            { 200,   10,    374,  56,   5 },
                                            { 38.5,   5,     89,   190,  343},
                                            { 1300,   564,   100,  767,  23 }
            };

            double max = 564;
            double programsMax = Program.maximumOf2DArrayOnAndAboveSecondaryDiagonal(arr);
            Assert.AreEqual(programsMax, max);
        }
    }
}
