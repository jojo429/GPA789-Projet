#include "QSeeds.h"
#include "QTrees.h"
//////
#include "QOak.h"
#include "QFir.h"
#include "QBirch.h"
#include "QHazel.h"
//////
#include <QBrush>
#include <QPainter>
#include <array>

QSeeds::QSeeds(QEnvironment const & environment) 
	: QDynamic{ environment }
{

}

QSeeds::~QSeeds()
{

}

void QSeeds::initialize(QEnvironment const & enviromnent)
{
	int treeKind;

//	switch ( treeKind ) 
//	{
//		case 0 :
////			QTrees *newTree = new QOak(enviromnent);
//			break;
//		case 1 :
////			QTrees *newTree = new QBirch(enviromnent);
//			break;
//		case 2 :
////			QTrees *newTree = new QHazel(enviromnent);
//			break;
//		case 3 :
////			QTrees *newTree = new QFir(enviromnent);
//			break;
//		default :
////			QTrees *newTree = new QOak(enviromnent);
//	}
}

void QSeeds::germinate()
{
	
}

void QSeeds::die()
{

}

void QSeeds::move()
{

}

QRectF QSeeds::boundingRect() const
{
	//QRectF(qreal x, qreal y, qreal width, qreal height)
	//return QRectF(0.0 - mSeedRadius, 0.0 - mSeedRadius, mSeedRadius * 2.0, mSeedRadius * 2.0);
	return QRectF(0.0 - mSeedRadius, 0.0 - (mSeedRadius - mSeedRadius * 0.5), mSeedRadius, mSeedRadius - mSeedRadius * 0.5);
}

void QSeeds::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QBrush brush(Qt::black);
	QPen pen = QPen(Qt::black, 2);
	QPointF center = QPointF(0, 0);

	//Dessine les graines
	painter->setBrush(brush);
	painter->setPen(pen);
	painter->drawEllipse(center, mSeedRadius, mSeedRadius - mSeedRadius * 0.5);
}

void QSeeds::advance(int phase)
{
	std::array<double, 2> movingVector;
	double movingFactor{ 1.3 };

	if (mCountFallDown < 50) {
		movingVector = mEnvironment.getAirDisplacement();
		moveBy(movingVector[0] * movingFactor,movingVector[1] * movingFactor);
		mCountFallDown++;
	}
	update();
}

