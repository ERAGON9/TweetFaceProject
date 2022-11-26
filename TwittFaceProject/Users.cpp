
#include <iostream>
using namespace std;
#include <string.h>
#include "Users.h"
#include "Status.h"
#include "FansPage.h"

#pragma warning(disable: 4996)

//User::User(const char* _name, const Date& _date) :bDay(_date)
//{
//	name = new char[strlen(_name) + 1];
//	strcpy(name, _name);
//	statusCount = 0;
//	statusPhysic = 1;
//	friendsCount = 0;
//	friendsPhysic = 1;
//	pagesCount = 0;
//	pagesPhysic = 1;
//	publishBoard = new Status*[statusPhysic];
//	friends = new User* [friendsPhysic];
//	pArrFansPages = new FansPage * [pagesPhysic];
//}

User::User(const char* _name, const int day, const int month, const int year) : bDay(day, month, year)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	statusCount = 0;
	statusPhysic = 1;
	friendsCount = 0;
	friendsPhysic = 1;
	pagesCount = 0;
	pagesPhysic = 1;
	publishBoard = new Status * [statusPhysic];
	friends = new User * [friendsPhysic];
	pArrFansPages = new FansPage * [pagesPhysic];
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
	for (int i = statusCount; i > statusCount - 10; i--)
		publishBoard[i]->printStatus();
}

void User::addStatus(Status* tweet)
{
	if (statusCount == statusPhysic) 
	{
		statusPhysic *= 2;
		Status** tmp = new Status * [statusPhysic];

		for (int i = 0; i < statusCount; i++)
			tmp[i] = publishBoard[i];

		delete[]publishBoard;
		publishBoard = tmp;
	}

	publishBoard[statusCount] = tweet;
	statusCount++;
}

void User::addFriend(User* _friend)
{
	if (friendsCount == friendsPhysic) 
	{
		friendsPhysic *= 2;
		User** tmp = new User * [friendsPhysic];

		for (int i = 0; i < friendsCount; i++)
			tmp[i] = friends[i];

		delete[]friends;
		friends = tmp;
	}
	friends[friendsCount] = _friend;
	friendsCount++;
}

void User::removeFriend(User* _friend)
{
	for (int i = 0; i < friendsCount; i++)
	{
		if (friends[i] == _friend)
		{
			if (i != friendsCount - 1) 
				friends[i] = friends[friendsCount - 1];
			friends[friendsCount - 1] = nullptr;
			i = friendsCount;
			friendsCount--;
		}
	}

}

void User::printFriends() 
{
	for (int i = 0; i < friendsCount; i++) 
		cout << friends[i]->getName() << endl;
}

void User::printAllStatuses()
{
	for (int i = 0; i < statusCount; i++)
		publishBoard[i]->printStatus();
}

void User::addFansPage(FansPage* page)
{
	if (pagesCount == pagesPhysic) 
	{
		pagesPhysic *= 2;
		FansPage** tmp = new FansPage * [pagesPhysic];

		for (int i = 0; i < pagesCount; i++)
			tmp[i] = pArrFansPages[i];

		delete[]pArrFansPages;
		pArrFansPages = tmp;
	}
	pArrFansPages[pagesCount] = page;
	pagesCount++;
}

void User::removeFansPage(FansPage* page) 
{
	for (int i = 0; i < pagesCount; i++)
	{
		if (pArrFansPages[i] == page)
		{
			if (i != pagesCount - 1)
				pArrFansPages[i] = pArrFansPages[pagesCount - 1];
			pArrFansPages[pagesCount - 1] = nullptr;
			i = pagesCount;
			pagesCount--;
		}
	}
}

bool User::checkIfFriend(const char* name)
{
	for (int i = 0; i < friendsCount; i++)
	{
		if (strcmp(friends[i]->getName(), name) == 0)
			return true;
	}

	return false;
}