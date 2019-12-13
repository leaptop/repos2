#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <locale.h>
#include "Set.cpp"
using namespace std;

main(){
//	setlocale(0, "Rus");
	setlocale (LC_ALL, "RUS"); 
	short int temp; 
	cout<<"Enter 1 for Stack or 2 for queue";
	cin>>temp;
	switch(temp){
		case 1:{
			Stack t(200);
			do{
				cout<<"1 Add, 2 delete, 3 look:";
				
				try{
					cin>>temp;
					if(temp!=1&&temp!=2&&temp!=3)throw 0;// обычно вместо нуля выбрасываются объекты исключений
				}catch(...){//троеточие срабатывает для любого исключения, но вообще для разных типов исключений разные кечи
					 cerr << "Wrong numbers\n";
				}
				switch(temp){
					case 1:{
						cout<<"=";
						cin>>temp;
						t.addElement(temp);
						break;
					}
					case 2:{
						t.delElement();
						break;
					}
					case 3:{
						t.printList();
						break;
					}
				}
			}while(1);
			break;
		}
		case 2:{
			Queue t;
			do{
				cout<<"1 Add, 2 delete, 3 look:";
				cin>>temp;
				switch(temp){
					case 1:{
						cout<<"=";
						cin>>temp;
						t.addElement(temp);
						break;
					}
					case 2:{
						t.delElement();
						break;
					}
					case 3:{
						t.printList();
						break;
					}
				}
			}while(1);
			break;
		}
	}

}
