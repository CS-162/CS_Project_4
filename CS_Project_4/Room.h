#ifndef ROOM_H
#define ROOM_H

#include "Event.h"
#include "Cave.h"

class Room {

private:

	Event* event;

public:

	Room();
	Room(const Room&);
	Room(Event*);

	~Room();

	Room& operator=(const Room&);

	Event* get_event();

	void percept(Cave&);
	void encounter(Cave&);

};

#endif