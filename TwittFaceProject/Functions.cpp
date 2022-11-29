
#include "Functions.h"
#include <iostream>
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string.h>
#include "Status.h"
#include "Users.h"

using namespace std;

const int maxName = 31;
const int maxStatus = 501;


void initHardCodedData(TwittFace& system)
{
	User* lior = new User("Lior", 3, 2, 1999);
	User* shalev = new User("Shalev", 1, 1, 1999);
	User*michael = new User("Michael", 2, 2, 1999);
	FansPage* liorFP = new FansPage("LiorBusiness");
	FansPage* shalevFP = new FansPage("ShalevBusiness");
	FansPage* michaelFP = new FansPage("MichaelBusiness");

	system.addUserToSystem(lior);
	system.addUserToSystem(shalev);
	system.addUserToSystem(michael);
	system.addFanPageToSystem(liorFP);
	system.addFanPageToSystem(shalevFP);
	system.addFanPageToSystem(michaelFP);

	lior->addStatus(new Status("Lior's First status"));
	lior->addStatus(new Status("Lior's Second status"));
	shalev->addStatus(new Status("Shalev's First status"));
	shalev->addStatus(new Status("Shalev'sSecond status"));
	michael->addStatus(new Status("Michael's First status"));
	michael->addStatus(new Status("Michael's Second status"));
	liorFP->addStatus(new Status("LiorBusiness First status"));
	liorFP->addStatus(new Status("LiorBusiness Second status"));
	shalevFP->addStatus(new Status("ShalevBusinessFirst status"));
	shalevFP->addStatus(new Status("ShalevBusiness Second status"));
	michaelFP->addStatus(new Status("MichaelBusiness First status"));
	michaelFP->addStatus(new Status("MichaelBusiness Second status"));

	lior->addFriend(shalev);
	shalev->addFriend(michael);
	lior->addFansPage(liorFP);
	shalev->addFansPage(shalevFP);
	michael->addFansPage(michaelFP);
}


void printMenu()
{
	cout << "\nPlease press a number for your deserve action:" << endl
		<< " 1 - Add a user." << endl
		<< " 2 - Add fans page." << endl
		<< " 3 - Add Status for a user / fans page." << endl
		<< " 4 - Show all the statuses for a user / fans page." << endl
		<< " 5 - Show 10 most recent statuses of all the friends of a user." << endl
		<< " 6 - Connect friendship between 2 friends." << endl
		<< " 7 - Delete friendship between 2 friends." << endl
		<< " 8 - Add a user to a fan page." << endl
		<< " 9 - Delete a user from a fan page." << endl
		<< "10 - Show all the users and fan pages at the system." << endl
		<< "11 - Show all the friends of a user / fans of a fan page" << endl
		<< "12 - Exit" << endl
		<< "Your choice: ";
}

void action(int& value, TwittFace& system)
{
	switch (value)
	{
	case 1:
		addUser(system);
		break;
	case 2:
		addFanPage(system);
		break;
	case 3:
		addStatus(system);
		break;
	case 4:
		printAllStatuses(system);
		break;
	case 5:
		printTenMostRecentFriendsStatuses(system);
		break;
	case 6:
		connectUsers(system);
		break;
	case 7:
		seperateUsers(system);
		break;
	case 8:
		addFanToFanPage(system);
		break;
	case 9:
		removeFanFromFanPage(system);
		break;
	case 10:
		printAllObjects(system);
		break;
	case 11:
		showAllFriendsOrFans(system);
		break;

	default:
		break;
	}
}

// action 1
void addUser(TwittFace& system)
{
	char name[maxName];
	int day, month, year;
	cout << "Please enter User name (one word, no more than 30 characters): ";
	cin >> name;
	if (system.isUserExist(name) == false)
	{
		cout << "\nPlease enter your birth day (day (space/enter)  month (space/enter) year ): ";
		cin >> day >> month >> year;
		User* newUser = new User(name, day, month, year);
		system.addUserToSystem(newUser);
		cout << "\nUser added successfully" << endl;
	}
	else
		cout << "\nThe name already taken, back to menu." << endl;
}

