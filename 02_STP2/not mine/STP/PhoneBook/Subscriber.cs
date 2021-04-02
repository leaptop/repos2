#nullable enable

using System;
using System.Collections.Generic;
using System.Text;

namespace PhoneBook
{
    [Serializable]
    public class Subscriber
    {
        private string name;

        public string Name
        {
            get => name;
            set
            {
                if (string.IsNullOrEmpty(value))
                {
                    throw new ArgumentException("Value is empty");
                }
                name = value;
            }
        }
        
        public List<string> PhoneNumbers { get; private set; }

        public string PhoneNumbersNewlineSeparated => string.Join("\n", PhoneNumbers);

        public Subscriber(string name)
        {
            this.name = name;
            PhoneNumbers = new List<string>();
        }
    }
}
