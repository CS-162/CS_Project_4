/**
**	Program: Abstract Event Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the event object class
**/
#include "Event.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Event::Event() {}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Event::Event(const Event& copy_event) {}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Event::~Event() {}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Event& Event::operator=(const Event& copy_event) {

	return *this;

}
