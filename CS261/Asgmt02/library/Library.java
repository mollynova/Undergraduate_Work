package library;
import java.util.ArrayList;

import java.io.PrintStream;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class Library
{
	// general methods
	private ArrayList<Item> items;
	
	//constructor
	public Library(){
		this.items = new ArrayList<>();
	}
	
	// returns all of the items which have the specified keyword
	public ArrayList<Item> itemsForKeyword(String keyword)
	{
		ArrayList<String> stringByKeyword = new ArrayList<>();
		ArrayList<Item> itemByKeyword = new ArrayList<>();
		
		for(Item item: items){
			if(item.getKeywords().contains(keyword)){
				stringByKeyword.add(item.getTitle());
			}
		}
		Collections.sort(stringByKeyword);
		
		for(String thisTitle: stringByKeyword){
			for(Item thisItem: items){
				if((thisItem).getTitle().equals(thisTitle)){
					itemByKeyword.add(thisItem);
				}
				
			}
		}
		return itemByKeyword;
	}
	
	// print an item from this library to the output stream provided
	public void printItem(PrintStream out, Item item)
	{
		if(item instanceof Book){
			out.println((Book) item);
		}
		else if(item instanceof Movie){
			out.println((Movie) item);
		} else {
			out.println((MusicAlbum) item);
		}
	}
	
	// book-related methods
	
	// adds a book to the library
	// NOTE: THIS METHOD ORIGINALLY WAS TYPE ITEM, NOT TYPE VOID. (NOW IVE CHANGED IT BACK)
	public Item addBook(String title, String author, int nPages, String... keywords)
	{
		Item newItem = new Book(title, author, nPages, keywords);
		items.add(newItem);
		return newItem;
	}
	
	// removes a book from the library
	public boolean removeBook(String title)
	{
		for(Item item: items){
			if(item instanceof Book){
				if(((Book) item).getTitle().equals(title)){
					items.remove(item);
					return true;
				}
			}
		}
		return false;
	}
	
	// returns all of the books by the specified author
	public ArrayList<Item> booksByAuthor(String author)
	{
		ArrayList<String> stringTitlesByAuthor = new ArrayList<>();
		ArrayList<Item> itemTitlesByAuthor = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof Book){
				if(((Book) item).getAuthor().equals(author)){
					stringTitlesByAuthor.add(item.getTitle());
				}
			}
		}
		
		Collections.sort(stringTitlesByAuthor);
		for(String thisTitle: stringTitlesByAuthor){
			for(Item thisItem: items){
				if(thisItem instanceof Book){
					if(((Book) thisItem).getTitle().equals(thisTitle)){
						itemTitlesByAuthor.add(thisItem);
					}
				}
			}
		}
		return itemTitlesByAuthor;
	}
	
	// returns all of the books in the library
	public ArrayList<Item> books()
	{
		ArrayList<String> stringBooks = new ArrayList<>();
		ArrayList<Item> itemBooks = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof Book){
				stringBooks.add(item.getTitle());
			}
		}
		Collections.sort(stringBooks);
		
		for(String thisTitle: stringBooks){
			for(Item thisItem: items){
				if(thisItem instanceof Book){
					if(((Book) thisItem).getTitle().equals(thisTitle)){
						itemBooks.add(thisItem);
					}
				}
			}
		}
		return itemBooks;
	}
	
	// music-related methods
	
	// adds a music album to the library
	public Item addMusicAlbum(String title, String band, int nSongs, String... keywords)
	{
		Item newItem = new MusicAlbum(title, band, nSongs, keywords);
		items.add(newItem);
		return newItem;
	}

	// adds the specified band members to a music album
	public void addBandMembers(Item album, String... members)
	{
		((MusicAlbum) album).setMembers(members);
	}
	
	// removes a music album from the library
	public boolean removeMusicAlbum(String title)
	{
		for(Item item: items){
			if(item instanceof MusicAlbum){
				if(item.getTitle().equals(title)){
					items.remove(item);
					return true;
				}
			}
		}
		return false;
	}

	// returns all of the music albums by the specified band
	public ArrayList<Item> musicByBand(String band)
	{
		ArrayList<String> stringAllAlbumsByBand = new ArrayList<>();
		ArrayList<Item> itemAllAlbumsByBand = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof MusicAlbum){
				if(((MusicAlbum) item).getBand().equals(band)){
					stringAllAlbumsByBand.add(item.getTitle());
				}
			}
		}
		
		Collections.sort(stringAllAlbumsByBand);
		for(String thisTitle: stringAllAlbumsByBand){
			for(Item thisItem: items){
				if(thisItem instanceof MusicAlbum){
					if(((MusicAlbum) thisItem).getTitle().equals(thisTitle)){
						itemAllAlbumsByBand.add(thisItem);
					}
				}
			}
		}
		return itemAllAlbumsByBand;
	}
	
	// returns all of the music albums by the specified musician
	public ArrayList<Item> musicByMusician(String musician)
	{
		ArrayList<String> stringAllAlbumsByArtist = new ArrayList<>();
		ArrayList<Item> itemAllAlbumsByArtist = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof MusicAlbum){
				ArrayList<String> tmpMembers = ((MusicAlbum) item).getMembers();
				if(tmpMembers.contains(musician)){
					stringAllAlbumsByArtist.add(item.getTitle());
				}			
			}
		}
		Collections.sort(stringAllAlbumsByArtist);

		for(String thisTitle: stringAllAlbumsByArtist){
			for(Item thisItem: items){
				if(thisItem instanceof MusicAlbum){
					if(((MusicAlbum) thisItem).getTitle().equals(thisTitle)){
						itemAllAlbumsByArtist.add(thisItem);
					}
				}
			}
		}
		return itemAllAlbumsByArtist;
	}
	
	// returns all of the music albums in the library
	public ArrayList<Item> musicAlbums()
	{
		ArrayList<String> stringAlbums = new ArrayList<>();
		ArrayList<Item> itemAlbums = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof MusicAlbum){
				stringAlbums.add(item.getTitle());
			}
		}
		
		Collections.sort(stringAlbums);
		
		for(String thisTitle: stringAlbums){
			for(Item thisItem: items){
				if(thisItem instanceof MusicAlbum){
					if(((MusicAlbum) thisItem).getTitle().equals(thisTitle)){
						itemAlbums.add(thisItem);
					}
				}
			}
		}
		return itemAlbums;

	}
	
	// movie-related methods
	
	// adds a movie to the library
	public Item addMovie(String title, String director, int nScenes, String... keywords)
	{
		Item newItem = new Movie(title, director, nScenes, keywords);
		items.add(newItem);
		return newItem;
	}

	// adds the specified actors to a movie
	public void addCast(Item movie, String... members)
	{
		((Movie) movie).setMembers(members);
	}

	// removes a movie from the library
	public boolean removeMovie(String title)
	{
		for(Item item: items){
			if(item instanceof Movie){
				if(item.getTitle().equals(title)){
					items.remove(item);
					return true;
				}
			}
		}
		return false;
	}
	
	// returns all of the movies by the specified director
	public ArrayList<Item> moviesByDirector(String director)
	{
		ArrayList<String> stringMoviesByDirector = new ArrayList<>();
		ArrayList<Item> itemMoviesByDirector = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof Movie){
				if(((Movie) item).getDirector().equals(director)){
					stringMoviesByDirector.add(item.getTitle());
				}
			}
		}
		Collections.sort(stringMoviesByDirector);

		for(String thisTitle: stringMoviesByDirector){
			for(Item thisItem: items){
				if(thisItem instanceof Movie){
					if(((Movie) thisItem).getTitle().equals(thisTitle)){
						itemMoviesByDirector.add(thisItem);
					}
				}
			}
		}
		return itemMoviesByDirector;
	}
	
	// returns all of the movies by the specified actor
	public ArrayList<Item> moviesByActor(String actor)
	{
		ArrayList<String> stringMoviesByActor = new ArrayList<>();
		ArrayList<Item> itemMoviesByActor = new ArrayList<>();
		
		for(Item item: items){
			if(item instanceof Movie){
				ArrayList<String> tmpActors = ((Movie) item).getCast();
				if(tmpActors.contains(actor)){
					stringMoviesByActor.add(item.getTitle());
				}
			}
		}
		Collections.sort(stringMoviesByActor);

		for(String thisTitle: stringMoviesByActor){
			for(Item thisItem: items){
				if(thisItem instanceof Movie){
					if(((Movie) thisItem).getTitle().equals(thisTitle)){
						itemMoviesByActor.add(thisItem);
					}
				}
			}
		}
		return itemMoviesByActor;
	}
	
	// returns all of the movies in the library
	public ArrayList<Item> movies()
	{
		ArrayList<String> stringAllMovies = new ArrayList<>();
		ArrayList<Item> itemAllMovies = new ArrayList<>();
		for(Item item: items){
			if(item instanceof Movie){
				stringAllMovies.add(item.getTitle());
			}
		}
		Collections.sort(stringAllMovies);
		
		for(String thisTitle: stringAllMovies){
			for(Item thisItem: items){
				if(thisItem instanceof Movie){
					if(((Movie) thisItem).getTitle().equals(thisTitle)){
						itemAllMovies.add(thisItem);
					}
				}
			}
		}
		return itemAllMovies;
	}	
}
