/**
**	Program: Cave Object
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of the cave object class
**/
#include "Cave.h"
#include <iostream>
#include "Bats.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Gold.h"
#include "util.h"
#include "Room.h"
#include "template_util.hpp"
#include <ctime>

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Cave::Cave(int width, int height, int seed, int num_bats, int num_pits) {
	
	load(width, height, seed, num_bats, num_pits);

}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Cave::Cave(const Cave& copy_cave) {

	width = copy_cave.width;
	height = copy_cave.height;
	exit = copy_cave.exit;
	pX = copy_cave.pX;
	pY = copy_cave.pY;
	running = copy_cave.running;
	gold_found = copy_cave.gold_found;
	wumpus_alive = copy_cave.wumpus_alive;
	arrows = copy_cave.arrows;

	for(int i = 0; i < copy_cave.rooms.size(); i++) 
		rooms.push_back(new Room(*copy_cave.rooms.at(i)));

}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Cave::~Cave() {

	for(auto* room : rooms) delete room;
	rooms.clear();

}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Cave& Cave::operator=(const Cave& copy_cave) {

	width = copy_cave.width;
	height = copy_cave.height;
	exit = copy_cave.exit;
	pX = copy_cave.pX;
	pY = copy_cave.pY;
	running = copy_cave.running;
	gold_found = copy_cave.gold_found;
	wumpus_alive = copy_cave.wumpus_alive;
	arrows = copy_cave.arrows;

	for(auto* room : rooms) delete room;
	rooms.clear();
	for(int i = 0; i < copy_cave.rooms.size(); i++)
		rooms.push_back(new Room(*copy_cave.rooms.at(i)));

	return *this;

}

/**
**	Function: load
**	Description: loads the cave with rooms
**	Parameters: width, height, generation seed, number of bats, number of pits
**/
void Cave::load(int width, int height, int seed, int num_bats, int num_pits) {

	this->width = width;
	this->height = height;
	running = true;
	gold_found = false;
	wumpus_alive = true;
	arrows = 3;

	if(rooms.size() > 0) {
		for(auto* room : rooms) delete room;
		rooms.clear();
	}

	if(num_bats + num_pits + 3 > width* height) num_bats = num_pits = 2;

	srand(seed);

	rooms.push_back(new Room(new Wumpus()));
	rooms.push_back(new Room(new Gold()));
	for(int i = 0; i < num_bats; i++) rooms.push_back(new Room(new Bats()));
	for(int i = 0; i < num_pits; i++) rooms.push_back(new Room(new Pit()));
	for(int i = 0; i < width * height - (2 + num_bats + num_pits); i++) rooms.push_back(new Room());

	shuffle(rooms);

	do {
		exit = get_rand(0, width * height - 1);
		pX = exit % width;
		pY = exit / width;
	} while(get_room_at(pX, pY)->get_event() != nullptr);

	srand(time(0));

}

/**
**	Function: get width
**	Description: gets width
**	Parameters: none
**/
int Cave::get_width() {

	return width;

}

/**
**	Function: get height
**	Description: gets height
**	Parameters: none
**/
int Cave::get_height() {

	return height;

}

int Cave::get_pX() {

	return pX;

}

int Cave::get_pY() {
	return pY;
}

/**
**	Function: set pX
**	Description: sets player x
**	Parameters: new pX
**/
void Cave::set_pX(int pX) {

	this->pX = pX;

}

/**
**	Function: set pY
**	Description: sets player y
**	Parameters: new pY
**/
void Cave::set_pY(int) {

	this->pY = pY;

}

/**
**	Function: is running
**	Description: gets running boolean
**	Parameters: none
**/
bool Cave::is_running() {

	return running;

}

/**
**	Function: set running
**	Description: sets running boolean
**	Parameters: new running boolean
**/
void Cave::set_running(bool running) {

	this->running = running;

}

/**
**	Function: is gold found
**	Description: gets gold found boolean
**	Parameters: none
**/
bool Cave::is_gold_found() {

	return gold_found;

}

