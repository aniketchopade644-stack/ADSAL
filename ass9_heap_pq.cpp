// Assignment 9: Max-Heap Priority Queue - Customer Support
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Request {
	string id;
	string desc;
	int priority;
};

// This tells priority_queue to treat higher priority = higher importance
bool operator<(const Request &a, const Request &b) {
	return a.priority < b.priority;
}

int main() {
	priority_queue<Request> pq;
	int choice;

	do {
		cout << "\n1.Add 2.Process 3.Display 4.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			Request r;
			cout << "ID: ";
			cin >> r.id;
			cin.ignore();
			cout << "Desc: ";
			getline(cin, r.desc);
			cout << "Priority (3=Urgent 2=Moderate 1=Routine): ";
			cin >> r.priority;
			pq.push(r);
			cout << "Added." << endl;
		}
		else if (choice == 2) {
			if (pq.empty()) {
				cout << "Empty!" << endl;
			}
			else {
				Request r = pq.top();
				pq.pop();
				cout << "Processing: " << r.id << " | " << r.desc << " | P" << r.priority << endl;
			}
		}
		else if (choice == 3) {
			if (pq.empty()) {
				cout << "Empty!" << endl;
			}
			else {
				// Copy queue to print without destroying original
				priority_queue<Request> tmp = pq;
				int i = 1;
				while (!tmp.empty()) {
					Request r = tmp.top();
					tmp.pop();
					cout << i << ". " << r.id << " P" << r.priority << " " << r.desc << endl;
					i++;
				}
			}
		}
		else if (choice != 4) {
			cout << "Invalid!" << endl;
		}

	} while (choice != 4);

	return 0;
}
