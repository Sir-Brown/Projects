/*
D'Jaine Brown
July 03,2024
Program Description: This program will act as a tutor for the user, giving them information pertaining to certain Java related topics.
*/

// Import necessary libraries.
import java.io.File;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.InputMismatchException;


public class projectTutor {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Create scanner object
		Scanner scanner = new Scanner(System.in);
		
		// Declare and/or Initialize any variables/constants as required
		int mainMenuChoice = 0;
		String choice = "Yes", filename;
		
		// Prompt user for login using login method
		login(scanner);
		
		// Make user tracking file
		filename = makeFile();
		
		// Use loop to keep the following running
		while (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y")) {
			
			// Display menu
			mainMenuChoice = mainMenu(scanner);

			// Validate the mainMenu method and respond accordingly.
			switch (mainMenuChoice) {
				case 1:
					subTopicMenu(scanner);
					break;
				case 2:
					displayUserLog(filename);
					break;
				case 3:
					System.out.println("\nYou will be logged out. Goodbye.");
					scanner.close();
					return;
				default:
					System.out.println("\nPlease enter a number from the menu.");
			}
			System.out.print("\nDo you want to try again? ");
			choice = scanner.nextLine();	
		}
		// Close the scanner.
		scanner.close();
	}

	// Create the login method to handle the verification of user credentials
	private static boolean login(Scanner scanner) {
		/*
		 * Program Description: This method will act as a login wall prompting the user to login and validating their input.
		 * @param scanner
		 * @return true or false
		*/
		
		//Declare and/or Initialize any variables/constants as required
		String username, password;
		
		// Display program 'header'
		System.out.println("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		System.out.println("\n* *			PROGRAM TUTOR				* *");
		System.out.println("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		
		while (true) {
			// Prompt user for credentials
			System.out.print("Enter username (\"user\"): ");
	        username = scanner.nextLine();
	        System.out.print("Enter password (\"password\"): ");
	        password = scanner.nextLine();
			
	        // Validate
	        if (username.equals("user") && password.equals("password")) {
	        	return true;
	        }
	        else {
	        	System.out.println("\nUsername or Password is incorrect. Try again.\n");
	        }
		}
	}
	
	// Create method to handle the main menu
	public static int mainMenu(Scanner scanner) {
		/*
		 * Program Description: This method will display the main menu for the user to choose from, and change output based on their choice.
		 * @param scanner
		 * @return choice
		*/
				
		//Declare and/or Initialize any variables/constants as required
		int choice = -1;
		boolean validInput = false;
				
		while (!validInput) {
			try {
				// Display sub-topic menu
				System.out.println("\n**********************************************************");
				System.out.println("\n**		1. Topics				**");
				System.out.println("\n**		2. User Learning Track			**");
				System.out.println("\n**		3. Quit					**");
				System.out.println("\n**********************************************************");
				
				System.out.print("\nPlease select an option (use numbers): ");
				choice = scanner.nextInt();
				
				// Clear buffer
				scanner.nextLine();
				
				validInput = true;
			}
			catch (InputMismatchException e) {
				System.out.println("Invalid input. Please enter a number.");
				
				// Clear invalid input
				scanner.next();
			}
		}
		return choice;
	}

	// Create method to handle the sub-topic menu
	public static void subTopicMenu(Scanner scanner) {
		/*
		 * Program Description: This method will display a sub-topic menu for the user to choose from, and change output based on their choice.
		 * @param scanner
		*/
				
		//Declare and/or Initialize any variables/constants as required
		int choice;
				
		// Display sub-topic menu
		System.out.println("\n******************************************************************");
		System.out.println("\n**		1. How to define variables?			**");
		System.out.println("\n**		2. What are data types?				**");
		System.out.println("\n**		3. If - else statements				**");
		System.out.println("\n**		4. Loops					**");
		System.out.println("\n**		5. Arrays					**");
		System.out.println("\n******************************************************************");
		
		System.out.print("\nPlease select an option (use numbers): ");
		choice = scanner.nextInt();
		
		// Clear buffer
		scanner.nextLine();
					
		subTopicOptions(choice);
	}

	public static void subTopicOptions(int x) {
		/*
		 * Program Description: This method will validate the subTopicMenu result and display the appropriate response.
		 * @param choice (user input).
		*/
		
		// Perform the operation and display the result using either a conditional or switch.
		// Write to the file "UserProgress.txt" throwing an exception as well.
		switch (x) {
			case 1:
				System.out.println("\nYou picked option one (1).");
				System.out.println("\nQ: How does one define variables in Java?");
				System.out.println("\nA: To create a variable, you must specify the type and assign it a value:\n   Syntax: type variableName = value;");
				
	            try (BufferedWriter log = new BufferedWriter(new FileWriter("UserProgress.txt", true))) {
	                log.write("User has viewed: How to define variables?\n");
	            }
	            catch (IOException e) {
	                System.err.println("Error writing to file: " + e.getMessage());
	            }
				break;
				
			case 2:
				System.out.println("\nYou picked option two (2).");
				System.out.println("\nQ: What are data types in Java?");
				System.out.println("\nA: In Java, data types define the type of data a variable can hold. They are categorized into two main types:"
						+ "\n   Primitive Data Type: such as boolean, char, int, short, byte, long, float, and double.\n   Non-Primitive Data Type or Object Data type: such as String, Array, etc.");
				
	            try (BufferedWriter log = new BufferedWriter(new FileWriter("UserProgress.txt", true))) {
	                log.write("User has viewed: What are data types?\n");
	            }
	            catch (IOException e) {
	                System.err.println("Error writing to file: " + e.getMessage());
	            } 
				break;
				
			case 3:
				System.out.println("\nYou picked option three (3).");
				System.out.println("\nQ: What is the significance of if-else statements in Java?");
				
				System.out.println("\nA: The if, else if, and else statements are used to specify a line/block of Java code to be executed if a condition is true or false (else). This is used for many reasons such as validation.\n   Example:"
						+ "\n   If (20 > 18) {\n"
						+ "   	System.out.println(\"20 is greater than 18\");\n"
						+ "   }");
				
				try (BufferedWriter log = new BufferedWriter(new FileWriter("UserProgress.txt", true))) {
	                log.write("User has viewed: If - else statements\n");
	            }
	            catch (IOException e) {
	                System.err.println("Error writing to file: " + e.getMessage());
	            }
				break;
				
			case 4:
				System.out.println("\nYou picked option four (4).");
				System.out.println("\nQ: What are the types of loops in Java?");
				
				System.out.println("\nA: Like other programming Languages, Java employs three main types of loops:"
						+ "\n   For Loop:"
						+ "\n	A pre-test loop, used when you know the exact number of iterations required."
						+ "\n	Syntax: for (initialization; condition; inc/dec) {code}"
						
						+ "\n   While Loop:"
						+ "\n	A pre-test loop, used when the number of iterations is not known in advance and depends on a condition."
						+ "\n	Syntax: while (condition) {code}"
						
						+ "\n   Do-While Loop:"
						+ "\n	A post-test loop, similar to a while loop, but the body is executed at least once."
						+ "\n	Syntax: do {code} while (condition);");
				
				try (BufferedWriter log = new BufferedWriter(new FileWriter("UserProgress.txt", true))) {
	                log.write("User has viewed: Loops\n");
	            }
	            catch (IOException e) {
	                System.err.println("Error writing to file: " + e.getMessage());
	            }
				break;
				
			case 5:
				System.out.println("\nYou picked option five (5).");
				System.out.println("\nQ: What is one difference between arrays and lists in Java?");
				
				System.out.println("\nA: An ARRAY is a data structure built into the Java language which can hold a number of elements, all of the same type."
						+ "\n   It cannot be resized once it has been created, and you cannot add elements to it without specifying an index."
						+ "\n   On the other hand, a LIST is a class that is part of the Java Standard Library which allows for dynamic insertion and deletion of elements.");
				
				try (BufferedWriter log = new BufferedWriter(new FileWriter("UserProgress.txt", true))) {
	                log.write("User has viewed: Arrays\n");
	            }
	            catch (IOException e) {
	                System.err.println("Error writing to file: " + e.getMessage());
	            }
				break;
				
			default:
				System.out.println("\nPlease select a number from the menu.");
				break;
		}
	}
	
	public static String makeFile() {
		/*
		 * Program Description: This method will create a file, if one has not already been created.
		 * @return filename.
		*/
		
		//Declare and/or Initialize any variables/constants as required
		String filename = "UserProgress.txt";
		
		// Create a file
		File file = new File(filename);
		
		try {
            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (IOException e) {
            System.err.println("Error creating file: " + e.getMessage());
        }
		
		//Return the file name
		return filename;
	}

	public static void displayUserLog(String filename) {
		//Declare and/or Initialize any variables/constants as required
		String userProgress;
		
		// Display the user's progress
		try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
			System.out.print("\n");
            while ((userProgress = reader.readLine()) != null) {
            	System.out.println(userProgress);
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
	}
}
