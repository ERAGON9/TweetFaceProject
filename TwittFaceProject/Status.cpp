#include "Status.h"

Status::Status(const char* txt, Date d, Time t)
{
	text = new char[strlen(txt) + 1];
	strcpy(text, txt);
	date.day = d.day;
	date.month = d.month;
	date.year = d.year;
	time.hours = t.hours;
	time.minutes = t.minutes;
}

Status::Status(const Status& other)
{
	text = new char[strlen(other.text) + 1];
	strcpy(text, other.text);
	date.day = other.date.day;
	date.month = other.date.month;
	date.year = other.date.year;
	time.hours = other.time.hours;
	time.minutes = other.time.minutes;
}

Status::~Status() 
{
	delete[]text;
}