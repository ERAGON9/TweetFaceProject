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
	publishBoard = new Status*[statusPhysic];
	friends = new User* [friendsPhysic];
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
	for (int i = statusCount; statusCount - i < 10; i--)
		publishBoard[i]->printStatus();

}

const char* User::getName() const
{
	return name;
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
	if (friendsCount == friendsPhysic) {
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
	if (pagesCount == pagesPhysic) {
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