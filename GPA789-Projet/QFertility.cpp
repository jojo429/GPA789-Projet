// QFertility.cpp
//
// Description:
// Classe représentant un facteur de fertilité généré aléatoirement pour un carte de points donnés.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QFertility.h"

QFertility::QFertility()
{
	// Crée une carte générée aléatoirement
	mFertilityMap = new QRandomMap;
}

QFertility::~QFertility()
{
	// Supprime la carte de fertilité
	delete mFertilityMap;
}

double QFertility::getFertility(int x, int y) const
{
	// Retourne la valeur de vertilité pour un point donné 
	return mFertilityMap->getMapValue(x, y); 
}

void QFertility::setFertility(double minValue, double maxValue)
{
	mFertilityMap->setMap(); // Générer la carte d'origine
	mFertilityMap->scaleValuesRangeMap(minValue, maxValue); // Redimensionner les valeurs de fertilités dans l'intervalle voulue
	mFertilityMap->drawMap(210, 105, 30); // Dessiner la carte de fertilités initiale
	mFertilityMap->resizeMap(); // Redimensionner la carte de 513x513 à 2052x2052
}

QPixmap QFertility::getFertilityPixmap()
{
	// Retourne une pixmap généré à partir des données de fertilité
	return mFertilityMap->getPixmap();
}

