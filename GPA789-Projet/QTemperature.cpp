#include "QTemperature.h"

QTemperature::QTemperature()
{
	


}


void QTemperature::Initialize(int cycle, int average, int variation)
{
	QCyclic::Initialize(cycle, average, variation);


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
