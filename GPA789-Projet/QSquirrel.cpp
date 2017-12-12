#include "QSquirrel.h"
#include <QPainter>
#include "QTrees.h"
#include <QtMath>

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

QGraphicsItem * QSquirrel::getTarget()
{
	 QList<QGraphicsItem *> inRangeItems  = collidingItems();
	
	if (inRangeItems.empty()) 
	{
		return Q_NULLPTR;
	}
	else 
	{

		for (QGraphicsItem * item : inRangeItems) {

			//If there a tree in the vision radius
			QTrees * currentItem = dynamic_cast<QTrees *>(item);
			if (currentItem) {



				mTargetType = Trees;
				return item;


			}



		}
		

	}



	return nullptr;
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

void QSquirrel::setRotationAdjustment()
{
	qreal x1, x2, y1, y2, teta1, teta2;
	x1 = pos().x();
	y1 = pos().y();
	x2 = mTargetPos.x();
	y2 = mTargetPos.y();
	teta1 = rotation();

	teta2 = qAtan2(y1 - y2, x1 - x2) * (180 / 3.14);

	setRotation(teta1 - teta2);

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
	//Mouvement aléatoire
	if (mActionCounter == 0)
	{
		mTarget = getTarget();
		if (mTargetType != NoTarget) {
			mTargetPos = mTarget->pos();
			setRotationAdjustment();
		}
		


		mActionCounter++;
	}
	setPos(mapToParent(0, -3));





}
