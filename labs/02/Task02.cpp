/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description: Library management using structures
*/

#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

void displayBook(const Book& book);
int findBook(const Book library[], int size, const string& searchTerm);

int main() {
    const int maxBooks = 100; 
    Book library[maxBooks];   
    int bookCount = 0;        

    char choice;

    do {
        
        cout << "Library Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Update book data\n";
        cout << "3. Display all books\n";
        cout << "4. Find a book by title or author\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case '1': 
                if (bookCount < maxBooks) {
                    cout << "Enter book details:\n";
                    cout << "Title: ";
                    getline(std::cin, library[bookCount].title);
                    cout << "Author: ";
                    getline(std::cin, library[bookCount].author);
                    cout << "Year: ";
                    cin >> library[bookCount].year;
                    cin.ignore();
                    cout << "Genre: ";
                    getline(std::cin, library[bookCount].genre);

                    ++bookCount;
                } else {
                    cout << "Library is full. Cannot add more books.\n";
                }
                break;

            case '2': 
                {
                    string searchTerm;
                    cout << "Enter the title or author of the book to update: ";
                    getline(std::cin, searchTerm);

                    int index = findBook(library, bookCount, searchTerm);
                    if (index != -1) {
                        cout << "Enter new details for the book:\n";
                        cout << "Title: ";
                        getline(std::cin, library[index].title);
                        cout << "Author: ";
                        getline(std::cin, library[index].author);
                        cout << "Year: ";
                        cin >> library[index].year;
                        cin.ignore();
                        cout << "Genre: ";
                        getline(std::cin, library[index].genre);
                    } else {
                        std::cout << "Book not found.\n";
                    }
                }
                break;

            case '3': 
                for (int i = 0; i < bookCount; ++i) {
                    displayBook(library[i]);
                }
                break;

            case '4':
                {
                    string searchTerm;
                    cout << "Enter the title or author to search for: ";
                    getline(std::cin, searchTerm);

                    int index = findBook(library, bookCount, searchTerm);
                    if (index != -1) {
                        cout << "Book found:\n";
                        displayBook(library[index]);
                    } else {
                        std::cout << "Book not found.\n";
                    }
                }
                break;

            case '5': 
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != '5');

    return 0;
}


void displayBook(const Book& book){
    cout << "Title: " << book.title << "\n";
    cout << "Author: " << book.author << "\n";
    cout << "Year: " << book.year << "\n";
    cout << "Genre: " << book.genre << "\n\n";
}


int findBook(const Book library[], int size, const string& searchTerm){
    for (int i = 0; i < size; ++i) {
        if (library[i].title == searchTerm || library[i].author == searchTerm) {
            return i; 
        }
    }
        return -1; 
}