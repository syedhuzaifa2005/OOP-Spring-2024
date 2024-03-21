/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;


class Office{
private:
    string Location;
    int SeatingCapacity;
    string Furniture[3];

public:
    Office(string pLocation = " ", int pCapacity = 0, string pf1 = "", string pf2 = "", string pf3 = "") : Location(pLocation), SeatingCapacity(pCapacity), Furniture{pf1, pf2, pf3} {}

    void displayOffice(){
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        for(int i = 0; i < 3; i++){
            cout << "Furniture " << i + 1 << ": " << Furniture[i] << endl;
        }
    }
};

int main(){
    Office office01("Karachi");
    Office office02("Karachi", 10);
    Office office03("Karachi", 10, "Desk", "Chair", "Cupboard");

    cout << "Office 1: " << endl;
    office01.displayOffice();
    cout << endl;
    cout << "Office 2: " << endl;
    office02.displayOffice();
    cout << endl;
    cout << "Office 3: " << endl;
    office03.displayOffice();
}