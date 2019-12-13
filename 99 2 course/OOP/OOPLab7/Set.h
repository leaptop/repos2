#pragma once
#include <string>
#include <stdint.h>
 using namespace std;
struct _stlistNode {        
	        struct _stlistNode *next;
	        int32_t data;
	    };
    
class Set{
public:	
	_stlistNode *head; 	
	int32_t sumList();
	virtual void addElement(int32_t)=0;
	virtual void delElement()=0;
	virtual void printList()=0;
protected:
	virtual void installList(void)=0;		
};

class Stack : public Set{
	public:	
	void  installList();
	void addElement(int32_t);
	void delElement();
	void printList();
	Stack(void);	
	Stack(int ml);
};

class Queue : public Set{
	public:	
	_stlistNode *tail;
	void  installList();	
	void addElement(int32_t);	
	void delElement();	
	void printList();	
	Queue(void);
	~Queue(void);
};

