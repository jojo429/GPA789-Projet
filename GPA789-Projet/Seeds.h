#ifndef SEEDS_H
#define SEEDS_H

#include "Dynamic.h"
#include "Trees.h"

class Seeds : public Dynamic
{

public:
	Seeds();
	~Seeds();
	void germinate(int luminosity, bool isRaining, char fertility, int age, int lifeSpan);
	void die() override;

protected:
	void move(int windAngle, int windForce);

private:
	int mHeight;
	int mWeight;
	Trees *mTree;

};

#endif //SEEDS_H

