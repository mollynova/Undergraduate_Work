#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "MusicAlbum.h"

MusicAlbum::~MusicAlbum(void)
{
	members.clear();
}

void MusicAlbum::addMember(string member) {
	members.insert(member);
}

void MusicAlbum::sortMembers() {
	//don't think I need this actually
}