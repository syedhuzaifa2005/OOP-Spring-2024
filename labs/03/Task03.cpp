/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
Description: Creating a class named Calendar and performing required operations
*/

#include <iostream>
#include <string>

using namespace std;


class Calendar{
    string January[31];
	string February[28];
	string March[31];
	string April[30];
	string May[31];
	string June[30];
	string July[31];
	string August[31];
	string September[30];
	string October[31];
	string November[30];
	string December[31];
	string current_year;

public:
    void add_task(int date, int month, string task){
		switch (month){
			case 1:
				January[date-1] = task;
				break;
			case 2:
				February[date-1] = task;
				break;
			case 3:
				March[date-1] = task;
				break;
			case 4:
				April[date-1] = task;
				break;
			case 5:
				May[date-1] = task;
				break;
			case 6:
				June[date-1] = task;
				break;
			case 7:
				July[date-1] = task;
				break;
			case 8:
				August[date-1] = task;
				break;
			case 9:
				September[date-1] = task;
				break;
			case 10:
				October[date-1] = task;
				break;
			case 11:
				November[date-1] = task;
				break;
			case 12:
				December[date-1] = task;
				break;
			default: 
				cout<<"Enter a valid month.";
				break;
		}
	}

    void remove_task(int date, int month){
		switch (month){
			case 1:
				January[date-1] = "";
				break;
			case 2:
				February[date-1] = "";
				break;
			case 3:
				March[date-1] = "";
				break;
			case 4:
				April[date-1] = "";
				break;
			case 5:
				May[date-1] = "";
				break;
			case 6:
				June[date-1] = "";
				break;
			case 7:
				July[date-1] = "";
				break;
			case 8:
				August[date-1] = "";
				break;
			case 9:
				September[date-1] = "";
				break;
			case 10:
				October[date-1] = "";
				break;
			case 11:
				November[date-1] = "";
				break;
			case 12:
				December[date-1] = "";
				break;
			default: 
				cout<<"Invalid month";
				break;
		}
	}

    void display_tasks(){
		for(int i = 1; i <= 12; i++){
			switch (i){
				case 1:
					cout << "Tasks for January: " << endl;
					for (int j = 0; j < 31; j++){
						cout <<"	Day "<<j + 1<<": "<< January[j] << endl;
					}
					break;
				case 2:
					cout << "Tasks for February: " << endl;
					for (int j = 0; j < 29; j++){
						cout <<"Day "<< j + 1 << ": " << February[j] << endl;
					}
					break;
				case 3:
					cout << "Tasks for March: " << endl;
					for (int j = 0; j < 31; j++){
					cout<<"	Day "<<j+1<<": "<<March[j]<<endl;
					}
					break;
				case 4:
					cout << "Tasks for April: " << endl;
					for (int j = 0; j < 30; j++){
						cout << "Day "<< j + 1 <<": " << April[j] << endl;
					}
					break;
				case 5:
					cout << "Tasks for May: " << endl;
					for (int j = 0; j < 31; j++){
						cout << "Day " << j + 1 << ": " << May[j] << endl;
					}
					break;
				case 6:
					cout << "Tasks for June: " << endl;
					for (int j = 0; j < 30; j++){
						cout <<"Day " << j + 1 << ": " << June[j] << endl;
					}
					break;
				case 7:
					cout << "Tasks for July: " << endl;
					for (int j = 0; j < 31; j++){
						cout << "Day "<< j+1 << ": " << July[j] << endl;
					}
					break;
				case 8:
					cout << "Tasks for August: " << endl;
					for (int j = 0; j < 30; j++){
						cout << "Day " << j + 1 << ": " << August[j] << endl;
					}
					break;
				case 9:
					cout << "Tasks for September: " << endl;
					for (int j = 0; j < 31; j++){
						cout << "Day " << j + 1 << ": " << September[j] << endl;
					}
					break;
				case 10:
					cout << "Tasks for October: " << endl;
					for (int j = 0; j < 30; j++){
						cout <<"Day " << j + 1 << ": " << October[j] << endl;
					}
					break;
				case 11:
					cout << "Tasks for November: " << endl;
	    			for (int j = 0; j < 31; j++){
						cout <<"Day " << j + 1 << ": " << November[j] << endl;
					}
					break;
				case 12:
					cout << "Tasks for December: " << endl;
					for (int j=0; j<30; j++){
						cout <<"Day " << j + 1 << ": " << December[j] << endl;
					}
					break;
			}
		}		
	}	

};

int main(){
    Calendar data;
	string task;
	int month;
	int date;
	int choice;
	cout<<"Press 1 to add a task\nPress 2 to remove a task\nPress 3 to display all the tasks\nPress 4 to exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	cout<<"\n";
	switch (choice){
		case 1:
			cout<<"Enter Month (in numbers): ";
			cin>>month;
			cout<<"Enter Day (in numbers): ";
			cin>>date;
			cout<<"Enter the Task: ";
			getline(cin, task);
			data.add_task(date, month, task);
			cout << endl;
			break;
		case 2:
			cout<<"Enter Month (in numbers): ";
			cin>>month;
			cout<<"Enter Day (in numbers): ";
			cin>>date;
			data.remove_task(date, month);
			cout << endl;
			break;
		case 3:
			data.display_tasks();
			cout << endl;
			break;
		case 4:
			exit(0);
			break;
	}
}