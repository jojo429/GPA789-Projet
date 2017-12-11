#include "QPrecipitation.h"

QPrecipitation::QPrecipitation(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, true)
{




}


QPrecipitation::~QPrecipitation()
{

}

float QPrecipitation::germinate(int time)
{
	return mSinusTable.getValue(time);
}

float QPrecipitation::grow(int time)
{
	return mSinusTable.getValue(time);
}

float QPrecipitation::adjustDryness(int time)
{
	return mSinusTable.getValue(time);
}

std::array<double, 3> QPrecipitation::airDisplacement(int time)
{
	std::array<double, 3> tmp;

	return tmp;
}