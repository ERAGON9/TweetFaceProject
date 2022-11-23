#ifndef __Users_H
#define __Users_H


using namespace std;
#include "FansPage.h"
#include "Date.h"

class User
{
private:
	char* name;
	Date bDay;

	Status** publishBoard;
	int statusCount;
	int statusPhysic;

	User** friends;
	int friendsPhysic;
	int friendsCount;

	FansPage** pArrFansPages;
	int pagesPhysic;
	int pagesCount;

public:
	User() = default;
	User(const char* txt, Date d);
	User(const User& other) = delete;
	~User();

	void printTenLastStatusOfUsers();
	void addUser(User& _friend);
	void printFansPages();

};

#endif // !__Users_H