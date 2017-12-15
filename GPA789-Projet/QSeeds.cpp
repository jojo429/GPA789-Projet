#include "QSeeds.h"
#include "QTrees.h"
//////
#include "QOak.h"
#include "QFir.h"
#include "QBirch.h"
#include "QHazel.h"
///////
#include <QBrush>
#include <QPainter>
#include <array>

QSeeds::QSeeds(QEnvironment const & environment, QForestScene & forestscene, treeType value)
	: QDynamic{ environment,forestscene }, mTreeType{value}
{


}

QSeeds::~QSeeds()
{

}

void QSeeds::germinate()
{
	//Comment le faire?	
	//QTrees * newTree = new QTrees(mMasterTree);
}

void QSeeds::die()
{
	
}

bool QSeeds::isItDead()
{
	return false;
}

void QSeeds::move()
{
	/*std::array<double, 2> movingVector;
	movingVector = mEnvironment.getAirDisplacement();
	moveBy(movingVector[0] * mMovingFactor, movingVector[1] * mMovingFactor);
	mCountFallDown++;
	update();*/
}

void QSeeds::piked()
{
	setVisible(false);
}

void QSeeds::droped( QPointF coordinate )
{
	setPos(coordinate);
	setVisible(true);
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
	if (mCountFallDown < 50) {
		mMovingFactor = 1.3;
		move();
	}
}

