/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

inline float BattingAverage(int runs_Scored, int Dismissals){
    if(Dismissals == 0){
        return 0;
    }
    else{
        return static_cast<double>(runs_Scored) / Dismissals;
    }
}

inline float StrikeRate(int runs_Scored, int BallsFaced){
    if(BallsFaced == 0){
        return 0;
    }
    else{
        return static_cast<double>(runs_Scored) / BallsFaced * 100;
    }
}

int main(){
    int runs_Scored, Dismissals, BallsFaced;
    cout << "Enter total runs scored: ";
    cin >> runs_Scored;
    cout << "Enter total dismissals: ";
    cin >> Dismissals;
    cout << "Enter total balls faced: ";
    cin >> BallsFaced;

    cout << "Batting average: " << BattingAverage(runs_Scored, Dismissals) << endl;
    cout << "Strike Rate: " << StrikeRate(runs_Scored, BallsFaced) << endl;
    return 0;
}