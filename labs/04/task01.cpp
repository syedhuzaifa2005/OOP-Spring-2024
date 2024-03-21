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
        Name = "";
        Author = "";
        ISBN = 0;
        totalpages = 0;
        pagesread = 0;
    }

    book(string title, string writer, int isbn, int total, int read){
        Name = title;
        Author = writer;
        ISBN = isbn;
        totalpages = total;
        pagesread = read;
    }

    void book_read(){
        if(pagesread == totalpages){
            cout << "Book Completed" << endl;
        } else{
            cout << "More pages to read" << endl;
        }
    }
};

int main(){

    book Book("harry potter", "jk-rowling", 123456, 200, 200);

    Book.book_read();  
}