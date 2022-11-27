#ifndef __FANSPAGE_H
#define __FANSPAGE_H

class Friend;
class Status;
class User;

class FansPage
{
private:
	char* name;

	User** pArrFans;
	int friendsPhysic;
	int friendsCount;

	Status** publishBoard;
	int statusCount;
	int statusPhysic;



public:
	FansPage(const char* name);
	FansPage(const FansPage& other) = delete;
	~FansPage();
	const char* getName() const { return name; }
	void addStatus(Status* status);
	void printAllStatuses();
	void addFan(User* newFan);
	bool checkIfFan(User* fan);

};




#endif // !__FANSPAGE_H

