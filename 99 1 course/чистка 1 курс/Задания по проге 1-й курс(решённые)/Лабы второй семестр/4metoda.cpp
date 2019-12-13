#include <stdio.h>
#include <stdlib.h>
#include <clocale>
const int n=5; // количество элементов в строке
typedef int rown[n];//rown - новый тип: массив (строка) из n целых чисел

main()

{ 


setlocale( LC_ALL, "Russian" );

 int i,j,m;
 rown *a; // указатель на строку
 int *b;   // указатель на целое
 printf ( "Число строк?  ");
 scanf ( "%d", &m );
 a = new rown[m]; // выделяем память под матрицу по адресу a, m строк
                                // по n элементов в строке 
if ( a == NULL ) 
{   printf("Не удалось выделить память");
    return 1; // выход по ошибке, код ошибки 1
}
b=new int[m]; // выделяем память под массив сумм строк (m строк)
if ( b == NULL ) 
{   printf("Не удалось выделить память");
    return 1; // выход по ошибке, код ошибки 1
}
// заполняем матрицу случайными числами
  for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
    { a[i][j]=rand()%11;
      printf("%4d",a[i][j]);
    }
    puts("\n");
 } 
// записываем в массив b суммы строк матрицы
 for (i=0; i<m; i++)
 {   b[i]=0;
     for (j=0; j<n; j++) 
         b[i]+=a[i][j];  
 }
 puts("\n");
  for (j=0; j<m; j++)
     printf("%4d",b[j]);           
 delete a; // освобождаем память, занятую под матрицу a
 delete b; // освобождаем память, занятую под массив b  
 puts("\n");
 system("PAUSE");
 return 0;
}
