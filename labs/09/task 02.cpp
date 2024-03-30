/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14159;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const {

    }
};

class Circle : public Shape {
private:
    double Radius;
public:
    Circle(double radius) {
        Radius = radius;
    }

    double area() const override {
        return (pi * Radius * Radius);
    }
    double perimeter() const override {
        return (2 * pi * Radius);
    }
    void displayProperties() const override {
        cout << "Properties of the provided Circle are as follows: " << endl;
        cout << "Area: " << area() << "cm^2" << endl;
        cout << "Perimeter: " << perimeter() << "cm" << endl;
    }
};

class Rectangle : public Shape {
private:
    double Length;
    double Width;
public:
    Rectangle(double length, double width) {
        Length = length;
        Width = width;
    }

    double area() const override {
        return (Length * Width);
    }
    double perimeter() const override {
        return ((2 * Length) + (2 * Width));
    }
    double diagnol() const {
        return sqrt((pow(Length, 2)) + (pow(Width, 2)));
    }
    void displayProperties() const override {
        cout << "Properties of the provided Rectangle are as follows: " << endl;
        cout << "Area: " << area() << "cm" << endl;
        cout << "Perimeter: " << perimeter() << "cm" << endl;
        cout << "Diagnol: " << diagnol() << "cm" << endl;
    }
};

class Square : public Shape {
private:
    double SideLength;
public:
    Square(double sideLength) {
        SideLength = sideLength;
    }

    double area() const override {
        return (SideLength * SideLength);
    }
    double perimeter() const override {
        return (4 * SideLength);
    }
    double diagnol() const {
        return sqrt(2 * (pow(SideLength, 2)));
    }
    void displayProperties() const override {
        cout << "Properties of the provided Square are as follows: " << endl;
        cout << "Area: " << area() << "cm" << endl;
        cout << "Perimeter: " << perimeter() << "cm" << endl;
        cout << "Diagnol: " << diagnol() << "cm" << endl;
    }
};

class Triangle : public Shape {
protected:
    double side_1;
    double Base;
    double Height;
public:
    Triangle(double side1, double base, double height) {
        side_1 = side1;
        Base = base;
        Height = height;
    }

    double area() const override {
        return (0.5 * Base * Height);
    }
    double perimeter() const override {
        return (side_1 + Base + Height);
    }
    void displayProperties() const override {
        cout << "Properties of the provided Triangle are as follows: " << endl;
        cout << "Area: " << area() << "cm" << endl;
        cout << "Perimeter: " << perimeter() << "cm" << endl;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, (sqrt(3) / 2) * side) {}

    double perimeter() const override {
        return 3 * side_1;
    }

    void displayProperties() const override {
        cout << "Properties of the provided Equilateral Triangle are as follows: " << endl;
        cout << "Area: " << area() << " cm^2" << endl;
        cout << "Perimeter: " << perimeter() << " cm" << endl;
    }
};

int main() {
    int choice;
    cout << "Welcome to the Geometry Competition Calculator!" << endl;
    Shape* shape = nullptr;
    double d;
    double w;
    double b;
    double h;

    do {
        cout << "Please select a shape" << endl;
        cout << "1. Circle" << endl << "2. Rectangle" << endl << "3. Square" << endl << "4. Triangle" << endl << "5. Equilateral Triangle" << endl << "6. Quit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the radius of the Circle: ";
            cin >> d;
            shape = new Circle(d);
            break;
        case 2:
            cout << "Enter the Length of the Rectangle: ";
            cin >> d;
            cout << "Enter the width of the Rectangle: ";
            cin >> w;
            shape = new Rectangle(d, w);
            break;
        case 3:
            cout << "Enter the Length of the Square: ";
            cin >> d;
            shape = new Square(d);
            break;
        case 4:
            cout << "Enter the length of first side of the Triangle: ";
            cin >> d;
            cout << "Enter the length of the base of the Triangle: ";
            cin >> b;
            cout << "Enter the length of the height of the Triangle: ";
            cin >> h;
            shape = new Triangle(d, b, h);
            break;
        case 5:
            cout << "Enter the length of the Equilateral Triangle: ";
            cin >> d;
            shape = new EquilateralTriangle(d);
            break;
        }
        
        if (shape != nullptr) {
            shape->displayProperties();
            delete shape;
            shape = nullptr;
        }
    } while (choice != 6);
    cout << "Thank you for using the Geometry Competition Calculator!" << endl;
}

