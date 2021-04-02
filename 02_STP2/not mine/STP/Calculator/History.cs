using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    class History : IEnumerable<IHistoryRecord>
    {
        private List<IHistoryRecord> records;

        public int Count => records.Count;

        public IHistoryRecord this[int i]
        {
            get
            {
                if (i < 0 || i >= Count)
                {
                    throw new IndexOutOfRangeException();
                }
                return records[i];
            }
        }

        public History()
        {
            records = new List<IHistoryRecord>();
        }

        public void AddRecord(IHistoryRecord record)
        {
            if (record == null)
            {
                throw new ArgumentNullException(nameof(record));
            }
            records.Add(record);
        }

        public void Clear() => records.Clear();

        public IEnumerator<IHistoryRecord> GetEnumerator() 
            => records.GetEnumerator();

        IEnumerator IEnumerable.GetEnumerator() 
            => records.GetEnumerator();
    }
}
