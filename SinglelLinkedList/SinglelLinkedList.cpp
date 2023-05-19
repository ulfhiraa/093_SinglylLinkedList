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
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNote(int element);
	void tranverse();  
};

List::List()
{
	START = NULL;
}

void List::addNode() //Menambah sebuah Node kedalam List
{
	int nim;
	char nm[20];
	cout << "\nMasukkan Nomor Mahasiswa : ";
	cin >> nim;
	cout << "\nMasukkan Nama : ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm); 

	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diizinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return; 
	}
	Node* previous, * current;

	current = START;
	previous = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diizinkan\n";
			return;
		}
		previous = current;
		current = current->next;
	}

	//Jika loop diatas dieksekusi, previous dan current akan menempati posisi dimana
	nodeBaru->next = current;
	previous->next = nodeBaru; 
}

bool List::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}

bool List::delNote(int nim) // menghapus node dari dalam list
{
	Node* current,* previous;
	if (Search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

//Check apakah node yang dimaksud ada didalam list atau tidak?
bool List::Search(int nim, Node** previous, Node** current)
{
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = START;
		*current = START;
	}
	return (*current != NULL);
}

void List::tranverse() //Mengunjungi dan membaca data dalam list
{
	if ((listEmpty))
		cout << "\nList kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah : " << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next);
		{
			cout << currentNode->noMhs << " " << currentNode->nama << "\n";
		}
		cout << endl;
	}
}