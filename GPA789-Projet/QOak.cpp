// QOak.cpp
//
// Description:
// Classe contenant les donn�es particuli�res � un arbre de type Ch�ne.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QOak.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

// Tables de facteurs environmentaux sp�cifiques � un Ch�ne
GaussianTable QOak::mPrecipitationGrowFactor(28, 7, 70);
GaussianTable QOak::mLuminosityGrowFactor(200, 60, 11000, -100);
GaussianTable QOak::mTemperatureGrowFactor(150, 25, 900, -75);

// Tables de croissance sp�cifique � un Ch�ne
GaussianTable QOak::mGrowTable(500, 10, 50000);

QOak::QOak(QEnvironment const & environment, QForestScene & forestscene,  int lifeSpan, treeType tree, generalType type)
	: QTrees{ environment, forestscene,  lifeSpan, tree , type}
{
	// Couleurs et textures sp�cifiques � un Ch�ne
	mLeafColor.setRgb(100, 186, 63);
	mTrunkColor.setRgb(68, 49, 3);
	mPen.setColor(Qt::white);
	mPen.setWidth(0.1);

}

void QOak::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{


	//Dessine le tronc
	mBrush.setColor(mTrunkColor);
	mBrush.setStyle(Qt::SolidPattern);
	painter->setOpacity(1);
	painter->setBrush(mBrush);
	painter->setPen(mPen);
	painter->drawEllipse(mCenter, mTrunkRadius, mTrunkRadius);

	//Dessine les feuilles
	mBrush.setColor(mLeafColor);
	mBrush.setStyle(Qt::Dense5Pattern);
	painter->setBrush(mBrush);
	painter->drawEllipse(mCenter, mLeafRadius, mLeafRadius);
}

// Les quatres fonctions suivantes retournent les tables de facteurs environmentaux et de croissance du Ch�ne
GaussianTable & QOak::growTable()
{
	return mGrowTable;
}
GaussianTable & QOak::precipirationGrowFactorTable()
{
	return mPrecipitationGrowFactor;
}
GaussianTable & QOak::luminosityGrowFactorTable()
{
	return mLuminosityGrowFactor;
}
GaussianTable & QOak::temperatureGrowFactorTable()
{
	return mTemperatureGrowFactor;
}