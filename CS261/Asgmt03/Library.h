// do not remove any of the function prototypes from this class definition

#pragma once

#include <map>
#include <set>
#include <string>
#include "Item.h"


using namespace std;

// C++ Standard Library definitions for containers you may need
typedef set<string>				StringSet;
typedef set<ItemPtr>			ItemSet;				// see comment in Item.h about use of ItemPtr
typedef map<string,ItemSet*>	StringToItemSetMap;

class Library
{
private:
	//ItemSet books;
	ItemSet setMovies;
	ItemSet setAlbums;
	ItemSet setBooks;
public:
	Library();
	// general functions
	void addKeywordsForItem(Item* item, int nKeywords, ...);
	ItemSet* itemsForKeyword(const string keyword) const;

	// book-related functions
	Item* addBook(string title, string author, int nPages);
	ItemSet* booksByAuthor(const string author) const;
	ItemSet* books() ;			// returns set containing all the books

	// music-related functions
	Item* addMusicAlbum(const string title, const string band, const int nSongs);
	void addBandMembers(Item* const musicCD, int nBandMembers, ...);
	ItemSet* musicByBand(const string band) const;
	ItemSet* musicByMusician(const string musician) const;
	ItemSet* musicAlbums() ;		// returns set containing all the music

	// movie-related functions
	Item* addMovie(const string title, const string director, const int nScenes);
	void addCastMembers(Item* const movie, const int nCastMembers, ...);
	ItemSet* moviesByDirector(const string director) const;
	ItemSet* moviesByActor(const string actor) const;
	ItemSet* movies() const;			// returns set containing all the movies

	virtual ~Library();
};

