using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_04_ADT_TFrac;
using STP_08_TEditorForCommonFraction;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_08_TEditorForCommonFraction.Tests
{
    [TestClass()]
    public class TEditorForCommonFractionTests
    {
        TFrac tf = new TFrac(0, 1);
        TEditorForCommonFraction te = new TEditorForCommonFraction();
        [TestMethod()]
        public void addADigitTest()
        {
            te.addADigit(ref tf, 3, 0);
            Assert.AreEqual(tf.f, "30/1");
        }

        [TestMethod()]
        public void multiplyByMinusTest()
        {
            TFrac tf2 = new TFrac(35, 1);
            TEditorForCommonFraction te = new TEditorForCommonFraction();
            TFrac tfMinus = te.multiplyByMinus( tf2);
            Assert.AreEqual(tfMinus.f, "-35/1");
        }

        [TestMethod()]
        public void addADelimeterBetweenNumeratorAndDenominatorTest()
        {
            TFrac tf2 = new TFrac(36, 1);
            TEditorForCommonFraction te = new TEditorForCommonFraction();
            te.addADelimeterBetweenNumeratorAndDenominator(tf2, 1);
            Assert.AreEqual(tf2.f, "3/61");
        }

        [TestMethod()]
        public void backSpaceTest()
        {
            TFrac tf2 = new TFrac(36, 1);
            TEditorForCommonFraction te = new TEditorForCommonFraction();
            te.addADelimeterBetweenNumeratorAndDenominator(tf2, 1);
            Assert.AreEqual(tf2.f, "3/61");
        }

        [TestMethod()]
        public void ClearTest()
        {
            TFrac tf2 = new TFrac(36, 1);
            TEditorForCommonFraction te = new TEditorForCommonFraction();
            te.Clear(ref tf2);
            Assert.AreEqual(tf2.f, "0/1");
        }

        [TestMethod()]
        public void readFractionStringTest()
        {
            TFrac tf2 = new TFrac(36, 7);
            TEditorForCommonFraction te = new TEditorForCommonFraction();
          string str =  te.readFractionString(tf2);
            Assert.AreEqual(str, "36/7");
        }

        [TestMethod()]
        public void writeNewFToFractionTest()
        {
            TFrac tf2 = new TFrac(36, 7);
            TEditorForCommonFraction te = new TEditorForCommonFraction();
            te.writeNewFToFraction(ref tf2, "27/4");
            Assert.AreEqual(tf2.f, "27/4");
        }
    }
}