/*
	D'Jaine Brown

	evergladesRPG.cpp

	This is a menu-driven interface program that simulates an RPG game. It provides the user with multiple options and enacts various actions in response.
	The menu will include the following:
	1. See Rules.
	2. Play Game.
	3. Quit.

	Input:
		Various User Choices:
			Menu options
			Direction of Movement (Cell)
			Moves (Fight or Wait)

	Processing:
		1. Display menu.
		2. Prompt user for choice and validate it.
		3. Perform the menu options:
			a. See rules:
				Displays the game's rules to the player.
			b. Play Game:
				Generates map
				Allocates enemies
				Places player and trapped tourists
				Prompt player for moves, including decision when in an altercation
				Count down via 'Gong'
				Display result whether it be a win or lose
			c. Quit

	Output:
		Player Results (W or L)
*/

// Header Files
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

// Function Prototypes
int menu();
void rules();
void createMap(char map[][5], char grid[][5]);
void showMap(char map[][5]);
void placeDanger(char map[][5], char arr[]);
bool movement(char grid[][5], char map[][5], int& gongs, int& rangerRow, int& rangerCol, int& rowN, int& colN);
void conflict(const string ARRAY[], char arr[], char map[][5], char grid[][5], int& rangerRow, int& rangerCol, int rowN, int colN, int& gongs);
bool isGameOver(int rangerRow, int rangerCol, int touristRow, int touristCol, int gongs);

