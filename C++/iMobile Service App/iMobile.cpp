/*
	D'Jaine Brown

	iMobile.cpp

	Prompts user for necessary input to calculate and then display the customer's monthly bill.

	Input:
			Customer's Plan
			Number of Gigabytes of data used
	Processing:
			1. Display menu for user to choose plan
			2. Prompt Customer for number of data used
			3. Calculate the amount due based on the package and price
			4. Display Monthly Bill
	Output:
			Total Amount Due (Monthly Bill)
			

	Note: Uses Switch Statement
*/

// Header Files
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Constants & Variables
	const double A = 39.99, B = 59.99, C = 69.99;
	int choice;
	double dataUsed, addData, excessCost, totalPrice;

	//Prompt user for Package - validate this to ensure choice coincides with the menu
	cout << "Select a subscription package:\n"
		<< "\t1. Package A\n"
		<< "\t2. Package B\n"
		<< "\t3. Package C" << endl;
	cout << "\nPackage: ";
	cin >> choice;

	if (choice >= 1 && choice <= 3)
	{
		//Prompt user for how much data has been used - validate this to ensure no negative values have been entered
		cout << "\nHow many Gigabytes of Data were used? ";
		cin >> dataUsed;

		if (dataUsed < 0)
			cout << "\nError ... Please enter a positive value..." << endl;
		else
			//Calculate the total amount due based on Package (use if/else or if/else if or switch to do this)
			switch (choice)
			{
			case 1:
				if (dataUsed > 4.0)
				{
					addData = dataUsed - 4;
					excessCost = addData * 10;
					totalPrice = excessCost + A;

					cout << "\nYou exceeded the data limit by " << addData << "gbs" << endl;
					cout << "The total amount due is $" << setprecision(2) << fixed << totalPrice << endl;
					break;
				}
				else
					cout << "\nYou did not exceed the Data limit..." << endl;
					cout << "The total amount due is $" << setprecision(2) << fixed << A << endl;
					break;
			case 2:
				if (dataUsed > 8.0)
				{
					addData = dataUsed - 8;
					excessCost = addData * 5;
					totalPrice = excessCost + B;

					cout << "\nYou exceeded the data limit by " << addData << "gbs" << endl;
					cout << "The total amount due is $" << setprecision(2) << fixed << totalPrice << endl;
					break;
				}
				else
					cout << "\nYou did not exceed the Data limit..." << endl;
				cout << "The total amount due is $" << setprecision(2) << fixed << B << endl;
				break;
			case 3:
				cout << "\nThe total amount due is $" << setprecision(2) << fixed << C << endl;
				cout << "You have unlimited data so feel free to use more!\n";
				break;
			}
	}
	else
		cout << "\nError ... Invalid Package. Please enter a number from the menu..." << endl;

return 0;
}
