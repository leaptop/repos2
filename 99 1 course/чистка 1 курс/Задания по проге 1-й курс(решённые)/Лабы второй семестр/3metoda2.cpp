#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>


main()
{setlocale( LC_ALL, "Russian" ); 
  int i,n;  // размер массива n заранее неизвестен, т.е. n – не константа
  int *p; // указатель на целые числа
  printf (" Размер массива -> "); 
  scanf ("%d", &n);
  p = new int [n]; // выделение памяти под n целых чисел
  if ( p == NULL ) // если не удалось выделить память 
 {  
     printf(" Не удалось выделить память ");
    return 1; // выход по ошибке, код ошибки 1
 }
 for (i = 0; i < n; i ++ ) 
 { 
   printf ("\n p[%d] = ", i);
   scanf ("%d", &p[i]);
 }
 for (i = 0; i < n; i ++ ) 
    printf ("\n p[%d] = %d", i,p[i]);
 puts("\n");   
 delete p; // освобождение памяти
 p=NULL;
 getch();
 return 0;
}
