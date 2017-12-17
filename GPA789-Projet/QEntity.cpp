// QEntity.cpp
//
// Description:
// Classe virtuelle repr�sentant un �tre vivant qui sera simul� et les fonctions de bases le contr�lant.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QEntity.h"
#include "QForestScene.h"

RandomUniform QEntity::mDied(1, 500);

QEntity::QEntity(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: mEnvironment{ environment }, mForestScene{ forestscene }, mLifeSpan{ lifeSpan }, mTreeType{tree}, mGeneralType{type}
{

}

void QEntity::reproduce()
{

}

void QEntity::die()
{
	// Si l'�ge est plus grand que la dur�e de vie attendue, l'entit� a une chance sur mDied de mourrir � chaque advance.
	if (mAge > mLifeSpan && mDied.random()==1)
	{
		mIsDead = true;
		this->setVisible(false);

	}
}

// Retourne la grandeur d'une entit�
int QEntity::getHeight()
{
	return mHeight;
}

// Retourne vrai si l'entit� est morte et faux sinon
bool QEntity::isDead()
{
	return mIsDead;
}

// Ajoute un an � l'entit� � chaque 2190 advance
void QEntity::advanceTime()
{
	mTime++;
	if (mTime >= 2190)
	{
		mAge++;
		mTime = mTime - 2190;
	}
}

