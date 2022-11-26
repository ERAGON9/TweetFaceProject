
#include "Status.h"
#include <string.h>
#include <iostream>
#pragma warning(disable: 4996)

Status::Status(const char* txt, const Date& d, const Time& t) : date(d), time(t)
{
	text = new char[strlen(txt) + 1];
	strcpy(text, txt);
}

Status::~Status() 
{
	delete[]text;
}

void Status::printStatus() const
{
	cout << text << endl;
}