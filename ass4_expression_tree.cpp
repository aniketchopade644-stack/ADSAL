// Assignment 4: Expression Tree - Build from Prefix, Preorder, Non-Recursive Postorder, Delete
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
};

// Create a new node
Node* createNode(char ch) {
	Node* temp = new Node;
	temp->data = ch;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Check if character is an operator
bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	return false;
}

// Build tree from prefix expression
Node* buildFromPrefix(string prefix) {
	stack<Node*> s;

	// Scan from RIGHT to LEFT
	for (int i = prefix.size() - 1; i >= 0; i--) {
		Node* temp = createNode(prefix[i]);

		if (isOperator(prefix[i])) {
			// Pop two nodes and attach
			temp->left = s.top();
			s.pop();
			temp->right = s.top();
			s.pop();
		}

		s.push(temp);
	}

	return s.top();
}

// Preorder: Root -> Left -> Right (Recursive)
void preorder(Node* node) {
	if (node == NULL)
		return;
	cout << node->data;
	preorder(node->left);
	preorder(node->right);
}

// Postorder: Non-Recursive using Two Stacks
void postorderNR(Node* root) {
	if (root == NULL)
		return;

	stack<Node*> s1, s2;
	s1.push(root);

	while (!s1.empty()) {
		Node* temp = s1.top();
		s1.pop();
		s2.push(temp);

		if (temp->left != NULL)
			s1.push(temp->left);
		if (temp->right != NULL)
			s1.push(temp->right);
	}

	while (!s2.empty()) {
		cout << s2.top()->data;
		s2.pop();
	}
}

// Delete entire tree (postorder deletion)
void deleteTree(Node* node) {
	if (node == NULL)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	cout << "Deleting: " << node->data << endl;
	delete node;
}

int main() {
	Node* root = NULL;
	int choice;
	string prefix;

	do {
		cout << "\n1.Build 2.Preorder 3.Postorder(NR) 4.Delete 5.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Enter prefix: ";
			cin >> prefix;
			root = buildFromPrefix(prefix);
			cout << "Tree built." << endl;
		}
		else if (choice == 2) {
			if (root != NULL) {
				cout << "Preorder: ";
				preorder(root);
				cout << endl;
			}
			else {
				cout << "Tree is empty!" << endl;
			}
		}
		else if (choice == 3) {
			if (root != NULL) {
				cout << "Postorder: ";
				postorderNR(root);
				cout << endl;
			}
			else {
				cout << "Tree is empty!" << endl;
			}
		}
		else if (choice == 4) {
			deleteTree(root);
			root = NULL;
			cout << "Tree deleted." << endl;
		}
		else if (choice == 5) {
			cout << "Exit." << endl;
		}
		else {
			cout << "Invalid choice!" << endl;
		}

	} while (choice != 5);

	return 0;
}
