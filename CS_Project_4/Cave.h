#ifndef CAVE_H
#define CAVE_H

#include <vector>

class Room;
class Event;

class Cave {

private:

	std::vector<Room*> rooms;
	int width, height, exit, pX, pY, arrows;
	bool running, gold_found, wumpus_alive;

public:

	Cave(int = 4, int = 4, int = 0, int = 2, int = 2);
	Cave(const Cave&);

	~Cave();

	Cave& operator=(const Cave&);

	void load(int, int, int, int, int);

	int get_width();
	int get_height();
	int get_pX();
	int get_pY();
	void set_pX(int);
	void set_pY(int);
	bool is_running();
	void set_running(bool);
	bool is_gold_found();
	void set_gold_found(bool);
	bool is_wumpus_alive();
	int get_arrows();

	Room* get_room_at(int, int);

	void print(bool = false);
	void moveX(int);
	void moveY(int);
	void check_percepts();
	void update();
	void fire_arrow_xDir(int);
	void fire_arror_yDir(int);
	void move_wumpus();

	int get_percept_value();
	int check_value(Event*);

};

#endif