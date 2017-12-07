#include "QSeeds.h"
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
	return QRectF(0.0 - mSeedRadius, 0.0 - mSeedRadius, mSeedRadius * 2.0, mSeedRadius * 2.0);
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
	double movingFactor{ 1.5 };

	if (mCountFallDown < 50) {
		//movingVector = mEnvironment.getAirDisplacement();
		moveBy(/*movingVector[0]*/0.5 * movingFactor,/*movingVector[1]*/0.5 * movingFactor);
		update();
		mCountFallDown++;
	}
	update();
}

