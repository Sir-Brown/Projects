/*
		D'Jaine Brown

		creditCards.cpp

		Determines whether a credit card number is valid or not based on an array of already existing/valid account numbers.

		Input:
				A credit card number

		Processing:
				1. Display intro
				2. Open and read pathway file
				3. Sort data in ascending order
				4. Prompt user for data
				5. Compare data entered to data read from file
				6. Determine the input's validity and display the results
				7. Close the file

		Output:
				The validity of the user's input
*/

// Header Files
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

// Function Prototype
void getFile(long int array[], int s);
void sortAsc(long int array[], int s);
bool searchBinary(long int array[], int s, int num);

// Function Definition
void getFile(long int array[], int s) {
	// Open the file
	ifstream file("accNumbers.txt");

	if (!file) {
		cerr << "\nError: Could not find the file required (accNumbers.txt)." << endl;
		return;
	}

	// Read the data in the array
	for (int i = 0; i < s; i++) {
		file >> array[i];
	}

	// Close the file
	file.close();
}
void sortAsc(long int array[], int s) {
	// Constants & Variables
	bool swapped;
	int temp = 0;

	// Using the bubble sort method, sort array in ascending order
	for (int lastIndex = 0; lastIndex < s; lastIndex++) {
		swapped = false;
		for (int currentIndex = 0; currentIndex < s - lastIndex - 1; currentIndex++) {
			if (array[currentIndex] > array[currentIndex + 1]) {
				temp = array[currentIndex];
				array[currentIndex] = array[currentIndex + 1];
				array[currentIndex + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
bool searchBinary(long int array[], int s, int num) {
	// Constants & Variables
	bool found = false;
	int first = 0, mid, last = s - 1;

	// Search the array for the value entered by the user
	while (!found && first <= last) {
		mid = (first + last) / 2;
		if (array[mid] == num) {
			found = true;
		}
		else if (array[mid] > num) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}

	return found;
}

int main() {
	// Constants and Variables
	string response;
	bool validity, flag = true;
	const int SIZE = 18;
	long int array[SIZE], accNum;

	// Display intro
	cout << "Credit Card Account Checker ..." << endl;

	// Load the file and read it into an array
	getFile(array, SIZE);

	// Sort the array
	sortAsc(array, SIZE);

	// Nest the following in a loop in case the user wants to try again
	while (flag) {
		// Prompt user for credit card number
		cout << "\nPlease enter a 7 - digit account number: ";
		cin >> accNum;

		// Determine the validity of the user's input
		validity = searchBinary(array, SIZE, accNum);

		// Display the result
		if (validity) {
			cout << "-> The credit card number entered is valid." << endl;
		}
		else {
			cout << "-> The credit card number entered is invalid." << endl;
		}

		// Nested loop to keep asking if the user's response is invalid
		while (true) {
			// Ask the user if they want to go again
			cout << "\nWould you like to try another number? (y/n)\n-> ";
			cin >> response;

			if (response == "y" || response == "yes" || response == "Y" || response == "Yes") {
				flag = true;
				break;
			}
			else if (response == "n" || response == "no" || response == "N" || response == "No") {
				flag = false;
				cout << "\nGood Bye ..." << endl;
				break;
			}
			else {
				cout << "\nPlease enter a valid response." << endl;
			}
		}
	}

	return 0;
}