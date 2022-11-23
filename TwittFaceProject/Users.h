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

<<<<<<< Updated upstream:TwittFaceProject/Users.h
	User** friends;

	FansPage** pArrFansPages;
=======
	Friend** friends;
>>>>>>> Stashed changes:TwittFaceProject/Friend.h
	int friendsPysic;
	int friendsCount;

	FansPage** pArrFansPages;
	int pagesCount;
	int statusPysic;

public:
<<<<<<< Updated upstream:TwittFaceProject/Users.h
	User(const char* txt, Date d);
	User(const User& other);
	~User();
=======
	Friend(const char* txt, Date d);
	//Friend(const Friend& other);
	~Friend();

	void printTenLastStatusOfFriends() const;
	void addFriend(Friend& _friend);
	void printFansPages() const;
>>>>>>> Stashed changes:TwittFaceProject/Friend.h

};

#endif // !__Users_H