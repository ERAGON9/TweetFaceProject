#include "Users.h"
#pragma warning(disable: 4996)

#define maxLatest 10

User::User(const char* n, Date d)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	bDay = d;
	statusCount = 0;
	statusPhysic = 1;
	friendsCount = 0;
	friendsPhysic = 1;
	pagesCount = 0;
	pagesPhysic = 1;
	latestCount = 0;
	publishBoard = new Status*[statusPhysic];
	friends = new User* [friendsPhysic];
	pArrFansPages = new FansPage * [pagesPhysic];
	lastTen = new Status * [maxLatest];
}

User::~User()
{
	delete[]name;

	for (int i = 0; i < statusCount; i++) 
	{
		delete[]publishBoard[i];
	}
	
	delete[]publishBoard;
	delete[]friends;
	delete[]pArrFansPages;
}

void User::printTenLastStatusOfUsers()
{
	int i = 0;
	//while

}

void User::addUser(User& _friend)
{
	if()
	friends[friendsCount] = &_friend;



}

void User::printFansPages() 
{

}