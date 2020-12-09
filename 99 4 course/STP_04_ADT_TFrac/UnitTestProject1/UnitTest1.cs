using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_04_ADT_TFrac;
namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1CorrectNumerator()
        {
            TFrac f;
            int x = 0;
            try
            {
                f = new TFrac("10/11");
                x = f.numerator;
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(x, 10);
        }

        [TestMethod]
        public void TestMethod2NegativeDenominator()
        {
            int den = 0;
            try
            {//убеждаюсь, что минус из знаменателя убирается
                TFrac f = new TFrac(10, -11);
                den = f.getDenominator();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(den, 11);
        }
        [TestMethod]
        public void TestMethod2NegativeDenominatorString()
        {
            string den = "";
            try
            {//убеждаюсь, что минус из знаменателя убирается
                TFrac f = new TFrac("10/-11");
                den = f.getDenominatorString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(den, "11");
        }
        [TestMethod]
        public void TestMethod3ZeroException()
        {
            try
            {
                TFrac f = new TFrac(10, 0);
            }
            catch (Exception ex)//сам выброс исключения пытаюсь сделать положительным событием
            {//но пока не понимаю как это реализовать здесь
                throw new AssertInconclusiveException();
            }//
        }
        [TestMethod]
        public void TestMethod4CorrectStringNumerator()
        {
            TFrac f;
            string str = "";
            try
            {
                f = new TFrac("10/11");
                str = f.aStr;
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "10");
        }
        [TestMethod]
        public void TestMethod5CorrectAddition()
        {
            TFrac f, g, mulResult;
            string result = "";
            try
            {
                f = new TFrac("10/11");
                g = new TFrac(3, 4);
                mulResult = f.mul(f, g);
                result = mulResult.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(result, "15/22");
        }
        [TestMethod]
        public void TestMethod6DivResult()
        {
            TFrac f, g, divResult;
            string result = "";
            try
            {
                f = new TFrac("3/11");
                g = new TFrac(5, 2);
                divResult = f.dvd(f, g);
                result = divResult.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(result, "6/55");
        }
        [TestMethod]
        public void TestMethod7MinusResult()
        {
            TFrac f, g;
            string str = "";
            try
            {
                f = new TFrac("10/11");
                g = f.minus();
                str = g.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "-10/11");
        }
        [TestMethod]
        public void TestMethod7SubResult()
        {
            TFrac f, g, res;
            string str = "";
            try
            {
                f = new TFrac("10/11");
                g = new TFrac("9/11");
                res = f.sub(f, g);
                str = res.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "1/11");
        }
        [TestMethod]
        public void TestMethod8IsMoreThanParameter()
        {
            TFrac f, g, res;
            string str = "";
            bool bl = false; ;
            try
            {
                f = new TFrac("10/11");
                g = new TFrac("9/11");
                bl = f.isMoreThanParameter_d(g);                
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(bl, true);
        }
        [TestMethod]
        public void TestMethod9Clone()
        {
            TFrac f, g, res;
            string str = "";
            bool bl = false; ;
            try
            {
                f = new TFrac("35/22");
                g =  (TFrac)f.Clone();
                str = g.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "35/22");
        }
        [TestMethod]
        public void TestMethod10Square()
        {
            TFrac f, g, res;
            string str = "";
            bool bl = false; ;
            try
            {
                f = new TFrac("12/3");
                g = f.sqr(f);
                str = g.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "16");
        }
        [TestMethod]
        public void TestMethod11Reciprocal()
        {
            TFrac f, g, res;
            string str = "";
            bool bl = false; ;
            try
            {
                f = new TFrac("11/3");
                g = f.fractionsReciprocal(f);
                str = g.ToString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "3/11");
        }
        [TestMethod]
        public void TestMethod12ThisEqualsToParameter()
        {
            TFrac f, g, res;
            string str = "";
            bool bl = false; ;
            try
            {
                f = new TFrac("11/3");
                g = new TFrac("11/3");
                bl = g.thisEqualToParameter_d(f);
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(bl,true);
        }
        [TestMethod]
        public void TestMethod13GetNumerator()
        {
            TFrac f, g, res;
            string str = "";
            bool bl = false; ;
            int num = 0;
            try
            {
                f = new TFrac("11/3");
                num = f.getNumerator();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(num, 11);
        }
        [TestMethod]
        public void TestMethod14getNumeratorString()
        {
            TFrac f, g, res;
            string str = "";          
            try
            {
                f = new TFrac(11, 3);
                str = f.getNumeratorString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "11");
        }
        [TestMethod]
        public void TestMethod15getFractionString()
        {
            TFrac f, g, res;
            string str = "";
            try
            {
                f = new TFrac(111, 3);
                str = f.getFractionString();
            }
            catch (Exception ex)
            {

            }
            Assert.AreEqual(str, "111/3");
        }
    }
}
