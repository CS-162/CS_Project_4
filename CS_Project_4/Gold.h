#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

class Gold : public Event {

private:

public:

	Gold();
	Gold(const Gold&);

	~Gold();

	Gold& operator=(const Gold&);

	void percept(Cave&) override;
	void encounter(Cave&) override;

};

#endif