#ifndef Q_SEEDS_H
#define Q_SEEDS_H

#include "QDynamic.h"
#include "QTrees.h"

class QSeeds : public QDynamic
{

public:
	QSeeds();
	~QSeeds();
	void germinate(int luminosity, bool isRaining, char fertility, int age, int lifeSpan);
	void die() override;

protected:
	void move(int windAngle, int windForce);

private:
	int mHeight;
	int mWeight;
	QTrees *mTree;

};

#endif //Q_SEEDS_H

