#ifndef __FRIENDS_H
#define __FRIENDS_H

#include <iostream>
using namespace std;
#include "Status.h"
#include "FansPage.h"

class Friend
{
private:
	const char* name;
	const Date bDay;
	Status* publishBoard;
	Friend** friends;
	FansPage** pArrFansPages;
	int statusCount;
	int friendsCount;
	int pagesCount;

public:

};

#endif // !__FRIENDS_H