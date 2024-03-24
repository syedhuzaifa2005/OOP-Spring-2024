/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Vehicle{
protected:
    string Make;
    string Model;
    int Year;

public:
    Vehicle(const string& make, const string& model, int year){
        Make = make;
        Model = model;
        Year = year;
    }

    void displayVehicle(){
        cout << "Make: " << Make << endl;
        cout << "Model: " << Model << endl;
        cout << "Year: " << Year << endl;
    }
};

class Car: public Vehicle{
protected:
    int Doors;
    float FuelEfficiency;

public:
    Car(const string& make, const string& model, int year, int doors, float efficiency): Vehicle(make, model, year){
        Doors = doors;
        FuelEfficiency = efficiency;
    }

    void displayCar(){
        Vehicle::displayVehicle();
        cout << "Number od doors: " << Doors << endl;
        cout << "Fuel Efficiency: " << FuelEfficiency << endl;
    }
};

class ElectricCar: public Car{
private: 
    int BatteryLife;

public:
    ElectricCar(const string& make, const string& model, int year, int doors, float efficiency, float battery): Car(make, model, year, doors, efficiency){
        BatteryLife = battery;
    }

    void displayElectricCar(){
        Car::displayCar();
        cout << "Battery Life: " << BatteryLife << endl;
    }
};

int main(){
    ElectricCar car("Tesla", "Model S", 2022, 4, 89.54, 100.0);
    car.displayElectricCar();
}