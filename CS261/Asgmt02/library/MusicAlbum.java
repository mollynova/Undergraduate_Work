package library;
import java.util.ArrayList;
import java.util.Collections;

class MusicAlbum
	extends Item
{
	private int numSongs;
	private String band;
	private ArrayList<String> bandMembers = new ArrayList<>(); 
	
	public MusicAlbum(String title, String band, int nSongs, String[] keywords){
		super(title, keywords);
		this.numSongs = nSongs;
		this.band = band;
	}
	
	public int getNumSongs(){
		return numSongs;
	}
	
	public String getBand(){
		return band;
	}
	
	public ArrayList<String> getMembers(){
		return bandMembers;
	}
	
	public void setMembers(String[] members){
		for(int i = 0; i < members.length; i++){
			bandMembers.add(members[i]);
		}
		Collections.sort(bandMembers);
	}
	
	public String toString(){
		ArrayList<String> tmpKeywords = this.getKeywords();
		
		// Make printable string of keywords
		String tmpKeys = "";
		for(String string: tmpKeywords){
			tmpKeys += string;
			tmpKeys += ", ";
		}
		
		int keyLength = tmpKeys.length();
		String finalKeys = tmpKeys.substring(0,  (keyLength - 2));
		
		// Make printable string of members
		String tmpMembers = "";
		for(String string: bandMembers){
			tmpMembers += string;
			tmpMembers += ", ";
		}
		
		int membersLength = tmpMembers.length();
		String finalMembers = tmpMembers.substring(0,  (membersLength - 2));
		
		// Concatenate printable version of Music Album
		String print = "-Music Album-\nband: " + this.getBand() + "\n# songs: " +
		this.getNumSongs() + "\nmembers: " + finalMembers + "\ntitle: " + 
		this.getTitle() + "\nkeywords: " + finalKeys + "\n";
		
		return print;
	}
}
