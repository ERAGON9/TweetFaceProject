#include "Status.h"
#pragma warning(disable: 4996)

Status::Status(const char* txt, Date d, Time t)
{
	text = new char[strlen(txt) + 1];
	strcpy(text, txt);
	date = d;
	time = t;
}

Status::~Status() 
{
	delete[]text;
}