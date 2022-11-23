#include "FansPage.h"
#include <string.h>
#pragma warning(disable: 4996)

FansPage::FansPage(const char* n) 
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	statusCount = 0;
	friendsCount = 0;
}



FansPage::~FansPage()
{
	delete[]name;
}