
#include <iostream>
using namespace std;

void printMenu()
{
	cout << "Please press a number for your deserve action: " << endl
		<< "1- Add a user" << endl
		<< "2 - Add fans page" << endl
		<< "3 - Add Status for a user / fans page " << endl
		<< "4 - Show all the statuses for a user/ fans page" << endl
		<< "5 - Show 10 most recent statuses of a friend" << endl
		<< "6 - Connect friendship between 2 friends" << endl
		<< "7 - Delete friendship between 2 friends" << endl
		<< "8 - Add user to fan page" << endl
		<< "9 - Delete user from fan page" << endl
		<< "10 - Show all objects at the system" << endl
		<< "11 - Show all the friends of a user / fans of a fan page" << endl
		<< "12 - Exit" << endl;
}

void action(int& value)
{
	cin >> value;
	switch (value)
	{
	case 1:
		//addfriend();
	case 2:


	default:
		break;
	}
}