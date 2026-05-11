/*D'Jaine Brown
June 5,2024
Program Description: This program will read user input, convert it to Roman numerals and display it.
*/

//Import the Scanner library (java.util)
import java.util.Scanner;

public class RomanNumeral_Converter {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Create a scanner object - to read user input.
		Scanner readerObj = new Scanner(System.in);
				
		// Declare necessary variables/constants
		final String one = "I", two = "II", three = "III", four = "IV", five = "V", six = "VI", seven = "VII", eight = "VIII", nine = "IX", ten = "X"; 	
		int number;
		
		// Prompt user for number.
		System.out.print("Enter a number in the range of 1 - 10: ");
		number = readerObj.nextInt();
		
		// Convert based on number using conditional statement or a switch.
		switch (number) {
			case 1:
				System.out.println(one);
				break;
			case 2:
				System.out.println(two);
				break;
			case 3:
				System.out.println(three);
				break;
			case 4:
				System.out.println(four);
				break;
			case 5:
				System.out.println(five);
				break;
			case 6:
				System.out.println(six);
				break;
			case 7:
				System.out.println(seven);
				break;
			case 8:
				System.out.println(eight);
				break;
			case 9:
				System.out.println(nine);
				break;
			case 10:
				System.out.println(ten);
				break;
			default:
				System.out.print("\nInvalid number");
				break;
		}
		
	}
}
