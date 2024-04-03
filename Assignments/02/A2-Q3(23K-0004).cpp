#include <iostream>
using namespace std;

class DarazPersonData{
protected:
	string FirstName;
	string LastName;
	string Address;
	string City;
	string State;
	string Zip;
	string Phone;
public:
	DarazPersonData(const string& Fname, const string& Lname, const string& address, const string& city, const string& state, const string& zip, const string& phone){
		FirstName = Fname;
		LastName = Lname;
		Address = address;
		City = city;
		State = state;
		Zip = zip;
		Phone = phone;
	}
	
	string get_FirstName() const{ 
		return FirstName; 
	}
	string get_LastName() const{ 
		return LastName; 
	}
	string get_Address() const{ 
		return Address; 
	}
	string get_City() const{ 
		return City; 
	}
	string get_State() const{ 
		return State; 
	}
	string get_Zip() const{ 
		return Zip; 
	}
	string get_Phone() const{ 
		return Phone; 
	}
};

class DarazCustomerData: public DarazPersonData{
protected:
	int customerNumber;
	int loyaltyPoints;
public:
	DarazCustomerData(const string& Fname, const string& Lname, const string& address, const string& city, const string& state, const string& zip, const string& phone, int cNumber, int points)
	: DarazPersonData(Fname, Lname, address, city, state, zip, phone){
		customerNumber = cNumber;
		if(points >= 0){
			loyaltyPoints = points;
		}
	}
	
	int get_customerNumber() const{ 
		return customerNumber; 
		}
	int get_loyaltyPoints() const{ 
		return loyaltyPoints; 
		}
		
	void set_loyaltyPoints(int points) {
		if(points >= 0) {
			loyaltyPoints = points;
		}
	}
	
	void display(){
		cout << "Customer Name: " << get_FirstName() << " " << get_LastName() << endl;
		cout << "Address: " << get_Address() << " " << get_City() << " " << get_State() << endl;
		cout << "Zip: " << get_Zip() << endl;
		cout << "Phone: " << get_Phone() << endl;
		cout << "Customer Number: " << get_customerNumber() << endl;
		cout << "Loyalty Points: " << get_loyaltyPoints() << endl;
	}
};

class DarazLoyaltyProgram{
public:
	void addLoyaltyPoints(DarazCustomerData &customer, int points){
		customer.set_loyaltyPoints(customer.get_loyaltyPoints() + points);
		cout << "Adding " << points << " loyalty points to " << customer.get_customerNumber() << endl;
		customer.display();
	}
	void redeemLoyaltyPoints(DarazCustomerData &customer, int points){
		if(customer.get_loyaltyPoints() > points){
			customer.set_loyaltyPoints(customer.get_loyaltyPoints() - points);
			cout << "Redeeming " << points << " loyalty points from " << customer.get_customerNumber() << endl;
			customer.display();
		} else{
			cout << "Insufficient loyalty points" << endl;
		}
	}
	void displayLoyaltyPoints(DarazCustomerData &customer){
		cout << "The customer " << customer.get_customerNumber() << " has " << customer.get_loyaltyPoints() << " loyalty points" << endl;
	}
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	DarazCustomerData customer("Huzaifa", "Ali", "123 Main St", "Karachi", "Pakistan", "10001", "123-456-7890", 230004, 50);
	
	DarazLoyaltyProgram loyaltyProgram;
	loyaltyProgram.addLoyaltyPoints(customer, 30);
	loyaltyProgram.redeemLoyaltyPoints(customer, 20);
}
