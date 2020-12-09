using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_02_tests2
{
    public class Program
    {
        static void Main(string[] args)
        {
            double[,] arr = new double[,] { { 23.7,   10000,   374,  56,   56 },
                                            { 38.5,   5,     89,   190,  343},
                                            { 13,     564,   100,  767,  23 },
                                            { 20000,   10,    374,  56,   5 },
                                            { 38.5,   5,     89,   190,  343},
                                            { 1300,   564,   100,  767,  23000 }
            };
            
            Console.WriteLine("maximumOf2DArrayOnAndAboveSecondaryDiagonal(arr); = " + maximumOf2DArrayOnAndAboveSecondaryDiagonal(arr));
            Console.WriteLine("minimumOfAAndB(34, 12) = " + minimumOfAAndB(34, 12));
            Console.WriteLine("maximumOf2DArray(double[,] arr) = " + maximumOf2DArray(arr));
            Console.ReadKey();
        }

        public static int minimumOfAAndB(int a, int b)
        {
            if (a > b)
                return b;
            else return a;
        }
        public static double maximumOf2DArray(double[,] arr)
        {
            double max = arr[0, 0];
            foreach (var item in arr)
            {
                if (item > max)
                    max = item;
            }
            return max;
        }
        //Побочной диагональю матрицы называется диагональ, проведённая из левого нижнего угла матрицы в правый верхний(верно для квадратной матрицы)
        //Однако в прямоугольной матрице диагональ надо проводить из верхнего правого угла
        public static double maximumOf2DArrayOnAndAboveSecondaryDiagonal(double[,] arr)
        {
            int dimension0 = arr.GetLength(0);//height 
            int dimension1 = arr.GetLength(1);//width
            double max = arr[0, 0];
            for (int i = 0; i < dimension0; i++)
            {
                for (int j = dimension1 - 1 - i; j >= 0; j--)//сначала для всей ширины. Потом на 1 меньше(на следующем ряду).
                {//Т.о. хоть матрица толстая, хоть высокая смотреть буду только на побочную диагональ и выше
                    if (j < 0) break;
                    if (max < arr[i, j]) max = arr[i, j];
                }
            }
            return max;
        }
    }

}
