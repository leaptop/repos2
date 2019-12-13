#include <stdlib.h>
#include <stdio.h>
#include <clocale>


main()
{setlocale( LC_ALL, "Russian" ); int i,n,s;
  int *p;
  printf (" Размер массива -> "); 
  scanf ("%d", &n); 
  p = new int [n]; 
  if ( p == NULL ) 
  {  
     printf(" Не выделена память ");
    return 1; 
  }
  for (i = 0; i < n; i ++ ) 
  { 
     *(p+i)=rand()%20;
  }
  for (i = 0; i < n; i ++ ) 
     printf ("\n p[%d] = %d", i,*(p+i));
  puts("\n");  
  for (i=0; i<n/2; i++)
  {   s=*(p+i);
      *(p+i)=*(p+(n-i-1)); 
      *(p+(n-i-1))=s; 
  } 
  for (i = 0; i < n; i ++ ) 
      printf ("\n p[%d] = %d", i,*(p+i));
  puts("\n");  
  delete p; 
  p=NULL;
  system("PAUSE");
  return 0;
}

