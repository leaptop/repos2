
 #include <iostream> 
 #include <fstream> 
 #include <string>
 #include <stdint.h>
#include "Set.h"
 using namespace std;
 
 	int32_t Set::sumList(){
		int32_t sum=0;
		while(head!=NULL){
		sum++;
			head=head->next;
		}
		return sum-1;
	};		



	void  Stack::installList(){/*так объ€вл€ютс€ статические элементы класса(вне класса). 
	ќни существуют всегда в единственном экземпл€ре*/
		head=new _stlistNode;
		head->next=NULL;		
	};
	
	void Stack::addElement(int32_t temp ){
		_stlistNode *p;	
		p=new _stlistNode;			
		p->next=head->next;
		p->data=temp;
		head->next=p;
	};
	
	void Stack::delElement(){
		if(head->next!=NULL){
			_stlistNode *pElement = head->next;
			head=head->next;
			delete pElement;
				}else
				 cout<<"Stack is empty";
	};
	
	void Stack::printList(){
		_stlistNode *temp;
		temp=head;
		temp=temp->next;
			while(temp!=NULL){
				cout<<temp->data<<"|";
				temp=temp->next;
			}
			cout<<endl;
		};
	
	Stack::Stack(void){
		installList();
	};
	Stack::Stack(int ml){
		cout<<"ml = "<<ml<<" Overriden constructor was launched "<<"\n";
			installList();
	};

	void Queue::installList(){
	tail=(_stlistNode*)&head;	
	};
	
	void Queue::addElement(int32_t temp ){
		_stlistNode *p;	
		p=new _stlistNode;
		p->data=temp;
		tail->next=p;		
		tail=p;
	};
	
	void Queue::delElement(){
		if(head->next!=NULL){
			_stlistNode *pElement = head->next;
			head=head->next;
			delete pElement;
				}else
				 cout<<"Stack is empty";
	};
	
	void Queue::printList(){
		_stlistNode *temp;
		temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"|";
				temp=temp->next;
			}
			cout<<endl;
		};
	
	Queue::Queue(void){
	installList();
	}  ;
	
	Queue::	~Queue(void){
	delete(head);
	delete(tail);
	}  ;


