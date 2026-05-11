//D'Jaine Brown
//May 29,2024
//Program Description: This program is to calculate the gains/losses of a company given the shares initial cost and current price.

//Import the Scanner library (java.util)
import java.util.Scanner;
public class Gain_Loss {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//Create a scanner object - to read user input.
		Scanner readerObj = new Scanner(System.in);
		
		//Declare constants and/or variables
		int shares;
		double share_Cost,share_Price,total_Cost,total_Price,com_Pay,gain_Loss;
		
		//Prompt for company name:
		System.out.print("Please enter the name of your company: ");
		String company_Name = readerObj.nextLine();
		
		//Prompt for number of Shares transacted:
		System.out.print("\nPlease enter the number of Shares transacted this business year: ");
		shares = readerObj.nextInt();
		
		//Prompt for their cost:
		System.out.print("\nPlease enter the cost per share [at the time of buying]: ");
		share_Cost = readerObj.nextDouble();
		
		//Prompt for market value:
		System.out.print("\nPlease their current market value [per share]: ");
		share_Price = readerObj.nextDouble();
		
		
		//Calculate the total cost:
		total_Cost = (shares * share_Cost);
		
		//Calculate the total proceeds:
		total_Price = (shares * share_Price);
		
		//Calculate the commission paid:
		com_Pay = (total_Cost * 0.02) + (total_Price * 0.02);
		
		//Calculate the gain/loss generated [amount & %]:
		gain_Loss = total_Price - total_Cost;
		
		
		System.out.println("\nCompany Name:		" + company_Name);
		System.out.println("Number of Shares:	" + shares);
		System.out.println("Cost per Share:		" + share_Cost);
		System.out.println("Price sold per share:	" + share_Price);
		
		System.out.println("\nTotal Cost:		" + total_Cost);
		System.out.println("Total Proceeds:		" + total_Price);
		System.out.println("Comission Paid:		" + com_Pay);
		System.out.println("Gain or Loss accrued:	" + gain_Loss);
	}

}
