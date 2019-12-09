/**
**	Program: Bats Event Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the bat object class
**/
#include "Bats.h"
#include <iostream>
#include "util.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Bats::Bats() : Event() {}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Bats::Bats(const Bats& copy_bats) {}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Bats::~Bats() {}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Bats& Bats::operator=(const Bats& copy_bats) {

	return *this;

}

/**
**	Function: percept
**	Description: prints the percept message
**	Parameters: cave that event is in
**/
void Bats::percept(Cave& cave) {

	std::cout << "You hear wings flapping." << std::endl;

}

/**
**	Function: encounter
**	Description: runs the event encounter
**	Parameters: cave that event is in
**/
void Bats::encounter(Cave& cave) {

	cave.set_pX(get_rand(0, cave.get_width() - 1));
	cave.set_pY(get_rand(0, cave.get_height() - 1));
	std::cout << "Giant bats have carried you to a new room." << std::endl;
	cave.update();

}
