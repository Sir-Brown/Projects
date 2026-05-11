/*
		D'Jaine Brown

		paintEstimator.cpp

		Prompt the user for the price of the paint, amount of rooms to be painted and their square feet in order to calculate and display, how much paint is required,
		the cost of the paint, the hours of labor required & its cost, as well as the total cost of  the paint job.

		Input:
				Price of the paint per gallon
				Number of rooms to be painted
				The square feet of wall space in each room
		Processing:
				1. Display intro
				2. Prompt user for necessary information (may use functions)
				3. Validate the input
				4. Calculate:
								the number of gallons of paint required and its cost.
								the hours of labor required and the charges.
								the total cost of the pain job.
				5. Display the results
		Output:
				The number of gallons of paint required
				The cost of the paint
				The hours of labor required
				The labor charges
				The total cost of the paint job
*/
// Header Files
#include <iostream>
#include  <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

// Function Prototypes - void, value-returning, value parameters, reference parameters
double getPricePerGallon();
int getRooms();
int calcWallSpace(int rooms);
void calcPaint(double pricePaint, int gallons, double& total);
void calcLabor(double hours, double cost, double& total);

// Function Definitions
/*
getPricePerGallon();
Return Type: double
Parameter: none
Purpose: Prompts user for price of paint per gallon and returns it
*/
double getPricePerGallon()
{
	double gallon = -1;
	do
	{
		cout << "\nPrice per gallon of paint (>=0): ";
		cout << setprecision(2) << fixed;
		cin >> gallon;

		if (!(gallon >= 0))
		{
			cout << "\nError ... Invalid price per gallon of paint.Try again." << endl;
		}
		else
		{
			return gallon;
		}
	} while (gallon < 0);
}
/*
getRooms();
Return Type: int
Parameter: none
Purpose: Prompts user for the number of rooms to be painted and returns it
*/
int getRooms()
{
	int roomNum = 0;
	do
	{
		cout << "\nNumber of Rooms to be painted (>= 1): ";
		cin >> roomNum;

		if (roomNum < 1)
		{
			cout << "\nError ... Invalid number of rooms. Try again." << endl;
		}
		else
		{
			return roomNum;
		}
	}
	while (roomNum < 1);
}
/*
calcWallSpace(int rooms);
Return Type: int
Parameter: 1 int for number of rooms
Purpose: Prompts user for the square feet of the walls to be painted in each room and returns it
*/
int calcWallSpace(int rooms)
{
	int count, wallSpace, total = 0;

	cout << "\nSquare Feet of Wall Space (>= 25)" << endl;
	for (count = 1; count <= rooms; count++)
	{
		cout << "\tRoom " << count << ": ";
		cin >> wallSpace;

		if (wallSpace < 25)
		{
			cout << "\tError ... Incorrect wall space for the room. Try again." << endl;
			count -= 1;
		}
		else
		{
			total += wallSpace;
		}
	}
	return total;
}
/*
calcPaint(int sqrFeet, double pricePaint, int& gallons, double& cost);
Return Type: void
Parameter: 2 int, & 2 double
Purpose: Calculates the cost of the paint and displays it
*/
void calcPaint(double pricePaint, int gallons, double& total)
{
	double paintTCost = pricePaint * gallons;
	total += paintTCost;

	cout << "\n\tPaint Job Estimate" << endl;
	cout << "\nPaint ..." << endl;
	cout << "Gallons of Paint:" << setw(10) << gallons << endl;
	cout << "Cost of Paint:" << setw(14) << "$ " << paintTCost << endl;
}
/*
calcLabor(int sqrFeet, double hours, double& cost);
Return Type: void
Parameter: 3 double
Purpose: Calculates the cost of labor and displays it
*/
void calcLabor(double hours, double cost, double& total)
{
	double laborCost;
	laborCost = hours * cost;
	total += laborCost;

	cout << "\nLabor ..." << endl;
	cout << "Hours of Labor:" << setw(16) << hours << endl;
	cout << "Cost of Labor:" << setw(14) << "$ " << laborCost << endl;
	cout << setw(36) << "----------" << endl;
}



int main()
{
	// Constants (and)&& / (or)|| Variables
	double gallonPrice, gallons = 0.0, hours = 0.0, total = 0.0, compCharge = 25.00;
	int roomNum, sqrFeet;

	// Intro
	cout << "\nPaint Job Estimator ..." << endl;

	// Prompt user for input
	gallonPrice = getPricePerGallon();
	roomNum = getRooms();
	sqrFeet = calcWallSpace(roomNum);

	// Perform any necessary calculations
	gallons = sqrFeet / 115.0;
	int gallonsRounded = round(gallons);
	hours = gallons * 8;

	calcPaint(gallonPrice, gallonsRounded, total);
	calcLabor(hours, compCharge, total);

	// Display result
	cout << "\nTotal Cost:" << setw(17) << "$ " << total << endl;


	return 0;
}
