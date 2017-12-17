#include "QHazel.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

GaussianTable QHazel::mPrecipitationGrowFactor(28, 5, 23);
GaussianTable QHazel::mLuminosityGrowFactor(200, 40, 20000, -100);
GaussianTable QHazel::mTemperatureGrowFactor(150, 30, 800, -75);
GaussianTable QHazel::mGrowTable(500, 0, 2000);

QHazel::QHazel(QEnvironment const & environment, QForestScene & forestscene,  int lifeSpan, treeType tree, generalType type)
	: QTrees{ environment , forestscene , lifeSpan ,tree , type }
{
	mLeafColor.setRgb(74, 125, 50);
	mTrunkColor.setRgb(107, 75, 3);
	mPen.setColor(Qt::black);
	mPen.setWidth(0.1);

}

QHazel::~QHazel()
{

}



void QHazel::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
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
	mBrush.setStyle(Qt::Dense2Pattern);
	painter->setBrush(mBrush);
	painter->drawEllipse(mCenter, mLeafRadius, mLeafRadius);

}

GaussianTable & QHazel::growTable()
{
	return mGrowTable;
}
GaussianTable & QHazel::precipirationGrowFactorTable()
{
	return mPrecipitationGrowFactor;
}
GaussianTable & QHazel::luminosityGrowFactorTable()
{
	return mLuminosityGrowFactor;
}
GaussianTable & QHazel::temperatureGrowFactorTable()
{
	return mTemperatureGrowFactor;
}
