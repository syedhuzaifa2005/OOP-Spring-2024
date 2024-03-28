/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;



class Table{
private:
	int TableCapacity;
	int SeatsOccupied;
	int FreeSeats;
	bool Clean;
	bool Possession;
	
public:
	Table(){
		TableCapacity = 4;
		SeatsOccupied = 4;
		FreeSeats = TableCapacity;
		Clean = true;
		Possession = false;	
	}
	
	Table(int capacity, bool clean, bool possession){
		Clean = clean;
		Possession = possession;
		
		if(capacity == 4  || capacity == 8){
			TableCapacity = capacity;
		} else{
			int diff_4 = capacity - 4;
			int diff_8 = capacity - 8;
			if(diff_4 < diff_8){
				TableCapacity = 4;
			} else{
				TableCapacity = 8;
			}
		}
	}
	
	void UseTable(int size){
		if(Possession == false){
			if(Clean == true){
				if(size <= TableCapacity){
					Possession = false;
					//cout << "A table is available for this group" << endl;
				}
			} else{
				Possession = true;
				Clean = false;
				cout << "This table is either not clean or already occupied" << endl;
			}
		}
	}
	
	void HaveLunch(){
		Possession = true;
		Clean = false;
		cout << "The group is having lunch at this table" << endl;
	}
	
	void LeaveTable(){
		Possession = false;
		Clean = false;
		cout << "The group has left the table" << endl;
	}
	
	void CleanTable(){
		if(Possession == false){
				cout << "Cleaning the table" << endl;
		} else{
			cout << "The table cannot be cleaned when occupied" << endl;
		}
	}
	
	void Empty(){
		Possession = false;
		Clean = true;
		SeatsOccupied = 0;
		FreeSeats = TableCapacity;
		cout << "The table is now empty" << endl;
	}
	bool getpossession(){
		return Possession;
	}
};


void OccupyTable(Table tables[], int groupSize){
	if(groupSize > 0  &&  groupSize <= 4){
		for(int i = 2; i < 5; i++){
			bool checkVacancy = tables[i].getpossession();
			if(checkVacancy == false){
				tables[i].UseTable(groupSize);
			} else{
				continue;
			}
		}
		cout << "A table is available for this group" << endl;
		
	} else if(groupSize > 4  &&  groupSize <= 8){
		for(int i = 0; i < 2; i++){
			bool checkVacancy = tables[i].getpossession();
			if(checkVacancy == false){
				tables[i].UseTable(groupSize);
			} else{
				continue;
			}
		}
		cout << "A table is available for this group" << endl;
	}
}

void EmptyTable(Table tables[], int num){
	tables[num - 1].LeaveTable();
	tables[num - 1].CleanTable();
	tables[num - 1].Empty();
}


int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl << endl;
	Table tables[5] = {Table(8, true, false), Table(8, true, false), Table(4, true, false), Table(4, true, false), Table(4, true, false)};
	
	cout << "TABLE 1:" << endl;
	OccupyTable(tables, 4);
	tables[3].UseTable(4);
	tables[3].HaveLunch();
	tables[3].LeaveTable();
	tables[3].CleanTable();
	
	cout << endl << endl << "TABLE 2:" << endl;
	OccupyTable(tables, 6);
	EmptyTable(tables, 1);
}
