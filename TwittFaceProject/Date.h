#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(const int day, const int month, const int year) : day(day), month(month), year(year) {};
	const int getDay() { return day; };
	const int getmonth() { return month; };
	const int getYear() { return year; };
};

#endif