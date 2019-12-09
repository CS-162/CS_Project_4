/**
**	Program: Pit Event Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the pit object class
**/
#include "Pit.h"
#include <iostream>

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Pit::Pit() : Event() {}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Pit::Pit(const Pit& copy_pit) {}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Pit::~Pit() {}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Pit& Pit::operator=(const Pit& copy_pit) {

	return *this;

}

/**
**	Function: percept
**	Description: prints the percept message
**	Parameters: cave that event is in
**/
void Pit::percept(Cave& cave) {

	std::cout << "You feel a breeze." << std::endl;

}

/**
**	Function: encounter
**	Description: runs the event encounter
**	Parameters: cave that event is in
**/
void Pit::encounter(Cave& cave) {

	cave.set_running(false);
	std::cout << "You fell into a pit." << std::endl;

}
