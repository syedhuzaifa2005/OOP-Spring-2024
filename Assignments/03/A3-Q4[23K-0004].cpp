#include <iostream>
using namespace std;


class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class Drone{
protected:
	float Latitude;
	float Longitude;
	float Altitude;
	float Speed;

public:
	Drone(float latitude, float longitude, float altitude, float speed){
		Latitude = latitude;
		Longitude = longitude;
		Altitude = altitude;
		Speed = speed;
	}
	void adjustAltitude(float altitude){
		Altitude += altitude;
		cout << "the altitude now is " << Altitude << endl;
	}
	void setSpeed(float speed){
		Speed += speed;
		cout << "the speed now is" << Speed << endl;
	}
};

class ReconDrone: public Flyable, public Scannable, public Drone{
private:
	float CameraResolution;
	float MaxFlightTime;
public:
	ReconDrone(float resolution, float maxtime, float latitude, float longitude, float altitude, float speed): Drone(latitude, longitude, altitude, speed){
		CameraResolution = resolution;
		MaxFlightTime = maxtime;
	}
	void land()override{
		cout << "The plane is landing" << endl;
	}
	void takeoff()override{
		cout << "The drone is taking off" << endl;
	}
	void navigateTo(float latitude, float longitude, float altitude) override{
		Latitude = latitude;
		Longitude = longitude;
		Altitude = altitude;

		cout<<"changing the direction of the plane..."<<endl;
		cout << "The latitude now is: " << Latitude << " degrees" << endl;
		cout << "The Longitude is: " << Longitude << " degrees" << endl;
		cout << "The altitude is: " << Altitude << " meters" << endl;
		if (Altitude > 1000){
			cout << "error communicating with the drone" << endl;
		}
	}
	void scanArea(float radius) override{
		cout << "scanning!.....";
		int objectsDetected = rand() % 10;
		cout << "Number of objects detected is: " << objectsDetected << endl;
		
		for(int i = 0; i < objectsDetected; i++){
			float objectLatitude;
			float objectLongitude;
			objectLatitude = Latitude + rand()% static_cast<int>(radius);
			objectLongitude = Longitude + rand()% static_cast<int>(radius);
			cout << "Latitude of the detected object " << i + 1 << " is: " << objectLatitude << endl;
			cout << "Longitude of the detected object " << i + 1 <<" is: " << objectLongitude << endl;
		}
		if (objectsDetected >= 9){
			cout << "Error, signals lost!....";
		}
	}
	void Display(){
		cout << "Drone Details" << endl;
		cout << "Camera Resolution: " << CameraResolution << endl;
		cout << "Max Flight Time: " << MaxFlightTime << endl;
		cout << "Current Latitude: " << Latitude << " degrees" << endl;
		cout << "Current Longitude: " << Longitude << " degrees" << endl;
		cout << "Current Altitude: " << Altitude << " meters" << endl;
		cout << "Speed: " << Speed << "m/s" << endl;
	}
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	ReconDrone recon1(400, 20, 36, 72, 680, 30);
	recon1.takeoff();
	recon1.Display();
	recon1.navigateTo(79, 48, 820);
	recon1.scanArea(10);
	return 0;
}
