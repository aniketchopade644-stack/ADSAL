#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Employee {
	string name;
	string role;
	vector<Employee*> children;
};

Employee* createEmployee(string n, string r) {
	Employee* temp = new Employee;
	temp->name = n;
	temp->role = r;
	return temp;
}

Employee* search(Employee* node, string key) {
	if (node == NULL)
		return NULL;
	if (node->name == key)
		return node;

	for (int i = 0; i < node->children.size(); i++) {
		Employee* found = search(node->children[i], key);
		if (found != NULL)
			return found;
	}
	return NULL;
}
int height(Employee* node) {
	if (node == NULL)
		return 0;
	int mx = 0;
	for (int i = 0; i < node->children.size(); i++) {
		int h = height(node->children[i]);
		if (h > mx)
			mx = h;
	}
	return mx + 1;
}

void display(Employee* node, int indent) {
	if (node == NULL)
		return;

	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->name << " (" << node->role << ")" << endl;

	for (int i = 0; i < node->children.size(); i++)
		display(node->children[i], indent + 1);
}

int main() {
	Employee* CEO = NULL;
	int choice;
	string name, senior;

	do {
		cout << "\n1.CreateCEO 2.AddManager 3.AddEmployee 4.Display 5.Height 6.Search 7.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			if (CEO != NULL) {
				cout << "CEO already exists!" << endl;
			}
			else {
				cout << "CEO name: ";
				cin >> name;
				CEO = createEmployee(name, "CEO");
			}
		}
		else if (choice == 2 || choice == 3) {
			if (CEO == NULL) {
				cout << "Create CEO first!" << endl;
			}
			else {
				cout << "Name: ";
				cin >> name;
				cout << "Under whom: ";
				cin >> senior;

				Employee* s = search(CEO, senior);
				if (s != NULL) {
					string role;
					if (choice == 2)
						role = "Manager";
					else
						role = "Employee";

					s->children.push_back(createEmployee(name, role));
					cout << "Added." << endl;
				}
				else {
					cout << "Not found!" << endl;
				}
			}
		}
		else if (choice == 4) {
			if (CEO != NULL)
				display(CEO, 0);
			else
				cout << "Empty!" << endl;
		}
		else if (choice == 5) {
			if (CEO != NULL)
				cout << "Height: " << height(CEO) << endl;
			else
				cout << "Empty!" << endl;
		}
		else if (choice == 6) {
			cout << "Name: ";
			cin >> name;
			if (CEO != NULL && search(CEO, name) != NULL)
				cout << "Found!" << endl;
			else
				cout << "Not found!" << endl;
		}
		else if (choice == 7) {
			cout << "Exit." << endl;
		}
		else {
			cout << "Invalid!" << endl;
		}

	} while (choice != 7);

	return 0;
}
