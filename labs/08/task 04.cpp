/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Person{
protected:
    string Name;
    int Age;

public:
    Person(const string& name, int age){
        Name = name;
        Age = age;
    }

    void displayPerson(){
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
    }
};

class Student: public Person{
protected:
    int StudentID;
    int gradeLevel;

public:
    Student(const string& name, int age, int ID, int grade): Person(name, age){
        StudentID = ID;
        gradeLevel = grade;
    }

    void displayStudent(){
        Person::displayPerson();
        cout << "Student ID: " << StudentID << endl;
        cout << "Grade: " << gradeLevel << endl;
    }
};

class Teacher: public Person{
protected:
    string Subject;
    int RoomNumber;

public:
    Teacher(const string& name, int age, string subject, int room): Person(name, age){
        Subject = subject;
        RoomNumber = room;
    }

    void displayTeacher(){
        Person::displayPerson();
        cout << "Subject: " << Subject << endl;
        cout << "Room Number: " << RoomNumber << endl;
    }
};

class GraduateStudent: public Student, Teacher{
public:
    GraduateStudent(const string& name, int age, int ID, int grade, string subject, int room): Student(name, age, ID, grade), Teacher(name, age, subject, room){

    }

    void displayGraduate(){
        Student::displayStudent();
        Teacher::displayTeacher();
    }
};

int main(){
    GraduateStudent gradStudent("John Doe", 25, 123456, 12, "Mathematics", 101);
    gradStudent.displayGraduate();

}