/**
**	Function: set gold found
**	Description: sets gold found boolean
**	Parameters: new gold found boolean 
**/
void Cave::set_gold_found(bool gold_found) {

	this->gold_found = gold_found;

}

/**
**	Function: is wumpus alive
**	Description: gets wumpus alive boolean
**	Parameters: none
**/
bool Cave::is_wumpus_alive() {

	return wumpus_alive;

}

/**
**	Function: get arrows
**	Description: gets arrow count
**	Parameters: none
**/
int Cave::get_arrows() {

	return arrows;

}

/**
**	Function: get room at
**	Description: gets room at x, y coordinates
**	Parameters: x coordinate, y coordinate
**/
Room* Cave::get_room_at(int x, int y) {

	if(x < 0 || x >= width || y < 0 || y >= height) return nullptr;
	return rooms.at(x + y * width);

}

/**
**	Function: print
**	Description: prints cave map
**	Parameters: debug mode boolean
**/
void Cave::print(bool debug) {

	for(int j = 0; j < height; j++)  for(int k = 0; k < 4; k++) {

		for(int i = 0; i < width; i++) {

			if(k == 0) {
				std::cout << "+---";
				if(i == width - 1) std::cout << "+";
			} else if(k == 1) {
				std::cout << "|";
				if(debug) {
					if(i + j * width == exit) std::cout << " E ";
					else if(get_room_at(i, j)->get_event() == nullptr) std::cout << "   ";
					else if(dynamic_cast<Bats*>(get_room_at(i, j)->get_event()) != nullptr)
						std::cout << " B ";
					else if(dynamic_cast<Pit*>(get_room_at(i, j)->get_event()) != nullptr)
						std::cout << " P ";
					else if(wumpus_alive && dynamic_cast<Wumpus*>(get_room_at(i, j)->get_event()) != nullptr)
						std::cout << " W ";
					else if(!gold_found && dynamic_cast<Gold*>(get_room_at(i, j)->get_event()) != nullptr)
						std::cout << " G ";
					else std::cout << "   ";
				} else std::cout << "   ";
				if(i == width - 1) std::cout << "|";
			} else if(k == 2 && i == pX && j == pY) {
				std::cout << "| * ";
				if(i == width - 1) std::cout << "|";
			} else {
				std::cout << "|   ";
				if(i == width - 1) std::cout << "|";
			}

		}
			
		std::cout << std::endl;

	}

	for(int i = 0; i < width; i++) {

		std::cout << "+---";
		if(i == width - 1)  std::cout << "+" << std::endl;

	}

}

/**
**	Function: move y
**	Description: changes player x
**	Parameters: x change
**/
void Cave::moveX(int dX) {

	if(pX + dX < 0 || pX + dX >= width) return;
	pX += dX;

}

/**
**	Function: move y
**	Description: changes player y
**	Parameters: y change
**/
void Cave::moveY(int dY) {

	if(pY + dY < 0 || pY + dY >= height) return;
	pY += dY;

}

/**
**	Function: check percepts
**	Description: checks for percepts around the player
**	Parameters: none
**/
void Cave::check_percepts() {

	if(pX > 0) get_room_at(pX - 1, pY)->percept(*this);
	if(pX < width - 1) get_room_at(pX + 1, pY)->percept(*this);
	if(pY > 0) get_room_at(pX, pY - 1)->percept(*this);
	if(pY < height - 1) get_room_at(pX, pY + 1)->percept(*this);

}

/**
**	Function: update
**	Description: updates encounters and game state
**	Parameters: none
**/
void Cave::update() {

	if(exit == pX + pY * width && gold_found) {
		std::cout << "You win!" << std::endl;
		running = false;
	}
	get_room_at(pX, pY)->encounter(*this);

}

