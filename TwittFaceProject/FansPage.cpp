#include "FansPage.h"
#include <string.h>
#pragma warning(disable: 4996)

FansPage::FansPage(const char* n) 
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	statusCount = 0;
	statusPysic = 1;
	friendsCount = 0;
	friendsPysic = 1;
	pArrFans = new Friend * [friendsPysic];
	publishBoard = new Status * [statusPysic];
}



FansPage::~FansPage()
{
	delete[]name;

	for (int i = 0; i < statusCount; i++) 
	{
		delete[]publishBoard[i];
	}
	delete []publishBoard;
	delete []pArrFans;
}