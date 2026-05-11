/*
	D'Jaine Brown
	soccer.cpp
	Menu driven interface program that enables the user to load different pieces of information about a soccer team.

	Input:
			Player Name
			Player Number
			Goals Scored
	Processing:
			1. Display the menu.
			2. Perform the action signalled by the user's choice.
			3. Open and read the AtlantaUnited file.
			4. Store the data in a structure array.
			5. Display either the roster, goals, or star(2) based on input.
	Output:
			The team's Information in the form of its: Roster, Goals, and Star Players
*/
// Header Files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Declare Structures and their Arrays
struct Player
{
	string name;
	int number, goals;
} playerData[33];

// Function Prototypes
int menu();
string option1();

// Function definition
/*
int menu()
Parameters: None
Return type: integer
Purpose: To Display the menu, prompt the user for their choice, and return it.
*/
int menu()
{
	// Declare and Initialize temp variable
	int choice = 0;
	do
	{
		cout << "\nChoose one of the following options" << endl;
		cout << "\t1. Load the team's information." << endl;
		cout << "\t2. Display the team's roster." << endl;
		cout << "\t3. Display the team's goals." << endl;
		cout << "\t4. Display the team's star(s)." << endl;
		cout << "\t5. Quit." << endl;
		cout << "\nOption: ";

		// Get & Validate the input
		cin >> choice;
		if (choice < 1 || choice > 5)
		{
			cout << "\nError: Invalid Choice ... Please enter a valid choice from the menu." << endl;
		}
		else
		{
			return choice;
		}
	} while (choice < 1 || choice > 5);
}

/*
string option1()
Parameters: None
Return type: string
Purpose: Prompts the user for the name of the file they want to load, and returns it.
*/
string option1()
{
	// temp const & vars
	string file;

	// Get the name of the file
	cout << "\nEnter File Name: ";
	cin >> file;

	return file;
}

int main()
{
	//Consts & Vars
	ifstream file;
	string fileName;
	int userChoice, i = 0, total = 0, maxGoals = -1;

	// Display Intro followed by menu
	cout << "\nSoccer Team Goal ..." << endl;
	userChoice = menu();

	// Branch off based on choice
	do
	{
		// Open the file
		file.open("AtlantaUnited.txt");

		switch (userChoice)
		{
		// Load the File
		case 1:
			fileName = option1();
			if (fileName == "AtlantaUnited.txt")
			{
				cout << "\nFile has been loaded" << endl;
			}
			else
			{
				cout << "\nFile cannot be found" << endl;
			}
			userChoice = menu();
			break;
		// Display the team's roster
		case 2:
			// Read the data from the file into the Structure Array
			for (i = 0; i < 33 && getline(file, playerData[i].name); i++)
			{	
				file >> playerData[i].number;
				file >> playerData[i].goals;
				file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			// Display roster
			cout << "\nPlayer Name" << setw(15) << "Number" << setw(10) << "Goals" << endl << "--------------------------------------------------------------\n";
			for (int j = 0; j < i; j++)
			{
				cout << playerData[j].name << setw(11) << playerData[j].number << setw(11) << playerData[j].goals << endl;
			}

			userChoice = menu();
			break;
		// Display the team's goals
		case 3:
			total = 0;
			for (int k = 0; k < i; k++)
			{
				total += playerData[k].goals;
			}
			// Display goals
			cout << "\nTotal goals scored: " << total << endl;

			userChoice = menu();
			break;
		// Display star player(s)
		case 4:
			maxGoals = -1;
			int position;
			for (int l = 0; l < i; l++)
			{
				if (playerData[l].goals > maxGoals)
				{
					maxGoals = playerData[l].goals;
					position = l;
				}
			}
			cout << "\nTop team player(s): " << playerData[position].name << " (" << playerData[position].goals << " goals)" << endl;

			userChoice = menu();
			break;
		}

		// Close the file once you are done with it
		file.close();

	} while (userChoice != 5);
	cout << "\nOkay ..." << "\nGood Bye." << endl;
	
	return 0;
}