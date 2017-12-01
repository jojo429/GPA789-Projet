#ifndef Q_ENVIRONMENT_H
#define Q_ENVIRONMENT_H

#include <list>
#include <array>
#include "QEnvironmentalFactor.h"
class QSeeds;
class QTrees;

class QEnvironment
{

public:
	QEnvironment();
	~QEnvironment();
	void germinate(QSeeds &seeds);
	void grow(QTrees &trees);
	void adjustDryness(QTrees &trees);
	void airDisplacement(QSeeds &seeds);
	std::list<float> getGerminate();
	std::list<float> getGrow();
	std::list<float> getAdjustDryness();
	std::array<double,2> getAirDisplacement();

private:
	std::list<QEnvironmentalFactor> mEnvironmentalFactor;

};

#endif //Q_ENVIRONMENT_H

