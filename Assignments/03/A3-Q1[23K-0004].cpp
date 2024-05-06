#include <iostream>
using namespace std;

class Medicine{
protected:
	string name;
	string formula;
	float price;
	string mfg;
	string exp;

public:
	Medicine(string name, string formula, float price, string mfg, string exp) : name(name), formula(formula), price(price), mfg(mfg), exp(exp) {}

	void setName(string n){
		name = n;
	}

	void setFormula(string f){
		formula = f;
	}

	void setPrice(float p){
		price = p;
	}

	void setMfg(string m){
		mfg = m;
	}

	void setExp(string e){
		exp = e;
	}

	string getName(){
		return name;
	}

	string getFormula(){
		return formula;
	}

	float getPrice(){
		return price;
	}

	string getMfg(){
		return mfg;
	}

	string getExp(){
		return exp;
	}

	void virtual print(){
		cout << "Name: " << name << "\nFormula: " << formula << "\nPrice: " << price << "\nManufacturing Date: " << mfg << "\nExpiration Date" << exp << endl;
	}

	friend class Pharmacist;
	friend class Counter;

	bool operator==(const Medicine &m2){
		if (exp.substr(0, 2) == m2.exp.substr(0, 2)){ // considering the date format yy/mm/dd
			return true;
    } else{
    	return false;
	}   
	}
};

class Tablet: public Medicine{
	float sucrose;

public:
	Tablet(string name, string formula, float price, string mfg, string exp, float s) : Medicine(name, formula, price, mfg, exp){
		if (s >= 0 && s <= 1){
			sucrose = s;
    	} else{
			sucrose = 0;
    	}
	}

	void setSucroselvl(float s){
		if (s >= 0 && s <= 1){
			sucrose = s;
		} else{
			sucrose = 0;
		}
	}

	float getSucroselvl(){
		return sucrose;
	}

	void print(){
		cout << "Name: " << name << "\nFormula: " << formula << "\nPrice: " << price << "\nManufacturing Date: " << mfg << "\nExpiration Date" << exp << "\nSucrose level: " << sucrose << endl;
	}
};

class Capsule: public Medicine{
	int absorption;

public:
	Capsule(string name, string formula, float price, string mfg, string exp, int a) : Medicine(name, formula, price, mfg, exp){
		if (a >= 1 && a <= 100){
			absorption = a;
		} else{
			absorption = 0;
		}
	}

	void setAbsorptionlvl(int a){
		if (a >= 1 && a <= 100){
			absorption = a;
		} else{
			absorption = 0;
		}
	}

	float getAbsorptionlvl(){
		return absorption;
	}

	void print(){
		cout << "Name: " << name << "\nFormula: " << formula << "\nPrice: " << price << "\nManufacturing Date: " << mfg << "\nExpiration Date" << exp << "\nAbsorption level: " << absorption << endl;
	}
};

class Syrup: public Medicine{
	int concentration;

public:
	Syrup(string name, string formula, float price, string mfg, string exp, int c) : Medicine(name, formula, price, mfg, exp){
		if (c >= 1 && c <= 100){
			concentration = c;
		} else{
			concentration = 1;
		}
	}

	void setConclvl(int c){
		if (c >= 1 && c <= 100){
			concentration = c;
		} else{
			concentration = 1;
		}
	}

	float getConcentrationlvl(){
		return concentration;
	}

	void print(){
		cout << "Name: " << name << "\nFormula: " << formula << "\nPrice: " << price << "\nManufacturing Date: " << mfg << "\nExpiration Date" << exp << "\nConcentration level: " << concentration << endl;
	}
};

class Pharmacist{
public:
	Medicine search_medicine(Medicine meds[], string formula);
};

class Counter{
	int revenue;

public:
	Medicine search_medicine(Medicine meds[], string name);
	int update_revenue(int bill_Amount);
};

int main(){
  	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	cout << "No implementation required a/c to given question";
return 0;
}
