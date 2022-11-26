
#include "Functions.h"
#include <iostream>
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <ctime>
using namespace std;

const int maxName = 31;

void printMenu()
{
	cout<< "Please press a number for your deserve action:" << endl
		<< "1 - Add a user." << endl
		<< "2 - Add fans page." << endl
		<< "3 - Add Status for a user / fans page." << endl
		<< "4 - Show all the statuses for a user / fans page." << endl
		<< "5 - Show 10 most recent statuses of all the friends of a user." << endl
		<< "6 - Connect friendship between 2 friends." << endl
		<< "7 - Delete friendship between 2 friends." << endl
		<< "8 - Add a user to a fan page." << endl
		<< "9 - Delete a user from a fan page." << endl
		<< "10 - Show all the users and fan pages at the system." << endl
		<< "11 - Show all the friends of a user / fans of a fan page" << endl
		<< "12 - Exit" << endl;
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
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		connectUsers(system);
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;

	default:
		break;
	}
}


void addUser(TwittFace& system)
{
	char name[maxName];
	int day, month, year;
	cout << "\nYou choosen to Add a user: \nPlease enter User name (no more than 30 characters): ";
	cin >> name;
	cout << "\nPlease enter your birth day (day  month  year): ";
	cin >> day >> month >> year;
	User* newUser = new User(name, day, month, year);
	system.addUserToSystem(newUser);
}


void addFanPage(TwittFace& system)
{
	char name[maxName];
	cout << "\nYou choosen to Add a fan page: \nPlease enter fan page name (no more than 30 characters): ";
	cin >> name;
	FansPage* newFanPage = new FansPage(name);
	system.addFanPageToSystem(newFanPage);
}

User* findUser(TwittFace& system, const char* name) 
{
	User*** tmp = system.getAllTheUsers();

	for (int i = 0; i < system.getUsersLogic(); i++)
	{
		if (strcmp((*tmp)[i]->getName(), name))
			return (*tmp)[i];
	}

	return nullptr;
}

void connectUsers(TwittFace& system)
{
	char name1[maxName], name2[maxName];
	User *user1, *user2;
	cout << "Please enter the name of the first user: ";
	cin >> name1;
	cout << "Please enter the name of the second user: ";
	cin >> name2;
	user1 = findUser(system, name1);

	if (!user1->checkIfFriend(name2))
	{
		user2 = findUser(system, name2);
		user2->addFriend(user1);
		user1->addFriend(user2);
	}

}