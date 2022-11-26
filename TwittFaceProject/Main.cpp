/*
Welcome to TwittFaceProject:
*/
#include <iostream>
#include "TwittFace.h"
#include "Users.h"
#include "Status.h"
#include "FansPage.h"
#include "Functions.h"

using namespace std;

#pragma warning(disable: 4996)

const int maxStatus = 500;

int main()
{
	TwittFace system;
	int input = 0;
	
	User* lior = new User ("lior", 3, 2, 1999), *shalev = new User("shalev", 1, 1, 1999), *michael = new User("michael", 2, 2, 1999);
	FansPage* liorFP = new FansPage("liorbusiness"), *shalevFP = new FansPage("shalevbusiness"), *michaelFP = new FansPage("michaelbusiness");

	system.addUserToSystem(lior);
	system.addUserToSystem(shalev);
	system.addUserToSystem(michael);
	system.addFanPageToSystem(liorFP);
	system.addFanPageToSystem(shalevFP);
	system.addFanPageToSystem(michaelFP);

	do
	{
		for (int i = 0; i < system.getUsersLogic(); i++) // check that action number 1 work
		{
			cout << endl << (*((*system.getAllTheUsers())[i])).getName() << endl << endl;
		}

		printMenu();
		cin >> input;
		action(input, system);
		
	} while (input != 12);
}