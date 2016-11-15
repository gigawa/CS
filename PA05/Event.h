/* @file Event.h */
#ifndef EVENT_
#define EVENT_

class Event
{
public:
	Event();

	bool operator==(const Event & rightSide) const;
	bool operator!=(const Event & rightSide) const;
	bool operator>(const Event & rightSide) const;
	bool operator<(const Event & rightSide) const;
	bool operator=(const Event & rightSide);

	bool arrival;
	int time;
	int length;
}; // end Event
#include "Event.cpp"
#endif
