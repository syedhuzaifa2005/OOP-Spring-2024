/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class ValidateString{
private:
	string String;

public:
	ValidateString( const string& str){
		String = str;
	}
	
	bool checkString() const{
		for(char ch: String){
			if(!isalpha(ch)){
				return false;
			} 
		}
		return true;
	}
};

int main(){
	ValidateString string1("HelloWorld");
	ValidateString string2("Hello123");
	
	cout << "String 1 is " << (string1.checkString() ? "valid" : "invalid") << endl;
	cout << "String 2 is " << (string2.checkString() ? "valid" : "invalid") << endl;
}
