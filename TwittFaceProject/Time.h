#ifndef __TIME_H
#define __TIME_H

class Time
{
private:
	int hour;
	int minute;

public:
	Time() = default;
	Time(const int hour, const int minute, const int year) : minute(minute), hour(hour) {};
	Time(const Time& other) = delete;
	const int getHour() { return hour; };
	const int getminute() { return minute; };
};




#endif