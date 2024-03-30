/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

const double pi = 3.14159;

class Shape{
public:
    double calculateArea(double radius){
        return (pi * radius * radius);
    }
    double calculateArea(double length, double width){
        return (length * width);
    }
    double calculateArea(double side1, double base, double height){
        return (0.5 * base * height);
    }

    double calculatePerimeter(double radius){
        return (2 * pi * radius);
    }
    double calculatePerimeter(double length, double width){
        return ((2 * length) + (2 * width));
    }
    double calculatePerimeter(double side1, double base, double height){
        return (side1 + base + height);
    }
};

int main(){
    Shape shape;
    cout << "Area of circle having radius 8.65cm is " << shape.calculateArea(8.65) << "cm" << endl;
    cout << "Perimeter of circle having radius 8.65cm is " << shape.calculatePerimeter(8.65) << "cm" << endl;

    cout << "Area of rectangle having length = 12.38cm and width = 7.87cm is " << shape.calculateArea(12.38, 7.87) << "cm" << endl;
    cout << "Perimeter of rectangle having length = 12.38cm and width = 7.87cm is " << shape.calculatePerimeter(12.38, 7.87) << "cm" << endl;

    cout << "Area of triangle having 3 sides namely side_1 = 17.37cm, base = 9.33cm and height = 13.39cm is " << shape.calculateArea(17.37, 9.33, 13.39) << "cm" << endl;
    cout << "Perimeter of triangle having 3 sides namely side_1 = 17.37cm, base = 9.33cm and height = 13.39cm is " << shape.calculatePerimeter(17.37, 9.33, 13.39) << "cm" << endl;
}
