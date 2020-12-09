using System;

namespace ZeroKnowledgeHamilton
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Diagnostics;
    using System.Threading;
    //using System.Runtime.Remoting.Metadata.W3cXsd2001;
    using System.Text;
    using System.Threading.Tasks;

    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 20000; i < 160000; i += 10000)
            {
                var model = new modelOfZeroKnowledge(new PrivateKey(i, 30));
                Console.WriteLine(model.ShowTimerOfAll(0.999));
            }
        }
    }
    class modelOfZeroKnowledge
    {
        public Checker singleCheker;
        public PrivateKey OurKey;
        public modelOfZeroKnowledge(PrivateKey Key)
        {
            OurKey = Key;
        }
        public int ShowTimerOfAll(double P)
        {
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            precision(P);
            stopWatch.Stop();
            // Get the elapsed time as a TimeSpan value.
            TimeSpan ts = stopWatch.Elapsed;
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}",
            ts.Minutes, ts.Seconds, ts.Milliseconds);
            //Console.WriteLine("RunTime " + elapsedTime);
            return ts.Seconds * 1000 + ts.Milliseconds;
        }
        public void ShowTimerOfoneTick()
        {
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            precision(0.5);
            stopWatch.Stop();
            // Get the elapsed time as a TimeSpan value.

            TimeSpan ts = stopWatch.Elapsed;
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}",
            ts.Minutes, ts.Seconds, ts.Milliseconds);
            Console.WriteLine("RunTime " + elapsedTime);
        }
        public void precision(double P)
        {
            double reliability = 0;
            double rate = 0.5;
            int i = 0;
            var rnd = new Random();
            while (i < 100 && reliability < P)
            {
                OurKey.IsomorphicTransformation();
                singleCheker = new Checker(OurKey.OpenKey);
                int l = rnd.Next(2);
                bool f = true;
                if (l == 1)
                {
                    f = singleCheker.CheckPath(OurKey.GetPrivateKeyPath());
                }
                else
                {
                    f = singleCheker.CheckIsomorphic(OurKey.graph, OurKey.GetIsomorphicKey());
                }
                if (f)
                {
                    reliability += rate;
                    rate /= 2;
                    //Console.WriteLine("success on " + reliability);
                }
                else
                {
                    //Console.WriteLine("EROOR ");
                    break;
                }
            }
        }
    }
    class Checker
    {
        public List<List<int>> Key;
        public Checker(List<HashSet<int>> OpenKey)
        {
            Key = new List<List<int>>();
            for (int i = 0; i < OpenKey.Count; ++i)
            {
                Key.Add(new List<int>());
                foreach (var vertix in OpenKey[i])
                {
                    Key[i].Add(vertix);
                }
            }
        }
        public Boolean CheckPath(List<int> path)//проверяю есть ли из каждой вершины действителньо путь
        {
            Boolean answer = true;
            for (int i = 0; i < path.Count - 1; ++i)
            {
                if (!Key[path[i]].Contains(path[i + 1])) answer = false;

            }
            if (!Key[path[path.Count - 1]].Contains(path[0])) answer = false;
            return answer;
        }
        public Boolean CheckIsomorphic(List<HashSet<int>> graph, List<int> IsomorphicKey)
        {
            Boolean answer = true;
            for (int i = 0; i < graph.Count; ++i)
            {
                if (graph[i].Count() != Key[IsomorphicKey[i]].Count()) answer = false;
                var IsomorphicV = new HashSet<int>();
                foreach (var v in graph[i])
                {
                    IsomorphicV.Add(IsomorphicKey[v]);
                }
                foreach (var v in Key[IsomorphicKey[i]])
                {
                    if (!IsomorphicV.Contains(v)) answer = false;
                }
            }
            return answer;
        }
    }
    class PrivateKey
    {
        public List<HashSet<int>> graph;//внес исправления с хэш сетов не проверял граф вроде  работает
        private int _size;
        public List<int> _path;
        //создать изоморфный ключ
        public List<HashSet<int>> OpenKey;
        private List<int> _IsomorphicKey;
        public int degree;
        public void InitKey(int size)
        {
            _size = size;
            _path = new List<int>();
            graph = new List<HashSet<int>>();
            for (int i = 0; i < _size; ++i)
            {
                graph.Add(new HashSet<int>());
            }
        }
        public PrivateKey(int size, int d)
        {
            InitKey(size);
            degree = d;
            GeneratePath();
            GenerateGraph();
        }
        public PrivateKey(int size, List<int> path, List<HashSet<int>> graph)//check it
        {
            InitKey(size);
            foreach (var vertix in path)
            {

                _path.Add(vertix);

            }
            foreach
           (var vertix in graph)

            {
                this.graph.Add(vertix);

            }

        }
        private List
       <int> Shafle(int size)

        {
            var answer = new List
           <int>();
            for
           (int i = 0; i < _size; ++i)

            {
                answer.Add(i);

            }
            Random rnd = new Random();
            for
           (int i = 0; i < _size; ++i)

            {
                var a = rnd.Next(_size);
                var b = rnd.Next(_size);//переписать нормально
                int copy = answer[a];
                answer[a] = answer[b];
                answer[b] = copy;

            }
            return answer;

        }
        public void GeneratePath()

        {
            _path = Shafle(_size);

        }
        public void GenerateGraph()

        {
            for
           (int i = 0; i < _size
           - 1; ++i)

            {
                graph[_path[i]].Add(_path[i + 1]);

            }
            graph[_path[_size
           - 1]].Add(_path[0]);
            Random rnd = new Random();
            for
           (int i = 0; i < _size; ++i)

            {
                int count = rnd.Next(degree);
                for
               (int j = 0; j < count; ++j)

                {
                    graph[i].Add(rnd.Next(_size
                   - 1));

                }

            }

        }
        public List
       <int> GetPrivateKeyPath()

        {
            var privateKey = new List
           <int>();
            for
           (int i = 0; i < _path.Count; ++i)

            {
                privateKey.Add(_IsomorphicKey[_path[i]]);

            }
            return privateKey;

        }
        public List
       <int> GetIsomorphicKey()

        {
            return _IsomorphicKey;

        }
        public void IsomorphicTransformation()

        {

            _IsomorphicKey = Shafle(_size);
            OpenKey = new List<HashSet<int>>();
            for (int i = 0; i < _size; ++i)
            {
                OpenKey.Add(new HashSet<int>());
            }
            for (int i = 0; i < _size; ++i)
            {
                foreach (var vertix in graph[i])
                {
                    OpenKey[_IsomorphicKey[i]].Add(_IsomorphicKey[vertix]);
                }
            }
        }
        public void ShowOpenKey()
        {
            Console.WriteLine("Vertix : Connecting vertix");
            for (int i = 0; i < graph.Count; ++i)
            {
                string numberOfvertix = "";
                numberOfvertix += i;
                if (numberOfvertix.Count() < 2) numberOfvertix += " ";
                Console.Write(" " + numberOfvertix + " : ");
                foreach (var v in graph[i])
                {
                    Console.Write(v + " ");
                }
                Console.Write("\n");
            }
        }
        public void ShowIsoporphicKey()
        {
            Console.WriteLine("Vertix : Connecting vertix");
            for (int i = 0; i < OpenKey.Count; ++i)
            {
                string numberOfvertix = "";
                numberOfvertix += i;
                if (numberOfvertix.Count() < 2) numberOfvertix += " ";
                Console.Write(" " + numberOfvertix + " : ");
                foreach (var v in OpenKey[i])
                {
                    Console.Write(v + " ");
                }
                Console.Write("\n");
            }
        }
    }

}
