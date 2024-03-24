/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Book{
protected:
    string Title;
    string Author;
    string Publisher;

public:
    Book(string title, string author, string publisher){
        Title = title;
        Author = author;
        Publisher = publisher;
    }

    void displayBook(){
        cout << "Book details are as follows" << endl;
        cout << "Title: " << Title << endl;
        cout << "Author: " << Author << endl;
        cout << "Publisher: " << Publisher << endl;
    }
};

class FictionBook: public Book{
public:
    string Genre;
    string Protagonist;

public:
    FictionBook(string title, string author, string publisher, string genre, string protagonist): Book(title, author, publisher){
        Genre = genre;
        Protagonist = protagonist;
    }

    void displayFictionBook(){
        Book::displayBook();
        cout << "Genre: " << Genre << endl;
        cout << "Protagonist: " << Protagonist << endl;
    }
};

int main(){
    FictionBook Book1("The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Tragedy", "Jay Gatsby");
    Book* bookptr = &Book1;
    bookptr->displayBook();
    cout << endl << endl << endl;
    Book1.displayFictionBook();

}
