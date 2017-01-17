import java.util.Scanner;

public class Main
{

	public static void main(String[] args){
		
		menu();
		
	}

	public static void menu(){
		Functions functions = new Functions();
		Scanner sc = new Scanner(System.in);
		int scNum = 1;
		int val1 = 0;
		int val2 = 0;

		while(scNum != 0){		

			System.out.println("\nWelcome to Functionator. Please select an option from the menu.\n");
			System.out.println("0 - Quit\n1 - Find Average\n2 - Find GCD\n3 - Find LCM\n4 - Find Factorial\n");
			scNum = sc.nextInt();
			
			switch(scNum){
				case 1: System.out.println("Please enter the two numbers you wish to see averaged: ");
					val1 = sc.nextInt();
					val2 = sc.nextInt();	
					functions.doAverage(val1, val2);
					break; 
				case 2: System.out.println("Please enter the two numbers for which you wish to see the GCD: ");
					val1 = sc.nextInt();
					val2 = sc.nextInt();
					functions.doGCD(val1, val2);
					break;
				case 3: System.out.println("Please enter the two numbers for which you wish to see the LCM: ");	
					val1 = sc.nextInt();
					val2 = sc.nextInt();
					functions.doLCM(val1, val2);
					break;
				case 4: System.out.println("Please enter the number for which you wish to see the factorial: ");	
					val1 = sc.nextInt();
					functions.doFactorial(val1);
					break;
			}
			

		}
		System.out.println("\nThank you... goodbye.");
		System.exit(0);
		}
	
}
