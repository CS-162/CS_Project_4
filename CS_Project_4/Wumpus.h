#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"

class Wumpus : public Event {

private:

public:

	Wumpus();
	Wumpus(const Wumpus&);

	~Wumpus();

	Wumpus& operator=(const Wumpus&);

	void percept(Cave&) override;
	void encounter(Cave&) override;

};

#endif