/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
#include <cmath>
using namespace std;


class Square{
private:
	float sideLength;
	float area;
	static float allareas;
	
public:
	Square(){
		sideLength = 0;
		area = 0;
	}
	
	Square(float sideLength){
		this-> sideLength = sideLength;
	}
	
	void calculateArea(){
		area = pow(sideLength, 2);
		allareas += area;
	}
	
	float getSideLength(){
		return sideLength;
	}
	void setSideLength(float sideLength){
		this->sideLength = sideLength;
	}
	
	float getArea(){
		return area;
	}
	static float getAllAreas(){
		return allareas;
	}
};

float Square::allareas = 0;

int main(){
	Square square1(5.6);
	Square square2(6.9);
	Square square3(8.7);
	
	square1.calculateArea();
	square2.calculateArea();
	square3.calculateArea();
	
	
	cout << "Area of Square 1: " << square1.getArea() << endl;
	cout << "Area of Square 2: " << square2.getArea() << endl;
	cout << "Area of Square 3: " << square3.getArea() << endl;
	cout << "All areas: " << Square::getAllAreas() << endl;
}
