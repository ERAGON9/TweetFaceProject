#include "Users.h"

User::User(const char* n, Date d)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	bDay.day = d.day;
	bDay.month = d.month;
	bDay.year = d.year;
	statusCount = 0;
	friendsCount = 0;
	pagesCount = 0;
}

<<<<<<< Updated upstream:TwittFaceProject/Users.cpp
User::User(const Friend& other)
=======
/*
Friend::Friend(const Friend& other)
>>>>>>> Stashed changes:TwittFaceProject/Friend.cpp
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	bDay.day = other.bDay.day;
	bDay.month = other.bDay.month;
	bDay.year = other.bDay.year;
	statusCount = other.statusCount;
	friendsCount = other.friendsCount;
	pagesCount = other.pagesCount;
}
<<<<<<< Updated upstream:TwittFaceProject/Users.cpp

User::~User()
=======
*/

Friend::~Friend()
>>>>>>> Stashed changes:TwittFaceProject/Friend.cpp
{
	delete[]name;
}

void Friend::printTenLastStatusOfFriends() const
{

}

void Friend::addFriend(Friend& _friend)
{

}

void Friend::printFansPages() const
{

}