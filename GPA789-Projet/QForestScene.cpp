#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"
#include "QSquirrel.h"


QForestScene::QForestScene(QGraphicsScene * parent)
	: QGraphicsScene(parent)
{
	



}


QForestScene::~QForestScene()
{
	

}


void QForestScene::initialize(QEnvironment const & enviromnent)
{
	
	this->setBackgroundBrush(mBackgroundBrush);
	int treeCount{ 50 };

	for (int i{ 0 }; i < treeCount; ++i) {
		//Add trees
		QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
		QTrees *newTree = new QOak(enviromnent);
		this->addItem(newTree);
		newTree->setPos(spawnPoint);

		//Add seeds
		QSeeds *newSeed = new QSeeds(enviromnent);
		this->addItem(newSeed);
		newSeed->setPos(spawnPoint);
	}
	for (int i{ 0 }; i < treeCount; ++i) {
		//Add trees
		QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
		QTrees *newTree = new QHazel(enviromnent);
		this->addItem(newTree);
		newTree->setPos(spawnPoint);
	}
	for (int i{ 0 }; i < treeCount; ++i) {
		//Add trees
		QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
		QTrees *newTree = new QBirch(enviromnent);
		this->addItem(newTree);
		newTree->setPos(spawnPoint);
	}
	for (int i{ 0 }; i < treeCount; ++i) {
		//Add trees
		QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
		QTrees *newTree = new QFir(enviromnent);
		this->addItem(newTree);
		newTree->setPos(spawnPoint);
	}
	QSquirrel *squirrel = new QSquirrel(enviromnent);
	this->addItem(squirrel);
	squirrel->setPos(QPointF(1000, 1000));

}

void QForestScene::closestTree(QPointF pt2D)
{

}

void QForestScene::lightningStrike(QPointF pt2D)
{

}
