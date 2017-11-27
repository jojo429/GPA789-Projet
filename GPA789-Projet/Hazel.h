#ifndef HAZEL_H
#define HAZEL_H

#include "Trees.h"

class Hazel : public Trees
{

public:
	Hazel();
	~Hazel();
	void grow(int luminosity, int fertility, int age);

};

#endif //HAZEL_H
