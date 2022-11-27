
#include "FansPage.h"
#include <string.h>
#include "Status.h"
#include "Users.h"
#pragma warning(disable: 4996)

FansPage::FansPage(const char* n) 
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	statusCount = 0;
	statusPhysic = 1;
	friendsCount = 0;
	friendsPhysic = 1;
	pArrFans = new User* [friendsPhysic];
	publishBoard = new Status* [statusPhysic];
}


FansPage::~FansPage()
{
	delete[]name;

	for (int i = 0; i < statusCount; i++) 
	{
		delete[]publishBoard[i];
	}
	delete []publishBoard;
	delete []pArrFans;
}


void FansPage::addStatus(Status* status)
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

	publishBoard[statusCount] = status;
	statusCount++;
}


void FansPage::printAllStatuses()
{
	for (int i = 0; i < statusCount; i++)
		publishBoard[i]->printStatus();
}


void FansPage::addFan(User* newFan)
{
	if (checkIfFan(newFan) == false)
	{
		if (friendsCount == friendsPhysic)
		{
			friendsPhysic *= 2;
			User** tmp = new User * [friendsPhysic];

			for (int i = 0; i < friendsCount; i++)
				tmp[i] = pArrFans[i];

			delete[]pArrFans;
			pArrFans = tmp;
		}

		pArrFans[friendsCount] = newFan;
		friendsCount++;

		newFan->addFansPage(this);
	}
}


bool FansPage::checkIfFan(User* fan)
{
	for (int i = 0; i < friendsCount; i++)
	{
		if (pArrFans[i] == fan)
			return true;
	}

	return false;
}