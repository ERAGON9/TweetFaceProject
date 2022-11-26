/*
Welcome to TwittFaceProject:
*/
#include <iostream>
#include "Status.h"
#include "Users.h"
#include "TwittFace.h"
#include "Functions.h"

using namespace std;

#pragma warning(disable: 4996)

const int maxName = 20;
const int maxStatus = 500;

int main()
{
	TwittFace system;
	int input = 0;


	do
	{
		cin >> input;
		printMenu();
		action(input);

		
	} while (input != 12);
}