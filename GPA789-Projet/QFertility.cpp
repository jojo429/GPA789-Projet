#include "QFertility.h"

QFertility::QFertility()
{
	mFertilityMap = new QRandomMap;
}

QFertility::~QFertility()
{

}

double QFertility::getFertility(int x, int y) const
{
	return mFertilityMap->getMapValue(x, y); 
}

void QFertility::setFertility(double minValue, double maxValue)
{
	mFertilityMap->setMap();
	mFertilityMap->scaleValuesRangeMap(minValue, maxValue);
	mFertilityMap->drawMap(244, 164, 96); 
}

void QFertility::updateFertility(int x, int y, double fertility)
{
	mFertilityMap->updateDrawMap(x, y);
	mFertilityMap->setMapValue(x, y, fertility);
}

void QFertility:: enableFertility()
{

}

void QFertility::disableFertility()
{

}

QPixmap QFertility::getFertilityPixmap()
{
	return mFertilityMap->getPixmap();
}

