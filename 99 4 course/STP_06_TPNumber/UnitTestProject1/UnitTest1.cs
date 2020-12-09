using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_06_TPNumber;
namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1dvoichnaiaA()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);// 24.36=11000.0101110
            tp.translateFromDecimalTo_b_basedNumber(tp.integerPartOfaInIntegerDecimal, tp.fractionalPartOfaInIntegerDecimal, tp.b, tp.c);
            Assert.AreEqual(tp.na, "11000");
        }
        [TestMethod]
        public void TestMethod1dvoichnaiaB()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);// 24.36=11000.0101110         
            tp.translateFromDecimalTo_b_basedNumber(tp.integerPartOfaInIntegerDecimal, tp.fractionalPartOfaInIntegerDecimal, tp.b, tp.c);
            Assert.AreEqual(tp.nb, "0101110");
        }
        [TestMethod]
        public void TestMethod2HexA()
        {
            TPNumber tp = new TPNumber(193.36, 16, 7);// 193.36=C1.5C28F5C28F6
            tp.translateFromDecimalTo_b_basedNumber(tp.integerPartOfaInIntegerDecimal, tp.fractionalPartOfaInIntegerDecimal, tp.b, tp.c);
            Assert.AreEqual(tp.na, "C1");
        }
        [TestMethod]
        public void TestMethod3CHETIRNADCATERICHNAIAA()
        {
            TPNumber tp = new TPNumber(193.36, 14, 7);// 193.36=DB.507BA8D
            tp.translateFromDecimalTo_b_basedNumber(tp.integerPartOfaInIntegerDecimal, tp.fractionalPartOfaInIntegerDecimal, tp.b, tp.c);
            Assert.AreEqual(tp.na, "DB");
        }
        [TestMethod]
        public void TestMethod3CHETIRNADCATERICHNAIAB()
        {
            TPNumber tp = new TPNumber(193.36, 14, 7);// 193.36=DB.507BA8D
            tp.translateFromDecimalTo_b_basedNumber(tp.integerPartOfaInIntegerDecimal, tp.fractionalPartOfaInIntegerDecimal, tp.b, tp.c);
            Assert.AreEqual(tp.nb, "507BA8D");
        }
        [TestMethod]
        public void TestMethodsetCString()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            tp.setCString("20");
            Assert.AreEqual(tp.c, 20);
        }
        [TestMethod]
        public void TestMethodsetCInteger()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            tp.setCInteger(20);
            Assert.AreEqual(tp.c, 20);
        }
        [TestMethod]
        public void TestMethodsetBaseInteger()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            tp.setBaseInteger(12);
            Assert.AreEqual(tp.b, 12);
        }
        [TestMethod]
        public void TestMethodgetCString()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
           string str = tp.getCString();
            Assert.AreEqual(str, "7");
        }
        [TestMethod]
        public void TestMethodgetBaseStringC()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            string str = tp.getBaseString();
            Assert.AreEqual(str, "2");
        }
        [TestMethod]
        public void TestMethodgetBase()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            int str = tp.getBase();
            Assert.AreEqual(str, 2);
        }
        [TestMethod]
        public void TestMethodgetn()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            string str = tp.getn();
            Assert.AreEqual(str, "11000,0101110");
        }
        [TestMethod]
        public void TestMethodgetnDecimal()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            double str = tp.getnDecimal();
            Assert.AreEqual(str, 24.36);
        }
        [TestMethod]
        public void TestMethodsquare()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            TPNumber str = tp.square();
            Assert.AreEqual(str.nDecimal, 593.4096);
        }
        [TestMethod]
        public void TestMethodadd()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            TPNumber tp2 = new TPNumber(20.36, 2, 7);
            TPNumber tp3 = tp2.add(tp);
            Assert.AreEqual(tp3.nDecimal, 44.72);
        }
        [TestMethod]
        public void TestMethodClone()
        {
            TPNumber tp = new TPNumber(24.36, 2, 7);
            TPNumber tp2 = (TPNumber) tp.Clone();
            
            Assert.AreEqual(tp2.nDecimal, 24.36);
        }
        [TestMethod]
        public void TestMethodStringConstructorFrac()
        {
            TPNumber tp = new TPNumber("212,22", 3, 7);//"212.22(троичная) = 23.888888888888(десятичная)


            Assert.AreEqual(tp.fractionalPartOfaInIntegerDecimal, 8888888);
        }
        [TestMethod]
        public void TestMethodStringConstructorInt()
        {
            TPNumber tp = new TPNumber("212,22", 3, 7);//"212.22(троичная) = 23.888888888888(десятичная)


            Assert.AreEqual(tp.integerPartOfaInIntegerDecimal, 23);
        }
        [TestMethod]
        public void TestMethodStringConstructorFracFifteenFrac()
        {
            TPNumber tp = new TPNumber("AB4C,B9A", 15, 7);//AB4C.B9A(пятнадцатеричная) = 36297.776296296(десятичная)


            Assert.AreEqual(tp.fractionalPartOfaInIntegerDecimal, 7762962);
        }
        [TestMethod]
        public void TestMethodStringConstructorIntFifteenInt()
        {
            TPNumber tp = new TPNumber("AB4C,B9A", 15, 7);//AB4C.B9A(пятнадцатеричная) = 36297.776296296(десятичная)


            Assert.AreEqual(tp.integerPartOfaInIntegerDecimal, 36297);
        }
        [TestMethod]
        public void TestMethodStringConstructorIntFifteennDecimal()
        {
            TPNumber tp = new TPNumber("AB4C,B9A", 15, 7);//AB4C.B9A(пятнадцатеричная) = 36297.776296296(десятичная)


            Assert.AreEqual(tp.nDecimal, 36297.7762962);
        }
    }
}
