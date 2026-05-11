/*
		D'Jaine Brown

		labAssignment.cpp

		Manages a list of students via structures using an array. Prompt the user for bits of data for 5 students and store it in an array.
		Calculate and display the GPA for each student, and display the student with the highest GPA.

		Input:
				An integer for 'id'
				A string for 'name'
				An integer for 'year'
				Decimal value for 'GPA'
		Processing:
				1. Display intro
				2. Prompt user for data
				3. Calculate GPA
				4. Determine which is the highest
				5. Display the result
		Output:
				The name, id, year, and gpa of the student with the highest gpa
*/

// Header Files
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    int year;
    double GPA;
};

int main() {
    // Constants & Variables
    int higher = 0, marker, sum = 0;
    const int SIZE = 5;
    Student studentData[SIZE];

    // Display Intro
    cout << "Welcome to the GPA ranking program!\n" << endl;

    for (int i = 0; i < SIZE; i++) {
        // Get the name and enter it into the array
        cout << "Enter the student's name: ";
        getline(cin, studentData[i].name);

        // Get the grade and enter it into the array
        cout << "Enter the student's ID: ";
        cin >> studentData[i].id;

        // Get the age and enter it into the array
        cout << "Enter the student's year in school: ";
        cin >> studentData[i].year;

        // Get the grade and enter it into the array
        cout << "Enter the student's GPA: ";
        cin >> studentData[i].GPA;

        // Calculate the average GPA
        sum += studentData[i].GPA;

        // Record the highest GPA
        if (studentData[i].GPA > higher) {
            higher = studentData[i].GPA;
            marker = i;
        }
        else {
            higher = higher;
        }

        // Refresh the buffer
        cin.ignore();
        system("cls");
    }

    // Display results
    cout << "The average GPA is: " << sum / SIZE << endl;

    cout << "\nThe Student with the highest GPA is Student #" << marker + 1 << endl;
    cout << "\nName: " << studentData[marker].name << endl;
    cout << "ID: " << studentData[marker].id << endl;    
    cout << "Year: " << studentData[marker].year << endl;
    cout << "GPA: " << studentData[marker].GPA << endl;

    return 0;

}
