#include <iostream>
using namespace std;

class Vehicle{
protected:
    string Make;
    string Model;
    double Speed;

public:
    string getMake(){ 
		return Make;
	}
    string getModel(){
		return Model;
	}
    double getSpeed(){
		return Speed;
	}

    virtual void Accelerate() = 0;
    virtual void Brake() = 0;
    virtual void CalculateFuelEfficiency() = 0;
};

class Car : public Vehicle
{
private:
    double fuelCapacity;

public:
    Car(string make, string model, double speed, double fuelCapacity){
        this->Make = make;
        this->Model = model;
        this->Speed = speed;
        this->fuelCapacity = fuelCapacity;
    }

    void Accelerate() override{
        Speed += 10;
    }

    void Brake() override{
        Speed -= 10;
    }

    void CalculateFuelEfficiency() override {}
};

class Truck : public Vehicle{
private:
    int cargoCapacity;

public:
    Truck(string make, string model, double speed, int cargoCapacity){
        this->Make = make;
        this->Model = model;
        this->Speed = speed;
        this->cargoCapacity = cargoCapacity;
    }

    void Accelerate() override{
        Speed += 5;
    }

    void Brake() override{
        Speed -= 5;
    }

    void CalculateFuelEfficiency() override {}
};

int main(){
    Car car("Diahatsu", "Cuore", 100, 50);
    Truck truck("Bugatti", "Chevron", 5, 150);

    car.Accelerate();
    truck.Accelerate();

    car.Brake();

    cout << "Car speed: " << car.getSpeed() << endl;
    cout<< "Car Make: "<<car.getMake() <<endl;
    cout<< "Car Model: "<<car.getModel() <<endl;

    cout << "Truck speed: " << truck.getSpeed() << endl;
    cout<< "Truck Make: "<<truck.getMake() <<endl;
    cout<< "Truck Model: "<<truck.getModel() << endl;

    return 0;
}
