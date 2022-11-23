#ifndef __STATUS_H
#define __STATUS_H

#include <string.h>

const int maxStatus = 500;

typedef struct Date 
{
	int day;
	int month;
	int year;
} Date;

typedef struct Time 
{
	int hours;
	int minutes;
} Time;



class Status
{
private:
	Date date;
	Time time;
	char text[maxStatus];

public:
	Status(const char* txt, Date d, Time t);
	Status(const Status& other) = delete;
	~Status();

};


#endif // !__STATUS_H

