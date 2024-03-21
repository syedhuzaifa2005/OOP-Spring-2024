/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Engine{
private:
    string enginetype;
    string enginemodel;
    
public:
    Engine(string enginetype, string enginemodel){
        this->enginemodel = enginemodel;
        this->enginetype = enginetype;
    }
    
    string getEngineModel() const{
        return enginemodel;
    }
    string getEnginetype() const{
        return enginetype;
    }
    
    void setEnginemodel(string enginemodel){
        this->enginemodel = enginemodel;
    }
    void setEnginetype(string enginetype){
        this->enginetype = enginetype;
    }

};

class Wheel{
private:
    bool condition;
    string wheelbrand;
    
public:
    Wheel(bool condition, string wheelbrand){ 
        this->condition = condition;
        this->wheelbrand = wheelbrand;
    }
    
    bool getCondition() const {return condition;}
    string getWheelBrand() const{return wheelbrand;}
     
    void setCondition(bool condition){this->condition = condition;}
    void setWheelBrand(string wheelbrand){this->wheelbrand = wheelbrand;}
};

class Headlights{
private:
    bool working;
    
public:
    Headlights(){}
    Headlights(bool working){
        this->working = working;
    }
    bool getWorking() const{return working;}
    void setWorking(bool working){this->working = working;}
};

class Steering{
private:
    string steeringtype;
    
public:
    Steering(){} 
    Steering(string steeringtype){ 
        this->steeringtype = steeringtype;
    }
    string getType() const{
        return steeringtype;
    }
    void setType(string steeringtype){
        this->steeringtype = steeringtype;
    }
};

class Car{
private:
    int ID;
    string model;
    Engine *e; 
    Wheel *wheel;
    Headlights lights; 
    Steering steering;
	 
public:
    Car(int ID, string model, Engine *e, Wheel *wheel){
        this->ID = ID;
        this->model = model;
        this->e = e;
        this->wheel = wheel;
    }
    void displayCarDetails(){
        cout<<"\nIdentification number: "<<ID<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Engine Type: "<<e->getEnginetype()<<endl;
        cout<<"Engine Model: "<<e->getEngineModel()<<endl;
        cout<<"Wheel's Condition: "<<wheel->getCondition()<<endl;
        cout<<"Wheel's Brand: "<<wheel->getWheelBrand()<<endl;
        cout<<"Headlights working? "<<lights.getWorking()<<endl;
        cout<<"Steering type: "<<steering.getType()<<endl;
    }
    void driveforwards(){
        cout<<"The car is moving forward"<<endl;
    }
    void reverse(){
        cout<<"The car is reversing."<<endl;
    }
    void right(){
        cout<<"The car is turning right."<<endl;
    }
    void left(){
        cout<<"The car is turning left."<<endl;
    }
    
    int getID() const {return ID;}
    string getModel() const {return model;}
    Headlights getLights() const {return lights.getWorking();}
    Steering getSteering() const {return steering.getType();}
    
    void setID(int ID){this->ID = ID;}
    void setModel(string model){this->model = model;}
    void setLights(bool w){lights.setWorking(w);}
    void setSteering(string s) {steering.setType(s);}
};

int main(){
    Engine e("W16", "K-0004");
    Wheel w("New", "Maxxis");
    Car c1(04, "Chiron", &e, &w);

    int id; string model; string steeringtype; string functioning;

    cout<<"Enter The Steering Type: ";
    cin>>steeringtype;
    cout<<"Are The Headlights working? (Yes or No) ";
    cin>>functioning;

    c1.setSteering(steeringtype);
    if(functioning == "yes" || functioning == "Yes"){
        c1.setLights(true);
    }
    else{
        c1.setLights(false);
    }
    c1.displayCarDetails();

    c1.driveforwards();
	c1.right();  
	c1.driveforwards();
	c1.left(); 
	c1.reverse();
    
    return 0;
}