/**
**	Program: Utility
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Implementation of utility functions
**/
#include "util.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/**
**	Function: is number
**	Description: checks if string is a valid number
**	Parameters: string to check
**/
bool is_num(const char* str) {

	for(int i = (str[0] == '-' ? 1 : 0); str[i] != '\0'; i++) 
		if(str[i] < '0' || str[i] > '9') return false;

	return true;

}

/**
**	Function: debug argumnets
**	Description: checks program arguments
**	Parameters: number of arguments, program arguments
**/
void debug_args(int argc, char** argv) {

	if(argc < 3) {
		cerr << "Error: not enough arguments." << endl;
		exit(1);
	} else if(!is_num(argv[1])) {
		cerr << "Error: cave size argument is not a number." << endl;
		exit(2);
	} else if(atoi(argv[1]) < 4) {
		cerr << "Error: cave size is less than 4." << endl;
		exit(3);
	} else if(string(argv[2]) != "true" && string(argv[2]) != "false") {
		cerr << "Error: debug argument must be either \"true\" or \"false\"." << endl;
		exit(4);
	}

}

/**
**	Function: handle restart
**	Description: handles program restart
**	Parameters: cave, cave size, game seed, number of bats, number of pits
**/
bool handle_restart(Cave& cave, int size, int& seed, int num_bats, int num_pits) {

	string c;
	do {
		std::cout << "Play again? (y/n): ";
		getline(cin, c);
		if(c == "y") {
			cout << "Keep current cave? (y/n): ";
			do {
				getline(cin, c);
				if(c == "y") cave.load(size, size, seed, num_bats, num_pits);
				else if(c == "n") {
					seed = rand();
					cave.load(size, size, seed, num_bats, num_pits);
				} else cout << "Error: invalid choice. Enter again:";
			} while(c != "y" && c != "n");
		} else if(c == "n") return false;
		else cout << "Error: invalid choice. Enter again:";
	} while(c != "y" && c != "n");

	return true;

}

/**
**	Function: handle action
**	Description: handles player actions
**	Parameters: current cave
**/
void handle_action(Cave& cave) {

	string action;
	cout << "Enter action: ";
	getline(cin, action);
	if(action == "w") cave.moveY(-1);
	else if(action == "a") cave.moveX(-1);
	else if(action == "s") cave.moveY(1);
	else if(action == "d") cave.moveX(1);
	else if(action == "quit") cave.set_running(false);
	else if(action == " a") cave.fire_arrow_xDir(-1);
	else if(action == " d") cave.fire_arrow_xDir(1);
	else if(action == " w") cave.fire_arror_yDir(-1);
	else if(action == " s") cave.fire_arror_yDir(1);
	else cout << "Invalid action.";
	cout << endl;

}

/**
**	Function: get random
**	Description: gets random numer between specified bounds
**	Parameters: first bounds, second bounds
**/
int get_rand(int a, int b) {

	int min = (a < b ? a : b), max = (b > a ? b : a);
	return rand() % (max - min + 1) + min;

}
