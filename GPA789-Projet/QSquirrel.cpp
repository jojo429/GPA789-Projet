// QSquirrel.cpp
//
// Description:
// Création et comportement d'un écureuil
//
//
// Auteur:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017
#include "QSquirrel.h"
#include <QPainter>
#include "QTrees.h"
#include <QtMath>
#include <QDebug>
#include "QSeeds.h"


QSquirrel::QSquirrel(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QAnimals{ environment, forestscene , lifeSpan, tree, type }, mGenerateAngle(-180, 180), mRandomSeedDrop(0, 500)
{


		 
}

QSquirrel::~QSquirrel()
{

}


void QSquirrel::move()
{
	setPos(mapToParent(3, 0));

}


QGraphicsItem * QSquirrel::getTarget()
{
	QGraphicsItem * tree{Q_NULLPTR};
	 QList<QGraphicsItem *> inRangeItems  = collidingItems();
	 inRangeItems = compareTargetList(inRangeItems);

	if (inRangeItems.empty()) 
	{
		
		return Q_NULLPTR;
	}
	else 
	{
		for (QGraphicsItem * item : inRangeItems) 
		{
			//If there's a tree in the vision radius
			if (mSeeds.size() < mSeedsLimit) 
			{
				QSeeds * currentItem = dynamic_cast<QSeeds *>(item);
				if(currentItem)
				{
					if (currentItem->getHeight() == 0) 
					{
						mTargetType = Seed;
						return item;
					}
				}
			}	
		}
	}
	return nullptr;
}

QList<QGraphicsItem*> QSquirrel::compareTargetList(QList<QGraphicsItem*> &newTarget)
{
	if(!mPastTarget.isEmpty())
	{
		for (QGraphicsItem * item : newTarget)
		{
			for (QGraphicsItem * pastTarget : mPastTarget)
			{
				if (item == pastTarget) {
					newTarget.removeOne(item);
				}
			}
			
		}		
	}
	return newTarget;
}

void QSquirrel::randomDropSeed()
{
	if (mRandomSeedDrop.random() <= 2) 
	{
		dropSeed();
	}

}





void QSquirrel::pickSeed()
{
	QSeeds* currentSeed;
	currentSeed = dynamic_cast<QSeeds*>(mTarget);
	if (mSeeds.size() <= mSeedsLimit && currentSeed)
	{
		mTarget->setVisible(false);
		currentSeed->setCarried(true);
		mSeeds.append(currentSeed);

	}




}

void QSquirrel::dropSeed()
{
	
	if (!mSeeds.isEmpty())
	{
		mSeeds.first()->setPos(pos());
		mSeeds.first()->setVisible(true);
		mSeeds.first()->setCarried(false);
		addPastTarget(mSeeds.first());
		mSeeds.removeFirst();
	}



}



void QSquirrel::setRotationAdjustment()
{
	if (mTargetType != NoTarget) {
		qreal x1, x2, y1, y2, teta1, teta2;
		x1 = pos().x();
		y1 = pos().y();
		x2 = mTargetPos.x();
		y2 = mTargetPos.y();
		teta1 = rotation();

		teta2 = qRadiansToDegrees(qAtan2(y2 - y1, x2 - x1));

		setRotation(teta2);
	}
	else
	{
		setRotation(mGenerateAngle.random());
	}

}

void QSquirrel::addPastTarget(QGraphicsItem * pastItem)
{

	if (mPastTarget.size() < mPastTargetLimit) {
		mPastTarget.append(pastItem);
	}
	else
	{
		mPastTarget.removeFirst();
		mPastTarget.append(pastItem);
	}
}

qreal QSquirrel::getTargetDistance()
{
	return qSqrt(qPow(mTargetPos.x() - pos().x(),2)+ qPow(mTargetPos.y() - pos().y(), 2));
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
	//mPen.setWidthF(0.5);
	//painter->drawEllipse(mCenter, mVisionRadius, mVisionRadius);
	mBrush.setColor(mFurColor);
	mBrush.setStyle(Qt::SolidPattern);
	mPen.setColor(mFurColor);
	mPen.setWidthF(1.0);
	painter->setOpacity(1);
	painter->setBrush(mBrush);
	painter->setPen(mPen);
	painter->drawConvexPolygon(mTriangle, 3);
	mBrush.setColor(mTailColor);
	painter->drawEllipse(QPointF(-12, 0), -12, -4);
	mPen.setColor(Qt::black);
	painter->setPen(mPen);
	painter->drawLine(15, 0, 30, 0);
	



}
void QSquirrel::advance(int phase)
{

	//qDebug() << "test";

	//Choose a target or a random direction
	if (phase = 1) {
		advanceTime();
		if (mActionCounter == 0)
		{
			mTarget = getTarget();
			if (mTarget != Q_NULLPTR) {
				addPastTarget(mTarget);
			}
			if (mTargetType != NoTarget) {
				mTargetPos = mTarget->pos();
				setRotationAdjustment();
			}
			else
			{
				setRotationAdjustment();
			}
			mActionCounter++;
		}
		else if (mActionCounter <= 80)
		{
			if ((pos().x() > 0 && pos().x() < 2050) && (pos().y() > 0 && pos().y() < 2050))
			{
				if (mTarget == Q_NULLPTR || getTargetDistance() >= 3)
				{
					move();
					mActionCounter++;
					if (mSeeds.size() > 0)
					{
						randomDropSeed();
					}
				}
				else
				{
					if (mTargetType == Seed)
					{
						pickSeed();
					}
					mTargetType = NoTarget;
					mActionCounter = 0;
				}
			}
			else
			{
				setPos(mapToParent(-15, 0));
				mTargetType = NoTarget;
				mActionCounter = 0;

			}
		}
		else
		{
			mTargetType = NoTarget;
			mActionCounter = 0;
		}


	}
	
}
