#include "FansPage.h"
#include <string.h>

FansPage::FansPage(const char* n) 
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	statusCount = 0;
	friendsCount = 0;
}

FansPage::FansPage(const FansPage& other) 
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	statusCount = other.statusCount;
	friendsCount = other.friendsCount;
}

FansPage::~FansPage()
{
	delete[]name;
}