/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class Course{
private:
    string courseCode;
    string courseName;
    int creditHours;

public:
    Course(string Ccode, string Cname, int Chours){
        courseCode = Ccode;
        courseName = Cname;
        creditHours = Chours;
    }

    string getCourseCode() const {
        return courseCode;
    }

    string getCourseName() const {
        return courseName;
    }

    int getCreditHours() const {
        return creditHours;
    }
};

class Student{
private:
    string StdID;
    string StdName;
    static const int max_courses = 8;
    Course* enrolledCourse[max_courses];
    int numberofCourses;

public:
    Student(string ID, string name){
        StdID = ID;
        StdName = name;
        numberofCourses = 0;
    }

    void enroll(Course* course){
        if(numberofCourses < max_courses){
            enrolledCourse[numberofCourses] = course;
            numberofCourses++;
        } else{
            cout << "Limit reached" << endl;
        }
    }

    void drop(Course* course){
        for(int i = 0; i < numberofCourses; i++){
            if(enrolledCourse[i] == course){
                for(int j = i; j < numberofCourses - 1; j++){
                    enrolledCourse[j] = enrolledCourse[j + 1];
                }
                numberofCourses--;
                break;
            }
        }
    }

    int getTotalCreditHours(){
        int totalHours = 0;
        for (int i = 0; i < numberofCourses; ++i) {
            totalHours += enrolledCourse[i]->getCreditHours();
        }
        return totalHours;
    }

    void printEnrolledCourses(){
        cout << "Student Name: " << StdName << "\tStudent ID: " << StdID << endl;
        cout << "Enrolled Courses: " << endl;
        for(int i = 0; i < numberofCourses; i++){
            cout << "Course Code: " << enrolledCourse[i]->getCourseCode() << endl;
            cout << "Course Name: " << enrolledCourse[i]->getCourseName() << endl;
            cout << "Total Credit Hours: " << enrolledCourse[i]->getCreditHours() << endl;
        }
    }
};

int main(){
    Course course1("CSCI101", "Introduction to Computer Science", 3);
    Course course2("MATH201", "Calculus I", 4);

    Student student("S123456", "John Doe");
    student.enroll(&course1);
    student.enroll(&course2);

    student.printEnrolledCourses();
    cout << "Total Credit Hours: " << student.getTotalCreditHours() << endl;

    student.drop(&course1);
    student.printEnrolledCourses();
    cout << "Total Credit Hours: " << student.getTotalCreditHours() << endl;

}
