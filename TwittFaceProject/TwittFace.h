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
	int getUsersLogic() { return usersLogic; };
	User*** getAllTheUsers() { return &allTheUsers; };
	FansPage*** getAllTheFanPages() { return &allTheFanPages; };

};
























#endif // !___TWITTFACE_H