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


int main()
{
	TwittFace system;
	int input = 0;
	
	initHardCodedData(system);

	do
	{
		for (int i = 0; i < system.getUsersLogic(); i++) // check that actions
		{
			cout << "\n\n" << (*((*system.getAllTheUsers())[i])).getName() << "\n" << endl;
		}
		for (int j = 0; j < system.getFanPageLogic(); j++) // check that actions
		{
			cout << "\n\n" << (*((*system.getAllTheFanPages())[j])).getName() << "\n" << endl;
		}

		printMenu();
		cin >> input;
		action(input, system);
		
	} while (input != 12);
}