#include "QEnvironment.h"
#include "QSeeds.h"
#include "QTrees.h"

QEnvironment::QEnvironment()
{

}

QEnvironment::~QEnvironment()
{

}

void QEnvironment::germinate(QSeeds &seeds)
{

}


void QEnvironment::grow(QTrees &trees)
{

}

void QEnvironment::adjustDryness(QTrees &trees)
{

}

void QEnvironment::airDisplacement(QSeeds &seeds)
{

}

std::list<float> QEnvironment::getGerminate() const
{
	std::list<float> tmp;

	return tmp;
}

std::list<float> QEnvironment::getGrow() const
{
	std::list<float> tmp;

	return tmp;
}

std::list<float> QEnvironment::getAdjustDryness() const
{
	std::list<float> tmp;

	return tmp;
}

std::array<double, 2> QEnvironment::getAirDisplacement() const
{
	std::array<double, 2> tmp;

	return tmp;
}
