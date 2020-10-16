using System;
using System.Collections;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using TYAP_Lab2_00;
namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1CheckingIfTheNewStateBelongsToTheSetOfStates()
        {
            ArrayList rowsHeadersIE_States = new ArrayList();
            rowsHeadersIE_States.Add("q");
            rowsHeadersIE_States.Add("r");
            rowsHeadersIE_States.Add("p");
            Form1 fm = new Form1();//можно было конечно не подгонять метод под тест, а здесь просто объекту fm 
            //инициализировать его родной ArrayList, но уже поздно, пусть останется в назидание.
            bool x = fm.checkIfTheStringBelongsToArrayList(rowsHeadersIE_States, "r");
            Assert.IsTrue(x);
        }
    }
}
