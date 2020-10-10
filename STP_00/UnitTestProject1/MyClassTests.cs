using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_00;
namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void Shift_Right_result_2()
        {
            //arrange(обеспечить)
            int[] result = new int[] { 1, 2 };//Исходный массив.
            int p = 1;
            int[] expected = new int[] { 2, 1 };//Ожидаемое значение.
                                                //act(выполнить)
            MyClass.moveCyclicRight(ref result, p);
            //assert(доказать)
            CollectionAssert.AreEqual(expected, result);//Оракул
        }
    }
}
