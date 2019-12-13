#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{ char ch, sl[50];
  char text[]="one two three four";
  FILE *pf, *pr;                      // Указатели на файлы
  pf=fopen("new1.txt","w");  // Создание нового файла new1.txt
 // system(“CLS”);
  fprintf(pf,"%s\n",text);        // Запись в файл строки text
  fclose(pf);                            // Закрытие файла pf  
  pf=fopen("new1.txt","r");   // Открытие файла pf для чтения
  pr=fopen("new2.txt","w");  // Создание нового файла new2.txt
  while (!feof(pf))                  // Пока не конец файла
  { ch=getc(pf);                      // Чтение символа ch из файла pf
     if (ch != ' ')
         putc(ch,pr);                    // Запись в файл pr символа ch
  }
  fclose(pr);                           // Закрытие файла pr
  rewind(pf);                          // Возврат указателя на начало файла pf
  fgets(sl,50,pf);                     // Чтение из файла pf строки в переменную sl
  printf("%s\n",sl);                 // Вывод строки sl 
  pr=fopen("new2.txt","r");   // Открытие файла pr для чтения
  while (!feof(pr))                 // Пока не конец файла pr
  {  ch=getc(pr);                   // Чтение символа из файла pr
      putchar(ch);                  // Вывод символа ch 
   }
  fclose(pf);                          // Закрытие файлов
  fclose(pr);
  getch();
}
