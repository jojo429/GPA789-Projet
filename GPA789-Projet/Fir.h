#ifndef FIR_H
#define FIR_H

#include "Trees.h"

class Fir : public Trees
{

public:
	Fir();
	~Fir();
	void grow(int luminosity, int fertility, int age);

};

#endif //FIR_H