/**
**	Function: fire arrow in x direction
**	Description: fires an arrow left or right
**	Parameters: x direction
**/
void Cave::fire_arrow_xDir(int xDir) {

	if(arrows <= 0) {
		std::cout << "Out of arrows." << std::endl;
		return;
	}

	if(!wumpus_alive) {
		std::cout << "The arrow missed." << std::endl;
		return;
	}

	bool hit = false;
	if(xDir == 1) {
		std::cout << "You fire an arrow east." << std::endl;
		for(int i = 1; !hit && i <= 3; i++)
			if(get_room_at(pX + i, pY) != nullptr && 
				dynamic_cast<Wumpus*>(get_room_at(pX + i, pY)->get_event()) != nullptr)  hit = true;
	} else if(xDir == -1) {
			std::cout << "You fire an arrow west." << std::endl;
			for(int i = 1; !hit && i <= 3; i++)
				if(get_room_at(pX - i, pY) != nullptr &&
					dynamic_cast<Wumpus*>(get_room_at(pX - i, pY)->get_event()) != nullptr)  hit = true;
	}

	if(hit) {
		wumpus_alive = false;
		std::cout << "The wumpus has been killed." << std::endl;
	} else {
		std::cout << "The arrow missed." << std::endl;
		if(get_rand(0, 3) >= 2) move_wumpus();
	}

	arrows--;
	
}

/**
**	Function: fire arrow in y direction
**	Description: fires an arrow up or down
**	Parameters: y direction
**/
void Cave::fire_arror_yDir(int yDir) {

	if(arrows <= 0) {
		std::cout << "Out of arrows." << std::endl;
		return;
	}

	if(!wumpus_alive) {
		std::cout << "The arrow missed." << std::endl;
		return;
	}

	bool hit = false;
	if(yDir == 1) {
		std::cout << "You fire an arrow south." << std::endl;
		for(int i = 1; !hit && i <= 3; i++)
			if(get_room_at(pX, pY + i) != nullptr &&
				dynamic_cast<Wumpus*>(get_room_at(pX, pY + i)->get_event()) != nullptr)  hit = true;
	} else if(yDir == -1) {
		std::cout << "You fire an arrow north." << std::endl;
		for(int i = 1; !hit && i <= 3; i++)
			if(get_room_at(pX, pY - i) != nullptr &&
				dynamic_cast<Wumpus*>(get_room_at(pX, pY - i)->get_event()) != nullptr)  hit = true;
	}

	if(hit) {
		wumpus_alive = false;
		std::cout << "The wumpus has been killed." << std::endl;
	} else {
		std::cout << "The arrow missed." << std::endl;
		if(get_rand(0, 3) >= 2) move_wumpus();
	}

	arrows--;

}

/**
**	Function: move wumpus
**	Description: moves wumpus to a random empty room
**	Parameters: none
**/
void Cave::move_wumpus() {
	
	int current_i = -1, target_i = -1;
	for(int i = 0; current_i == -1 && i < width * height; i++)
		if(rooms.at(i)->get_event() != nullptr && dynamic_cast<Wumpus*>(rooms.at(i)->get_event()) != nullptr)
			current_i = i;
	do {
		target_i = get_rand(0, width * height - 1);
	} while(rooms.at(target_i) == nullptr || rooms.at(target_i)->get_event() != nullptr);

	swap(rooms.at(current_i), rooms.at(target_i));

	std::cout << "The wumpus has hidden in a new location." << std::endl;

}

int Cave::get_percept_value() {

	int total = 0;
	if(get_room_at(pX + 1, pY) != nullptr) total += check_value(get_room_at(pX + 1, pY)->get_event());
	if(get_room_at(pX - 1, pY) != nullptr) total += check_value(get_room_at(pX - 1, pY)->get_event());
	if(get_room_at(pX, pY + 1) != nullptr) total += check_value(get_room_at(pX, pY + 1)->get_event());
	if(get_room_at(pX, pY - 1) != nullptr) total += check_value(get_room_at(pX, pY - 1)->get_event());

	return total;
		
}

int Cave::check_value(Event* e) {

	if(e == nullptr) return 0;
	else if(dynamic_cast<Wumpus*>(e) != nullptr) return -2;
	else if(dynamic_cast<Pit*>(e) != nullptr) return -2;
	else if(dynamic_cast<Bats*>(e) != nullptr) return -1;
	else if(dynamic_cast<Gold*>(e) != nullptr) return 1;

	return 0;

}
