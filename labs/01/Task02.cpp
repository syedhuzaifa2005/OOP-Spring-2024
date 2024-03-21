#include <iostream>

using namespace std;

// Function to calculate grade based on marks
char calculateGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int numStudents;
   
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 1; i <= numStudents; ++i) {
        float mathMarks, englishMarks, scienceMarks;

        cout << "Enter marks for student " << i << " (Math English Science): ";
        cin >> mathMarks >> englishMarks >> scienceMarks;

        float totalMarks = mathMarks + englishMarks + scienceMarks;
        float averageMarks = totalMarks / 3.0;

        char grade = calculateGrade(averageMarks);
      
        cout << "\nStudent " << i << ":\n";
        cout << "Mathematics: " << mathMarks << "\n";
        cout << "English: " << englishMarks << "\n";
        cout << "Science: " << scienceMarks << "\n";
        cout << "Total Marks: " << totalMarks << "\n";
        cout << "Average Marks: " << fixed << averageMarks << "\n";
        cout << "Grade: " << grade << "\n\n";
    }

    return 0;
}