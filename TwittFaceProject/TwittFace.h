#ifndef __TWITTFACE_H
#define __TWITTFACE_H

class User;
class FansPage;

class TwittFace
{
private:
	User** allTheUsers;
	int usersLogic;
	int userPhysic;

	FansPage** allTheFanPages;
	int fanPagesLogic;
	int fansPagesPhysic;

public:
	TwittFace();
	TwittFace(TwittFace& twitFace) = delete;
	~TwittFace();

	void addUserToSystem(User* newUser);
	void addFanPageToSystem(FansPage* newFanPage);
	int getUsersLogic() { return usersLogic; }
	int getFanPageLogic() { return fanPagesLogic; }
	User** getAllTheUsers() { return allTheUsers; }
	FansPage** getAllTheFanPages() { return allTheFanPages; }
	bool isUserExist(const char* userName);
	User& getUserbyName(const char* userName);
	bool isFanPageExist(const char* fanPageName);
	FansPage& getFanPagebyName(const char* fanPageName);
};

#endif // !___TWITTFACE_H