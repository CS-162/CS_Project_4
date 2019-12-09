/**
**	Program: Gold Event Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the gold object class
**/
#include "Gold.h"
#include <iostream>

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Gold::Gold() : Event() {}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Gold::Gold(const Gold& copy_gold) {}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Gold::~Gold() {}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Gold& Gold::operator=(const Gold& copy_gold) {

	return *this;

}

/**
**	Function: percept
**	Description: prints the percept message
**	Parameters: cave that event is in
**/
void Gold::percept(Cave& cave) {

	if(cave.is_gold_found()) return;
		
	std::cout << "You see a glimmer nearby." << std::endl;

}

/**
**	Function: encounter
**	Description: runs the event encounter
**	Parameters: cave that event is in
**/
void Gold::encounter(Cave& cave) {

	if(cave.is_gold_found()) return;

	cave.set_gold_found(true);
	std::cout << "You picked up the gold." << std::endl;

}
