using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_13_ParameterizedSet
{
    public class tset<T>
    {
        private List<T> items;

        public tset()
        {
            items = new List<T>();
        }
        private tset(IEnumerable<T> items)//IEnumerable позволяет запускать циклы с объектами
        {
            this.items = new List<T>(items);
        }
        public void Clear()
        {
            items.Clear();
        }
        public void add(T d)
        {
            if (contains(d))
            {
                return;
            }
            items.Add(d);
        }
        public void remove(T d)
        {
            items.Remove(d);
        }
        public bool isEmpty()
        {
            return items.Count == 0;
        }
        public bool contains(T d)
        {
           return items.Contains(d);
        }
        public bool Contains(T item) => items.Contains(item);
        public tset<T> unifySets(tset<T> other)
        {
            var result = new tset<T>(this.items);
            foreach (var item in other.items)
            {
                result.add(item);
            }
            return result;
        }
        public tset<T> deleteOtherFromThis(tset<T> other)
        {
            var result = new tset<T>(this.items);
            foreach (var item in other.items)
            {
                result.remove(item);
            }
            return result;
        }
        public tset<T> intersection(tset<T> other)
        {
            var resultItems = new List<T>();
            foreach (var item in this.items)
            {
                if (other.contains(item))
                {
                    resultItems.Add(item);
                }
            }
            var result = new tset<T>(resultItems);
            return result;
        }
        public int getNumberOfElements()
        {
            return items.Count;
        }
        public T getjthElement(int j)
        {
            return items[j];
        }
        public T this[int i]
        {//индексатор
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