#include "QTemperature.h"

QTemperature::QTemperature(int cycle, int average, int variation)
	:QCyclic(cycle, average, variation, false)
{
	


}


QTemperature::~QTemperature()
{

}

