//пример использования функции strtok
#include <iostream>
#include <cstring>
 
int main ()
{
  char str[] = "Russian traditions, are-funny\tand hurtful";
 
  std::cout << "String division of "" << str << "" to lexems:\n";
  char * pch = strtok (str," ,.-\t"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
 
  while (pch != NULL)                         // пока есть лексемы
  {
      std::cout << pch  << "\n";
      pch = strtok (NULL, " ,.-\t");
  }
  return 0;
}
