#include "QBirch.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

GaussianTable QBirch::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QBirch::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QBirch::mTemperatureGrowFactor(150, 30, 1000, -75);
GaussianTable QBirch::mGrowTable(500, 10, 50000);

QBirch::QBirch(QEnvironment const & environment,  QForestScene & forestscene, treeType value)
	: QTrees{ environment ,forestscene, value}
{

	mLeafColor.setRgb(85, 200, 25);
	mTrunkColor.setRgb(210, 216, 205);
	mPen.setColor(Qt::black);
	mPen.setWidthF(0.1);

}

QBirch::~QBirch()
{

}

void QBirch::grow()
{

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

//void QBirch::advance(int phase)
//{
//}

