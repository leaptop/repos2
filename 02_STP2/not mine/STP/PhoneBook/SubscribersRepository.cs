using System;
using System.IO;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;

namespace PhoneBook
{
    class SubscribersRepository
    {
        public string Path { get; set; }

        public SubscribersRepository(string path)
        {
            Path = path;
        }

        public SubscriberCollection Read()
        {
            try
            {
                using var file = File.OpenRead(Path);
                var formatter = new BinaryFormatter();
                return (SubscriberCollection)formatter.Deserialize(file);
            }
            catch (FileNotFoundException)
            {
                return new SubscriberCollection();
            }
        }

        public void Write(SubscriberCollection subscribers)
        {
            using var file = File.OpenWrite(Path);
            var formatter = new BinaryFormatter();
            formatter.Serialize(file, subscribers);
        }
    }
}
