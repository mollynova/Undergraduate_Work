import java.util.Scanner;
import java.math.*;

public class Lab03 {

	public static void main (String[] args) {
		// get 3 pieces of info from user
		// starting balance, interest rate, no. of years
		System.out.print("\n");
		Scanner reader = new Scanner(System.in);
		System.out.print("Enter starting balance: ");
		int inStartBalance = reader.nextInt();
		System.out.print("Enter interest rate: ");
		int inInterestRate = reader.nextInt();
		System.out.print("Enter number of years: ");
		int years = reader.nextInt();
		System.out.print("\n");

		// convert starting balance and interest rate to type double
		double startBalance = inStartBalance;
		double interestRate = inInterestRate;
		double currentBalance = startBalance;

		// for loop based on years
		for(Integer i = 0; i < years; i++){
			currentBalance = getBalance(currentBalance, interestRate, i);
		}
		
		System.out.println("\n");
	}
	
	public static double getBalance(double bal, double rate, int i){
		// calculate new balance and rate
		double balance = bal;
		double intRate = rate;
		
		balance = balance * (1+(intRate/100));
		print(balance, i);
		return balance;
	}

	public static void print(double balance, int i){
		// print the balance
		double truncDouble = new BigDecimal(balance)
			.setScale(16, BigDecimal.ROUND_HALF_UP)
			.doubleValue();

	
		System.out.println("Year " + (i+1) + " $" + truncDouble);
	}
}

