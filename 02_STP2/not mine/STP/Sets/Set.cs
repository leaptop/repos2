using System;
using System.Linq;
using System.Collections.Generic;

namespace Sets
{
    public class Set<T>
    {
        private List<T> items;

        public int Count => items.Count;

        public bool IsEmpty => Count == 0;

        public Set()
        {
            items = new List<T>();
        }

        private Set(IEnumerable<T> items)
        {
            this.items = new List<T>(items);
        }

        public void Clear()
        {
            items.Clear();
        }

        public bool Add(T newItem)
        {
            if (Contains(newItem))
            {
                return false;
            }
            items.Add(newItem);
            return true;
        }

        public bool Remove(T item) => items.Remove(item);

        public bool Contains(T item) => items.Contains(item);

        public Set<T> Union(Set<T> other)
        {
            var result = new Set<T>(this.items);
            foreach (var thatItem in other.items)
            {
                result.Add(thatItem);
            }
            return result;
        }

        public Set<T> Except(Set<T> other)
        {
            var result = new Set<T>(this.items);
            foreach (var thatItem in other.items)
            {
                result.Remove(thatItem);
            }
            return result;
        }

        public Set<T> Intersect(Set<T> other)
        {
            var resultItems = new List<T>();
            foreach (var item in this.items)
            {
                if (other.Contains(item))
                {
                    resultItems.Add(item);
                }
            }
            var result = new Set<T>(resultItems);
            return result;
        }

        public T this[int i]
        {
            get
            {
                if (i < 0 || i >= items.Count)
                {
                    throw new IndexOutOfRangeException();
                }
                return items[i];
            }
        }
    }
}
