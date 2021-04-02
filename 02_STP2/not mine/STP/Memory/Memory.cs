using System;
using Numbers;

namespace Memory
{
    public class Memory<T> where T : INumber<T>, new()
    {
        private T number;

        public T Number {
            get => number;
            set
            {
                number = value;
                State = MemoryState.On;
            }
        }

        public MemoryState State { get; private set; }

        public Memory()
        {
            Clear();
        }

        public void Clear()
        {
            number = new T();
            State = MemoryState.Off;
        }

        public void Add(T other)
        {
            if (State == MemoryState.Off)
            {
                number = other;
                State = MemoryState.On;
                return;
            }
            number = number.Add(other);
            State = MemoryState.On;
        }
    }
}
