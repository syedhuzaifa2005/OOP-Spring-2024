/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Employee{
protected:
    int EmployeeID;
    string EmployeeName;
public:
    Employee(int ID, const string& Name){
        EmployeeID = ID;
        EmployeeName = Name;
    }

    virtual double calculatePay() const{
        return 0;
    }
    virtual void displayDetails(){
        cout << "Employee ID: " << EmployeeID << endl;
        cout << "Employee Name: "  << EmployeeName << endl;
    }
};

class FullTimeEmployee: public Employee{
private:
    float monthlySalary;
public:
    FullTimeEmployee(int ID, const string& Name, float Salary): Employee(ID, Name){
        monthlySalary = Salary;
    }

    double calculatePay() const override{
        return monthlySalary;
    }
    void displayDetails() override{
        Employee::displayDetails();
        cout << "Type: Full Time Employee" << endl;
        cout << "Monthly Salary: " << monthlySalary << "$" << endl;
    }
};

class PartTimeEmployee: public Employee{
private:
    float hourlyWage;
    int hoursWorked;
public:
    PartTimeEmployee(int ID, const string& Name, float Wage, int Worked): Employee(ID, Name){
        hourlyWage = Wage;
        hoursWorked = Worked;
    }

    double calculatePay() const override{
        return (hourlyWage * hoursWorked);
    }
    void displayDetails() override{
        Employee::displayDetails();
        cout << "Type: Part Time Employee" << endl;
        cout << "Hourly Wage: " << hourlyWage << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Pay: " << calculatePay() << "$" << endl;
    }
};

int main(){
    Employee* E1;
    FullTimeEmployee F1(101, "Huzaifa", 5000);
    E1 = &F1;
    E1->calculatePay();
    E1->displayDetails();

    Employee* E2;
    PartTimeEmployee P1(102, "Rayyan", 15, 40);
    E2 = &P1;
    E2->calculatePay();
    E2->displayDetails();
}