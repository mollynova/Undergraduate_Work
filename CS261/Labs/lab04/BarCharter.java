import java.util.ArrayList;

public class BarCharter
{
	private DataSet data;

	// Constructor
	public BarCharter()
	{
		data = new DataSet();
	}

	public void printChart()
	{
		ArrayList<Integer> newList = new ArrayList<Integer>(data.getData());
		int length = newList.size();
		int star = 1;
		int space = 0;
	
		int thisChart[][] = new int[10][length];
		for(int j = 0; j < length; j++){
			int numStars = newList.get(j);
			int numBlanks = 10 - (newList.get(j));
			System.out.println("For num " + j + " we have " + numStars + " stars and " + numBlanks + " blanks.");

			for(int k = 0; k < numBlanks; k++){
				thisChart[k][j] = space;
			}
			for(int l = 0; l < numStars; l++){
				thisChart[10 - numStars + l][j] = star;
			}
		}

		for(int m = 0; m < 10; m++){
			for(int n = 0; n < length; n++){
				if(thisChart[m][n] == 0){
					System.out.print(" ");
				} else {
					System.out.print("*");
				}
			}
			System.out.println();
		}

	}
}



