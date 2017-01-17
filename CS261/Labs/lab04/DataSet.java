
import java.util.Scanner;
import java.util.*;

public class DataSet
{
	// Declare variables
	private int numValues;    // number of values
	private int numStars;     // number of stars for each value
	private ArrayList<Integer> valueArray;     // array to hold all entries of numStars

	// Constructor
	public DataSet()
	{
		numValues = 0;
		numStars = 0;
		valueArray = new ArrayList<>();
	}

	public ArrayList<Integer> getData(){
		
		System.out.println("\n");
		Scanner reader = new Scanner(System.in);
		System.out.println("How many values will you enter: ");
		numValues = reader.nextInt();
		while(numValues < 1 || numValues > 20){	
			System.out.println("Invalid value. Try again. (1 - 20)");
			System.out.println("How many values will you enter: ");
			numValues = reader.nextInt(); 
		}
		
		
		for(int i = 0; i < numValues; i++){
			System.out.println("Enter a number between 0 and 10 (inclusive): ");
			numStars = reader.nextInt();
			
			if(numStars < 0 || numStars > 10){
				System.out.println("Invalid value. Try again.");
				System.out.println("Enter a number between 0 and 10 (inclusive): ");
				numStars = reader.nextInt();
			} 
			valueArray.add(i, numStars);

		}
	return valueArray;

	}
}

