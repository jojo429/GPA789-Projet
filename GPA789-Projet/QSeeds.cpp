// QSeeds.cpp
//
// Description:
// Classe g�rant la cr�ation et le comportement d'une entit� de type semence d'arbre.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QSeeds.h"
#include "QTrees.h"
#include "QOak.h"
#include "QFir.h"
#include "QBirch.h"
#include "QHazel.h"
#include <QBrush>
#include <QPainter>
#include <array>
#include "QForestScene.h"
#include <math.h>

// Tables de facteurs environmentaux sp�cifiques � une semence
GaussianTable QSeeds::mPrecipitationGrowFactor(28, 6, 25);
GaussianTable QSeeds::mLuminosityGrowFactor(200, 50, 10000, -100);
GaussianTable QSeeds::mTemperatureGrowFactor(150, 30, 1000, -75);

QSeeds::QSeeds(QEnvironment const & environment, QForestScene & forestscene,  int lifeSpan, treeType tree, generalType type, int height)
	: QDynamic{ environment,forestscene, lifeSpan , tree, type}, mGenerateTree(0, 1000), mGenerateAngle(-45, 45)
{
	mHeight = height;
}

void QSeeds::germinate()
{
	// Ne peut pas germer s'il y a d'autres entit�s autour
	if((collidingItems().empty()))
	{
		// Calcul du pourcentage de chance selon les facteurs environnementaux
		double chance = (this->mTemperatureGrowFactor.getValue(mEnvironment.mFactors[0]) + this->mPrecipitationGrowFactor.getValue(mEnvironment.mFactors[1]) + this->mLuminosityGrowFactor.getValue(mEnvironment.mFactors[2])) / 3;
		// Ajoute un facteur al�atoire
		chance = chance * (mGenerateTree.random() / 1000.0);
		if (chance > 0.85)
		{
			// Cr�ation d'un arbre � partir de la graine et supression de la semence 
			mForestScene.createTree(this);
			mIsDead = true;
			this->setVisible(false);
		}
	}
}


void QSeeds::move()
{
	// R�duit la hauteur de la semence
	mHeight = mHeight--;

	// Calcule le vecteur en x � partir de l'angle du vent et de la vitesse du vent
	double x = -sin(2 * 3.1416* (mForestScene.mWindAngle + mGenerateAngle.random())/ 360.0)*mEnvironment.mFactors[3] / 20.0;
	double y = cos(2 * 3.1416* (mForestScene.mWindAngle + mGenerateAngle.random())/ 360.0)*mEnvironment.mFactors[3] / 20.0;

	// Si la semence tombe en dehors de la sc�ne, elle est supprim�e
	if ((((this->pos().x() + x)>2045) || ((this->pos().x() + x)<5))||((this->pos().y() + x)>2045 || (this->pos().y() + x)<5))
	{
		setVisible(false);
		mIsDead = true;
	}
	else
	{
		//Nouvelle position de la semence
		this->setPos(QPointF(this->pos().x() + x, this->pos().y() + y));
	}
}

void QSeeds::picked()
{
	// Rend la semence invisible lorsque prise par une autre entit�
	setVisible(false);
}

void QSeeds::droped( QPointF coordinate )
{
	// D�pose la graine � une coordonn�e et la remet visible
	setPos(coordinate);
	setVisible(true);
}

void QSeeds::setCarried(bool status)
{
	// Met � jour le statut de la semence
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
		
		// Avance l'�ge de l'entit�
		advanceTime();

		if (mCarriedBySquirrel == false)
		{


			// Si elle est en l'air elle se d�place
			if (mHeight > 0)
			{
				move();
			}
			else if (!mIsDead)
			{
				// Regarde si elle doit germiner
				germinate();

				if (!mIsDead)
				{
					// Regarde si elle doit mourir
					die();

				}
			}
		}
	}
}

