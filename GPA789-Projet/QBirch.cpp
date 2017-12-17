// QBirch.cpp
//
// Description:
// Classe contenant les données particulières à un arbre de type Bouleau.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QBirch.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

// Tables de facteurs environmentaux spécifiques à un bouleau
GaussianTable QBirch::mPrecipitationGrowFactor(28, 8 , 28);
GaussianTable QBirch::mLuminosityGrowFactor(200, 70, 8000, -100);
GaussianTable QBirch::mTemperatureGrowFactor(150, 30, 1200, -75);

// Table de croissance en fonction de l'âge d'un bouleau
GaussianTable QBirch::mGrowTable(500, 0, 1000);


QBirch::QBirch(QEnvironment const & environment,  QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QTrees{ environment ,forestscene,lifeSpan, tree, type}
{
	// Couleurs et textures spécifiques à un bouleau
	mLeafColor.setRgb(85, 200, 25);
	mTrunkColor.setRgb(210, 216, 205);
	mPen.setColor(Qt::black);
	mPen.setWidthF(0.1);

}

void QBirch::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	//Dessine le tronc
	mBrush.setColor(mTrunkColor);
	mBrush.setStyle(Qt::SolidPattern);
	painter->setOpacity(1);
	painter->setBrush(mBrush);
	painter->setPen(mPen);
	painter->drawEllipse(mCenter, mTrunkRadius, mTrunkRadius);

	//Dessine les feuilles
	mPen.setColor(Qt::white);
	mBrush.setColor(mLeafColor);
	mBrush.setStyle(Qt::Dense4Pattern);
	painter->setBrush(mBrush);
	painter->drawEllipse(mCenter, mLeafRadius, mLeafRadius);

}

// Les quatres fonctions suivantes retournent les tables de facteurs environmentaux et de croissance du bouleau
GaussianTable & QBirch::growTable()
{
	return mGrowTable;
}
GaussianTable & QBirch::precipirationGrowFactorTable()
{
	return mPrecipitationGrowFactor;
}
GaussianTable & QBirch::luminosityGrowFactorTable()
{
	return mLuminosityGrowFactor;
}
GaussianTable & QBirch::temperatureGrowFactorTable()
{
	return mTemperatureGrowFactor;
}

