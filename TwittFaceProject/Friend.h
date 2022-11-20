#ifndef __FRIENDS_H
#define __FRIENDS_H


#include <iostream>
using namespace std;
#include "Status.h"

class Friend
{
private:
	const char* name;
	const int day;
	const int month;
	const int year;
	Status* publishBoard;
	Friend* friends;
	FansPage** pArrFansPages;

public:

};

#endif // !__FRIENDS_H