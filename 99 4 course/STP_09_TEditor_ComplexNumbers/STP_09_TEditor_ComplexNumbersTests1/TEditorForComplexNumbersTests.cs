using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_09_TEditor_ComplexNumbers;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_05_ComplexNumber;
namespace STP_09_TEditor_ComplexNumbers.Tests
{
    [TestClass()]
    public class TEditorForComplexNumbersTests
    {
        [TestMethod()]
        public void addADigitTest()
        {
            TEditorForComplexNumbers te = new TEditorForComplexNumbers();
            TComplex tc = new TComplex(-55, 10);
            tc = te.addADigit(tc, 2, 4);
            Assert.AreEqual(tc.ToString(), "-545+i*10");
        }

        [TestMethod()]
        public void change_a_and_b_signsByMultiplyingThemByMinusOneTest()
        {
            TEditorForComplexNumbers te = new TEditorForComplexNumbers();
            TComplex tc = new TComplex(-55, 10);
            tc = te.change_a_and_b_signsByMultiplyingThemByMinusOne(tc, -1, -1);
            Assert.AreEqual(tc.ToString(), "55-i*10");
        }
        [TestMethod()]
        public void change_a_and_b_signsByMultiplyingThemByMinusOneTestException()
        {
            bool exceptionWasThrown = false;
            try
            {
                TEditorForComplexNumbers te = new TEditorForComplexNumbers();
                TComplex tc = new TComplex(-55, 10);
                tc = te.change_a_and_b_signsByMultiplyingThemByMinusOne(tc, -10, -1);                
            }
            catch (WrongInputException)
            {
                exceptionWasThrown = true;
            }
            Assert.IsTrue(exceptionWasThrown);
        }

        [TestMethod()]
        public void shiftFloatingPointOf_re_or_imTest()
        {
            TEditorForComplexNumbers te = new TEditorForComplexNumbers();
            TComplex tc = new TComplex(-55, 11);
            tc = te.shiftFloatingPointOf_re_or_im(tc, 2, 1);
            Assert.AreEqual(tc.ToString(), "-5,5+i*1,1");
        }

        [TestMethod()]
        public void backspaceTest()
        {
            TEditorForComplexNumbers te = new TEditorForComplexNumbers();
            TComplex tc = new TComplex(-55, 11);
            string str = te.backspace(tc);
            Assert.AreEqual(str, "-55+i*1");
        }

        [TestMethod()]
        public void ClearTest()
        {
            TEditorForComplexNumbers te = new TEditorForComplexNumbers();
            TComplex tc = new TComplex(-55, 11);
            tc = te.Clear(tc);
            Assert.AreEqual(tc.ToString(), "0");
        }

        [TestMethod()]
        public void getStringOfTComplexTest()
        {
            TEditorForComplexNumbers te = new TEditorForComplexNumbers();
            TComplex tc = new TComplex(-55, -11);
            string str = te.getStringOfTComplex(tc);
            Assert.AreEqual(str, "-55-i*11");
        }
    }
}