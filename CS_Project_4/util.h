#ifndef UTIL_H
#define UTIL_H

#include "Cave.h"

bool is_num(const char*);
int get_rand(int, int);

void debug_args(int, char**);
void handle_action(Cave&);
bool handle_restart(Cave&, int, int&, int, int);

#endif