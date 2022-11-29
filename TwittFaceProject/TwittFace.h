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

	const int& getUsersLogic() const { return usersLogic; }
	const int& getFanPageLogic() const { return fanPagesLogic; }
	User** getAllTheUsers() { return allTheUsers; }
	FansPage** getAllTheFanPages() { return allTheFanPages; }

	void addUserToSystem(User* newUser);
	void addFanPageToSystem(FansPage* newFanPage);
	const bool isUserExist(const char* userName) const;
	User& getUserbyName(const char* userName);
	const bool isFanPageExist(const char* fanPageName) const;
	FansPage& getFanPagebyName(const char* fanPageName);
};

#endif // !___TWITTFACE_H