#include "QWind.h"

QWind::QWind(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, true)
{



}

QWind::~QWind()
{

}

float QWind::adjustDryness(int time)
{
	return mSinusTable.getValue(time);
}

std::array<double, 3> QWind::airDisplacement(int time)
{
	std::array<double, 3> tmp;

	return tmp;
}