#ifndef OAK_H
#define OAK_H

#include "Trees.h"

class Oak : public Trees
{

public:
	Oak();
	~Oak();
	void grow(int luminosity, int fertility, int age);
};

#endif //OAK_H
