//������ ������������� ������� strtok
#include <iostream>
#include <cstring>
 
int main ()
{
  char str[] = "Russian traditions, are-funny\tand hurtful";
 
  std::cout << "String division of "" << str << "" to lexems:\n";
  char * pch = strtok (str," ,.-\t"); // �� ������ ��������� ������� ����������� (������, �������, �����, ����)
 
  while (pch != NULL)                         // ���� ���� �������
  {
      std::cout << pch  << "\n";
      pch = strtok (NULL, " ,.-\t");
  }
  return 0;
}
