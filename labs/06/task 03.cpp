/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Appointment{
private:
    string Name;
    string Day;
    static int NumOfAppointments;
    static float Total;

public:
    Appointment(string name, string day, float price){
        NumOfAppointments++;
        Name = name;
        Day = day;
        Total += price;
    }
    
    static float AverageAmount(){
        if(NumOfAppointments != 0){
            return (Total / NumOfAppointments);
        } else{
            return 0;
        }
    }

};

int Appointment::NumOfAppointments = 0;
float Appointment::Total = 0;

int main(){
    Appointment A1("Smith", "Tuesday", 1290);
    Appointment A2("Tom", "Thursday", 1990);
    Appointment A3("Juan", "Friday", 2780);

    cout << "The Average cost per appointment is " << A1.AverageAmount() << endl;
}