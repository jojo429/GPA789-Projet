#include "QForestScene.h"
#include "QTrees.h"


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
		QPointF spawnPoint = QPointF(rand() % 1920 + 100, rand() % 1080 + 100);
		QTrees *newTree = new QTrees(enviromnent);
		this->addItem(newTree);
		newTree->setPos(spawnPoint);
	}

}

void QForestScene::closestTree(QPointF pt2D)
{

}

void QForestScene::lightningStrike(QPointF pt2D)
{

}
