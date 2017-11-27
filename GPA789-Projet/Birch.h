#ifndef BIRCH_H
#define BIRCH_H

#include "Trees.h"

class Birch : public Trees
{

public:
	Birch();
	~Birch();
	void grow(int luminosity, int fertility, int age);

};

#endif //BIRCH_H
