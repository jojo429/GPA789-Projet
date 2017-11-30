#include "QTrees.h"
#include <QBrush>
#include <QPainter>
QTrees::QTrees()
{

	mLeafRadius = 50;
	mTrunkRadius = 10;

}

QTrees::~QTrees()
{

}

void QTrees::grow(int luminosity, int fertility, int age)
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

void QTrees::adjustDryness(bool isRaining)
{

}

void QTrees::setOnFire(bool gotHit, int dryness)
{

}

QRectF QTrees::boundingRect() const
{

	return QRectF(0,0,mLeafRadius, mLeafRadius);
}

void QTrees::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QBrush brush(Qt::green);
	QPen pen = QPen(Qt::white, 2);
	QColor darkGreen = QColor(100, 186, 63);
	QColor darkBrown = QColor(86, 75, 52);
	QPointF center = QPointF(0, 0);

	//Dessine le tronc
	brush.setColor(darkBrown);
	brush.setStyle(Qt::SolidPattern);
	painter->setBrush(brush);
	painter->setPen(pen);
	painter->drawEllipse(center,mTrunkRadius,mTrunkRadius);
	//Dessine les feuilles
	brush.setColor(darkGreen);
	brush.setStyle(Qt::Dense5Pattern);
	painter->setBrush(brush);
	painter->drawEllipse(center, mLeafRadius, mLeafRadius);

}

void QTrees::advance(int phase)
{
}
