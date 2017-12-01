#include "QTemperature.h"

QTemperature::QTemperature(int cycle, int average, int variation)
	: QCyclic{ cycle, average, variation }
{

}

QTemperature::~QTemperature()
{

}

float QTemperature::germinate()
{
	return 0;
}

float QTemperature::grow()
{
	return 0;
}

float QTemperature::adjustDryness()
{
	return 0;
}
