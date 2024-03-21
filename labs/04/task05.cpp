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
    int size;

public:
    Office(string pLocation, int pCapacity, int psize){
			size = psize;
            string* furniture = new string[size]; // dynamically allocating memory fir the array
            Location = pLocation;
            SeatingCapacity = pCapacity;
    }

    ~Office(){
        delete[] Furniture;
    }

     void setFurniture(string item, int i) {
        Furniture[i-1] = item;
    }

    void displayOffice(){
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        for(int i = 0; i < 3; i++){
            cout << "Furniture " << i + 1 << ": " << Furniture[i] << endl;
        }
    }
};

int main(){
    Office *office01 = new Office("Karachi", 10, 3);

    office01-> setFurniture("Desk", 1);
    office01-> setFurniture("Chair", 2);
    office01-> setFurniture("Cupboard", 3);

    office01->displayOffice();

    office01->~Office();
    delete[] office01;
}