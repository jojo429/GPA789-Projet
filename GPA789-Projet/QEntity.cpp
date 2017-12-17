// QEntity.cpp
//
// Description:
// Classe virtuelle représentant un être vivant qui sera simulé et les fonctions de bases le contrôlant.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
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
	// Si l'âge est plus grand que la durée de vie attendue, l'entité a une chance sur mDied de mourrir à chaque advance.
	if (mAge > mLifeSpan && mDied.random()==1)
	{
		mIsDead = true;
		this->setVisible(false);

	}
}

// Retourne la grandeur d'une entité
int QEntity::getHeight()
{
	return mHeight;
}

// Retourne vrai si l'entité est morte et faux sinon
bool QEntity::isDead()
{
	return mIsDead;
}

// Ajoute un an à l'entité à chaque 2190 advance
void QEntity::advanceTime()
{
	mTime++;
	if (mTime >= 2190)
	{
		mAge++;
		mTime = mTime - 2190;
	}
}

