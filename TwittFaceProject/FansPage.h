#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "Status.h"


class Friend;

class FansPage
{
private:
	char* name;

	Friend** pArrFans;
	int friendsPysic;
	int friendsCount;

	Status** publishBoard;
	int statusCount;
	int statusPysic;



public:
	FansPage(const char* name);
	FansPage(const FansPage& other) = delete;
	~FansPage();
};




#endif // !__FANSPAGE_H

