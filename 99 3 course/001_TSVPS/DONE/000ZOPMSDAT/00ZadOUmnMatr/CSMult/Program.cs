using System;// НЕПОНЯТНО КАК ЗАПУСТИТЬ
using System.Collections.Generic;

namespace CSMult
{
    class Datatstore
    {
        public List<List<int>> m;                   //матрица m
        public List<List<int>> s;                   //матрица s
        public List<List<int>> result;              //результат всех перемножений
        public List<List<List<int>>> source;        //массив из 2-мерных матриц (A0,A1,...,An) которые нужно перемножить
        public List<int> sizes = new List<int>();   //размеры матриц (записаны таким образом - 12,10,7,4 => значит 3 матрицы размерами 12x10,10x7,7x4)
        public string order = new string('a', 0);   //правильное расположение скобок
    }
    class Program
    {
        static void Main(string[] args)
        {
            

            Console.WriteLine("Hello World!");
            Datatstore dataStore = new Datatstore();


        }
        private void matrixChainOrder(Datatstore dataStore)
        {
            
            int n = dataStore.sizes.Count - 1;

            //выделяем память под матрицы m и s
            dataStore.m = new List<List<int>>();
            dataStore.s = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                dataStore.m.Add(new List<int>());
                dataStore.s.Add(new List<int>());
                //заполняем нулевыми элементами
                for (int a = 0; a < n; a++)
                {
                    dataStore.m[i].Add(0);
                    dataStore.s[i].Add(0);
                }
            }
            //выполняем итерационный алгоритм
            int j;
            for (int l = 1; l < n; l++)
            {
                for (int i = 0; i < n - l; i++)
                {
                    j = i + l;
                    dataStore.m[i][j] = int.MaxValue;
                    for (int k = i; k < j; k++)
                    {
                        int q = dataStore.m[i][k] + dataStore.m[k + 1][j] +
                                dataStore.sizes[i] * dataStore.sizes[k + 1] * dataStore.sizes[j + 1];
                        if (q < dataStore.m[i][j])
                        {
                            dataStore.m[i][j] = q;
                            dataStore.s[i][j] = k;
                        }
                    }
                }
            }
        }
        //метод - простое перемножение 2-х матриц
        private List<List<int>> matrixMultiply(List<List<int>> A, List<List<int>> B)
        {
            int rowsA = A.Count;
            int columnsB = B[0].Count;
            //column count of A == rows count of B
            int columnsA = B.Count;

            //memory alloc for "c"
            List<List<int>> c = new List<List<int>>();
            for (int i = 0; i < rowsA; i++)
            {
                c.Add(new List<int>());
                for (int a = 0; a < columnsB; a++)
                {
                    c[i].Add(0);
                }
            }

            //do multiplying
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < columnsB; j++)
                {
                    for (int k = 0; k < columnsA; k++)
                    {
                        c[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            //return value
            return c;
        }

        //метод, который непосредственно выполняет перемножение в правильном порядке
        //первоначально вызывается таким образом
        //dataStore.result = matrixChainMultiply(0, dataStore.sizes.Count - 2); 
        private List<List<int>> matrixChainMultiply(int i, int j, Datatstore dataStore)
        {
            
            if (j > i)
            {
                List<List<int>> x = matrixChainMultiply(i, dataStore.s[i][j],  dataStore);
                List<List<int>> y = matrixChainMultiply(dataStore.s[i][j] + 1, j, dataStore);
                return matrixMultiply(x, y);
            }
            else return dataStore.source[i];
        }

        //метод печатающий строку с правильной расстановкой скобок

        private void printOrder(int i, int j, string order, Datatstore dataStore)
        {
            if (i == j)
            {
                order += "A" + i.ToString();
            }
            else
            {
                order += "(";
                printOrder(i, dataStore.s[i][j], order, dataStore);
                order += "*";
                printOrder(dataStore.s[i][j] + 1, j,order,  dataStore);
                order += ")";
            }
        }
    }
}
