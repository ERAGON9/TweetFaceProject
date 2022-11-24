#ifndef __STATUS_H
#define __STATUS_H

#include <string.h>
#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace std;


class Status
{
private:
	Date date;
	Time time;
	char* text;

public:
	Status() = default;
	Status(const char* txt, Date d, Time t);
	Status(const Status& other) = delete;
	void printStatus() const;
	~Status();

};


#endif // !__STATUS_H

