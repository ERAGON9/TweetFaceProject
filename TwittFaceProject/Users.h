#ifndef __Users_H
#define __Users_H


using namespace std;
#include "FansPage.h"

class User
{
private:
	char* name;
	Date bDay;

	Status* publishBoard;
	int statusCount;

	User** friends;

	FansPage** pArrFansPages;
	Friend** friends;
	int friendsPysic;
	int friendsCount;

	FansPage** pArrFansPages;
	int pagesCount;
	int statusPysic;

public:
	User(const char* txt, Date d);
	User(const User& other) = delete;
	~User();

	void printTenLastStatusOfFriends() const;
	void addFriend(Friend& _friend);
	void printFansPages() const;

};

#endif // !__Users_H