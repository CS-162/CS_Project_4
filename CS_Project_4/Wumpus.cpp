/**
**	Program: Wumpus Event Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the wumpus object class
**/
#include "Wumpus.h"
#include <iostream>

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Wumpus::Wumpus() : Event() {}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Wumpus::Wumpus(const Wumpus& copy_wumpus) {}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Wumpus::~Wumpus() {}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Wumpus& Wumpus::operator=(const Wumpus& copy_wumpus) {

	return *this;

}

/**
**	Function: percept
**	Description: prints the percept message
**	Parameters: cave that event is in
**/
void Wumpus::percept(Cave& cave) {

	std::cout << "You smell a terrible stench." << std::endl;

}

/**
**	Function: encounter
**	Description: runs the event encounter
**	Parameters: cave that event is in
**/
void Wumpus::encounter(Cave& cave) {

	if(!cave.is_wumpus_alive()) return;

	cave.set_running(false);
	std::cout << "You have been eaten by the wumpus." << std::endl;

}
