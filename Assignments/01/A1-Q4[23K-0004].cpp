/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;


class RollerCoaster{
private:
	string Name;
	int Height;
	int Length;
	int Speed;
	int Capacity;
	int CurrentNumRiders;
	bool RideInProgress;

protected:
	int set; 
	
public:
	//DEFAULT CONSTRUCTOR
	RollerCoaster(){
		Name = "roller coaster";
		Height = 500;
		Length = 2000;
		Capacity = 20;
		Speed = 0;
		RideInProgress = false;
	}
	
	//PARAMETERIZED CONSTRUCTOR
	RollerCoaster(string name, int height, int length, int capacity, int currentRiders, int speed){
		Name = name;
		Height = height;
		Length = length;
		Capacity = capacity;
		CurrentNumRiders = currentRiders;
		Speed = speed;
		
		if(Capacity > 3){
			if(Capacity % 2 == 0){
				set = Capacity / 2;
			} else if(Capacity % 3 == 0){
				set = Capacity / 3;
			} else if((Capacity % 2 != 0)  &&  (Capacity % 3 != 0)){
				set = Capacity / 2;
			} else if((Capacity % 2 == 0)  &&  (Capacity % 3 == 0)){
				set = Capacity / 2;
			}	
		} else{
			cout << "Capacity should always be greater than 3" << endl;
		}
	}
	
	//GETTER METHODS
	string getName() const{
		return Name;
	}
	int getHeight() const{
		return Height;
	}
	int getLength() const{
		return Length;
	}
	int getSpeed() const{
		return Speed;
	}
	int getCurrentNumRiders() const{
		return CurrentNumRiders;
	}
	int getCapacity() const{
		return Capacity;
	}
	
	//SETTER METHODS
	void setName(const string& name){
		Name = name;
	}
	void setHeight(int height){
		Height = height;
	}
	void setLength(int length){
		Length = length;
	}
	void setSpeed(int speed){
		Speed = speed;
	}
	void setCurrentNumRiders(int currentRiders){
		CurrentNumRiders = currentRiders;
	}
	void setCapacity(int capacity){
		Capacity = capacity;
		
		if(Capacity > 3){
			if(Capacity % 2 == 0){
				set = Capacity / 2;
			} else if(Capacity % 3 == 0){
				set = Capacity / 3;
			} else if((Capacity % 2 != 0)  &&  (Capacity % 3 != 0)){
				set = Capacity / 2;
			} else if((Capacity % 2 == 0)  &&  (Capacity % 3 == 0)){
				set = Capacity / 2;
			}	
		} else{
			cout << "Capacity should always be greater than 3" << endl;
		}
	}
	
	
	void LoadRiders(){
		if(RideInProgress == false){
			if(CurrentNumRiders <= Capacity){
				cout << "Passengers seated" << endl;
			} else if(CurrentNumRiders > Capacity){
				int remainingPassengers = CurrentNumRiders - Capacity;
				cout << remainingPassengers << " passengers were not able to ride" << endl;
			}
		} else{
			cout << "Ride is in progress" << endl;
		}
	}
	
	int StartRide(){
		if(RideInProgress == false){
			if(CurrentNumRiders == Capacity){
				cout << "GET READY! Starting the ride" << endl;
			} else if(CurrentNumRiders < Capacity){
				int RemainingSeats = Capacity - CurrentNumRiders;
				cout << RemainingSeats << " seats remaining" << endl;
			}
		} else{
			return -1;
		}
	}
	
	void StopRide(){
		if(!RideInProgress){
			RideInProgress = false;
			cout << "Ride stopped" << endl;
		} else{
			cout << "Ride is already stopped" << endl;
		}
	}
	
	void UnloadRiders(){
		if(RideInProgress == false){
			cout << "Riders unloaded successfully" << endl;
		} else{
			cout << "Could not unload riders. Ride is in progress" << endl;
		}
	}
	
	void Accelerate(){
		Speed += 4;
		cout << "Speed increased to " << Speed << "km/h" << endl;
	}
	
	void Brakes(){
		Speed -= 2;
		cout << "Speed decrased to " << Speed << "km/h" << endl;
	}
	
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl << endl;
	RollerCoaster RC1;
	cout << "Default Roller Coaster details: " << endl;
	cout << "Name: " << RC1.getName() << endl;
	cout << "Height: " << RC1.getHeight() << "m" << endl;
	cout << "Length: " << RC1.getLength() << "m" << endl;
	cout << "Capacity: " << RC1.getCapacity() << endl;
	cout << "Speed: " << RC1.getSpeed() << "km/h" << endl << endl << endl;
	
	
	RollerCoaster RC2("Skyrocket Rumble", 750, 3000, 24, 24, 75);
	cout << "Custom Roller Coaster details: " << endl;
	cout << "Name: " << RC2.getName() << endl;
	cout << "Height: " << RC2.getHeight() << "m" << endl;
	cout << "Length: " << RC2.getLength() << "m" << endl;
	cout << "Capacity: " << RC2.getCapacity() << endl;
	cout << "Number of Riders: " << RC2.getCurrentNumRiders() << endl;
	cout << "Speed: " << RC2.getSpeed() << "km/h" << endl;
	
	
	RC2.LoadRiders();
	RC2.StartRide();
	RC2.Accelerate();
	RC2.Accelerate();
	RC2.Brakes();
	RC2.Brakes();
	RC2.StopRide();
	RC2.UnloadRiders();
		
}
