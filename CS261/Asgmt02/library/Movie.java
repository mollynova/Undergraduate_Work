package library;
import java.util.ArrayList;
import java.util.Collections;

class Movie
	extends Item
{
	private int numScenes;
	private String director;
	private ArrayList<String> cast = new ArrayList<>();
	
	public Movie(String title, String director, int nScenes, String[] keywords){
		super(title, keywords);
		this.numScenes = nScenes;
		this.director = director;
	}
	
	public int getNumScenes(){
		return numScenes;
	}
	
	public String getDirector(){
		return director;
	}
	
	public ArrayList<String> getCast(){
		return cast;
	}
	
	public void setMembers(String[] thisCast){
		for(int i = 0; i < thisCast.length; i++){
			cast.add(thisCast[i]);
		}
		Collections.sort(cast);
	}
	
	public String toString(){
		// Make printable string of keywords
		ArrayList<String> tmpKeywords = this.getKeywords();
		
		String tmpKeys = "";
		for(String string: tmpKeywords){
			tmpKeys += string;
			tmpKeys += ", ";
		}
		
		int keysLength = tmpKeys.length();
		String finalKeys = tmpKeys.substring(0, (keysLength - 2));
		
		// Make printable string of cast
		String tmpCast = "";
		for(String string: cast){
			tmpCast += string;
			tmpCast += ", ";
		}
		
		int castLength = tmpCast.length();
		String finalCast = tmpCast.substring(0,  (castLength - 2));
		
		// Concatenate printable version of Movie
		String print = "-Movie-\ndirector: " + this.getDirector() +
					   "\n# scenes: " + this.getNumScenes() + "\ncast: " +
					   finalCast + "\ntitle: " + this.getTitle() + 
					   "\nkeywords: " + finalKeys + "\n";
		
		return print;
	}
}
