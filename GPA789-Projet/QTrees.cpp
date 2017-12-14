#include "QTrees.h"
#include <QBrush>
#include <QPainter>

GaussianTable QTrees::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QTrees::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QTrees::mTemperatureGrowFactor(150, 30, 1000, -75);
GaussianTable QTrees::mGrowTable(500, 10, 50000);
GaussianTable QTrees::mReproduceTable(500, 10, 50000);

QTrees::QTrees(QEnvironment const & environment, treeType value )
	: QStatic(environment), mGenerateSeed(1, 6), mTreeType{ value }
{
	
	mAge = 0;
	mLeafRadius = 1;
	mTrunkRadius = 0.1 * mLeafRadius;
	mHeight = 2 * mLeafRadius;
	mMasterTree = this;

}

QTrees::~QTrees()
{

}

void QTrees::reproduce()
{
	if (mTime == 1000 )
	{

		

		for (int i{ 0 }; i < mGenerateSeed.random(); ++i) {

			


			//Add seeds
			//QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
			/*QTrees *newTree = new QOak(enviromnent);
			this->addItem(newTree);
			newTree->setPos(QPointF(1000 + 100 * i, 1000 + 100 * i));*/
		}

	}
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

void QTrees::setMasterTree(QTrees * tree)
{
	mMasterTree = tree;


}

QRectF QTrees::boundingRect() const
{
	
	return QRectF(0-mLeafRadius,0-mLeafRadius, mLeafRadius*2, mLeafRadius*2);
}


void QTrees::advance(int phase)
{

	mTime++;
	if (mTime >= 2190)
	{
		mAge++;
		mTime = mTime - 2190;
	}

	if (mAge < 500) {
		mLeafRadius = mLeafRadius + 0.05*(mGrowTable.getValue(mAge))*((mTemperatureGrowFactor.getValue(mEnvironment.mFactors[0])+mPrecipitationGrowFactor.getValue(mEnvironment.mFactors[1])+ mLuminosityGrowFactor.getValue(mEnvironment.mFactors[2]))/3);
		mTrunkRadius = 0.20 * mLeafRadius;
		update(boundingRect());
	}
	else {
		update();
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

