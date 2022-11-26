#ifndef __Users_H
#define __Users_H

#include "Date.h"
class FansPage;
class Status;

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
	/*User(const char* _name, const Date& _date);*/
	User(const char* _name, const int day, const int month, const int year);
	User(const User& other) = delete;
	~User();

	void printTenLastStatusOfUsers();
	void addFriend(User* _friend);
	void removeFriend(User* _friend);
	const char* getName() const { return name; };
	void printFriends();
	void addStatus(Status* status);
	void printAllStatuses();
	void addFansPage(FansPage* page);
	void removeFansPage(FansPage* page);
	bool checkIfFriend(const char* name);

};

#endif // !__Users_H