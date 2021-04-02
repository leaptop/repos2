using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Numbers;
using Memory;

namespace Tests
{
    [TestClass]
    public class MemoryTests
    {
        [TestMethod]
        public void TestCtorSetsNumberToDefaultAndStateToOff()
        {
            var m = new Memory.Memory<Complex>();
            Assert.AreEqual(new Complex(), m.Number);
            Assert.AreEqual(MemoryState.Off, m.State);
        }

        [TestMethod]
        public void TestNumberPropertySetsStateToOn()
        {
            var m = new Memory.Memory<Fraction>();
            var f = new Fraction(2, 7);
            m.Number = f;
            Assert.AreEqual(f, m.Number);
            Assert.AreEqual(MemoryState.On, m.State);
        }

        [TestMethod]
        public void TestClearMethodSetsNumberToDefaultAndStateToOff()
        {
            var m = new Memory.Memory<PNumber>();
            var p = new PNumber(5, 9, 4);
            m.Number = p;
            m.Clear();
            Assert.AreEqual(new PNumber(), m.Number);
            Assert.AreEqual(MemoryState.Off, m.State);
        }

        [TestMethod]
        public void TestAddMethodActuallyCalcsSum()
        {
            var m = new Memory.Memory<Fraction>();
            var a = new Fraction(5, 12);
            var b = new Fraction(11, 24);
            var r = new Fraction(21, 24);
            m.Number = a;
            m.Add(b);
            Assert.AreEqual(r, m.Number);
        }

        [TestMethod]
        public void TestAddMethodSetsStateToOn()
        {
            var m = new Memory.Memory<Complex>();
            m.Add(new Complex(10, 20));
            Assert.AreEqual(MemoryState.On, m.State);
        }
    }
}
