using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_05_ComplexNumber;
namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod01ConstructorString()
        {
            TComplex tc = new TComplex("-12 - i * 6");
            Assert.AreEqual(tc.getImaginaryDouble(), -6);
        }
        [TestMethod]
        public void TestMethod02ConstructorDouble()
        {
            TComplex tc = new TComplex(7, 56);
            Assert.AreEqual(tc.getRealDouble(), 7);
        }
        [TestMethod]
        public void TestMethod03Clone()
        {
            TComplex tc = new TComplex(7, 56);
            TComplex tc2 = (TComplex)tc.Clone();
            Assert.AreEqual(tc.getRealDouble(), tc2.getRealDouble());
        }
        [TestMethod]
        public void TestMethod04Add()
        {
            TComplex tc = new TComplex(7, 56);
            TComplex tc2 = new TComplex(-3, 12);
            TComplex tc3 = tc.add(tc2);
            Assert.AreEqual(tc3.getRealDouble(), 4);
        }
        [TestMethod]
        public void TestMethod05getRealDouble()
        {
            TComplex tc = new TComplex(45, 56);
            Assert.AreEqual(tc.getRealDouble(), 45);
        }
        [TestMethod]
        public void TestMethod06getImaginaryDouble()
        {
            TComplex tc = new TComplex(7, 56);
            Assert.AreEqual(tc.getImaginaryDouble(), 56);
        }
        [TestMethod]
        public void TestMethod07multiply()
        {
            TComplex tc = new TComplex(5, 2);
            TComplex tc2 = new TComplex(-3, 12);
            TComplex tc3 = tc.multiply(tc2);//5*(-3)-2*12 + i*(2*12 + -3*2) = -39 + i*18
            Assert.AreEqual(tc3.getRealDouble(), -39);
        }
        [TestMethod]
        public void TestMethod08square()
        {
            TComplex tc = new TComplex(7, 2);
            TComplex tcsq = tc.square();//7*7 - 2*2 + i* (7*2 +7 * 2) = 45 + i * 28
            Assert.AreEqual(tcsq.getImaginaryDouble(), 28);
        }
        [TestMethod]
        public void TestMethod09reciprocal()
        {
            TComplex tc = new TComplex(6, 3);
            TComplex tcrc = tc.reciprocal();//6/(6^2+3^2) - i * 3/(6^2 + 3^2) = 6/45(=0.13333(3))...
            Assert.AreEqual(tcrc.getRealDouble(), 0.133333, 0.00001);

        }
        [TestMethod]
        public void TestMethod10subtractParameter_d()
        {
            TComplex tc = new TComplex(7, 56);
            TComplex tc2 = new TComplex(3, 57);
            TComplex tcsub = tc.subtractParameter_d(tc2);//
            Assert.AreEqual(tcsub.getImaginaryDouble(), -1);
        }
        [TestMethod]
        public void TestMethod11divideBy_d()
        {
            TComplex tc = new TComplex(7, 2);
            TComplex tc2 = new TComplex(3, 8);
            TComplex tcdiv = tc.divideBy_d(tc2);//
            Assert.AreEqual(tcdiv.getImaginaryDouble(), -0.6849315, 0.00001);
        }
        [TestMethod]
        public void TestMethod12minus()
        {
            TComplex tc = new TComplex(7, 2);
            TComplex tc2 = tc.minus();
            Assert.AreEqual(tc2.getImaginaryDouble(), -2);
        }
        [TestMethod]
        public void TestMethod12module()
        {
            TComplex tc = new TComplex(7, 2);
            double res = tc.module();
            Assert.AreEqual(res, 7.280109, 0.00001);
        }
        [TestMethod]
        public void TestMethod13angleRadians()
        {
            TComplex tc = new TComplex(1, 1);
            double res = tc.angleRadians();
            Assert.AreEqual(res, 0.78539816, 0.00001);
        }
        [TestMethod]
        public void TestMethod14angleDegrees()
        {
            TComplex tc = new TComplex(1, 1);
            double res = tc.angleDegrees();
            Assert.AreEqual(res, 45, 0.00001);
        }
        [TestMethod]
        public void TestMethod12module2()
        {
            TComplex tc = new TComplex(5, 8);
            double res = tc.module();
            Assert.AreEqual(res, 9.433981132056, 0.00001);
        }
        [TestMethod]
        public void TestMethod15power()
        {
            TComplex tc = new TComplex(5, 8);
            TComplex res = tc.power(4);
            Assert.AreEqual(res.getImaginaryDouble(), -6239.99999899, 0.00001);
        }
        [TestMethod]
        public void TestMethod16root()
        {
            TComplex tc = new TComplex(1, 0);
            TComplex res = tc.root(5, 2);
            Assert.AreEqual(res.getImaginaryDouble(), 0.587785252292473, 0.00001);
        }
        [TestMethod]
        public void TestMethod17isEqualTo_d()
        {
            TComplex tc = new TComplex(7, 2);
            TComplex tc2 = new TComplex(7, 2);
            bool x = tc.isEqualTo_d(tc2);
            Assert.IsTrue(x);
        }
        [TestMethod]
        public void TestMethod18isNotEqualTo_d()
        {
            TComplex tc = new TComplex(7, 2);
            TComplex tc2 = new TComplex(6, 2);
            bool x = tc.isNotEqualTo_d(tc2);
            Assert.IsTrue(x);
        }
        [TestMethod]
        public void TestMethod19getRealString()
        {
            TComplex tc = new TComplex(7, 2);
            string str = tc.getRealString();
            Assert.AreEqual(str, "7");
        }
        [TestMethod]
        public void TestMethod20getImaginaryString()
        {
            TComplex tc = new TComplex(7, 2);
            string str = tc.getImaginaryString();
            Assert.AreEqual(str, "2");
        }
        [TestMethod]
        public void TestMethod21ToString()
        {
            TComplex tc = new TComplex(7, 2);
            string str = tc.ToString();
            Assert.AreEqual(str, "7+i*2");
        }
        [TestMethod]
        public void TestMethod22ToString()
        {
            TComplex tc = new TComplex(7, -2);
            string str = tc.ToString();
            Assert.AreEqual(str, "7-i*2");
        }
    }
    
}


