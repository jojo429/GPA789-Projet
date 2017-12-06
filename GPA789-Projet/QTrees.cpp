#include "QTrees.h"
#include <QBrush>
#include <QPainter>

QTrees::QTrees(QEnvironment const & environment)
	: QStatic(environment)
{

	mLeafRadius = 1;
	mTrunkRadius = 0.20 * mLeafRadius;

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

QRectF QTrees::boundingRect() const
{
	
	return QRectF(0-mLeafRadius,0-mLeafRadius, mLeafRadius*2, mLeafRadius*2);
}

void QTrees::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QBrush brush(Qt::green);
	QPen pen = QPen(Qt::white, 2);
	QColor darkGreen = QColor(100, 186, 63);
	QColor darkBrown = QColor(86, 75, 52);
	QPointF center = QPointF(0,0);

	//Test pour systeme de coordonnee
	QPointF x1 = mapFromScene(QPointF(0, 0));
	QPointF x2 = mapFromScene(QPointF(1000, 0));
	QPointF y1 = mapFromScene(QPointF(0, 0));
	QPointF y2 = mapFromScene(QPointF(0, 1000));

	//Dessine le tronc
	brush.setColor(darkBrown);
	brush.setStyle(Qt::SolidPattern);
	painter->drawLine(x1, x2);
	painter->drawLine(y1, y2);
	painter->setOpacity(1);
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
	if (mLeafRadius < 50) {
		mLeafRadius = mLeafRadius + 0.10*(rand() % 2 + 1);
		mTrunkRadius = 0.20 * mLeafRadius;
		update(boundingRect());
	}
	else {
		update();
	}

}

