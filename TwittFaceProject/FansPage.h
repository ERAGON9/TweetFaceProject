#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "Status.h"


class Friend;

class FansPage
{
private:

	char* name;
	Friend** pArrFans;
	Status* publishBoard;
	int friendsPysic;
	int friendsCount;
	int statusCount;
	int statusPysic;



public:
	FansPage(const char* name);
	FansPage(const FansPage& other);
	~FansPage();
};




#endif // !__FANSPAGE_H

