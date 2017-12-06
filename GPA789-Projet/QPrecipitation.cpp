#include "QPrecipitation.h"

QPrecipitation::QPrecipitation(int cycle, int average, int variation)
	: QCyclic{ cycle, average, variation, true}
{




}

QPrecipitation::~QPrecipitation()
{

}

float QPrecipitation::germinate()
{
	return 0;
}

float QPrecipitation::grow()
{
	return 0;
}

float QPrecipitation::adjustDryness()
{
	return 0;
}

std::array<double, 3> QPrecipitation::airDisplacement()
{
	std::array<double, 3> tmp;

	return tmp;
}