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

User::~User()
{

}


void User::printTenLastStatusOfFriends() const
{

}

void User::addFriend(User& _friend)
{

}

void User::printFansPages() const
{

}