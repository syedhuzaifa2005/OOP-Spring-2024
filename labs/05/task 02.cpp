/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class LoanHelper{
private:
	const float interestRate;
	float amount;
	int Months;
	
public:
	LoanHelper(float interestRate, float amount, int Months)
		: interestRate(interestRate), amount(amount), Months(Months){
		}
	
	void LoanRepayment(){
		float MonthlyPayment = ((amount / Months) * interestRate) + (amount / Months);
		cout << "You have to pay " << MonthlyPayment << " every month for " << Months << " months";
	}
};

int main(){
	LoanHelper loanhelper(0.05, 50000, 12);
	loanhelper.LoanRepayment();
}
