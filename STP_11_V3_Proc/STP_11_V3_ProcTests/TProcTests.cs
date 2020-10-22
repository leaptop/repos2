using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_11_V3_Proc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_11_V3_Proc.Tests
{
    [TestClass()]
    public class TProcTests
    {
        [TestMethod()]
        public void TProcTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>();
            Assert.AreEqual(tp.readLeftOperand().ToString(), "0");
        }

        [TestMethod()]
        public void TProcTest1()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(1, 7), new TFrac(1, 6));
            Assert.AreEqual(tp.readRightOperand().ToString(), "1/6");
        }

        [TestMethod()]
        public void ReloadProcessorTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(1, 7), new TFrac(1, 6));
            tp.ReloadProcessor();

            Assert.AreEqual(tp.readState(), "None");
        }

        [TestMethod()]
        public void DropOperationTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(1, 7), new TFrac(1, 6));
            tp.DropOperation();

            Assert.AreEqual(tp.readState(), "None");
        }

        [TestMethod()]
        public void executeOperationTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(1, 7), new TFrac(1, 6));
            tp.writeState("mul");
            tp.executeOperation();
            Assert.AreEqual(tp.readLeftOperand().ToString(), "1/42");
        }

        [TestMethod()]
        public void executeFunctionTest()
        {
            TProc<TComplex> tp = new TProc<TComplex>(new TComplex(1, 7), new TComplex(1, 6));
            tp.executeFunction("sqr");
            Assert.AreEqual(tp.readLeftOperand().ToString(), "-48+i*14");
        }

        [TestMethod()]
        public void readLeftOperandTest()
        {
            TProc<TComplex> tp = new TProc<TComplex>(new TComplex(1, 7), new TComplex(1, 6));
            Assert.AreEqual(tp.readLeftOperand().ToString(), "1+i*7");
        }

        [TestMethod()]
        public void writeLeftOperandTest()
        {
            TProc<TPNumber> tp = new TProc<TPNumber>(new TPNumber(11, 10, 1), new TPNumber(15, 10, 1));
            TPNumber tpn = new TPNumber("AB,0", 16, 1);
            tp.writeLeftOperand(tpn);

            Assert.AreEqual(tp.readLeftOperand().ToString(), "AB,0");
        }

        [TestMethod()]
        public void readRightOperandTest()
        {
            TProc<TComplex> tp = new TProc<TComplex>(new TComplex(1, 7), new TComplex(1, 6));
            Assert.AreEqual(tp.readRightOperand().ToString(), "1+i*6");            
        }

        [TestMethod()]
        public void writeRightOperandTest()
        {
            TProc<TPNumber> tp = new TProc<TPNumber>(new TPNumber(11, 10, 1), new TPNumber(15, 10, 1));
            TPNumber tpn = new TPNumber("AB,0", 16, 1);
            tp.writeRightOperand(tpn);

            Assert.AreEqual(tp.readRightOperand().ToString(), "AB,0");
            
        }

        [TestMethod()]
        public void readStateTest()
        {
            TProc<TPNumber> tp = new TProc<TPNumber>();
            Assert.AreEqual(tp.readState(), "None");
        }

        [TestMethod()]
        public void writeStateTest()
        {
            TProc<TPNumber> tp = new TProc<TPNumber>();
            tp.writeState("dvd");
            Assert.AreEqual(tp.readState(), "dvd");
        }

        [TestMethod()]
        public void addTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(1, 7), new TFrac(1, 6));
            tp.writeState("add");
            tp.executeOperation();
            Assert.AreEqual(tp.readLeftOperand().ToString(), "13/42");
        }

        [TestMethod()]
        public void mulTest()
        {
            TProc<TComplex> tp = new TProc<TComplex>(new TComplex(1, 7), new TComplex(1, 6));
            tp.writeState("mul");
            tp.executeOperation();
            Assert.AreEqual(tp.readLeftOperand().ToString(), "-41+i*13");
        }

        [TestMethod()]
        public void subTest()
        {
            TProc<TComplex> tp = new TProc<TComplex>(new TComplex(1, 7), new TComplex(1, 6));
            tp.writeState("sub");
            tp.executeOperation();
            Assert.AreEqual(tp.readLeftOperand().ToString(), "0+i*1");
        }

        [TestMethod()]
        public void dvdTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(1, 7), new TFrac(1, 6));
            tp.writeState("dvd");
            tp.executeOperation();
            Assert.AreEqual(tp.readLeftOperand().ToString(), "6/7");
        }       

        [TestMethod()]
        public void revTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(2, 7), new TFrac(1, 6));
            tp.executeFunction("rev");
            Assert.AreEqual(tp.readLeftOperand().ToString(), "7/2");
        }

        [TestMethod()]
        public void sqrTest()
        {
            TProc<TFrac> tp = new TProc<TFrac>(new TFrac(2, 7), new TFrac(1, 6));
            tp.executeFunction("sqr");
            Assert.AreEqual(tp.readLeftOperand().ToString(), "4/49");
        }
    }
}