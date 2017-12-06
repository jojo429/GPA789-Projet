#include "QBirch.h"

QBirch::QBirch(QEnvironment const & environment)
	: QTrees{ environment }
{

	mLeafRadius = 1;
	mTrunkRadius = 0.20 * mLeafRadius;

}

QBirch::~QBirch()
{

}

void QBirch::grow()
{

}

void QBirch::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
}

void QBirch::advance(int phase)
{
}

