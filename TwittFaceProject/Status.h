#ifndef __STATUS_H
#define __STATUS_H

#pragma warning(disable: 4996)
#include <string.h>

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct Time {
	int hours;
	int minutes;
} Time;

class Status
{
private:
	Date date;
	Time time;
	char* text;

public:
	Status(const char* txt, Date d, Time t);
	Status(const Status& other);
	~Status();


};


#endif // !__STATUS_H

