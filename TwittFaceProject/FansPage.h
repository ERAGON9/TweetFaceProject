#ifndef __FANSPAGE_H
#define __FANSPAGE_H

class FansPage
{
private:

	const char* name;
	Friend** pArrFans;
	Status* publishBoard;
	int friendsCount;
	int statusCount;



public:
	FansPage(const char* name);
	FansPage(const FansPage& other);
	~FansPage();
};




#endif // !__FANSPAGE_H

