using System;

namespace ConsoleApp3
{
    class Program
    {
        public static void WriteReversed(char[] items, int startIndex )
        {
            if (items.Length == startIndex) return;
            // Выводим в обратном порядке все элементы с индексом больше startIndex
            WriteReversed(items, startIndex + 1);
            // а потом выводим сам элемент startIndex
            Console.Write(items[startIndex]);
        }

        static void Main(string[] args)
        {  char[] cr = { 'a' ,'b', 'c','d'};
            Console.WriteLine("Hello World!");
            WriteReversed(cr, 0);
            Console.WriteLine("\n"+1 % 2); 
            Console.ReadKey();
        }
    }
}
