using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_07TEditor;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_06_TPNumber;
namespace STP_07TEditor.Tests
{
    [TestClass()]
    public class TEditorTests
    {

        [TestMethod()]
        public void addADigitOrALetterTestException()
        {
            bool exceptionThrown = false;
            TPNumber tp = new TPNumber(546.164, 16, 7);
            TEditor te = new TEditor();
            try
            {
                te.addADigitOrALetter(tp, "Z", 4);
            }
            catch (Exception)
            {
                exceptionThrown = true;
            }
            Assert.IsTrue(exceptionThrown);
        }
        [TestMethod()]
        public void addADigitOrALetterTest()
        {
            bool exceptionThrown = false;
            TPNumber tp = new TPNumber("AC4D,A5", 16, 7);
            TEditor te = new TEditor();
            try
            {
                te.addADigitOrALetter(tp, "B", 4);
            }
            catch (Exception)
            {
                exceptionThrown = true;
            }
            Assert.AreEqual("AC4DB,A5", tp.n);
        }

        [TestMethod()]
        public void multiplyByMinusTest()
        {
            TPNumber tp = new TPNumber("AC4D,A5", 16, 7);
            TEditor te = new TEditor();
            te.multiplyByMinus(tp);
            Assert.AreEqual("-AC4D,A5", tp.n);
        }

        [TestMethod()]
        public void addADelimeterOfIntAndFracTest()
        {
            TPNumber tp = new TPNumber("AC4D,A5", 16, 7);
            TEditor te = new TEditor();
            te.addADelimeterOfIntAndFrac(tp, 2);
            Assert.AreEqual("AC,4DA5", tp.n);
        }

        [TestMethod()]
        public void backSpaceTest()
        {
            TPNumber tp = new TPNumber("AC4D,A5", 16, 7);
            TEditor te = new TEditor();
            te.backSpace(tp);
            Assert.AreEqual("AC4D,A", tp.n);
        }

        [TestMethod()]
        public void ClearTest()
        {
            TPNumber tp = new TPNumber("AC4D,A5", 16, 7);
            TEditor te = new TEditor();
            te.Clear(tp);
            Assert.AreEqual("0,0", tp.n);
        }
        TPNumber tpGeneral = new TPNumber("AC4D,A5", 16, 7);
        TEditor teGeneral = new TEditor();
        [TestMethod()]
        public void get_nStringTest()
        {
          string str =  teGeneral.get_nString(tpGeneral);
            Assert.AreEqual(str, "AC4D,A5");
        }

        [TestMethod()]
        public void set_nStringTest()
        {
            teGeneral.set_nString(tpGeneral, "123D");
            Assert.AreEqual(tpGeneral.n, "123D");
        }
    }
}