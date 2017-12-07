#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"

QForestScene::QForestScene(QGraphicsScene * parent)
	: QGraphicsScene(parent)
{


}


QForestScene::~QForestScene()
{
	

}


void QForestScene::initialize(QEnvironment const & enviromnent)
{
	
	
	int treeCount{ 150 };

	for (int i{ 0 }; i < treeCount; ++i) {
		//Add trees
		QPointF spawnPoint = QPointF(rand() % 1920 + 100, rand() % 1080 + 100);
		QTrees *newTree = new QOak(enviromnent);
		this->addItem(newTree);
		newTree->setPos(spawnPoint);

		//Add seeds
		QSeeds *newSeed = new QSeeds(enviromnent);
		this->addItem(newSeed);
		newSeed->setPos(spawnPoint);
	}

}

void QForestScene::closestTree(QPointF pt2D)
{

}

void QForestScene::lightningStrike(QPointF pt2D)
{

}
