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

GaussianTable QSeeds::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QSeeds::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QSeeds::mTemperatureGrowFactor(150, 30, 1000, -75);

QSeeds::QSeeds(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan)
	: QDynamic{ environment,forestscene, lifeSpan }, mTreeType{value}, mGenerateTree(0,1000)
{


}

QSeeds::~QSeeds()
{

}

void QSeeds::germinate()
{
	double chance = (this->mTemperatureGrowFactor.getValue(mEnvironment.mFactors[0]) + this->mPrecipitationGrowFactor.getValue(mEnvironment.mFactors[1]) + this->mLuminosityGrowFactor.getValue(mEnvironment.mFactors[2])) / 3;
	chance = chance*(mGenerateTree.random() /1000.0);

	if (chance > 0.90)
	{
		mForestScene.createTree(this);
		mGerminated = true;
		this->setVisible(false);
	}
	

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
	mHeight = mHeight--;
	this->setPos(this->pos().x() + 2, this->pos().y() + 2);
	
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


	if (phase == 1) {

		advanceTime();

		if (mHeight > 0)
		{
			move();

		}
		else if (mAge < 2 && !mGerminated)
		{
			germinate();

		}


	}

}

