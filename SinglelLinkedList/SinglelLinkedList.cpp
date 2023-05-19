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

int main()
{
	List mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "Menu";
		cout << endl << "1. Menambah data kedalam list" << endl;
		cout << "2. Menghapus data dari dalam list" << endl;
		cout << "3. Menampilkan semua data didalam list" << endl;
		cout << "4. Mencari data dalam list" << endl;
		cout << "5. Keluar" << endl; 
		cout << endl << "Masukkan Pilihan (1-5) : ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			mhs.addNode();
		}
		break;

		case '2':
		{
			if (mhs.listEmpty())
			{
				cout << endl << "List kosong" << endl;
				break;
			}
			cout << endl << "\nMasukkan no Mahasiswa yang akan dihapus : ";
			cin >> nim;
			if (mhs.delNote(nim) == false)
				cout << endl << "Data tidak ditemukan" << endl;
			else
				cout << endl << "Data dengan nomor Mahasiswa " << nim << " berhasil dihapus " << endl;
		}
		break;

		case '3':
		{
			mhs.tranverse();
		}
		break;

		case '4':
		{
			if (mhs.listEmpty() == true)
			{
				cout << "\nList Kosong\n";
				break;
			}
			Node* previous, * current;
			cout << endl << "Masukkan no Mahasiswa yang dicari : ";
			cin >> nim;
			if (mhs.Search(nim, &previous, &current) == false)
				cout << endl << "Data tidak ditemukan" << endl;
			else
			{
				cout << endl << "Data ditemukan" << endl;
				cout << "\nNo Mahasiswa : " << current->noMhs;
				cout << "\n\nNama : " << current->nama;
				cout << "\n";
			}
		}
		break;

		case '5':
		{
			exit(0);
		}
		break;
		default:
		{
			cout << "Pilihan Salah !." << endl;
		}
		break;
		}
	}
}