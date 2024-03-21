/*
Programmer: Syed Huzaifa Ali
Date: 1 Feb 2024
Description: Implement a basic Student Registration System in C++.
*/


#include <iostream>
#include <string>

using namespace std;

struct Register {
    string courseId;
    string courseName;
};

struct Student : public Register {
    string std_Id;
    string first_name;
    string last_name;
    long long cell_no; 
    string email;
};

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;

        cout << "Course ID: ";
        getline(cin, students[i].courseId);

        cout << "Course Name: ";
        getline(cin, students[i].courseName);

        cout << "Student ID: ";
        getline(cin, students[i].std_Id);

        cout << "First Name: ";
        getline(cin, students[i].first_name);

        cout << "Last Name: ";
        getline(cin, students[i].last_name);

        cout << "Cell Number: ";
        cin >> students[i].cell_no;
		cin.ignore();
		
        cout << "Email: ";
        getline(cin, students[i].email);

        cout << endl;
    }

    cout << "Student Information:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n"
             << "Course ID: " << students[i].courseId << "\n"
             << "Course Name: " << students[i].courseName << "\n"
             << "Student ID: " << students[i].std_Id << "\n"
             << "First Name: " << students[i].first_name << "\n"
             << "Last Name: " << students[i].last_name << "\n"
             << "Cell Number: " << students[i].cell_no << "\n"
             << "Email: " << students[i].email << "\n\n";
    }

    return 0;
}
