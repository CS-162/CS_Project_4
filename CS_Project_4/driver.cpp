/**
**	Program: Driver File
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Program driver
**/
#include <iostream>
#include <string>
#include "util.h"
#include "Cave.h"
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

/**
**	Function: main function
**	Description: driver function
**	Parameters: number of program arguments, program arguments
**/
int main(int argc, char* argv[]) {

	bool debug = false, game_running = true;

	debug_args(argc, argv);
	
	srand(time(0));
	int seed = ((argc > 3 && is_num(argv[3])) ? atoi(argv[3]) : rand());
	int num_bats = ((argc > 4 && is_num(argv[4])) ? atoi(argv[4]) : 2);
	int num_pits = ((argc > 5 && is_num(argv[5])) ? atoi(argv[5]) : 2);
	int size = atoi(argv[1]);
	Cave cave(size, size, seed, num_bats, num_pits);

	if(string(argv[2]) == "true") {
		debug = true;
		cout << "Running game with debug funtions on." << endl;
	}

	while(game_running) {

		cout << "\nGame seed : " << seed << endl;

		while(cave.is_running()) {
			cave.print(debug);
			handle_action(cave);
			cave.update();
		}

		game_running = handle_restart(cave, size, seed, num_bats, num_pits);
	
	}

	cout << "\nGame ended." << endl;
	
	return 0;

}