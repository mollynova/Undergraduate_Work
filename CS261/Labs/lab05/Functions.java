public class Functions
{

	public void doAverage(int val1, int val2){
		int sum = val1 + val2;
		int average = sum/2;
		System.out.println("The average of " + val1 + " and " + val2 + " is " + average + "\n");		
	}

	public void doGCD(int val1, int val2){
		int GCD = calculateGCD(val1, val2);
		System.out.println("The GCD of " + val1 + " and " + val2 + " is " + GCD + "\n");
	}

	public void doLCM(int val1, int val2){
		int one = val1;
		int two = val2;
		int product = one * two;
		int GCD = calculateGCD(one, two);
		int LCM = product / GCD;
		System.out.println("The LCM of " + val1 + " and " + val2 + " is " + LCM + "\n");
		
	}	

	public void doFactorial(int val1){
		int num = val1;
		int total = 1;
		for(int i = 1; i <= num; i++){
			total *= i;
		}
		System.out.println("The factorial of " + val1 + " is " + total + "\n");

	}

	private int calculateGCD(int val1, int val2){
		int one = val1;
		int two = val2;
		
		while(one != two && one >= 0 && two >= 0){
			if(one > two){
				int holder = one - two;
				one = holder;
			} else {
				int hold = two - one;
				two = hold;
		}
		
		}return one;
	}
}
