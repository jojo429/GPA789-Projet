#include "QEntity.h"
#include "QForestScene.h"

QEntity::QEntity(QEnvironment const & environment, QForestScene & forestscene)
	: mEnvironment{ environment }, mForestScene{forestscene}
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

}

bool QEntity::isItDead()
{
	return false;
}

void QEntity::striked()
{

}

