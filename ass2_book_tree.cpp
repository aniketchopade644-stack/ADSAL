#include <iostream>
#include <string>
using namespace std;

struct Node {
	string label;
	int count;
	Node* child[10];
};

Node* createNode() {
	Node* temp = new Node;
	temp->count = 0;
	return temp;
}

void makeTree(Node* &root) {
	root = createNode();
	cout << "Book name? ";
	cin >> root->label;
	cout << "How many chapters? ";
	cin >> root->count;

	for (int i = 0; i < root->count; i++) {
		root->child[i] = createNode();
		cout << "Chapter name? ";
		cin >> root->child[i]->label;
		cout << "How many sections? ";
		cin >> root->child[i]->count;

		for (int j = 0; j < root->child[i]->count; j++) {
			root->child[i]->child[j] = createNode();
			cout << "Section name? ";
			cin >> root->child[i]->child[j]->label;
			cout << "How many sub-sections? ";
			cin >> root->child[i]->child[j]->count;

			for (int k = 0; k < root->child[i]->child[j]->count; k++) {
				root->child[i]->child[j]->child[k] = createNode();
				cout << "Sub-section name? ";
				cin >> root->child[i]->child[j]->child[k]->label;
				root->child[i]->child[j]->child[k]->count = 0;
			}
		}
	}
}

void display(Node* root) {
	cout << "Book: " << root->label << " (" << root->count << " chapters)" << endl;

	for (int i = 0; i < root->count; i++) {
		cout << "  Ch: " << root->child[i]->label;
		cout << " (" << root->child[i]->count << " sections)" << endl;

		for (int j = 0; j < root->child[i]->count; j++) {
			cout << "    Sec: " << root->child[i]->child[j]->label;
			cout << " (" << root->child[i]->child[j]->count << " sub-sections)" << endl;

			for (int k = 0; k < root->child[i]->child[j]->count; k++) {
				cout << "      Sub: " << root->child[i]->child[j]->child[k]->label << endl;
			}
		}
	}
}

int main() {
	Node* root = NULL;
	int choice;

	do {
		cout << "\n1.Create 2.Display 3.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			makeTree(root);
		}
		else if (choice == 2) {
			if (root != NULL)
				display(root);
			else
				cout << "No tree!" << endl;
		}
		else if (choice != 3) {
			cout << "Invalid!" << endl;
		}

	} while (choice != 3);

	return 0;
}
