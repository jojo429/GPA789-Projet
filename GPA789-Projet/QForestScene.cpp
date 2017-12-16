#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"
#include "QSquirrel.h"
#include "SimulationStatistics.h"


QForestScene::QForestScene(QEnvironment const & environment, QGraphicsScene * parent)
	: QGraphicsScene(parent), mGenerate(-100, 100), mEnvironment{environment}, mGenerateCoordinate(0,2052)
{
	//Delimitation de la zone de simulation
	



	this->setBackgroundBrush(mBackgroundBrush);
	
	

}


QForestScene::~QForestScene()
{
	

}

void QForestScene::createSeed(QTrees* parent)
{
	QSeeds *newSeed = new QSeeds(mEnvironment, *this , parent->mTreeType, 2);
	newSeed->mHeight = parent->getHeight();
	addItem(newSeed);
	newSeed->setPos(QPointF((parent->pos().x() + (parent->getRadius()*mGenerate.random()/100)),( parent->pos().y()+(parent->getRadius() *mGenerate.random() / 100))));
	mSimulationStatistics->mNumberOfSeeds++;
}

void QForestScene::createTree(QSeeds* parent)
{
	QTrees *newTree;
	switch (parent->mTreeType) {
	mSimulationStatistics->mNumberOfSeeds--;
	mSimulationStatistics->mNumberOfTrees++;
	case Hazel:
		newTree = new QHazel(mEnvironment, *this, Hazel, 20);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfHazel++;
		break;

	case Birch:
		newTree = new QBirch(mEnvironment, *this, Birch, 30);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfBirch++;
		break;

	case Fir:
		newTree = new QFir(mEnvironment, *this, Fir, 500);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfFir++;
		break;

	case Oak:
		newTree = new QOak(mEnvironment, *this, Oak, 200);
		this->addItem(newTree);
		newTree->setPos(QPointF((parent->pos().x()), (parent->pos().y())));
		mSimulationStatistics->mNumberOfOak++;
		break;

	default:
		newTree = new QOak(mEnvironment, *this, Oak, 200);
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
		newSquirrel = new QSquirrel(mEnvironment, *this, 5);
		this->addItem(newSquirrel);
		newSquirrel->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfSquirrel++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberHazel; ++i)
	{
		newTree = new QHazel(mEnvironment, *this, Hazel, 20);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfHazel++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberBirch; ++i) 
	{
		newTree = new QBirch(mEnvironment,*this, Birch, 30);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfBirch++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberOak; ++i)
	{
		newTree = new QOak(mEnvironment, *this, Oak, 200);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfOak++;
	}
	for (int i{ 0 }; i < simulationParameters.mNumberFir; ++i)
	{
		newTree = new QFir(mEnvironment, *this, Fir, 500);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
		mSimulationStatistics->mNumberOfFir++;
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