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
    public class TPolyTests
    {
        [TestMethod()]
        public void findPolynomesPowerTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 12));
            arr.Add(new TMember(4, 8));
            TPoly tp = new TPoly(arr);
           int i = tp.findPolynomesPower();
            Assert.AreEqual(i, 12);
        }

        [TestMethod()]
        public void findCoefficientByPowerTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 12));
            arr.Add(new TMember(4, 8));
            TPoly tp = new TPoly(arr);
            int i = tp.findCoefficientByPower(8);
            Assert.AreEqual(i, 4);
        }

        [TestMethod()]
        public void ClearTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 12));
            arr.Add(new TMember(4, 8));
            TPoly tp = new TPoly(arr);
           tp = tp.Clear();
            Assert.AreEqual(tp.ToString(), "(0*x^0)");
        }

        [TestMethod()]
        public void addTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 2));
            arr.Add(new TMember(4, 8));
            TPoly tp = new TPoly(arr);
            ArrayList arr2 = new ArrayList();
            arr2.Add(new TMember(2, 5));
            arr2.Add(new TMember(3, 2));
            arr2.Add(new TMember(4, 8));
            arr2.Add(new TMember(71, 15));
            TPoly tp2 = new TPoly(arr2);
            tp.add(tp2);
            string str = tp.ToString();
            Assert.AreEqual("(6*x^2) + (4*x^5) + (8*x^8) + (71*x^15)", str);

        }

        [TestMethod()]
        public void mulTest()
        {
            ArrayList arr1 = new ArrayList();
            arr1.Add(new TMember(2, 3));
            arr1.Add(new TMember(-3, 4));
            TPoly tp1 = new TPoly(arr1);

            ArrayList arr2 = new ArrayList();            
            arr2.Add(new TMember(3, 5));
            arr2.Add(new TMember(5, 10));
            TPoly tp2 = new TPoly(arr2);
            TPoly tp3 = tp1.mul(tp2);

            Assert.AreEqual("(6*x^8) + (-9*x^9) + (10*x^13) + (-15*x^14)", tp3.ToString());
        }

        [TestMethod()]
        public void subTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 2));
            arr.Add(new TMember(4, 8));
            //TMember tm = (TMember)arr[2];
            TPoly tp = new TPoly(arr);
            ArrayList arr2 = new ArrayList();
            arr2.Add(new TMember(2, 5));
            arr2.Add(new TMember(3, 2));
            arr2.Add(new TMember(3, 8));
            arr2.Add(new TMember(71, 15));
            TPoly tp2 = new TPoly(arr2);
            tp.sub(tp2);
            string str = tp.ToString();
            Assert.AreEqual("(1*x^8) + (-71*x^15)", str);
        }

        [TestMethod()]
        public void minusTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 2));
            arr.Add(new TMember(4, 8));
            TPoly tp = new TPoly(arr);
        }

        [TestMethod()]
        public void equalsTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));
            arr.Add(new TMember(3, 2));
            arr.Add(new TMember(4, 8));
            TPoly tp = new TPoly(arr);

            ArrayList arr2 = new ArrayList();
            arr2.Add(new TMember(3, 2));
            arr2.Add(new TMember(2, 5));
            arr2.Add(new TMember(4, 8));
            TPoly tp2 = new TPoly(arr2);
            Assert.IsTrue(tp.equals(tp2));
        }

        [TestMethod()]
        public void diffirentiateTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 5));//10x^4
            arr.Add(new TMember(3, 2));//6x^1
            arr.Add(new TMember(4, 8));//32x^7
            TPoly tp = new TPoly(arr);
            tp = tp.diffirentiate();
            Assert.AreEqual(tp.ToString(), "(10*x^4) + (6*x^1) + (32*x^7)");
        }

        [TestMethod()]
        public void calculateTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 3));//16
            arr.Add(new TMember(3, 2));//12
            arr.Add(new TMember(4, 2));//16
            TPoly tp = new TPoly(arr);
            double res = tp.calculate(2);
            Assert.AreEqual(res, 44);
        }

        [TestMethod()]
        public void ToStringTest()
        {
            ArrayList arr = new ArrayList();
            arr.Add(new TMember(2, 3));
            arr.Add(new TMember(3, 2));          
            TPoly tp = new TPoly(arr);           
            Assert.AreEqual(tp.ToString(), "(2*x^3) + (3*x^2)");
        }
    }
}