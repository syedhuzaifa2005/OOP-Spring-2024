#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;
    if (number <= 1) {
        cout << number << " is not a prime number." << endl;
    } else {
        bool isPrime = true;
        for (int i = 2; i <= sqrt(number); ++i) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << number << " is a prime number." << endl;
        } else {
            cout << number << " is not a prime number." << endl;
        }
    }

    return 0;
}