// Function Definitions
/*
int menu()
Parameters: None
Return type: integer
Purpose: To display the menu, prompt the user for their choice, and return it.
*/
int menu()
{
	// Declare and initialize a temporary variable
	int choice = 0;
	do
	{
		cout << "\nChoose one of the following options:" << endl;
		cout << "1. Load the game's rules." << endl;
		cout << "2. Play the game." << endl;
		cout << "3. Quit." << endl;
		cout << "\nOption: ";

		// Get & Validate the input
		cin >> choice;
		if (choice < 1 || choice > 3)
		{
			cout << "\nError: Invalid Choice ... Please enter a valid choice from the menu." << endl;
		}
		else
		{
			return choice;
		}
	} while (choice < 1 || choice > 3);
}
/*
void rules()
Parameters: None
Return type: Void
Purpose: To display the rules of the game.
*/
void rules()
{
	// List the game's rules in this function
	cout << "\nThe game's rules are as follows:" << endl;
	cout << "\nA group of tourists has gone missing in the Everglades and you, the ranger, must rescue them before time runs out."
		<< "\nThe playable area is a 5 x 5 matrix, and you (R) start the rescue at the upper-left corner of the park."
		<< "\nThe missing tourists (T) are at the lower-right corner."
		<< "\nYou have 12 'gongs of time' to find and rescue the tourists before they perish."
		<< "\nOn your journey, you might encounter the following dangers: hungry alligators, swarms of giant mosquitoes, venomous spiders and/or Pythons." << endl;

	cout << "\nIf you run into danger, you can choose to fight or hide and wait for them to leave." << endl
		<< "\n\t* If you choose to hide, you risk losing 5 gongs of time." << endl
		<< "\n\t* If you choose to fight and win, you only lose 2 gongs of time." << endl
		<< "\n\t* If you choose to fight and lose, you stay in the same cell and lose 3 gongs of time." << endl
		<< "\nIf you don't run into danger, you simply lose 1 gong of time." << endl;

	cout << "\nThe game ends when either:" << endl
		<< "\n\t* You rescue the lost group." << endl
		<< "\n\t* The time expires." << endl
		<< "\nGood Luck Ranger . . . you'll need it." << endl;
}
/*
void createMap(char map[][5], char grid[][5])
Parameters: Two 2d Arrays
Return type: Void
Purpose: To create the playable area of the game, with the player and the enemies.
*/
void createMap(char map[][5], char grid[][5])
{
	// Initialize the 2d array (map) with 'unknown symbols' for now
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = '*';
		}
	}

	// Add the ranger and the tourists to the map
	map[0][0] = 'R';
	map[4][4] = 'T';

	// Create a copy - the scapegoat that we will show in order to hide the enemies. Initialize the 2d array (grid) with 'unknown symbols' for now
	for (int k = 0; k < 5; k++)
	{
		for (int l = 0; l < 5; l++)
		{
			grid[k][l] = '*';
		}
	}

	// Add the ranger and the tourists to the map
	grid[0][0] = 'R';
	grid[4][4] = 'T';
}
/*
void showMap(char map[][5])
Parameters: 2d Array
Return type: Void
Purpose: To only display the playable area of the game.
*/
void showMap(char map[][5])
{
	cout << "\t  " << 0 << "\t  " << 1 << "\t  " << 2 << "\t  " << 3 << "\t  " << 4 << endl;

	for (int a = 0; a < 5; a++)
	{
		cout << a << "\t";
		for (int b = 0; b < 5; b++)
		{
			cout << "| " << map[a][b] << " |" << "\t";
		}
		cout << endl;
	}
}
/*
void placeDanger(char map[][5], char arr[])
Parameters: 2d Array and a 1d Array
Return type: Void
Purpose: To generate random locations for the enemies and place them on the map.
*/
void placeDanger(char map[][5], char arr[])
{
	// Declare and/or Initialize Necessary Local Variables
	int enemyRow, enemyCol;

	// Add the 4 enemies to random coordinates on the grid
	for (int i = 0, j = 0; i < 10; i++)
	{
		enemyRow = rand() % 5;
		enemyCol = rand() % 5;

		if ((enemyRow == 0 && enemyCol == 0) || (enemyRow == 4 && enemyCol == 4))
		{
			enemyRow = rand() % 5;
			enemyCol = rand() % 5;
			map[enemyRow][enemyCol] = arr[j];
			j++;
		}
		else
		{
			map[enemyRow][enemyCol] = arr[j];
			j++;
		}
		if (j == 4)
		{
			j = 0;
		}
	}
}
/*
bool movement(char grid[][5], char map[][5], int& gongs, int& rangerRow, int& rangerCol);
Parameters: Two 2d Arrray and 5 integers
Return type: Bool
Purpose: To move the player along the grid based on their input and determine remaining time.
*/
bool movement(char grid[][5], char map[][5], int& gongs, int& rangerRow, int& rangerCol, int& rowN, int& colN)
{
	showMap(grid);
	cout << "\nGongs Left: " << gongs << endl;

	// Prompt player for their desired cell
	cout << "\nEnter the coordinates of the cell you want to move to (row & col): ";
	cin >> rowN >> colN;

	// Validate their input
	if ((rowN < 0 || rowN >= 5 || colN < 0 || colN >= 5))
	{
		cout << "\nError: Invalid cell ... Please enter a valid cell to move to.\n" << endl;
		return false;
	}
	// If the new input leads to the tourists make current/previous spot blank and return true for final check
	else if (map[rowN][colN] == 'T')
	{
		map[rangerRow][rangerCol] = ' ';   // Leaves the previous position blank
		grid[rangerRow][rangerCol] = ' '; // Leaves the previous position blank
		rangerRow = rowN;
		rangerCol = colN;
		return true;
	}
	// If new input leads to a taken spot, return false to check for conflict
	else if (map[rowN][colN] != '*')
	{
		return false;
	}
	// If new input leads to vacant spot, the player may go there in peace
	else if (map[rowN][colN] == '*')
	{
		// Inform the player that their input is valid
		cout << "\n---> Cell (" << rowN << ", " << colN << ") is free, you may advance.\n" << endl;

		// Update the maps accordingly
		map[rangerRow][rangerCol] = ' ';   // Leaves the previous position blank
		grid[rangerRow][rangerCol] = ' '; // Leaves the previous position blank
		rangerRow = rowN;
		rangerCol = colN;
		map[rangerRow][rangerCol] = 'R';   // Assigns new coordinates 'R'
		grid[rangerRow][rangerCol] = 'R'; // Assigns new coordinates 'R'

		// Update the time, showcasing the remaining gongs of time
		--gongs;
		return true;
	}
}
/*
void conflict(const string ARRAY[], char arr[], char map[][5], char grid[][5], int& rangerRow, int& rangerCol, int rowN, int colN, int& gongs)
Parameters: 3 arrays, and 5 integers
Return type: Void
Purpose: To determine whether or not the player should have an encounter with the threats lurking in the everglades, and the outcome of it.
*/
void conflict(const string ARRAY[], char arr[], char map[][5], char grid[][5], int& rangerRow, int& rangerCol, int rowN, int colN, int& gongs)
{
	// Local Variables
	int choice;

	// Use loop to check which enemy it is
	for (int i = 0; i < 4; i++)
	{
		if (map[rowN][colN] == arr[i])
		{
			cout << "\n---> Watch out! There is a " << ARRAY[i] << " ahead." << endl;
			cout << "\nChoose your next move:" << endl
				<< "\n\t1. Hide and Wait until it leaves." << endl
				<< "\n\t2. Fight it." << endl
				<< "\nEnter your choice: ";
			cin >> choice;

			// Option Selected: Hide & Wait
			if (choice == 1)
			{
				cout << "\nThe " << ARRAY[i] << " is gone ... You may advance.\n" << endl;
				gongs -= 5;
				map[rangerRow][rangerCol] = ' ';
				grid[rangerRow][rangerCol] = ' ';
				map[rowN][colN] = 'R';
				grid[rowN][colN] = 'R';

			}
			// Option Selected: Fight
			else if (choice == 2)
			{
				// Win
				if (rand() % 2 == 0)
				{
					cout << "\nYou fought the " << ARRAY[i] << " and won .. You may advance.\n" << endl;
					gongs -= 2;
					map[rangerRow][rangerCol] = ' ';
					grid[rangerRow][rangerCol] = ' ';
					map[rowN][colN] = 'R';
					grid[rowN][colN] = 'R';
				}
				// Lose
				else
				{
					cout << "\nYou fought the " << ARRAY[i] << " and lost ... Retreat.\n" << endl;
					gongs -= 3;

					// Clear the current cell
					map[rangerRow][rangerCol] = ' ';
					grid[rangerRow][rangerCol] = ' ';

					// Move the player back to the initial cell due to loss
					rangerRow = 0; rangerCol = 0;
					map[rangerRow][rangerCol] = 'R';
					grid[rangerRow][rangerCol] = 'R';
				}
			}
		}
	}
}
/*
bool isGameOver(int rangerRow, int rangerCol, int touristRow, int touristCol, int gongs) {
Parameters: 5 integers
Return type: bool
Purpose: To determine whether the player has won the game or ran out of time.
*/
bool isGameOver(int rangerRow, int rangerCol, int touristRow, int touristCol, int gongs) {
	if (gongs <= 0) {
		cout << "\n\t!!GAME OVER . . . YOU ARE OUT OF TIME!!\nTHE TOURISTS HAVE BEEN CLAIMED BY THE EVERGLADES, NEVER TO RETURN.\n" << endl;
		return true;
	}
	else if (rangerRow == touristRow && rangerCol == touristCol) {
		cout << "\nCongratulations! You have rescued the tourists!" << endl;
		return true;
	}
	else {
		return false;
	}
}



