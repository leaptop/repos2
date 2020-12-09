using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_01_changingTheTypeToDotNetFramework;
namespace MytProject_1_Tests
{
    [TestClass]
    public class MyClassTests
    {
        [TestMethod]
        public void Shift_Right_result_2()
        {
            //arrange(обеспечить)
            double[] result = new double[] { 1, 2 };//Исходный массив.
            int p = 1;
            double[] expected = new double[] { 2, 1 };//Ожидаемое значение.
                                                      //act(выполнить)
            MyClass.moveCyclicRight(ref result, p);
            //assert(доказать)
            CollectionAssert.AreEqual(expected, result);//Оракул
        }
        [TestMethod]
        public void multiplyOddIndexes_result_19_78()
        {
            //arrange(обеспечить)
            double[] arr = { 1, 2.3, 3.1, 8.6 };//2.3*8.6=19,78//Исходный массив.
            double expected = 19.78d;//Ожидаемое значение.
                                     //act(выполнить)
            double result = MyClass.multiplyOddIndexes(arr);
            //assert(доказать)
            Assert.AreEqual(result, expected, 0.00000001d, "maybe delta isn't small enough");
        }
        [TestMethod]
        public void sToInt_bBase_58_16_34375()
        {
            string s = "58";
            int b = 16;
            int expected = 34375;
            int result = MyClass.sToInt_bBase(s, b);
            //assert(доказать)
            Assert.AreEqual(expected, result);
        }
    }
}
