#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int val) : value(val) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(10);

    cout << "Before Prefix Decrement: ";
    num.display();

    --num; 
    cout << "After Prefix Decrement: ";
    num.display();

    cout << "Before Postfix Decrement: ";
    num.display();

    num--;
    cout << "After Postfix Decrement: ";
    num.display();

    return 0;
}

