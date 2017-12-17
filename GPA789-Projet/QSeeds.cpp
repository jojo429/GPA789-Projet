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
#include "QForestScene.h"
#include <math.h>

GaussianTable QSeeds::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QSeeds::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QSeeds::mTemperatureGrowFactor(150, 30, 1000, -75);

QSeeds::QSeeds(QEnvironment const & environment, QForestScene & forestscene, treeType tree, int lifeSpan, generalType type)
	: QDynamic{ environment,forestscene, lifeSpan }, mTreeType{tree}, mGenerateTree(0,1000), mGenerateAngle(-45,45), mGeneralType(type)
{


}

QSeeds::~QSeeds()
{

}

void QSeeds::germinate()
{
	if((collidingItems().empty()))
	{
		double chance = (this->mTemperatureGrowFactor.getValue(mEnvironment.mFactors[0]) + this->mPrecipitationGrowFactor.getValue(mEnvironment.mFactors[1]) + this->mLuminosityGrowFactor.getValue(mEnvironment.mFactors[2])) / 3;
		chance = chance * (mGenerateTree.random() / 1000.0);

		if (chance > 0.85)
		{
			mForestScene.createTree(this);
			mIsDead = true;
			this->setVisible(false);
		}
	}
	
	

}





void QSeeds::move()
{
	mHeight = mHeight--;
	double x = -sin(2 * 3.1416* (mForestScene.mWindAngle + mGenerateAngle.random())/ 360.0)*mEnvironment.mFactors[3] / 20.0;
	double y = cos(2 * 3.1416* (mForestScene.mWindAngle + mGenerateAngle.random())/ 360.0)*mEnvironment.mFactors[3] / 20.0;

	if ((((this->pos().x() + x)>2045) || ((this->pos().x() + x)<5))||((this->pos().y() + x)>2045 || (this->pos().y() + x)<5))
	{
		setVisible(false);
		mIsDead = true;
	}
	else
	{
		this->setPos(QPointF(this->pos().x() + x, this->pos().y() + y));
	}
	
	
	
}

void QSeeds::picked()
{
	setVisible(false);
}

void QSeeds::droped( QPointF coordinate )
{
	setPos(coordinate);
	setVisible(true);
}

void QSeeds::setCarried(bool status)
{
	mCarriedBySquirrel = status;
}

QRectF QSeeds::boundingRect() const
{
	//QRectF(qreal x, qreal y, qreal width, qreal height)
	//return QRectF(0.0 - mSeedRadius, 0.0 - mSeedRadius, mSeedRadius * 2.0, mSeedRadius * 2.0);
	return QRectF(0.0 - mSeedRadius, 0.0 - (mSeedRadius - mSeedRadius * 0.5), mSeedRadius*5, (mSeedRadius - mSeedRadius * 0.5)*5);
}

void QSeeds::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QBrush brush(QColor(219,195,109));
	QPen pen = QPen(QColor(219, 195, 109), 2);
	QPointF center = QPointF(0, 0);

	//Dessine les graines
	painter->setBrush(brush);
	painter->setPen(pen);
	painter->drawEllipse(center, mSeedRadius, mSeedRadius - mSeedRadius * 0.5);
}



void QSeeds::advance(int phase)
{


	if (phase == 1) {
		
		advanceTime();

		if (mCarriedBySquirrel == false)
		{
			
			die();

			if (mHeight > 0)
			{
				move();


			}
			else if (!mIsDead)
			{
					germinate();

			}
		}

		

	}

}