// action 2
void addFanPage(TwittFace& system)
{
	char name[maxName];
	cout << "Please enter fan page name (no more than 30 characters): ";
	cin >> name;
	if (system.isFanPageExist(name) == false)
	{
		FansPage* newFanPage = new FansPage(name);
		system.addFanPageToSystem(newFanPage);
		cout << "\nFan page added successfully" << endl;
	}
	else
		cout << "\nThe name already taken, back to menu." << endl;
}

// action 3
void addStatus(TwittFace& system)
{
	char answer;
	cout << "Please select to who you want to add new status: (U-user / F-fan page) ";
	cin >> answer;
	if (answer == 'U')
		addStatusToUser(system);
	else if (answer == 'F')
		addStatuesToFanPage(system);
	else
		cout << "\nYou entered wrong input, back to menu." << endl;
}

// sub function of action 3
void addStatusToUser(TwittFace& system)
{
	char userName[maxName];
	cout << "\nPlease enter the name of the user: ";
	cin >> userName;

	if (system.isUserExist(userName) == true)
	{
		char statusData[maxStatus];
		cout << "\nPlease enter the new status (no more than 500 characters): ";
		cleanBuffer();
		cin.getline(statusData, 500);
		Status* newstatus = new Status(statusData);
		system.getUserbyName(userName).addStatus(newstatus);
		cout << "\nUser status added successfully" << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 3
void addStatuesToFanPage(TwittFace& system)
{
	char fanPageName[maxName];
	cout << "\nPlease enter the name of the fan page: ";
	cin >> fanPageName;

	if (system.isFanPageExist(fanPageName) == true)
	{
		char statusData[maxStatus];
		cout << "\nPlease enter the new status (no more than 500 characters): ";
		cleanBuffer();
		cin.getline(statusData, 500);
		Status* newstatus = new Status(statusData);
		system.getFanPagebyName(fanPageName).addStatus(newstatus);
		cout << "\nFan page status added successfully" << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 3
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

// action 4
void printAllStatuses(TwittFace& system)
{
	char answer;
	cout << "Please select to who you want to show all the statuses: (U-user / F-fan page) ";
	cin >> answer;
	if (answer == 'U')
		printAllUserStatuses(system);
	else if (answer == 'F')
		printAllFanPageStatuses(system);
	else
		cout << "\nYou entered wrong input, back to menu." << endl;
}

// sub function of action 4
void printAllUserStatuses(TwittFace& system)
{
	char userName[maxName];
	cout << "\nPlease enter the name of the user: ";
	cin >> userName;

	if (system.isUserExist(userName) == true)
	{
		cout << "\nAll the user statuses are:" << endl;
		system.getUserbyName(userName).printAllStatuses();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 4
void printAllFanPageStatuses(TwittFace& system)
{
	char fanPageName[maxName];
	cout << "\nPlease enter the name of the fan page: ";
	cin >> fanPageName;

	if (system.isFanPageExist(fanPageName) == true)
	{
		cout << "\nAll the fan page statuses are:" << endl;
		system.getFanPagebyName(fanPageName).printAllStatuses();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 5
void printTenMostRecentFriendsStatuses(TwittFace& system)
{
	char userName[maxName];
	cout << "Please enter the name of the user: ";
	cin >> userName;

	if (system.isUserExist(userName) == true)
	{
		User& curUser = system.getUserbyName(userName);
		for (int i = 0; i < curUser.getFriendsLogic(); i++)
		{
			cout << "\nThe most recent statuses of " << curUser.getFriends()[i]->getName() << " are:" << endl;
			curUser.getFriends()[i]->printTenLastStatusOfTheUser();
		}
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 6
void connectUsers(TwittFace& system)
{
	char name1[maxName], name2[maxName];
	
	cout << "Please enter the name of the first user: ";
	cin >> name1;
	cout << "\nPlease enter the name of the second user: ";
	cin >> name2;
	if (system.isUserExist(name1) == true && system.isUserExist(name2) == true)
	{
		User& user1 = system.getUserbyName(name1);
		
		if (user1.checkIfFriend(name2) == false)
		{
			User& user2 = system.getUserbyName(name2);
			user1.addFriend(&user2);
			cout << "\nThe connection added successfully" << endl;
		}
		else
			cout << "\nYou entered two users that already friends" << endl;
	}
	else
		cout << "\nAt least one of the names does not exist at the system, back to menu." << endl;
}

// action 7
void seperateUsers(TwittFace& system)
{
	char name1[maxName], name2[maxName];

	cout << "Please enter the name of the first user: ";
	cin >> name1;
	cout << "\nPlease enter the name of the second user: ";
	cin >> name2;
	if (system.isUserExist(name1) == true && system.isUserExist(name2) == true)
	{
		User& user1 = system.getUserbyName(name1);

		if (user1.checkIfFriend(name2) == true)
		{
			User& user2 = system.getUserbyName(name2);
			user1.removeFriend(&user2);
			cout << "\nThe seperate happened, the two users no more friends" << endl;
		}
		else
			cout << "\nYou entered two users that not friends" << endl;
	}
	else
		cout << "\nAt least one of the names does not exist at the system, back to menu." << endl;
}

// action 8
void addFanToFanPage(TwittFace& system)
{
	char fanPageName[maxName], newfanName[maxName];
	cout << "Please enter the name of the fan page: ";
	cin >> fanPageName;

	if (system.isFanPageExist(fanPageName) == true)
	{
		cout << "\nPlease enter the name of the new fan (user name): ";
		cin >> newfanName;

		if (system.isUserExist(newfanName) == true)
		{
			FansPage& curfanPage = system.getFanPagebyName(fanPageName);
			User& newfan = system.getUserbyName(newfanName);
			if (curfanPage.checkIfFan(&newfan) == false)
			{
				curfanPage.addFan(&newfan);
				cout << "\nThe user is a fan of the fan page now" << endl;
			}
			else
				cout << "\nThe user already a fan of this fan page, back to menu." << endl;
		}
		else
			cout << "\nThe name does not exist at the system, back to menu." << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 9
void removeFanFromFanPage(TwittFace& system)
{
	char fanPageName[maxName], oldfanName[maxName];
	cout << "Please enter the name of the fan page: ";
	cin >> fanPageName;

	if (system.isFanPageExist(fanPageName) == true)
	{
		cout << "\nPlease enter the name of the user, to be no more a fan of the fan page: ";
		cin >> oldfanName;

		if (system.isUserExist(oldfanName) == true)
		{
			FansPage& curfanPage = system.getFanPagebyName(fanPageName);
			User& oldfan = system.getUserbyName(oldfanName);
			if (curfanPage.checkIfFan(&oldfan) == true)
			{
				curfanPage.removeFan(&oldfan);
				cout << "\nThe user no more fan of the fan page" << endl;
			}
			else
				cout << "\nThe user already not a fan of this fan page, back to menu." << endl;
		}
		else
			cout << "\nThe name does not exist at the system, back to menu." << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 10
void printAllObjects(TwittFace& system)
{
	
	cout << "All the users at the system are: " << endl;
	for (int i = 0; i < system.getUsersLogic(); i++)
	{
		cout << "\n" << system.getAllTheUsers()[i]->getName() << endl;
	}

	cout << "\nAll the fan pages at the system are: " << endl;
	for (int j = 0; j < system.getFanPageLogic(); j++) // check that actions
	{
		cout << "\n" << system.getAllTheFanPages()[j]->getName() << endl;
	}
}

// action 11
void showAllFriendsOrFans(TwittFace& system)
{
	char answer;
	cout << "Please select if to show, all the friends of a user/ all the fans of a fan page: (U-user / F-fan page) ";
	cin >> answer;
	if (answer == 'U')
		showAllFriens(system);
	else if (answer == 'F')
		showAllFans(system);
	else
		cout << "\nYou entered wrong input, back to menu." << endl;
}

// sub function of action 11
void showAllFriens(TwittFace& system)
{
	char userName[maxName];
	cout << "\nPlease enter the name of the user: ";
	cin >> userName;

	if (system.isUserExist(userName) == true)
	{
		cout << "\nAll the friends of " << userName << " are:\n" << endl;
		system.getUserbyName(userName).printAllFriends();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 11
void showAllFans(TwittFace& system)
{
	char fanPageName[maxName];
	cout << "\nPlease enter the name of the fan page: ";
	cin >> fanPageName;

	if (system.isFanPageExist(fanPageName) == true)
	{
		cout << "\nAll the fans of " << fanPageName << " are:\n" << endl;
		system.getFanPagebyName(fanPageName).printAllFans();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}