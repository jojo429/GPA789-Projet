#ifndef Q_SQUIRREL_H
#define Q_SQUIRREL_H

#include "QAnimals.h"
//class QSeeds;
#include <list>

class QSquirrel : public QAnimals
{

public:
	QSquirrel(QEnvironment const & environment);
	~QSquirrel();

private:
	int mGender;
	float mHunger;
	int mMaxReach;
	int mMinReach;
	void move() override;
	void reproduce(int age);
	void die(int age);
	void eat();
	void pickSeed();
	void striked() override;
	std::list<QSeeds*> mSeeds;

};

#endif //Q_SQUIRREL_H

