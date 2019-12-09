/**
**	Program: Template Utility
**	Author: Austin Chayka
**	Date: 11.20.2019
**	Description: Definition and implementation of template utility functions
**/
#ifndef TEMPLATE_UTIL_HPP
#define TEMPLATE_UTIL_HPP

#include <vector>

/**
**	Function: shuffle
**	Description: randomizes the order of items in a vector
**	Parameters: vector to randomize
**/
template <typename T>
void shuffle(std::vector<T>& vect) {
	
	std::vector<T> temp;
	while(vect.size() > 0) {
		int i = rand() % vect.size();
		temp.push_back(vect.at(i));
		vect.erase(vect.begin() + i);
	}

	vect = temp;

}

/**
**	Function: swap
**	Description: swaps to items
**	Parameters: first item, second item
**/
template <typename T>
void swap(T& a, T& b) {

	T temp(a);
	a = b;
	b = temp;

}

#endif