#ifndef EVENT_H
#define EVENT_H

#include "Cave.h"

class Event {

private:

public:

	Event();
	Event(const Event&);

	virtual ~Event();

	Event& operator=(const Event&);

	virtual void percept(Cave&) = 0;
	virtual void encounter(Cave&) = 0;

};

#endif