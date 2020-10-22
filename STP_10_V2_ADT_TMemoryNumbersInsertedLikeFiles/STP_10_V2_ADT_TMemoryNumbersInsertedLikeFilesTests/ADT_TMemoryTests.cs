using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles;
namespace STP_10_V2_ADT_TMemoryNumbersInsertedLikeFiles.Tests
{
    [TestClass()]
    public class ADT_TMemoryTests
    {
        [TestMethod()]
        public void ADT_TMemoryTestAdd2parameters()
        {
            ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(new TFrac(1, 13));
            ADT_TMemory<TFrac> newNumber2 = new ADT_TMemory<TFrac>(new TFrac(1, 13));
            // TFrac tf = newNumber.add(newNumber.FNumber, newNumber2.FNumber);
            newNumber.FNumber = newNumber.add(newNumber.FNumber, newNumber2.FNumber);
            // Console.WriteLine("newNumber.FNumber.ToString() = " + newNumber.FNumber.ToString());
            Assert.AreEqual("2/13", newNumber.FNumber.ToString());
        }

        [TestMethod()]
        public void ADT_TMemoryTest1()
        {
            ADT_TMemory<TComplex> newNumber = new ADT_TMemory<TComplex>(new TComplex(1, 13));
            ADT_TMemory<TComplex> newNumber2 = new ADT_TMemory<TComplex>(new TComplex(1, 13));
            newNumber.FNumber = newNumber.add(newNumber.FNumber, newNumber2.FNumber);
            Assert.AreEqual("2+i*26", newNumber.FNumber.ToString());
        }

        [TestMethod()]
        public void writeTest()
        {
            ADT_TMemory<TComplex> newNumber = new ADT_TMemory<TComplex>(new TComplex(1, 13));
            ADT_TMemory<TComplex> newNumber2 = new ADT_TMemory<TComplex>(new TComplex(24, -2));
            newNumber.write(newNumber2.FNumber);
            Assert.AreEqual("24-i*2", newNumber.FNumber.ToString());
        }

        [TestMethod()]
        public void getTest()
        {
            ADT_TMemory<TComplex> newNumber = new ADT_TMemory<TComplex>(new TComplex(1, -13));
            ADT_TMemory<TComplex> newNumber2 = new ADT_TMemory<TComplex>(new TComplex());
            newNumber2.FNumber = newNumber.get();
            Assert.AreEqual("1-i*13", newNumber2.FNumber.ToString());
        }

        [TestMethod()]
        public void addTest1parameter()
        {
            ADT_TMemory<TPNumber> newNumber = new ADT_TMemory<TPNumber>(new TPNumber("1,0", 16, 5));
            ADT_TMemory<TPNumber> newNumber2 = new ADT_TMemory<TPNumber>(new TPNumber("9,0", 16, 5));
            newNumber.add(newNumber2.FNumber);
            Assert.AreEqual("A,00000", newNumber.FNumber.ToString());
        }


        [TestMethod()]
        public void ClearTest()
        {
            ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(new TFrac(1, 13));
            newNumber.Clear();
            Assert.AreEqual("0", newNumber.FNumber.ToString());
        }

        [TestMethod()]
        public void readMemoryStateTest()
        {
            ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(new TFrac(1, 13));
            string str = newNumber.readMemoryState();
            Assert.AreEqual("_On", str);
        }

        [TestMethod()]
        public void readNumberTest()
        {
            ADT_TMemory<TFrac> newNumber = new ADT_TMemory<TFrac>(new TFrac(1, 13));
            TFrac tf = newNumber.readNumber();
            Assert.AreEqual(tf.ToString(), "1/13");
        }
    }
}