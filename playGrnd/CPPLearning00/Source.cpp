#include <iostream>
#include <fstream>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

int main()
{
	std::cout << "insert an address of a file to copy like this: c:/hellocsc/sentence.txt\n";
	char source [200], final [200];
	std::cin >> source;
	std::cout << "insert an address of a final destination like this: c:/users/stepan/source/repos/cpplearning00/copied.txt\n";
	std::cin >> final;	
	fs::copy(source, final);	
}




//#include <stdio.h>
//struct st {
//	int data;
//};
//int main()
//{
//	struct st s00;
//	s00.data = 7;
//	printf("%d\n", s00.data);
//	struct st* s01;
//	s01 = &s00;
//	printf("hi\n");
//	printf("%d\n", s01->data);
//
//	return 0;
//
//
//}