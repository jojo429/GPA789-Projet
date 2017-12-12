#include "QFertility.h"

QFertility::QFertility()
{
	mFertilityMap = new QRandomMap;
}

QFertility::~QFertility()
{

}

double QFertility::getFertility(int x, int y)
{
	return mFertilityMap->getMapValue(x, y); 
}

void QFertility::setFertility(double minValue, double maxValue)
{
	mFertilityMap->setMap();
	mFertilityMap->scaleValuesRangeMap(minValue, maxValue);
	mFertilityMap->drawMap(264, 160, 96); 
}

void QFertility::updateFertility(int x, int y, double fertility)
{
	mFertilityMap->updateDrawMap(x, y, 264, 160, 96);
	mFertilityMap->setMapValue(x, y, fertility);
}

void QFertility:: enableFertility()
{

}

void QFertility::disableFertility()
{

}

float QFertility::germinate(int x, int y)
{
	return 0;
}

float QFertility::grow(int x, int y)
{
	return 0;
}