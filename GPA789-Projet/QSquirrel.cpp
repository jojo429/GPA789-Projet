#include "QSquirrel.h"
#include <QPainter>

QSquirrel::QSquirrel(QEnvironment const & environment)
	: QAnimals{ environment }
{


		 
}

QSquirrel::~QSquirrel()
{

}

void QSquirrel::move()
{

}

void QSquirrel::reproduce(int age)
{

}

void QSquirrel::die(int age)
{

}

void QSquirrel::eat()
{

}

void QSquirrel::pickSeed()
{

}

void QSquirrel::striked()
{

}

QRectF QSquirrel::boundingRect() const
{

	return QRectF(0 - mVisionRadius, 0 - mVisionRadius, mVisionRadius * 2, mVisionRadius * 2);

}

void QSquirrel::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{

	mPen.setColor(Qt::black);
	painter->setPen(mPen);
	painter->setOpacity(1);
	mPen.setWidthF(0.5);
	painter->drawEllipse(mCenter, mVisionRadius, mVisionRadius);
	mBrush.setColor(mFurColor);
	mBrush.setStyle(Qt::SolidPattern);
	mPen.setColor(mFurColor);
	mPen.setWidthF(1.0);
	painter->setOpacity(1);
	painter->setBrush(mBrush);
	painter->setPen(mPen);
	painter->drawConvexPolygon(mTriangle, 3);
	mBrush.setColor(mTailColor);
	painter->drawEllipse(QPointF(0, 12), 4, 12);
	mPen.setColor(Qt::black);
	painter->setPen(mPen);
	painter->drawLine(0, -15, 0, -30);
	



}
void QSquirrel::advance(int phase)
{

}
