#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"
#include "QSquirrel.h"


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
	}
	for (int i{ 0 }; i < simulationParameters.mNumberHazel; ++i)
	{
		newTree = new QHazel(mEnvironment, *this, Hazel, 20);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
	}
	for (int i{ 0 }; i < simulationParameters.mNumberBirch; ++i) 
	{
		newTree = new QBirch(mEnvironment,*this, Birch, 30);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
	}
	for (int i{ 0 }; i < simulationParameters.mNumberOak; ++i)
	{
		newTree = new QOak(mEnvironment, *this, Oak, 200);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
	}
	for (int i{ 0 }; i < simulationParameters.mNumberFir; ++i)
	{
		newTree = new QFir(mEnvironment, *this, Fir, 500);
		this->addItem(newTree);
		newTree->setPos(QPointF(mGenerateCoordinate.random(), mGenerateCoordinate.random()));
	}


}