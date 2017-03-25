// Each book, music album, or movie will be an instance of a subclass of this class.
// Instances of this class should not be created. Specifying it as 'abstract' ensures
// that they cannot.

package library;
import java.util.ArrayList;
import java.util.Collections;
import java.util.*;

public abstract class Item
{
	private String title;
	private ArrayList<String> keyWords = new ArrayList<>();
	
	public Item(String title, String[] keywords){
		this.title = title;
		
		for(int i = 0; i < keywords.length; i++){
			keyWords.add(keywords[i]);
		}
		Collections.sort(keyWords);
	}
	
	public String getTitle(){
		return title;
	}
	
	public ArrayList<String> getKeywords(){
		return keyWords;
	}

}
