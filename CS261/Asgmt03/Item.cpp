#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"
#include<string>
#include<algorithm>
#include "Book.h"
#include "Movie.h"
#include "MusicAlbum.h"
#include <iostream>

Item::Item(const string title, const string artist, int numStuff) :
	title(title),
	artist(artist),
	keywords(),
	numStuff(numStuff)
{
}

Item::~Item()
{
	// your code here
	keywords.clear();
}

bool operator<(Item i1, Item i2)
{
	return false;
}

bool operator<(ItemPtr ip1, ItemPtr ip2)
{
	// your code here
	if (ip1.getPtr()->getTitle() > ip2.getPtr()->getTitle()){
		return false;
	}
	return true;

}

ostream& operator<<(ostream& out, Item* item)
{
	vector<string> tmpKeywords = item->getKeywords();

	if (dynamic_cast<Book*>(item)) {
		out << "-Book-\nauthor:\t\t" << item->getArtist() << "\n# pages:\t"
			<< item->getNumStuff() << "\ntitle:\t\t" << item->getTitle()
			<< "\nkeywords:\t";

		vector<string> tmpKeywords = item->getKeywords();
		vector<string>::iterator iter = tmpKeywords.begin();
		for (iter; iter != tmpKeywords.end(); ++iter) {
			out << *iter << ", ";
		}
		out << "\b\b  " << endl << endl;
	}
	else if (dynamic_cast<Movie*>(item)) {
		set<string> tmpCast = dynamic_cast<Movie*>(item)->getCast();

		out << "-Movie-\ndirector:\t" << item->getArtist() << "\n# scenes:\t" << item->getNumStuff();
		out << "\ncast:\t\t";

		set<string>::iterator s_iter = tmpCast.begin();
		for (s_iter; s_iter != tmpCast.end(); ++s_iter) {
			out << *s_iter << ", ";
		}
		
		out << "\b\b  \ntitle:\t\t" << item->getTitle() << "\nkeywords:\t";

		vector<string> tmpKeywords = item->getKeywords();
		vector<string>::iterator iter = tmpKeywords.begin();
		for (iter; iter != tmpKeywords.end(); ++iter) {
			out << *iter << ", ";
		}
		out << "\b\b  " << endl << endl;;
	}
	else {
		set<string> tmpMembers = dynamic_cast<MusicAlbum*>(item)->getMembers();
		// default case: item is Music Album

		out << "-Music Album-\nband:\t\t" << item->getArtist() << "\n# songs:\t" << item->getNumStuff();
		out << "\nmembers:\t";

		set<string>::iterator m_iter = tmpMembers.begin();
		for (m_iter; m_iter != tmpMembers.end(); ++m_iter) {
			out << *m_iter << ", ";
		}

		out << "\b\b  \ntitle:\t\t" << item->getTitle() << "\nkeywords:\t";

		vector<string> tmpKeywords = item->getKeywords();
		vector<string>::iterator iter = tmpKeywords.begin();
		for (iter; iter != tmpKeywords.end(); ++iter) {
			out << *iter << ", ";
		}
		out << "\b\b  " << endl << endl;
	}
	return out;
}

void Item::addKeyword(string keyword) {
	keywords.push_back(keyword);
}

void Item::sortKeywords() {
	sort(keywords.begin(), keywords.end());
}
