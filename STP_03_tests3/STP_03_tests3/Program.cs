using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_03_tests3
{
    public class Program
    {
        static void Main(string[] args)
        {
            /*            int[] expected = { 2, 5, 1 };
                        Console.WriteLine("original array: ");
                        for (int i = 0; i < expected.Length; i++)
                        {
                            Console.Write(expected[i] + ", ");
                        }
                        Console.WriteLine("\nArranged array : ");
                        arrangeXYZ_inDescendingOrder(ref expected);
                        for (int i = 0; i < expected.Length; i++)
                        {
                            Console.Write(expected[i] + ", ");
                        }
                        Console.WriteLine("\n\ncreateANumberOfEvenDigitsOf_a(123456) = " + createANumberOfEvenDigitsOf_a(123456));
                        double[,] arr = new double[,] { { 23.7,   10000,   10.4,  56,   56 },
                                                        { 38.5,   5,     89,   190,  343},
                                                        { 13,     564,   100,  767,  23 },
                                                        { 2000,   10,    374,  56,   5 },
                                                        { 38.5,   5,     89,   190,  343},
                                                        { 1300,   564,   100,  767,  23000 }
                        };
                        Console.WriteLine("\ngetSumOfOddDoublesAboveMainDiagonal(arr) = " + getSumOfOddDoublesAboveMainDiagonal(arr));*/
            //Console.WriteLine("\ncalculateGCD_Euclid(27, 6) = " + calculateGCD_Euclid(27, 6));
            createANumberOfEvenDigitsOf_a(7);


            Console.ReadLine();
        }
        public static void arrangeXYZ_inDescendingOrder(ref int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (arr[i] < arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        public static int calculateGCD_Euclid(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            // Pull out remainders
            while (true)
            {
                int remainder = a % b;
                if (remainder == 0) return b;
                a = b;
                b = remainder;
            };
        }
        public static int createANumberOfEvenDigitsOf_a(int a)
        {
            string aStr = a.ToString();    
            string res = "";
            int startingIndex = aStr.Length -1;
            int result = Int32.MaxValue;
           // startingIndex = (startingIndex % 2 == 1) ? startingIndex-=1  : startingIndex-=2; //если последний индекс(порядковый номер крайней справа цифры) 
            //чётный, то уменьшаем его на 1. Счёт ведётся с 1 а не с 0.
            for (int i = startingIndex - 1; i >= 0; i -= 2)// индекс 1 - это цифра №2 входного числа, если считать цифры начиная с единицы, а не с нуля
            {
              res = String.Concat(aStr.ElementAt(i), res);//a way to concatenate strings from the left
            }
            try
            {
              result =  Int32.Parse(res);
            }
            catch (Exception)
            {
                Console.WriteLine("Wrong number format");
              
            }
           
            return result;
        }
        public static double getSumOfOddDoublesAboveMainDiagonal(double[,] arr)
        {
            int dimension0 = arr.GetLength(0);//height 
            int dimension1 = arr.GetLength(1);//width
            double sum = 0;
            if (dimension0 == 0 || dimension1 < 2) return Double.NaN;//the second double in the first row has to exist to enable 
            //extraction of an element above the main diagonal            
            for (int i = 0; i < dimension0; i++)//firstly first row
            {
                for (int j =  1 + i; j < dimension1; j++)//сначала для всей ширины. Потом на 1 меньше(на следующем ряду).
                {//Т.о. хоть матрица толстая, хоть высокая смотреть буду только выше главной диагонали                    
                    if (arr[i, j] % 2 == 1) sum += arr[i, j];
                }
            }
            return sum;
        }
    }
}
