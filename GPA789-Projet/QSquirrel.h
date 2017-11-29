#ifndef Q_SQUIRREL_H
#define Q_SQUIRREL_H

#include "QAnimals.h"
#include "QSeeds.h"

class QSquirrel : public QAnimals
{

public:
	QSquirrel();
	~QSquirrel();

private:
	int mGender;
	float mHunger;
	int mMaxReach;
	int mMinReach;
	QSeeds *mSeed;
	void movement();
	void reproduce(int age);
	void die(int age);
	void eat();
	void pickSeed();

};

#endif //Q_SQUIRREL_H

