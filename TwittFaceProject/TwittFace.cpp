#include "TwittFace.h"

#include "Users.h"
#include "FansPage.h"

TwittFace::TwittFace()
{
	usersLogic = 0;
	userPhysic = 1;
	allTheUsers = new User * [userPhysic];

	fanPagesLogic = 0;
	fansPagesPhysic = 1;
	allTheFanPages = new FansPage * [fansPagesPhysic];
}

TwittFace::~TwittFace()
{
	delete[]allTheUsers;
	delete[]allTheFanPages;

}
void TwittFace::addUserToSystem(User* newUser)
{
	if (usersLogic == userPhysic)
	{
		userPhysic *= 2;
		User** tmp = new User* [userPhysic];

		for (int i = 0; i < usersLogic; i++)
			tmp[i] = allTheUsers[i];

		delete[] allTheUsers;
		allTheUsers = tmp;
	}

	allTheUsers[usersLogic] = newUser;
	usersLogic++;
}

void TwittFace::addFanPageToSystem(FansPage* newFanPage)
{
	if (fanPagesLogic == fansPagesPhysic)
	{
		fansPagesPhysic *= 2;
		FansPage** tmp = new FansPage * [fansPagesPhysic];

		for (int i = 0; i < fanPagesLogic; i++)
			tmp[i] = allTheFanPages[i];

		delete[] allTheFanPages;
		allTheFanPages = tmp;
	}

	allTheFanPages[fanPagesLogic] = newFanPage;
	fanPagesLogic++;
}
