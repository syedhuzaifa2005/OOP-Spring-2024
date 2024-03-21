/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description: Constructing a stationary shop
*/

#include <iostream>
#include <string>

using namespace std;

int p = 0;

class StationaryShop{
private:    
    string Items[100];
    int Prices[100];

public:
    void AddItems(int x){
        for(int i = 0; i < x; i++){
            cout << "Enter item " << i + 1 << " details: " << endl;
            getline(cin, Items[i]);
            cout << "Enter the price for item " << i + 1 << ": " << endl;
            cin >> Prices[i];
            p++;
        }
    }
    void RetrieveList(){
        if(p == 0){
            cout << "No item in the list" << endl;
        } else{
            for(int i = 0; i < p; i++){
                cout << "Item " << i + 1 << ": " << Items[i] << endl;
            }
        }
    }
    void ModifyPrice(int price, int n){
        Prices[n - 1] = price;
    }
    void DisplayList(){
        for(int i = 0; i < p; i++){
            cout << "Item " << i + 1 << ": " << endl;
            cout << "Item name: " << Items[i] << endl;
            cout << "Price: " << Prices[i] << endl;
        }
    }
};


int main(){
    StationaryShop shop; 
    int n, price, choice;
    cout << "Press 1 to add Items\nPress 2 to retrieve the list\nPress 3 to modify the prices\nPress 4 to disply all the items\nPress 5 to exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            cout << "Enter the number of items to be added" << endl;
            cin >> n;
            shop.AddItems(n);
            cout << "Items added" << endl;
            break;
        case 2:
            shop.RetrieveList();
            break;
        case 3:
            cout << "Enter the item number for which you want to modify the price" << endl;
            cin >> n;
            cout << "Enter modified price" << endl;
            cin >> price;
            break;
        case 4:
            shop.DisplayList();
            break;
        case 5:
            cout << "Program exitted successfully" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
    }

}