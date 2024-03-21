/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;


class Weekdays{
private:
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int CurrentDay;

public:
    Weekdays(){
        CurrentDay = 0;
    }
    Weekdays(int x){
        if(x > 6){
            CurrentDay = x % 7;
        } else{
            CurrentDay = x;
        }
    }

    string getCurrentDay() const{
        return Days[CurrentDay];
    }
    string getNextDay() const{
        return Days[CurrentDay +1];
    }
    string getPreviousDay() const{
        return Days[(CurrentDay + 6) % 7];
    }
    string getNthDayFromToday(int n) const{
        return Days[(CurrentDay + n) % 7];
    }
};

int main(){
    Weekdays week(8);
    int n=4;
    cout << "Current Day: " << week.getCurrentDay() << endl;
    cout << "Next Day: " << week.getNextDay() << endl;
    cout << "Previous Day: " << week.getPreviousDay() << endl;
    cout << n << " days from today: " << week.getNthDayFromToday(n) << endl;
   
    return 0;
}