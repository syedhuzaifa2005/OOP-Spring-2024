/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description: Calculating GCD and LCM using recursions
*/


#include <iostream>

using namespace std;


int Calculate_GCD(int a, int b);
int Calculate_LCM(int a, int b, int i = 1);

int main(){
    int x, y;
    cout<< "Enter the first number: " << endl;
    cin>> x;
    cout<< "Enter the second number: " << endl;
    cin>> y;

    cout<< "GCD of " << x << " and " << y << " is: " << Calculate_GCD(x, y) << endl;
    cout<< "LCM of " << x << " and " << y << " is: " << Calculate_LCM(x, y) << endl;
}


int Calculate_GCD(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return Calculate_GCD(b, a % b);
    }
}


int Calculate_LCM(int a, int b, int i){
    if ((i * a) % b == 0) {
        return i * a;
    } 
    else{
        return Calculate_LCM(a, b, i + 1);
    }
}