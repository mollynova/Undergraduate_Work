#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include <cstdarg>					// support macros for vararg
#include <iostream>
#include "Library.h"
#include "Book.h"
#include "MusicAlbum.h"
#include "Movie.h"

// general functions

Library::Library() :
	setBooks(),
	setMovies(),
	setAlbums()
	
{
}

void Library::addKeywordsForItem(Item* item, int nKeywords, ...)
{
	// the code in this function demonstrates how to handle a vararg in C++

	va_list		keywords;
	char		*keyword;

	va_start(keywords, nKeywords);
	for (int i = 0; i < nKeywords; i++) {
		keyword = va_arg(keywords, char*);
		// do something with each keyword

		string newKeyword = keyword;
		item->addKeyword(newKeyword);
		}
	va_end(keywords);
	item->sortKeywords();
}

ItemSet* Library::itemsForKeyword(const string keyword) const
{
	ItemSet* tmpSet = new ItemSet();

	// Books
	ItemSet::iterator b_it = setBooks.begin();
	
	for (b_it; b_it != setBooks.end(); ++b_it) {
		vector<string> tmpKeywords;
		tmpKeywords = b_it->getPtr()->getKeywords();

		vector<string>::iterator iter;
		for (iter = tmpKeywords.begin(); iter != tmpKeywords.end(); ++iter) {
			if (*iter == keyword) {
				tmpSet->insert(b_it->getPtr());
			}
		}
	}

	// Movies

	ItemSet::iterator m_it = setMovies.begin();
	for (m_it; m_it != setMovies.end(); ++m_it) {
		vector<string> tmpKeywords;
		tmpKeywords = m_it->getPtr()->getKeywords();

		vector<string>::iterator iter;
		for (iter = tmpKeywords.begin(); iter != tmpKeywords.end(); ++iter) {
			if (*iter == keyword) {
				tmpSet->insert(m_it->getPtr());
			}
		}
	}

	// Music Albums

	ItemSet::iterator ma_it = setAlbums.begin();
	for (ma_it; ma_it != setAlbums.end(); ++ma_it) {
		vector<string> tmpKeywords;
		tmpKeywords = ma_it->getPtr()->getKeywords();

		vector<string>::iterator iter;
		for (iter = tmpKeywords.begin(); iter != tmpKeywords.end(); ++iter) {
			if (*iter == keyword) {
				tmpSet->insert(ma_it->getPtr());
			}
		}
	}
	
	return tmpSet;
}

// book-related functions

Item* Library::addBook(string title, string author, int nPages)
{
	Item* book = new Book(title, author, nPages);
	setBooks.insert(book);
	return book;
}

ItemSet* Library::booksByAuthor(const string author) const
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setBooks.begin();
	for (it; it != setBooks.end(); ++it) {
		if (it->getPtr()->getArtist() == author) {
			tmpSet->insert(it->getPtr());
		}
	}
	return tmpSet;

}

ItemSet* Library::books() 
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setBooks.begin();
	for (it; it != setBooks.end(); ++it) {
		tmpSet->insert(it->getPtr());
	}
	
	return tmpSet;
}

// music-related functions

Item* Library::addMusicAlbum(const string title, const string band, const int nSongs)
{
	Item* album = new MusicAlbum(title, band, nSongs);
	setAlbums.insert(album);
	return album;
}

void Library::addBandMembers(Item* const musicAlbum, const int nBandMembers, ...)
{

	va_list		keywords;
	char		*keyword;

	va_start(keywords, nBandMembers);
	for (int i = 0; i < nBandMembers; i++) {
		keyword = va_arg(keywords, char*);
		// do something with each keyword

		string newMember = keyword;
		dynamic_cast<MusicAlbum*>(musicAlbum)->addMember(newMember);
	}
	va_end(keywords);
	// sort members
	//dynamic_cast<MusicAlbum*>(musicAlbum)->sortMembers();
}

ItemSet* Library::musicByBand(const string band) const
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setAlbums.begin();
	for (it; it != setAlbums.end(); ++it) {
		if (it->getPtr()->getArtist() == band) {
			tmpSet->insert(it->getPtr());
		}
	}
	return tmpSet;

}

ItemSet* Library::musicByMusician(const string musician) const
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setAlbums.begin();
	for (it; it != setAlbums.end(); ++it) {
		set<string> tmpKeywords;
		tmpKeywords = dynamic_cast<MusicAlbum*>(it->getPtr())->getMembers();
		
		set<string>::iterator iter = tmpKeywords.begin();
		for (iter; iter != tmpKeywords.end(); ++iter) {
			if (*iter == musician) {
				tmpSet->insert(it->getPtr());
			}
		}
	}
	return tmpSet;
}

ItemSet* Library::musicAlbums() 
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setAlbums.begin();
	for (it; it != setAlbums.end(); ++it) {
		tmpSet->insert(it->getPtr());
	}
	return tmpSet;
}

// movie-related functions

Item* Library::addMovie(const string title, const string director, const int nScenes)
{
	Item* movie = new Movie(title, director, nScenes);
	setMovies.insert(movie);
	return movie;
}

void Library::addCastMembers(Item* const movie, const int nCastMembers, ...)
{
	va_list		keywords;
	char		*keyword;

	va_start(keywords, nCastMembers);
	for (int i = 0; i < nCastMembers; i++) {
		keyword = va_arg(keywords, char*);
		// do something with each keyword

		string newMember = keyword;
		dynamic_cast<Movie*>(movie)->addMember(newMember);
	}
	va_end(keywords);
}

ItemSet* Library::moviesByDirector(const string director) const
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setMovies.begin();
	for (it; it != setMovies.end(); ++it) {
		if (it->getPtr()->getArtist() == director) {
			tmpSet->insert(it->getPtr());
		}
	}
	return tmpSet;

}

ItemSet* Library::moviesByActor(const string actor) const
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setMovies.begin();
	for (it; it != setMovies.end(); ++it) {
		set<string> tmpKeywords;
		tmpKeywords = dynamic_cast<Movie*>(it->getPtr())->getCast();

		set<string>::iterator iter;
		for (iter = tmpKeywords.begin(); iter != tmpKeywords.end(); ++iter) {
			if (*iter == actor) {
				tmpSet->insert(it->getPtr());
			}
		}
	}
	return tmpSet;
}

ItemSet* Library::movies() const
{
	ItemSet* tmpSet = new ItemSet();
	ItemSet::iterator it = setMovies.begin();
	for (it; it != setMovies.end(); ++it) {
		tmpSet->insert(it->getPtr());
	}
	return tmpSet;

}

static void deleteMapContents(StringToItemSetMap& s2ism)
{
	// your code here
	// I didn't use a map
}

static void deleteItemSetContents(ItemSet& itemSet)
{
	// your code here
	itemSet.clear();
}

Library::~Library()
{
	// your code here
	setBooks.clear();
	setMovies.clear();
	setAlbums.clear();
}
