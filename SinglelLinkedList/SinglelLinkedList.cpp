#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public: 
	int noMhs;
	char nama[20];
	Node* next; 
};

class List
{
	Node* START; 
public: 
	List();
	void addNote();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNote(int element);
	void tranverse();  
};

List::List()
{
	START = NULL;
}