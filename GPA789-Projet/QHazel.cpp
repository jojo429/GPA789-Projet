#include "QHazel.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

GaussianTable QHazel::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QHazel::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QHazel::mTemperatureGrowFactor(150, 30, 1000, -75);
GaussianTable QHazel::mGrowTable(500, 10, 50000);

QHazel::QHazel(QEnvironment const & environment, treeType value)
	: QTrees{ environment, value }
{
	mLeafColor.setRgb(74, 125, 50);
	mTrunkColor.setRgb(107, 75, 3);
	mPen.setColor(Qt::black);
	mPen.setWidth(0.1);

}

QHazel::~QHazel()
{

}

void QHazel::grow()
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

//void QHazel::advance(int phase)
//{
//}
