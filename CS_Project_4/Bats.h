#ifndef BATS_H
#define BATS_H

#include "Event.h"

class Bats : public Event {

private:

public:

	Bats();
	Bats(const Bats&);

	~Bats();

	Bats& operator=(const Bats&);

	void percept(Cave&) override;
	void encounter(Cave&) override;

};

#endif