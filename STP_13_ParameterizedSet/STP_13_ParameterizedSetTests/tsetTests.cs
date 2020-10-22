using Microsoft.VisualStudio.TestTools.UnitTesting;
using STP_13_ParameterizedSet;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using STP_13_ParameterizedSet;
namespace STP_13_ParameterizedSet.Tests
{
    [TestClass()]
    public class tsetTests
    {
        [TestMethod()]
        public void tsetTest()
        {
            tset<int> ts = new tset<int>();
            Assert.IsTrue(ts.isEmpty());
        }

        [TestMethod()]
        public void ClearTest()
        {
            tset<int> ts = new tset<int>();
            ts.add(15);
            ts.add(27);
            Assert.IsTrue(ts.getNumberOfElements() == 2);
            ts.Clear();
            Assert.IsTrue(ts.getNumberOfElements() == 0);
        }

        [TestMethod()]
        public void addTest()
        {
            var s = new tset<string>();
            s.add("qwerty");
            Assert.IsTrue(s.getNumberOfElements() == 1);
            Assert.IsTrue(s.contains("qwerty"));

            s.add("500");
            Assert.IsTrue(s.getNumberOfElements() == 2);
            Assert.IsTrue(s.contains("500"));
        }

        [TestMethod()]
        public void removeTest()
        {
            var s = new tset<string>();
            s.add("a string");
            Assert.IsTrue(s.Contains("a string"));
            s.remove(("a string"));
            Assert.IsFalse(s.Contains("a string"));
        }

        [TestMethod]
        public void TestForDuplicatesInsertion()
        {
            var s = new tset<string>();
            s.add("hi there");
            Assert.AreEqual(1, s.getNumberOfElements());

            s.add("hi there");
            Assert.AreEqual(1, s.getNumberOfElements());
        }

        [TestMethod()]
        public void isEmptyTest()
        {
            var s = new tset<string>();
            s.add("hi there");
            s.Clear();
            Assert.IsTrue(s.isEmpty());
        }

        [TestMethod()]
        public void containsTest()
        {
            var s = new tset<string>();
            s.add("hi there");
            Assert.IsTrue(s.contains("hi there"));
            s.Clear();
            Assert.IsFalse(s.contains("hi there"));
        }

        [TestMethod()]
        public void unifySetsTest()
        {
            tset<int> ts = new tset<int>();
            ts.add(10);
            ts.add(19);
            tset<int> ts2 = new tset<int>();
            ts2.add(207);
            ts2.add(307);
            var ts3 = ts.unifySets(ts2);
            Assert.IsTrue(ts3.getNumberOfElements() == 4);
            Assert.IsTrue(ts3.contains(207));

        }    

        [TestMethod()]
        public void deleteOtherFromThisTest()
        {
            tset<int> ts = new tset<int>();
            ts.add(10);
            ts.add(19);
            ts.add(100);
            ts.add(190);
            tset<int> ts2 = new tset<int>();
            ts2.add(19);
            ts2.add(307);
            tset<int> ts3 = ts.deleteOtherFromThis(ts2);
            Assert.AreEqual(ts3.getNumberOfElements(), 3);
            Assert.IsTrue(ts3.contains(190));
            Assert.IsFalse(ts3.contains(19));
        }

        [TestMethod()]
        public void intersectionTest()
        {
            tset<int> ts = new tset<int>();
            ts.add(10);
            ts.add(19);
            ts.add(100);
            ts.add(190);
            tset<int> ts2 = new tset<int>();
            ts2.add(19);
            ts2.add(307);
            ts2.add(100);
            ts2.add(407);
            tset<int> ts3 = ts.intersection(ts2);
            Assert.AreEqual(ts3.getNumberOfElements(), 2);
            Assert.IsTrue(ts3.contains(100));
            Assert.IsFalse(ts3.contains(10));
        }

        [TestMethod()]
        public void getNumberOfElementsTest()
        {
            tset<int> ts2 = new tset<int>();
            ts2.add(19);
            ts2.add(307);
            ts2.add(100);
            Assert.AreEqual(ts2.getNumberOfElements(), 3);
        }

        [TestMethod()]
        public void getjthElementTest()
        {
            tset<int> ts2 = new tset<int>();
            ts2.add(19);
            ts2.add(307);
            ts2.add(100);
            ts2.add(307);
            Assert.AreEqual(ts2.getjthElement(1), 307);
        }
        [TestMethod]
        public void TestIndexer()
        {
            var s = new tset<int>();
            s.add(5);
            s.add(4);
            s.add(8);
            Assert.AreEqual(5, s[0]);
            Assert.AreEqual(4, s[1]);
            Assert.AreEqual(8, s[2]);
            int y;
            s.remove(4);
            Assert.AreEqual(8, s[1]);
            Assert.ThrowsException<IndexOutOfRangeException>(() => y = s[5]);
            Assert.ThrowsException<IndexOutOfRangeException>(() => _ = s[6]);
        }
    }
}