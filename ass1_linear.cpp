#include <iostream>
using namespace std;

#define SIZE 5
int id[SIZE];
int qty[SIZE];

// Initialize all slots to empty (-1)
void init() {
	for (int i = 0; i < SIZE; i++)
		id[i] = -1;
}

// Hash function
int h(int key) {
	return key % SIZE;
}

// Insert using linear probing
void insert(int pid, int q) {
	int i = h(pid);
	while (id[i] != -1)
		i = (i + 1) % SIZE;   // go to next slot (circular)
	id[i] = pid;
	qty[i] = q;
}

// Search using linear probing
void search(int pid) {
	int i = h(pid);
	int start = i;

	while (id[i] != -1) {
		if (id[i] == pid) {
			cout << "Found: ID-" << id[i] << " Qty-" << qty[i] << endl;
			return;
		}
		i = (i + 1) % SIZE;
		if (i == start)
			break;
	}
	cout << "Not found." << endl;
}

// Display table
void display() {
	for (int i = 0; i < SIZE; i++) {
		cout << i << ": ";
		if (id[i] == -1)
			cout << "Empty" << endl;
		else
			cout << "ID-" << id[i] << " Q-" << qty[i] << endl;
	}
}

int main() {
	init();
	int choice, pid, q;

	do {
		cout << "\n1.Insert 2.Search 3.Display 4.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "ID Qty: ";
			cin >> pid >> q;
			insert(pid, q);
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