int main()
{
	// Declare seed for random generator
	srand(time(0));

	// Declare and Initialize any necessary variables\constants for future use
	const string dangerName[]{"Hungry Alligator", "Swarm of Giant Mosquitos", "Venomous Spider", "Python"};
	const int MAX_DANGERS = 10;
	char dangerFill[]{'A', 'M', 'S', 'P'}, map[5][5], grid[5][5];
	int menuchoice, gongs = 12, rangerRow = 0, rangerCol = 0, touristRow = 4, touristCol = 4, rowN = 0, colN = 0;

	// Display the name of the program and then display the menu
	cout << "\nLost in the Everglades ..." << endl;
	cout << "\nGreetings traveler..." << endl;

	// Initiate a do-while loop to run at least once
	do
	{
		menuchoice = menu();

		switch (menuchoice) {
		// Option Selected: Display the game's rules
		case 1:
			rules();
			break;
		
		// Option Selected: Play game
		case 2:
			// Create the map, initializing it with the player, tourists, and dangers
			createMap(map, grid);
			placeDanger(map, dangerFill);

			while (!isGameOver(rangerRow, rangerCol, touristRow, touristCol, gongs))
			{
				if (movement(grid, map, gongs, rangerRow, rangerCol, rowN, colN))
				{
					// If the player has successfully moved check if they have won
					if (map[rangerRow][rangerCol] == 'T')
					{
						cout << "\nCongratulations!! You rescued the tourists!" << endl;
						rangerRow = 0, rangerCol = 0, touristRow = 4, touristCol = 4;
						break;
					}
				}
				// If not check for conflict
				else 
				{
					conflict(dangerName, dangerFill, map, grid, rangerRow, rangerCol, rowN, colN, gongs);
				}
			}
			break;
		}
	} while (menuchoice != 3);

	// Output message in the event: 'Option Selected: Quit game'
	cout << "\nQuitting the game . . . Thank you for playing!" << endl;
	return 0;
}