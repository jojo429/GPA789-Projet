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
	mFertilityMap->setMap(); // G�n�rer la carte d'origine
	mFertilityMap->scaleValuesRangeMap(minValue, maxValue); // Redimensionner les valeurs de fertilit�s dans l'intervalle voulue
	mFertilityMap->drawMap(210, 105, 30); // Dessiner la carte de fertilit�s initiale
	mFertilityMap->resizeMap(); // Redimensionner la carte de 513x513 � 2052x2052
}

void QFertility::updateFertility(int x, int y, double fertility)
{
	mFertilityMap->updateDrawMap(x, y); // Mise � jour du dessin de la carte de fertilit�s
	mFertilityMap->setMapValue(x, y, fertility); // Mise � jour du tableau de valeurs de fertilit�s
}

QPixmap QFertility::getFertilityPixmap()
{
	return mFertilityMap->getPixmap();
}

