#ifndef PIT_H
#define PIT_H

#include "Event.h"

class Pit : public Event {

private:

public:

	Pit();
	Pit(const Pit&);

	~Pit();

	Pit& operator=(const Pit&);

	void percept(Cave&) override;
	void encounter(Cave&) override;

};

#endif