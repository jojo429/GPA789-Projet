#include "QLuminosity.h"
#include "DoubleSinusTable.h"

QLuminosity::QLuminosity(int cycle, int average, int variation, int baseVariation)
	: QCyclic(cycle, average, variation)
{
	/*int year = 2190;
	static_cast<DoubleSinusTable> (QLuminosity::mSinusTable);
	mSinusTable.initialize(cycle, average, variation, baseVariation);*/
}



QLuminosity::~QLuminosity()
{

}

float QLuminosity::germinate(int time)
{
	return mSinusTable.getValue(time);
}

float QLuminosity::grow(int time)
{
	return mSinusTable.getValue(time);
}
