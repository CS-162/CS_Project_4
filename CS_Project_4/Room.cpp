/**
**	Program: Room Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the room object class
**/
#include "Room.h"
#include "util.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Room::Room() {

	event = nullptr;

}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Room::Room(const Room& copy_room) {

	if(copy_room.event != nullptr) *event = *copy_room.event;
	else event = nullptr;

}

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: room event
**/
Room::Room(Event* event) {

	this->event = event;

}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Room::~Room() {

	if(event != nullptr) delete event;

}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Room& Room::operator=(const Room& copy_room) {

	if(event != nullptr) delete event;
	*event = *copy_room.event;

	return *this;

}

/**
**	Function: get event
**	Description: gets the room event
**	Parameters: none
**/
Event* Room::get_event() {

	return event;

}

/**
**	Function: percept
**	Description: prints the event percept message
**	Parameters: cave that room is in
**/
void Room::percept(Cave& cave) {

	if(event != nullptr) event->percept(cave);

}

/**
**	Function: encounter
**	Description: runs the event encounter
**	Parameters: cave that room is in
**/
void Room::encounter(Cave& cave) {

	if(event != nullptr) event->encounter(cave);

}
