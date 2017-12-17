// QTrees.cpp
//
// Description:
// Classe g�rant la cr�ation et le comportement d'une entit� de type arbre.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QTrees.h"
#include <QBrush>
#include <QPainter>
#include "QForestScene.h"

// G�n�rateurs de chiffre al�atoires distribu�s uniform�ments
RandomUniform QTrees::mGenerateTime(700, 1500);
RandomUniform QTrees::mGenerateSeed(0, 3);

QTrees::QTrees(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QStatic(environment, forestscene, lifeSpan, tree, type), mEmpty(0, 0, 0)
{
	// D�fini les valeurs de base d'un arbre
	mAge = 0;
	mLeafRadius = 1;
	mTrunkRadius = 0.2 * mLeafRadius;
	mHeight = 4 * mLeafRadius;

	// D�fini le tic auquel l'arbre se reproduit
	mReproductiveTime = mGenerateTime.random();

}

void QTrees::reproduce()
{
	// Cr�e un nombre al�atoire de semences.
	for (int i{ 0 }; i < mGenerateSeed.random(); ++i) 
	{	
		mForestScene.createSeed(this);
	}

}

double QTrees::getShadowGrowFactor()
{
	// Calcul le facteur d'ombre en fonction du nombre d'entit�s qui sont plus haute que lui.
	double factor{ 1.0 };
	mShadowList = collidingItems();
	for (QGraphicsItem * currentItem : mShadowList)
	{
		QTrees * tree = dynamic_cast<QTrees *>(currentItem);
		if (tree)
		{
			if (tree->mHeight >= this->mHeight)
			{
				factor = factor / 2.0;

			}
		}
	}
	return factor;
}

// Retourne le rayon des feuilles de l'arbre
int QTrees::getRadius()
{
	return mLeafRadius;
}

// Ajuste la taille de colision de l'arbre
QRectF QTrees::boundingRect() const
{	
	return QRectF(0-mLeafRadius,0-mLeafRadius, mLeafRadius*2, mLeafRadius*2);
}

void QTrees::advance(int phase)
{
	
	if (phase == 1 && !mIsDead)
	{
		// Avance son �ge
		advanceTime();
		// Regarde s'il doit mourir
		die();

		if (mAge < mLifeSpan) 
		{
			// Grandit et ajuste son espace de collision
			grow();
			update(boundingRect());
		}
	
		if (mTime == mReproductiveTime)
		{
			// Regarde s'il va g�n�rer des semences cette ann�e.
			reproduce();
		}	
	}
}

// Fonctions � surcharger retournant des tables de facteurs environmentaux et de croissance vide
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
	// Calcule le facteur d'ombre
	mShadowFactor = getShadowGrowFactor();
	// Calcule le facteur de fertilit� du sol
	double fertility = mEnvironment.mFertility.getFertility(this->pos().x(), this->pos().y())/100.0;
	// Calcule le facteur de croissance g�n�ral
	double factor = mShadowFactor * (this->growTable().getValue(mAge))*((fertility + this->temperatureGrowFactorTable().getValue(mEnvironment.mFactors[0]) + this->precipirationGrowFactorTable().getValue(mEnvironment.mFactors[1]) + this->luminosityGrowFactorTable().getValue(mEnvironment.mFactors[2])) / 4);
	if (factor > 0.0)
	{
		// Ajuste la taille de l'arbre en fonction du facteur
		mLeafRadius = mLeafRadius + 0.05*factor;
		mTrunkRadius = 0.20 * mLeafRadius;
		mHeight = 4 * mLeafRadius;
	}

}
