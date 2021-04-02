#nullable enable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace PhoneBook
{
    [Serializable]
    public class SubscriberCollection : IEnumerable<Subscriber>, IEnumerable
    {
        private SortedDictionary<string, Subscriber> items;

        public int Count => items.Count;

        public SubscriberCollection()
        {
            items = new SortedDictionary<string, Subscriber>();
        }

        public void Add(Subscriber subscriber)
        {
            if (!items.TryAdd(subscriber.Name, subscriber))
            {
                string msg = $"Collection already contains subscriber with name '{subscriber.Name}'";
                throw new ArgumentException(msg);
            }
        }

        public void RemoveByName(string name)
        {
            if (!items.Remove(name))
            {
                string msg = $"Collection doesn't contain subscriber with name '{name}'";
                throw new ArgumentException(msg);
            }
        }

        public bool ContainsName(string name) => items.ContainsKey(name);

        public IEnumerator<Subscriber> GetEnumerator()
        {
            return items.Values.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return items.Values.GetEnumerator();
        }
    }
}
