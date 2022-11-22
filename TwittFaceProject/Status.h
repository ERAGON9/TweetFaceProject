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
	const Date date;
	const Time time;
	const char* text;

public:



};


#endif // !__STATUS_H

