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
	void addFriend(User* _friend);
	void removeFriend(User* _friend);
	const char* getName() const;
	void printFriends();
	void addStatus(Status* status);
	void printAllStatuses();
	void addFansPage(FansPage* page);
	void removeFansPage(FansPage* page);

};

#endif // !__Users_H