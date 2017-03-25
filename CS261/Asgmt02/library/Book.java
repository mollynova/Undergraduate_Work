package library;
import java.util.ArrayList;

class Book
	extends Item
{
	private int pageCount;
	private String author;
	
	public Book(String title, String author, int pageCount, String[] keywords){
		super(title, keywords);
		this.pageCount = pageCount;
		this.author = author;
	}
	
	public int getPageCount(){
		return pageCount;
	}
	
	public String getAuthor(){
		return author;
	}
	
	public String toString(){
		ArrayList<String> tmpKeywords = this.getKeywords();
		
		String print = "-Book-\nauthor: " + this.author + "\n# pages : " 
				+ this.pageCount + "\ntitle: " + this.getTitle() + "\nkeywords: ";
		
		for(String string: tmpKeywords){
			print += string;
			print += ", ";
		}
		
		int length = print.length();
		String newPrint = print.substring(0, (length - 2));
		newPrint += "\n";
		return newPrint;
				
	}
}
