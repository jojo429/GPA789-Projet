#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"
#include "QSquirrel.h"
#include "SimulationStatistics.h"
#include "QFertility.h"
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QRectF>
#include <QDebug>


QForestScene::QForestScene(QEnvironment & environment, QGraphicsScene * parent)
	: QGraphicsScene(parent), mGenerate(-100, 100), mEnvironment{environment}, mGenerateCoordinate(5,2045), mGenerateShortLifespan(0,1), mGenerateLongLifespan(1,2)
{
	//Delimitation de la zone de simulation



	QPixmap fertilityPixmap = (mEnvironment.mFertility).getFertilityPixmap();

	this->setSceneRect(0, 0, 2052, 2052);
	this->setBackgroundBrush(QBrush(fertilityPixmap.scaled(2052, 2052, Qt::KeepAspectRatio)));
}


QForestScene::~QForestScene()
{
	

}

void QForestScene::createSeed(QTrees* parent)
{
	QSeeds *newSeed = new QSeeds(mEnvironment, *this ,  mGenerateShortLifespan.random(), parent->mTreeType, Seed, parent->getHeight());
	addItem(newSeed);
	newSeed->setPos(QPointF((parent->pos().x() + (parent->getRadius()*mGenerate.random()/100)),( parent->pos().y()+(parent->getRadius() *mGenerate.random() / 100))));
	mSimulationStatistics->mNumberOfSeeds++;
}

void QForestScene::createTree(QSeeds* parent)
{
	QTrees *newTree;
	mSimulationStatistics->mNumberOfTrees++;
	mSimulationStatistics->mNumberOfGermination++;
	switch (parent->mTreeType) {
	
	case Hazel:
		newTree = new QHazel(mEnvironment, *this,  mGenerateShortLifespan.random(), Hazel, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfHazel++;
		break;

	case Birch:
		newTree = new QBirch(mEnvironment, *this,  mGenerateShortLifespan.random(), Birch, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfBirch++;
		break;

	case Fir:
		newTree = new QFir(mEnvironment, *this,  mGenerateLongLifespan.random(), Fir, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfFir++;
		break;

	case Oak:
		newTree = new QOak(mEnvironment, *this,  mGenerateLongLifespan.random(), Oak, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfOak++;
		break;

	default:
		newTree = new QOak(mEnvironment, *this,  mGenerateLongLifespan.random(), Oak, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfOak++;

	}
	

}


void QForestScene::closestTree(QPointF pt2D)
{

}

void QForestScene::lightningStrike(QPointF pt2D)
{

}

void QForestScene::setParameters(SimulationParameters &simulationParameters)
{
	this->addLine(0, 0, 2050, 0);
	this->addLine(0, 0, 0, 2050);
	this->addLine(2050, 0, 2050, 2050);
	this->addLine(0, 2050, 2050, 2050);
	
	QTrees *newTree;
	QSquirrel *newSquirrel;

	for (int i{ 0 }; i < simulationParameters.mNumberSquirrel; ++i)
	{
		newSquirrel = new QSquirrel(mEnvironment, *this, 5, Na, Squirrel);
		this->addItem(newSquirrel);
		newSquirrel->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfSquirrel++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberHazel; ++i)
	{
		newTree = new QHazel(mEnvironment, *this,  mGenerateShortLifespan.random(), Hazel, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfHazel++;
		mSimulationStatistics->mNumberOfTrees++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberBirch; ++i) 
	{
		newTree = new QBirch(mEnvironment,*this,  mGenerateShortLifespan.random(), Birch, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfBirch++;
		mSimulationStatistics->mNumberOfTrees++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberOak; ++i)
	{
		newTree = new QOak(mEnvironment, *this, mGenerateLongLifespan.random(), Oak, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfOak++;
		mSimulationStatistics->mNumberOfTrees++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberFir; ++i)
	{
		newTree = new QFir(mEnvironment, *this, mGenerateLongLifespan.random(), Fir, Tree);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfFir++;
		mSimulationStatistics->mNumberOfTrees++;
	}


}

void QForestScene::setStatistic(SimulationStatistics *simulationStatistics)
{
	mSimulationStatistics = simulationStatistics;
}

void QForestScene::windAngle(int windAngle)
{

	mWindAngle = windAngle;
}

void QForestScene::destroyDeadEntities()
{
	
	
	for (QGraphicsItem * currentItem : items())
	{
		mEntities.append(dynamic_cast<QEntity*>(currentItem));

	}


	for (QEntity * entity : mEntities)
	{
		if (entity)
		{
			if ((entity->isDead()))
			{

				switch (entity->mGeneralType) 
				{

				case Seed:
					mSimulationStatistics->mNumberOfSeeds--;
					break;

				case Tree:

					mSimulationStatistics->mNumberOfTrees--;

					switch (entity->mTreeType)
					{

					case Birch:
						mSimulationStatistics->mNumberOfBirch--;
						break;

					case Fir:
						mSimulationStatistics->mNumberOfFir--;
						break;
					case Oak:
						mSimulationStatistics->mNumberOfOak--;
						break;
					case Hazel:
						mSimulationStatistics->mNumberOfHazel--;
						break;
					default:
						mSimulationStatistics->mNumberOfOak--;
						break;
					}
					break;
				default:
					mSimulationStatistics->mNumberOfSeeds--;
					break;
				}

				removeItem(entity);
				delete entity;
			}
		}	
	}

	mEntities.clear();
	

}