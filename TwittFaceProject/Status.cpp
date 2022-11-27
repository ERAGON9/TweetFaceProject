
#include "Status.h"
#include <string.h>
#include <iostream>
//#include "Date.h"     // getting that from "Status.h"
//#include "Time.h"
#pragma warning(disable: 4996)

Status::Status(const char* txt): date(), time()
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
	cout <<"The status wroten at: " << date.getDay() <<" / " << date.getmonth() << " / " << date.getYear() << endl
		 <<"At time: " << time.getHour() << " : " << time.getminute() << endl 
		 <<"The status is: " << text << endl;
}