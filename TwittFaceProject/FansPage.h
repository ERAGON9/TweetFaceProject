#ifndef __FANSPAGE_H
#define __FANSPAGE_H

class FansPage
{
private:

	char* name;
	Friend** pArrFans;
	Status* publishBoard;
	int friendsCount;
	int statusCount;

	const char* name;
	Status* publishBoard;
	Friend** pArrFans;


public:
	FansPage(const char* name);
	FansPage(const FansPage& other);
	~FansPage();
};




#endif // !__FANSPAGE_H

