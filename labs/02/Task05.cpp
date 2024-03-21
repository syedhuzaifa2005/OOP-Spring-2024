/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description:Product management system
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int position=0;

struct product{
	int productid;
	string name;
	float price;
	int quantity;
};

product products[100];

void addProduct(product products[],int &position);
void findProduct(product products[],int productid);
void updaterecord(product products[],int productid);


int main() {
	int choice;
    do{
        cout<< "Press 1 to add a product" << endl;
        cout<< "Press 2 to update existing data" << endl;
        cout<< "Press 3 to find a product" << endl;
        cout<< "Exit" << endl;
        cout<< "Enter your choice:" << endl;
        cin>> choice;
    
        switch (choice) {
    	    case 1:
    		    addProduct(products,position);
    		break;
    		
    	    case 2:
    		    int productid;
    		    cout<< "enter the id of the product you want to find"<<endl;
    		    cin>> productid;
    		    findProduct(products,productid);
    		break;
    		
    	    case 3:
    		    int productid2;
    		    cout<< "enter the id of the product you want to find"<<endl;
    		    cin>> productid2;
    		    updaterecord(products,productid2);
    		break;
    		
    	    case 4:
    		    cout <<"Exiting the program"<<endl;
    		    exit(0);
    		break;
    		
            default:
        	    cout<< "Invalid input"<<endl;
        	    sleep(2);
        	break;
	    }

    } while(choice != 4);
	
}



void addProduct(product products[],int &position) {
	cout<< "Add product details" <<endl;
	cout<< "enter the product ID:" <<endl;
	cin>> products[position].productid;
	cout<< "enter the product name" <<endl;
	cin.ignore();
	getline(cin,products[position].name);
	cout<< "enter the product price" <<endl;
	cin>> products[position].price;
	cout<< "Enter the product quantity" <<endl;
	cin>> products[position].quantity;
	cout<< "Product added" <<endl;
	position++;
}


void findProduct(product products[],int productid) {
	for(int i=0;i<position;i++) {
		if(products[i].productid==productid) {
			cout<< "Product found" <<endl;
			cout<< "Product id: " <<endl;
			cout<< products[i].productid <<endl;
			cout<< "Product name:" <<endl;
			cout<< products[i].name <<endl;
			cout<< "Product price:" <<endl;
			cout<< products[i].price <<endl;
			cout<< "Product quantity:" <<endl;
			cout<< products[i].quantity <<endl;
		}
	}
	cout<< "Product not found"<<endl;
}


void updaterecord(product products[],int productid) {
	for(int i=0;i<position;i++) {
		if(products[i].productid==productid) {
			cout<< "Add new product name:"<<endl;
			cin.ignore();
			getline(cin,products[i].name);
			cout<< "Add new product price:"<<endl;
			cin>> products[i].price;
			cout<< "Add new product quantity:"<<endl;
			cin>> products[i].quantity;
			cout<< "Record updated"<<endl;
		}
	}
}
