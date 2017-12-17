#include "QTrees.h"
#include <QBrush>
#include <QPainter>
#include "QForestScene.h"



QTrees::QTrees(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan, generalType type)
	: QStatic(environment, forestscene, lifeSpan), mGenerateSeed(0, 3), mTreeType{ value }, mEmpty(0, 0, 0), mGenerateTime(700, 1500), mGeneralType{type}
{
	
	mAge = 0;
	mLeafRadius = 1;
	mTrunkRadius = 0.2 * mLeafRadius;
	mHeight = 4 * mLeafRadius;
	mReproductiveTime = mGenerateTime.random();


}

QTrees::~QTrees()
{

}

void QTrees::reproduce()
{
	
	for (int i{ 0 }; i < mGenerateSeed.random(); ++i) 
	{	
		mForestScene.createSeed(this);
	}

}

double QTrees::getShadowGrowFactor()
{
	double factor{ 1 };

	mShadowList = collidingItems();

	for (QGraphicsItem * currentItem : mShadowList)
	{
		QTrees * tree = dynamic_cast<QTrees *>(currentItem);
		if (tree)
		{
			if (tree->mHeight >= this->mHeight)
			{
				factor = factor / 2;

			}

		}

	}

	return factor;
}


int QTrees::getRadius()
{
	return mLeafRadius;
}


QRectF QTrees::boundingRect() const
{
	
	return QRectF(0-mLeafRadius,0-mLeafRadius, mLeafRadius*2, mLeafRadius*2);
}


void QTrees::advance(int phase)
{
	
	if (phase == 1 && !mIsDead)
		{
		die();
		advanceTime();

		if (mAge < 2) {
			grow();
			update(boundingRect());

		}
	
		if (mTime == mReproductiveTime)
		{
			reproduce();
		}
		
	}
	

}

GaussianTable & QTrees::growTable()
{
	return mEmpty;
}
GaussianTable & QTrees::precipirationGrowFactorTable()
{
	return mEmpty;
}
GaussianTable & QTrees::luminosityGrowFactorTable()
{
	return mEmpty;
}
GaussianTable & QTrees::temperatureGrowFactorTable()
{
	return mEmpty;
}

void QTrees::grow()
{

	mShadowFactor = getShadowGrowFactor();
	double fertility = mEnvironment.mFertility.getFertility(this->pos().x(), this->pos().y())/100.0;
	double factor = mShadowFactor * (this->growTable().getValue(mAge))*((fertility + this->temperatureGrowFactorTable().getValue(mEnvironment.mFactors[0]) + this->precipirationGrowFactorTable().getValue(mEnvironment.mFactors[1]) + this->luminosityGrowFactorTable().getValue(mEnvironment.mFactors[2])) / 4);
	if (factor > 0.0)
	{
		mLeafRadius = mLeafRadius + 0.05*factor;
		mTrunkRadius = 0.20 * mLeafRadius;
		mHeight = 4 * mLeafRadius;
	}




}
