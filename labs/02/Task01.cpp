/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description: Swapping using recursions
*/


#include <iostream>
using namespace std;

void RecursiveSwap(int &a, int &b);

int main() {
    int x = 5;
    int y = 10;

    cout << "Before swapping: x = " << x << ", y = " << y << std::endl;

    RecursiveSwap(x, y);

    cout << "After swapping: x = " << x << ", y = " << y << std::endl;

    return 0;
}



void RecursiveSwap(int &a, int &b){
    if (a == 0 || b == 0) {
        return;
    }

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    RecursiveSwap(a, b);
}
