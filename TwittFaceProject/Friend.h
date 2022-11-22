#ifndef __FRIENDS_H
#define __FRIENDS_H



#pragma warning(disable: 4996)


#include <iostream>
using namespace std;
#include "FansPage.h"

class Friend
{
private:
	char* name;
	Date bDay;
	Status* publishBoard;

	Friend** friends;

	FansPage** pArrFansPages;
	int friendsPysic;
	int statusCount;
	int friendsCount;
	int pagesCount;
	int statusPysic;

public:
	Friend(const char* txt, Date d);
	//Friend(const Friend& other);
	~Friend();


};

#endif // !__FRIENDS_H