#include "QEntity.h"
#include "QForestScene.h"

QEntity::QEntity(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan)
	: mEnvironment{ environment }, mForestScene{ forestscene }, mLifeSpan{ lifeSpan }, mDied(1,500)
{

}


QEntity::~QEntity()
{

}

void QEntity::reproduce()
{

}

void QEntity::die()
{
	if (mAge > mLifeSpan && mDied.random()==1)
	{
		mIsDead = true;
		this->setVisible(false);

	}
}

bool QEntity::isItDead()
{
	return false;
}



int QEntity::getHeight()
{
	return mHeight;
}

bool QEntity::isDead()
{
	return mIsDead;
}

void QEntity::advanceTime()
{
	mTime++;
	if (mTime >= 2190)
	{
		mAge++;
		mTime = mTime - 2190;
	}
}

