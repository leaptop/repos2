#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>

const int z = 2;

struct bag {char name[50]; int m; float ves;} t;
struct bag zap[z];
void input(FILE *); // создание нового файла
void print(FILE *); // просмотр файла
void app(FILE *); // добавление в файл
void s(FILE *); // поиск и изменение
main()
{ char c;
  FILE *tf;
  while (1)
  {
    puts("  1 - new file");
    puts("  2 - looking through file");
    puts("  3 - adding to file");
    puts("  4 - search ");
    puts("  0 - exit");
    c=getch();
    switch(c)
    { case '1':input(tf);break;
      case '2':print(tf);break;
      case '3':app(tf);break;
      case '4':s(tf);break;
      case '0':return 0;
      default : puts("Error");
     }
  }
}
void input(FILE *tf)
{ char ch;
int i;
  tf=fopen("file1.dat","wb"); // открытие бинарного файла для записи

  printf("\n Input passenger's data\n");
  for (i=0;i<z;i++){
   printf("\n  name, luggage value, luggage weight  ");
     scanf("%s%d%f",&t.name,&t.m,&t.ves);
     fwrite(&t,sizeof(t),1,tf);
     zap[i]=t; }



  fclose(tf);
}
void print(FILE *tf)
{ int i;

  tf=fopen("file1.dat","rb"); // открытие бинарного файла для чтения
  i=1;
  fread(&t,sizeof(t),1,tf); // чтение из файла одной структуры t1
  while (!feof(tf))
  { printf("\n %d. - %s take's up %d space, which weighs %6.2f kg",i,t.name,t.m,t.ves);
    fread(&t,sizeof(t),1,tf);
    i++;
  }
  fclose(tf);
  getch();
}
void app(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","ab"); // открытие бинарного файла для добавления

  printf("\n  Input data: \n");
  do
  {  printf("\n name, luggage value, luggage weight:  ");
     scanf("%s%d%f",&t.name,&t.m,&t.ves);
    fwrite(&t,sizeof(t),1,tf);
    printf(" Finished?  y/n ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void s(FILE *tf)
{ char c;
int result;
 float mm= 10;
 FILE *tf2;
  tf=fopen("file1.dat","rb+"); // открытие бинарного файла для чтения и записи
  tf2=fopen("file2.dat","wb");
   while (!feof(tf)){
    fread(&t,sizeof(t),1,tf);
    if(t.ves>mm){
    fwrite(&t,sizeof(t),1,tf2);}
   }


  fclose(tf);
  fclose(tf2);
  remove( "file1.dat" ) ;


  result = rename("file2.dat","file1.dat");




}
