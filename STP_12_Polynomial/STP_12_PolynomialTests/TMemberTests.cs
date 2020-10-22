using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_12_Polynomial;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_12_Polynomial.Tests
{
    [TestClass()]
    public class TMemberTests 
    {
        [TestMethod()]
        public void TMemberTestEmpty()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember());
            TMember tm1 = (TMember)arr[0];
            Assert.AreEqual(tm1.ToString(), "0*x^0");
        }

        [TestMethod()]
        public void TMemberTest2Parameters()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(12, 6));
            TMember tm1 = (TMember)arr[0];          
            Assert.AreEqual(tm1.ToString(), "12*x^6");
        }

        [TestMethod()]
        public void getPowerTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(3, 2));
            TMember tm1 = (TMember)arr[0];
            int t = tm1.getPower();
            Assert.AreEqual(t, 2);
        }

        [TestMethod()]
        public void getCoefficientTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(3, 2));
            TMember tm1 = (TMember)arr[0];
            int t = tm1.getCoefficient();
            Assert.AreEqual(t, 3);
        }

        [TestMethod()]
        public void ClearTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(3, 2));
            TMember tm1 = (TMember)arr[0];
            tm1.Clear(ref tm1);
            Assert.AreEqual(tm1.ToString(), "0*x^0");
        }

        [TestMethod()]
        public void setPowerTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(3, 2));
            TMember tm1 = (TMember)arr[0];
            tm1.setPower(5);
            Assert.AreEqual(tm1.getPower(), 5);
        }

        [TestMethod()]
        public void setCoefficientTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(3, 2));
            TMember tm1 = (TMember)arr[0];
            tm1.setCoefficient(5);
            Assert.AreEqual(tm1.getCoefficient(), 5);
        }

        [TestMethod()]
        public void equalsTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(3, 2));
            arr.Add(new TMember(3, 2));
            TMember tm1 = (TMember)arr[0];
            TMember tm2 = (TMember)arr[1];
            bool x = tm1.equals(tm2);
            Assert.IsTrue(x);
        }

        [TestMethod()]
        public void differentiateTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 2));
            arr.Add(new TMember(4, 8));
            TMember tm = (TMember)arr[2];
            tm.differentiate();
            Assert.AreEqual(tm.ToString(), "32*x^7");
        }

        [TestMethod()]
        public void calculateTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 2));
            TMember tm = (TMember)arr[1];
            double res = tm.calculate(3.0);
            Assert.AreEqual(res, 27);
        }

        [TestMethod()]
        public void ToStringTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            string str = arr[0].ToString();
            Assert.AreEqual(str, "2*x^5");
        }

    }
}