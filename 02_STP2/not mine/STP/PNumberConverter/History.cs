using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Lab1
{
    class History : IEnumerable<HistoryRecord>
    {
        private List<HistoryRecord> records;

        public int Count => records.Count;

        public History()
        {
            records = new List<HistoryRecord>();
        }

        public HistoryRecord this[int i]
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

        public void AddRecord(HistoryRecord record)
        {
            records.Add(record);
        }

        public void Clear()
        {
            records.Clear();
        }

        public IEnumerator<HistoryRecord> GetEnumerator() 
            => records.GetEnumerator();

        IEnumerator IEnumerable.GetEnumerator() 
            => records.GetEnumerator();
    }
}
