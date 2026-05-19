// Assignment 1B: Hash Table - Chaining (Separate Chaining using STL list)
#include <iostream>
#include <list>
using namespace std;

#define SIZE 5

struct Entry {
	int id;
	int qty;
};

list<Entry> table[SIZE];   // array of linked lists

// Hash function
int h(int key) {
	return key % SIZE;
}

// Insert - just append to the correct bucket
void insert(int pid, int q) {
	Entry e;
	e.id = pid;
	e.qty = q;
	table[h(pid)].push_back(e);
}

// Search - look through the chain at hash position
void search(int pid) {
	int index = h(pid);
	list<Entry>::iterator it;

	for (it = table[index].begin(); it != table[index].end(); it++) {
		if (it->id == pid) {
			cout << "Found: ID-" << it->id << " Qty-" << it->qty << endl;
			return;
		}
	}
	cout << "Not found." << endl;
}

// Display all buckets
void display() {
	for (int i = 0; i < SIZE; i++) {
		cout << i << ": ";
		list<Entry>::iterator it;
		for (it = table[i].begin(); it != table[i].end(); it++) {
			cout << "[" << it->id << "," << it->qty << "] -> ";
		}
		cout << "NULL" << endl;
	}
}

int main() {
	int choice, pid, q;

	do {
		cout << "\n1.Insert 2.Search 3.Display 4.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "ID Qty: ";
			cin >> pid >> q;
			insert(pid, q);
			cout << "Done." << endl;
		}
		else if (choice == 2) {
			cout << "ID: ";
			cin >> pid;
			search(pid);
		}
		else if (choice == 3) {
			display();
		}

	} while (choice != 4);

	return 0;
}
