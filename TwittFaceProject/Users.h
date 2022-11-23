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

	User** friends;

	FansPage** pArrFansPages;
	int friendsPysic;
	int statusCount;
	int friendsCount;
	int pagesCount;
	int statusPysic;

public:
	User(const char* txt, Date d);
	User(const User& other);
	~User();

};

#endif // !__Users_H