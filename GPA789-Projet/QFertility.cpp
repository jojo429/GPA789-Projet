#include "QFertility.h"

QFertility::QFertility()
{
	mFertilityMap = new QRandomMap;
}

QFertility::~QFertility()
{
	delete mFertilityMap;
}

double QFertility::getFertility(int x, int y) const
{
	return mFertilityMap->getMapValue(x, y); 
}

void QFertility::setFertility(double minValue, double maxValue)
{
	mFertilityMap->setMap();
	mFertilityMap->scaleValuesRangeMap(minValue, maxValue);
	mFertilityMap->drawMap(210, 105, 30);
}

void QFertility::updateFertility(int x, int y, double fertility)
{
	mFertilityMap->updateDrawMap(x, y);
	mFertilityMap->setMapValue(x, y, fertility);
}


QPixmap QFertility::getFertilityPixmap()
{
	return mFertilityMap->getPixmap();
}

