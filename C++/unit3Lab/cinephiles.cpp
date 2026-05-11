/*
		D'Jaine Brown

		cinephiles.cpp

		Gathers statistical data about the number of movies college students pursuing a particular pathway see in a month.

		Input:
				A string for file name

		Processing:
				1. Display intro
				2. Prompt user for data
				3. Open and read pathway file
				4. Allocate space to store the values read
				5. Feed the space the data read
				6. Display the values
				7. Calculate & display average number of movies watched in a month
				8. Deallocate the previously allocated space

		Output:
				An array [The Student's Answers]
				An int [average movies watched]
*/

// Header Files
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

// Structure Definition
struct StudentData {
    string collegeName;
    int numStudents;
    string major;
};

// Function Prototype
void getFile();
void averageMovies(int* arr, StudentData s);

// Function Definittion
void getFile() {
    // Constants & Variables
    string fileName;
    StudentData student;

    // Prompt the user for the name of the pathway file containing the number of movies seen by students.
    cout << "\nPlease enter Pathway File Name (lowercase e.g. name.txt): ";
    getline(cin, fileName);

    // Load the appropriate file based on the user's input
    ifstream file(fileName);

    if (!file) {
        cerr << "\nError: Could not open the specified file." << endl;
        return;
    }

    // Read data from the file
    getline(file, student.collegeName);
    getline(file, student.major);
    file >> student.numStudents;

    // Dynamically allocate an array of integers with a size equal to the number of student answers in the pathway file.
    int* array = new int[student.numStudents];

    // Read data directly into the array
    for (int i = 0; i < student.numStudents; i++) {
        if (!(file >> array[i])) {
            cerr << "\nError: Could not read enough data for students." << endl;
            delete[] array;
            return;
        }
    }

    // Display the student's school, pathway and answers (10 values per line).
    cout << "\nCollege: " << student.collegeName << endl;
    cout << "Pathway: " << student.major << endl;
    cout << "------------------------------" << endl;
    cout << "\nNumber of movies seen by " << student.numStudents << " students" << endl;

    for (int j = 0; j < student.numStudents; j++) {
        cout << "    " << setw(3) << array[j] << "    ";

        // Print 10 values per line
        if ((j + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    averageMovies(array, student);

    // Deallocate memory and close file
    delete[] array;
    file.close();

}

void averageMovies(int* arr, StudentData s) {
    // Constants & Variables
    int totalMovies = 0, averageMovies = 0;

    for (int i = 0; i < s.numStudents; i++) {
        totalMovies += arr[i];
    }

    averageMovies = totalMovies / s.numStudents;

    cout << "\nTotal Movies watched by all students: " << totalMovies << endl;
    cout << "Average number of movies seen per month: " << averageMovies << endl;
}

int main() {
    // Constants & Variables
    string multipleFiles;
    bool flag = true;
    
    // Display Intro
    cout << "Welcome Welcome!\n" << endl;
    cout << "College Cinephiles Pathway Stats ..." << endl;

    while (flag) {
        // Get the file
        getFile();

        while (true) {
            // Check if the user has another file
            cout << "\nDo you have another file? (y/n) ";
            getline(cin, multipleFiles);

            if (multipleFiles == "y" || multipleFiles == "yes" || multipleFiles == "Y" || multipleFiles == "Yes") {
                flag = true;
                break;
            }
            else if (multipleFiles == "n" || multipleFiles == "no" || multipleFiles == "N" || multipleFiles == "No") {
                flag = false;
                break;
            }
            else {
                cout << "\nPlease enter a valid response." << endl;
            }
        }
    }
    return 0;
}
