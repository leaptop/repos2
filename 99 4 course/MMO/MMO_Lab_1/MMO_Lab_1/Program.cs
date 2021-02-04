using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;
using System.Threading;
using System.Collections.Concurrent;

namespace MMO_Lab_1
{
    class Program
    {
        static Random random = new Random();

        static Entry[] ReadAllData(string filename)
        {
            string[] lines = File.ReadAllLines(filename);
            var result = lines.Skip(1).Select(line => new Entry(line)).ToArray();//the first line is: MrotInHour, Salary, Class, so I had to skip it
            return result;
        }

        static (Entry[], Entry[]) SplitData(Entry[] data)// method returning two entities
        {
            int n = data.Length;
            int nTraining = n * 2 / 3;//6666 values for training
            int nTesting = n - nTraining;//3334 values for testing

            var trainingData = new List<Entry>();
            var testingData = new List<Entry>();

            var grouppedByClass = new Dictionary<int, List<Entry>>();//here key is int(0 or 1) and we divide the data between two keys(0 & 1)
            foreach (var d in data)
            {//eventually 7012 of 0 and 2988 of 1
                if (!grouppedByClass.TryGetValue(d.Class, out var list))//each variable of every Entry in (Entry[] data) named "Class" is looked. 
                {//if it's there, then
                    list = new List<Entry>();//these two lines are only called once in the beginning
                    grouppedByClass[d.Class] = list;
                }
                list.Add(d);
            }

            int classI = 0;
            int i = 0;
            while (i < n)
            {
                classI = (classI + 1) % grouppedByClass.Keys.Count;//for some reason classI can become 0... it just switches back and forth ofcourse
                var @class = grouppedByClass.Keys.ElementAt(classI);
                var group = grouppedByClass[@class];
                if (group.Count == 0)
                {
                    grouppedByClass.Remove(@class);
                    continue;
                }
                int index = random.Next(group.Count);//create a random number with the upper bound of group.Count (2988 or 7012)
                var item = group[index];//randomly choose items from the (2988 or 7012) group (by the random index)
                group.RemoveAt(index);
                var target = i < nTraining ? trainingData : testingData;//while i is less than 6666, target is assigned with trainingData
                target.Add(item);//and I put the deleted element to the "target" var
                i++;//eventually I have two arrays filled with randomly chosen Entries. And trainingData is filled half with class 0, half with class 1
            }//and testing data is thoroughly of 0 Class
            return (trainingData.ToArray(), testingData.ToArray());
        }

        static int SqrDistance(Entry a, Entry b)
        {
            int dx = a.MrotInHour - b.MrotInHour;
            int dy = a.Salary - b.Salary;
            return dx * dx + dy * dy;
        }

        static float Distance(Entry a, Entry b)//it just invokes the SqrDistance method
        {
            return (float)Math.Sqrt(SqrDistance(a, b));
        }

        static float Kernel(float x)
        {
            if (x >= 1)
            {
                return 0;
            }
            float t = (1 - x * x) * (1 - x * x);
            return t * t;
        }


        static Dictionary<Entry, Entry[]> SortDatasByDistance(Entry[] allData, Entry[] trainingData)
        {
            var result = new ConcurrentDictionary<Entry, Entry[]>();
            int j = 1;
            Action progressShow = async () =>//public delegate void Action(); Encapsulates a method that has no parameters and does not return a value.
            {
                while (j < allData.Length - 1)
                {
                    Console.Write($"Sorting by distance: {j}/{allData.Length}               ");
                    Console.CursorLeft = 0;
                    await Task.Delay(10);
                }
                Console.Write($"Sorting by distance: {j}/{allData.Length}               ");
                Console.WriteLine();
            };
            progressShow();
            Parallel.For(0, allData.Length, i =>//Executes a for (For in Visual Basic) loop in which iterations may run in parallel.
            {
                Interlocked.Increment(ref j);//just incrementing j, like j++
                var trainingDataSortedByDistanceToD = (Entry[])trainingData.Clone();
                var d = allData[i];
                Array.Sort(trainingDataSortedByDistanceToD, (a, b) => SqrDistance(a, d) - SqrDistance(b, d));
                result[d] = trainingDataSortedByDistanceToD;
            });
            return new Dictionary<Entry, Entry[]>(result);
        }
        //first 
        static int Categorize(Entry item, Entry[] sortedTrainingData, float h)
        {

            float class0 = 0, class1 = 0;
            foreach (var neighbor in sortedTrainingData)
            {
                if (neighbor == item) continue;
                var measure = Kernel(Distance(item, neighbor) / h);
                if (measure <= 0) break;
                if (neighbor.Class == 0) class0 += measure;
                else class1 += measure;

            }

            return class0 > class1 ? 0 : 1;
        }

        static int CountMatches(Entry[] data, Dictionary<Entry, Entry[]> sortedTrainingDatas, float k)
        {
            int count = 0;
            foreach (var d in data)
            {//считаю совпадения по классу
                var trainingData = sortedTrainingDatas[d];
                if (d.Class == Categorize(d, trainingData, k))
                    count++;
            }
            return count;
        }

        static float FindBestK(Dictionary<Entry, Entry[]> sortedTrainingDatas, int maxK)
        {
            int maxMatches = 0;
            object lockObj = new object();
            float bestK = 0;
            var anyOrderTrainingData = sortedTrainingDatas.First().Value;
            int i = 1;

            double r = 2;
            var results = new Dictionary<float, float>();
            for (float h = 0; h < 10; h += 0.1f)
            {
                int matches = CountMatches(anyOrderTrainingData, sortedTrainingDatas, h);

                lock (lockObj)//Оператор lock получает взаимоисключающую блокировку заданного объекта перед выполнением определенных операторов, а затем снимает блокировку. Во время блокировки поток, удерживающий блокировку, может снова поставить и снять блокировку. Любой другой поток не может получить блокировку и ожидает ее снятия.
                {
                    if (matches > maxMatches)
                    {
                        maxMatches = matches;
                        bestK = h;
                    }
                    results[h] = (float)matches / anyOrderTrainingData.Length;
                    //results[k] = (float)Math.Pow((1 - (float)(Math.Pow(((float)matches / anyOrderTrainingData.Length), r))),r);
                }
            };
            File.AppendAllText("results.txt", string.Join("\n", results.OrderBy(pair => pair.Key).Select(pair => pair.Value)) + "\n\n");
            return bestK;
        }

        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            for (int i = 0; i < 10; i++)
            {
                var allData = ReadAllData("data3.csv");
                (var trainingData, var testingData) = SplitData(allData);
                var sortedTrainingData = SortDatasByDistance(allData, trainingData);
                float k = FindBestK(sortedTrainingData, 13);

                Console.WriteLine("Best h: " + k);
                Console.WriteLine("Training: " + (float)CountMatches(trainingData, sortedTrainingData, k) / trainingData.Length);
                Console.WriteLine("Testing: " + (float)CountMatches(testingData, sortedTrainingData, k) / testingData.Length);

                Console.WriteLine();
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}




class Entry
{
    public int MrotInHour, Salary, Class;
    public Entry(string str)
    {
        var blocks = str.Split(',');
        MrotInHour = Convert.ToInt32(blocks[0]);
        Salary = Convert.ToInt32(blocks[1]);
        Class = Convert.ToInt32(blocks[2]);
    }
}


