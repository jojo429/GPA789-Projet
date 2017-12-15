#include "QTrees.h"
#include <QBrush>
#include <QPainter>
#include "QForestScene.h"



QTrees::QTrees(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan )
	: QStatic(environment, forestscene, lifeSpan), mGenerateSeed(1, 6), mTreeType{ value }, mEmpty(0,0,0)
{
	
	mAge = 0;
	mLeafRadius = 1;
	mTrunkRadius = 0.2 * mLeafRadius;
	mHeight = 4 * mLeafRadius;



}

QTrees::~QTrees()
{

}

void QTrees::reproduce()
{
	
		

	for (int i{ 0 }; i < mGenerateSeed.random(); ++i) {

			
		mForestScene.createSeed(this);

	}

}

void QTrees::die()
{

}

int QTrees::getHeight()
{
	return mHeight;
}

int QTrees::getRadius()
{
	return mLeafRadius;
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


void QTrees::advance(int phase)
{

	if (phase == 1)
		{
		advanceTime();

		if (mAge < 2) {
			grow();
			update(boundingRect());

		}
		else {
			update();
		}

		if (mTime == 1000)
		{
			reproduce();
		}
	}
	
	/*if (mLeafRadius < 50) {
		mLeafRadius = mLeafRadius + 0.10*(rand() % 2 + 1);
		mTrunkRadius = 0.20 * mLeafRadius;
		update(boundingRect());
	}
	else {
		update();
	}*/

}

GaussianTable QTrees::growTable()
{
	return mEmpty;
}
GaussianTable QTrees::precipirationGrowFactorTable()
{
	return mEmpty;
}
GaussianTable QTrees::luminosityGrowFactorTable()
{
	return mEmpty;
}
GaussianTable QTrees::temperatureGrowFactorTable()
{
	return mEmpty;
}

void QTrees::grow()
{
	mLeafRadius = mLeafRadius + 0.04*(this->growTable().getValue(mAge))*((this->temperatureGrowFactorTable().getValue(mEnvironment.mFactors[0]) + this->precipirationGrowFactorTable().getValue(mEnvironment.mFactors[1]) + this->luminosityGrowFactorTable().getValue(mEnvironment.mFactors[2])) / 3);
	mTrunkRadius = 0.20 * mLeafRadius;
	mHeight = 4 * mLeafRadius;
}
