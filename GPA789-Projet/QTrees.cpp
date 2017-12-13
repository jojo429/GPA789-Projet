#include "QTrees.h"
#include <QBrush>
#include <QPainter>

QTrees::QTrees(QEnvironment const & environment)
	: QStatic(environment)
{

	
	mLeafRadius = 1;
	mTrunkRadius = 0.1 * mLeafRadius;
	mMasterTree = this;

}

QTrees::~QTrees()
{

}

void QTrees::grow()
{

}

void QTrees::reproduce()
{

}

void QTrees::die()
{

}

int QTrees::getHeight()
{
	return 0;
}

void QTrees::adjustDryness()
{

}

void QTrees::setOnFire()
{

}


void QTrees::striked()
{

}

void QTrees::setMasterTree(QTrees * tree)
{
	mMasterTree = tree;


}

QRectF QTrees::boundingRect() const
{
	
	return QRectF(0-mLeafRadius,0-mLeafRadius, mLeafRadius*2, mLeafRadius*2);
}


void QTrees::advance(int phase)
{
	if (mLeafRadius < 50) {
		mLeafRadius = mLeafRadius + 0.10*(rand() % 2 + 1);
		mTrunkRadius = 0.20 * mLeafRadius;
		update(boundingRect());
	}
	else {
		update();
	}

}

