// QFertility.cpp
//
// Description:
// Classe repr�sentant un facteur de fertilit� g�n�r� al�atoirement pour un carte de points donn�s.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QFertility.h"

QFertility::QFertility()
{
	// Cr�e une carte g�n�r�e al�atoirement
	mFertilityMap = new QRandomMap;
}

QFertility::~QFertility()
{
	// Supprime la carte de fertilit�
	delete mFertilityMap;
}

double QFertility::getFertility(int x, int y) const
{
	// Retourne la valeur de vertilit� pour un point donn� 
	return mFertilityMap->getMapValue(x, y); 
}

void QFertility::setFertility(double minValue, double maxValue)
{
	mFertilityMap->setMap(); // G�n�rer la carte d'origine
	mFertilityMap->scaleValuesRangeMap(minValue, maxValue); // Redimensionner les valeurs de fertilit�s dans l'intervalle voulue
	mFertilityMap->drawMap(210, 105, 30); // Dessiner la carte de fertilit�s initiale
	mFertilityMap->resizeMap(); // Redimensionner la carte de 513x513 � 2052x2052
}

QPixmap QFertility::getFertilityPixmap()
{
	// Retourne une pixmap g�n�r� � partir des donn�es de fertilit�
	return mFertilityMap->getPixmap();
}

