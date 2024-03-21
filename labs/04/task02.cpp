/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;


class book{
private:
   string Name;
   string Author;
   int ISBN;
   int totalpages;
   int pagesread;
   
public:
    book(){
        Name = "Harry Potter";
        Author = "Jk-Rowling";
        ISBN = 123456;
        totalpages = 1000;
        pagesread = 0;
    }

    void setName(string title){
        Name = title;
    }
    void setAuthor(string writer){
        Author = writer;
    }
    void setISBN(int isbn){
        ISBN = isbn;
    }
    

    void book_read(){
        if(pagesread == totalpages){
            cout << "Book Completed" << endl;
        } else{
            cout << "More pages to read" << endl;
        }
    }

    void display_book(){
        cout << "Book Name: " << Name << endl;
        cout << "Author: " << Author << endl;
        cout << "ISBN No: " << ISBN << endl;
        cout << "Total pages: " << totalpages << endl;
        cout << "Pages read: " << pagesread << endl;
    }
};

int main(){

    book Book;

    Book.setName("Harry Potter");
    Book.setAuthor("Jk-Rowling");
    Book.setISBN(123456);
    Book.display_book();
    Book.book_read();  
}