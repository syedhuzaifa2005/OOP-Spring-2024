#include <iostream>
using namespace std;


template <typename T>
class Pet {
protected:
    string Name;
    int Age;

public:
    Pet(string name, int age){
    	Name = name;
    	 Age = age;
	}

    virtual void makeSound() = 0;

    string get_Name() const {
        return Name;
    }

    int get_Age() const {
        return Age;
    }
};

class Cat: public Pet<Cat> {
public:
    Cat(string name, int age): Pet(name, age) {}

    void makeSound(){
        cout << "Meow" << endl;
    }
};

class Dog: public Pet<Dog> {
public:
    Dog(string name, int age): Pet(name, age) {}

    void makeSound(){
        cout << "Woof" << endl;
    }
};

class Bird: public Pet<Bird> {
public:
    Bird(string name, int age): Pet(name, age) {}

    void makeSound(){
        cout << "Chirp" << endl;
    }
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
    Cat cat("Tom", 2);
    Dog dog("Spike", 4);
    Bird bird("Tweetie", 3);

    Pet<Cat>* catPtr = &cat;
    Pet<Dog>* dogPtr = &dog;
    Pet<Bird>* birdPtr = &bird;

    cout << "Cat: " << catPtr->get_Name() << endl << "Age: " << catPtr->get_Age() << endl << "Sound: ";
    catPtr->makeSound();
    cout << endl;

    cout << "Dog: " << dogPtr->get_Name() << endl << "Age: " << dogPtr->get_Age() << endl << "Sound: ";
    dogPtr->makeSound();
    cout << endl;

    cout << "Bird: " << birdPtr->get_Name() << endl << "Age: " << birdPtr->get_Age() << endl << "Sound: ";
    birdPtr->makeSound();
	cout << endl;
	
    return 0;
}

