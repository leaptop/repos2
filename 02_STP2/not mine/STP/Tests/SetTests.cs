using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Numbers;
using Sets;

namespace Tests
{
    [TestClass]
    public class SetTests
    {
        [TestMethod]
        public void TestCtorCreatesEmptySet()
        {
            var s = new Set<int>();
            Assert.IsTrue(s.IsEmpty);
            Assert.AreEqual(0, s.Count);
        }

        [TestMethod]
        public void TestAddDoesAddItems()
        {
            var s = new Set<string>();
            s.Add("abc");
            Assert.AreEqual(1, s.Count);
            Assert.IsTrue(s.Contains("abc"));

            s.Add("1234");
            Assert.AreEqual(2, s.Count);
            Assert.IsTrue(s.Contains("1234"));
        }

        [TestMethod]
        public void TestRemoveDoesRemoveItems()
        {
            var s = new Set<Fraction>();
            s.Add(new Fraction(10, 1));
            Assert.IsTrue(s.Contains(new Fraction(10, 1)));
            s.Remove(new Fraction(10, 1));
            Assert.IsFalse(s.Contains(new Fraction(10, 1)));

            s.Add(new Fraction(0, 1));
            Assert.IsTrue(s.Contains(new Fraction(0, 1)));
            Assert.IsFalse(s.Contains(new Fraction(10, 1)));
            s.Remove(new Fraction(0, 1));
            Assert.IsFalse(s.Contains(new Fraction(0, 1)));
        }

        [TestMethod]
        public void TestAddDoesntAddTwice()
        {
            var s = new Set<string>();
            s.Add("do class if");
            Assert.AreEqual(1, s.Count);
            
            s.Add("do class if");
            Assert.AreEqual(1, s.Count);
        }

        [TestMethod]
        public void TestUnionCreatesActualUnion()
        {
            var a = new Set<int>();
            a.Add(1);
            a.Add(2);
            a.Add(3);
            a.Add(4);

            var b = new Set<int>();
            b.Add(2);
            b.Add(4);
            b.Add(6);
            b.Add(8);

            var u = a.Union(b);
            Assert.AreEqual(6, u.Count);
            
            Assert.IsTrue(u.Contains(1));
            Assert.IsTrue(u.Contains(2));
            Assert.IsTrue(u.Contains(3));
            Assert.IsTrue(u.Contains(4));
            Assert.IsTrue(u.Contains(6));
            Assert.IsTrue(u.Contains(8));
        }

        [TestMethod]
        public void TestExceptCreatesSetNotContainingItemsOfOtherSet()
        {

            var a = new Set<int>();
            a.Add(1);
            a.Add(2);
            a.Add(3);
            a.Add(4);

            var b = new Set<int>();
            b.Add(2);
            b.Add(4);
            b.Add(6);
            b.Add(8);

            var u = a.Except(b);
            Assert.AreEqual(2, u.Count);

            Assert.IsTrue(u.Contains(1));
            Assert.IsTrue(u.Contains(3));
            
            Assert.IsFalse(u.Contains(2));
            Assert.IsFalse(u.Contains(4));

            Assert.IsFalse(u.Contains(6));
            Assert.IsFalse(u.Contains(8));
        }

        [TestMethod]
        public void TestIntersectCreatesActualIntersection()
        {
            var a = new Set<int>();
            a.Add(1);
            a.Add(2);
            a.Add(3);
            a.Add(4);

            var b = new Set<int>();
            b.Add(2);
            b.Add(4);
            b.Add(6);
            b.Add(8);

            var u = a.Intersect(b);
            Assert.AreEqual(2, u.Count);

            Assert.IsTrue(u.Contains(2));
            Assert.IsTrue(u.Contains(4));

            Assert.IsFalse(u.Contains(1));
            Assert.IsFalse(u.Contains(3));

            Assert.IsFalse(u.Contains(6));
            Assert.IsFalse(u.Contains(8));
        }

        [TestMethod]
        public void TestIndexerReturnsActualItems()
        {
            var s = new Set<int>();
            s.Add(5);
            s.Add(4);
            s.Add(8);
            Assert.AreEqual(5, s[0]);
            Assert.AreEqual(4, s[1]);
            Assert.AreEqual(8, s[2]);

            s.Remove(4);
            Assert.AreEqual(8, s[1]);
        }

        [TestMethod]
        public void TestIndexerThrowsWhenIndexOutOfBounds()
        {
            var s = new Set<string>();
            s.Add("abc");
            s.Add("xyz");
            Assert.ThrowsException<IndexOutOfRangeException>(() => _ = s[2]);
            Assert.ThrowsException<IndexOutOfRangeException>(() => _ = s[200]);
            Assert.ThrowsException<IndexOutOfRangeException>(() => _ = s[-1]);
            Assert.ThrowsException<IndexOutOfRangeException>(() => _ = s[-200]);
        }

        [TestMethod]
        public void TestClearRemovesAllItems()
        {
            var s = new Set<int>();
            s.Add(10);
            s.Add(1);
            Assert.AreEqual(2, s.Count);
            Assert.IsFalse(s.IsEmpty);

            s.Clear();
            Assert.AreEqual(0, s.Count);
            Assert.IsTrue(s.IsEmpty);
            Assert.IsFalse(s.Contains(10));
            Assert.IsFalse(s.Contains(1));
        }
    }
}
