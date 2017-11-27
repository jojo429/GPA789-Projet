#ifndef SQUIRREL_H
#define SQUIRREL_H

#include "Animals.h"
#include "Seeds.h"

class Squirrel : public Animals
{

public:
	Squirrel();
	~Squirrel();

private:
	int mGender;
	float mHunger;
	int mMaxReach;
	int mMinReach;
	Seeds *mSeed;
	void movement();
	void reproduce(int age);
	void die(int age);
	void eat();
	void pickSeed();

};

#endif //SQUIRREL_H

