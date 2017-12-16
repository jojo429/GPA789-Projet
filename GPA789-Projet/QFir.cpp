#include "QFir.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

GaussianTable QFir::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QFir::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QFir::mTemperatureGrowFactor(150, 30, 1000, -75);
GaussianTable QFir::mGrowTable(500, 10, 50000);

QFir::QFir(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan)
	: QTrees{ environment ,forestscene, value, lifeSpan }
{
	
	/*mLuminosityGrowFactor.set(40, 10000);
	mTemperatureGrowFactor.set(20, 900);*/
	mLeafColor.setRgb(31, 86, 33);
	mTrunkColor.setRgb(38, 43, 3);
	mPen.setColor(Qt::black);
	mPen.setWidth(0.1);
}

QFir::~QFir()
{

}


void QFir::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
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
	mBrush.setStyle(Qt::Dense1Pattern);
	painter->setBrush(mBrush);
	painter->drawEllipse(mCenter, mLeafRadius, mLeafRadius);
}

GaussianTable & QFir::growTable()
{
	return mGrowTable;
}
GaussianTable & QFir::precipirationGrowFactorTable()
{
	return mPrecipitationGrowFactor;
}
GaussianTable & QFir::luminosityGrowFactorTable()
{
	return mLuminosityGrowFactor;
}
GaussianTable & QFir::temperatureGrowFactorTable()
{
	return mTemperatureGrowFactor;
}