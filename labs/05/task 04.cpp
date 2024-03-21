/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;


class BankAccount{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }
    
    void deposit(double amount){
        balance += amount;
        cout << "Amount succesfully added" << endl;
    }
    
    void withdraw(double amount){
        if(balance > amount){
            balance -= amount;
            cout << "Amount withdrawn successfully" << endl;
        } else{
            cout << "Insufficient balance" << endl;
        }
    }
    
    void display(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main(){
    BankAccount accounts[3] = {
        {123, "John", 1000.0},
        {345, "Smith", 200.0},
        {789, "Jane", 2500.0}
	};
    
    for(int i = 0; i < 3; i++){
        accounts[i].deposit(100.0);
        accounts[i].withdraw(500.0);
        accounts[i].display();
    }
}

