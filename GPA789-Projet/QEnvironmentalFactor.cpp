#include "QEnvironmentalFactor.h"

QEnvironmentalFactor::QEnvironmentalFactor(QGraphicsItem * parent)
	: QGraphicsItem(parent)
{

}

QEnvironmentalFactor::~QEnvironmentalFactor()
{

}

float QEnvironmentalFactor::germinate()
{
	return 0;
}

float QEnvironmentalFactor::grow()
{
	return 0;
}

float QEnvironmentalFactor::adjustDryness()
{
	return 0;
}

std::array<double, 3> QEnvironmentalFactor::airDisplacement()
{
	std::array<double, 3> tmp;
	
	return tmp;
}