// QSquirrel.cpp
//
// Description:
// Classe gérant la création et le comportement d'une entité de type écureuil.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017
#include "QSquirrel.h"
#include <QPainter>
#include "QTrees.h"
#include <QtMath>
#include <QDebug>
#include "QSeeds.h"

QSquirrel::QSquirrel(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QAnimals{ environment, forestscene , lifeSpan, tree, type }, mGenerateAngle(-180, 180), mRandomSeedDrop(0, 500)
{
	 
}
//Fonction de déplacement
void QSquirrel::move()
{
	setPos(mapToParent(3, 0));

}

//Fonction qui retourne une entité ciblé par l'écureuil
QGraphicsItem * QSquirrel::getTarget()
{
	QGraphicsItem * tree{Q_NULLPTR};

	//Obtiens la liste des objets dans le champ de vision de l'écureuil
	//et les compares avec la liste d'ancienne cible
	QList<QGraphicsItem *> inRangeItems  = collidingItems();
	inRangeItems = compareTargetList(inRangeItems);

	
	if (inRangeItems.empty()) 
	{
		
		return Q_NULLPTR;
	}
	else 
	{
		for (QGraphicsItem * item : inRangeItems) 
		{
			//Si la liste de graines transportés n'est pas pleine
			if (mSeeds.size() < mSeedsLimit) 
			{
				//Vérifie si la cible est une graine
				QSeeds * currentItem = dynamic_cast<QSeeds *>(item);
				if(currentItem)
				{
					//si la graine n'est pas dans les airs
					if (currentItem->getHeight() == 0) 
					{
						mTargetType = Seed;
						return item;
					}
				}
			}	
		}
	}
	return nullptr;
}
//Fonction qui compare une liste d'objet à la liste d'ancienne cible de l'écureuil.
//Retourne une liste d'objet excluant les anciennes cibles
QList<QGraphicsItem*> QSquirrel::compareTargetList(QList<QGraphicsItem*> &newTarget)
{
	if(!mPastTarget.isEmpty())
	{
		for (QGraphicsItem * item : newTarget)
		{
			for (QGraphicsItem * pastTarget : mPastTarget)
			{
				if (item == pastTarget) {
					newTarget.removeOne(item);
				}
			}
			
		}		
	}
	return newTarget;
}
//Fonction qui détermine aléatoirement si l'écureuil dépose une graine
void QSquirrel::randomDropSeed()
{
	if (mRandomSeedDrop.random() <= 2) 
	{
		dropSeed();
	}
}
//Fonction qui fait la gestion de la graine lorsque l'écureuil la ramasse.
void QSquirrel::pickSeed()
{
	QSeeds* currentSeed;
	currentSeed = dynamic_cast<QSeeds*>(mTarget);
	if (mSeeds.size() <= mSeedsLimit && currentSeed)
	{
		mTarget->setVisible(false);
		currentSeed->setCarried(true);
		mSeeds.append(currentSeed);
	}
}
//Fonction qui fais la gestion de la graine lorsque l'écureuil la laisse tomber
void QSquirrel::dropSeed()
{
	if (!mSeeds.isEmpty())
	{
		mSeeds.first()->setPos(pos());
		mSeeds.first()->setVisible(true);
		mSeeds.first()->setCarried(false);
		addPastTarget(mSeeds.first());
		mSeeds.removeFirst();
	}
}
//Fonction qui ajuste l'orientation selon l'objet ciblé par l'écureuil (ou l'abscence d'objet).
void QSquirrel::setRotationAdjustment()
{
	if (mTargetType != NoTarget) {
		qreal x1, x2, y1, y2, teta;
		x1 = pos().x();
		y1 = pos().y();
		x2 = mTargetPos.x();
		y2 = mTargetPos.y();

		//calcul de l'angle de rotation
		teta = qRadiansToDegrees(qAtan2(y2 - y1, x2 - x1));
		setRotation(teta);
	}
	else
	{
		//choisi un angle aléatoirement
		setRotation(mGenerateAngle.random());
	}

}
//Fonction qui ajoute une cible à la liste d'ancienne cible
void QSquirrel::addPastTarget(QGraphicsItem * pastItem)
{

	if (mPastTarget.size() < mPastTargetLimit) {
		mPastTarget.append(pastItem);
	}
	else
	{
		mPastTarget.removeFirst();
		mPastTarget.append(pastItem);
	}
}
//Fonction qui retourne la distance entre l'écureuil et sa cible
qreal QSquirrel::getTargetDistance()
{
	return qSqrt(qPow(mTargetPos.x() - pos().x(),2)+ qPow(mTargetPos.y() - pos().y(), 2));
}
//Mise en place du boundingRect() de l'écureuil
QRectF QSquirrel::boundingRect() const
{

	return QRectF(0 - mVisionRadius, 0 - mVisionRadius, mVisionRadius * 2, mVisionRadius * 2);

}
//Fonction responsable de dessiner un écureuil
void QSquirrel::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{

	mPen.setColor(Qt::black);
	painter->setPen(mPen);
	painter->setOpacity(1);
	mBrush.setColor(mFurColor);
	mBrush.setStyle(Qt::SolidPattern);
	mPen.setColor(mFurColor);
	mPen.setWidthF(1.0);
	painter->setOpacity(1);
	painter->setBrush(mBrush);
	painter->setPen(mPen);
	painter->drawConvexPolygon(mTriangle, 3);
	mBrush.setColor(mTailColor);
	painter->drawEllipse(QPointF(-12, 0), -12, -4);
	mPen.setColor(Qt::black);
	painter->setPen(mPen);
	painter->drawLine(15, 0, 30, 0);
	



}
//Fonction appelé à chaque tic() et responsable du comportement générale de l'écureuil
void QSquirrel::advance(int phase)
{

	if (phase = 1) {
		advanceTime();
		//Si l'écureuil débute une prise de décision
		if (mActionCounter == 0)
		{
			//Trouve une cible
			mTarget = getTarget();
			if (mTarget != Q_NULLPTR) {
				addPastTarget(mTarget);
			}
			if (mTargetType != NoTarget) {
				//Si on a une cible
				mTargetPos = mTarget->pos();
				setRotationAdjustment();
			}
			else
			{
				//Si il n'y a aucune cible
				setRotationAdjustment();
			}
			mActionCounter++;
		}
		//Si l'écureuil a déjà une cible ou si il a une direction aléatoire
		else if (mActionCounter <= 80)
		{
			//Si l'écureuil n'est pas en dehors de la zone restreinte
			if ((pos().x() > 0 && pos().x() < 2050) && (pos().y() > 0 && pos().y() < 2050))
			{
				//Si il n'a pas de cible ou si il est loin de sa cible
				if (mTarget == Q_NULLPTR || getTargetDistance() >= 3)
				{
					move();
					mActionCounter++;
					//Si il transporte une graine
					if (mSeeds.size() > 0)
					{
						randomDropSeed();
					}
				}
				//Si il possède une cible
				else
				{
					//Si la cible est une graine
					if (mTargetType == Seed)
					{
						pickSeed();
					}
					//Annule la cible et retourne en mode prise de décision
					mTargetType = NoTarget;
					mActionCounter = 0;
				}
			}
			//Si l'écureuil est en dehors de la zone restreinte
			else
			{
				//Recule et annule sa cible
				setPos(mapToParent(-15, 0));
				mTargetType = NoTarget;
				mActionCounter = 0;
			}
		}
		//l'écureuil a fini son mouvement aléatoire
		else
		{
			mTargetType = NoTarget;
			mActionCounter = 0;
		}
	}	
}
