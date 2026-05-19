// Assignment 10: File Handling - Library System (CRUD on text file)
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

struct Book {
	int id;
	string title;
	string author;
	string genre;
	string status;
};

string FILE_NAME = "books.txt";

// Write one book to file
void writeBook(ofstream &f, Book b) {
	f << b.id << "|" << b.title << "|" << b.author << "|" << b.genre << "|" << b.status << endl;
}

// Read one book from file
bool readBook(ifstream &f, Book &b) {
	if (!(f >> b.id))
		return false;
	f.ignore();
	getline(f, b.title, '|');
	getline(f, b.author, '|');
	getline(f, b.genre, '|');
	getline(f, b.status);
	return true;
}

// Add a new book
void addBook() {
	Book b;
	cout << "ID: ";
	cin >> b.id;
	cin.ignore();
	cout << "Title: ";
	getline(cin, b.title);
	cout << "Author: ";
	getline(cin, b.author);
	cout << "Genre: ";
	getline(cin, b.genre);
	cout << "Status (Available/Issued): ";
	getline(cin, b.status);

	ofstream f(FILE_NAME.c_str(), ios::app);
	writeBook(f, b);
	f.close();
	cout << "Added." << endl;
}

// Display all books
void displayAll() {
	ifstream f(FILE_NAME.c_str());
	Book b;
	while (readBook(f, b)) {
		cout << b.id << " | " << b.title << " | " << b.author;
		cout << " | " << b.genre << " | " << b.status << endl;
	}
	f.close();
}

// Search by ID
void searchBook() {
	int sid;
	cout << "Search ID: ";
	cin >> sid;

	ifstream f(FILE_NAME.c_str());
	Book b;
	while (readBook(f, b)) {
		if (b.id == sid) {
			cout << "Found: " << b.title << " by " << b.author << endl;
			f.close();
			return;
		}
	}
	cout << "Not found." << endl;
	f.close();
}

// Delete by ID (copy everything except target to temp file)
void deleteBook() {
	int did;
	cout << "Delete ID: ";
	cin >> did;

	ifstream f(FILE_NAME.c_str());
	ofstream t("temp.txt");
	Book b;
	bool found = false;

	while (readBook(f, b)) {
		if (b.id == did)
			found = true;
		else
			writeBook(t, b);
	}

	f.close();
	t.close();
	remove(FILE_NAME.c_str());
	rename("temp.txt", FILE_NAME.c_str());

	if (found)
		cout << "Deleted." << endl;
	else
		cout << "Not found." << endl;
}

// Update by ID (copy all to temp, modify the matching one)
void updateBook() {
	int uid;
	cout << "Update ID: ";
	cin >> uid;

	ifstream f(FILE_NAME.c_str());
	ofstream t("temp.txt");
	Book b;
	bool found = false;

	while (readBook(f, b)) {
		if (b.id == uid) {
			found = true;
			cin.ignore();
			cout << "New Title: ";
			getline(cin, b.title);
			cout << "New Author: ";
			getline(cin, b.author);
			cout << "New Genre: ";
			getline(cin, b.genre);
			cout << "New Status: ";
			getline(cin, b.status);
		}
		writeBook(t, b);
	}

	f.close();
	t.close();
	remove(FILE_NAME.c_str());
	rename("temp.txt", FILE_NAME.c_str());

	if (found)
		cout << "Updated." << endl;
	else
		cout << "Not found." << endl;
}

int main() {
	int choice;

	do {
		cout << "\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
			addBook();
		else if (choice == 2)
			displayAll();
		else if (choice == 3)
			searchBook();
		else if (choice == 4)
			updateBook();
		else if (choice == 5)
			deleteBook();
		else if (choice != 6)
			cout << "Invalid!" << endl;

	} while (choice != 6);

	return 0;
}
