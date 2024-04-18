#include <iostream>
using namespace std;

class shape{
private:
	float area = 9.67;
public:
	shape operator +(const shape& shape2){
		shape shape1;
		shape1.area = area + shape2.area;
		return shape1;
	}
	
	void display(){
		cout << area << endl;
	}
};

int main(){
	shape shape1, shape2;
	shape shape3 = shape1 + shape2;
	cout << "Area of shape 1 is: ";
	shape1.display();
	cout << "Area of shape 2 is: ";
	shape2.display();
	cout << "Area of shape 3 is ";
	shape3.display();
}
