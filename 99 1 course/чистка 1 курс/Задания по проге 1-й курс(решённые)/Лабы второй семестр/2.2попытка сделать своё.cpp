#include <iostream>

#include <windows.h>

using namespace std;
int s=0;
void rekursPrint(int * seq, int i) {
	if(seq[i]) {
	
		if(s==0) {if( seq[i] < 0) {
				cout<<seq[i]<<" ";
			}	Sleep(100);
		rekursPrint (seq, i+1);
			
			
		}
	

	} else {
		i = 0;
		s = 1;
		if(seq[i]) {
			if(seq[i]>0)
				cout<<seq[i]<<" ";
			Sleep(1000);
			rekursPrint(seq, i+1);


		}
	}

}
int main() {
	int sequence[] = {-2, 15, -1, -8, 14, 125, -345, 11, 199, -6, 0};
	rekursPrint(sequence, 0);

	return 0;
}


