#include "QWind.h"

QWind::QWind(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, true)
{



}

QWind::~QWind()
{

}

float QWind::adjustDryness()
{
	return 0;
}

std::array<double, 3> QWind::airDisplacement()
{
	std::array<double, 3> tmp;

	return tmp;
}