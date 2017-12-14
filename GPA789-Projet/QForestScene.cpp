#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"
#include "QSquirrel.h"


QForestScene::QForestScene(QEnvironment const & enviromnent, QGraphicsScene * parent)
	: QGraphicsScene(parent), mGenerate(0, 3)
{

	this->setBackgroundBrush(mBackgroundBrush);
	int treeCount{ 15 };
	int tree;

	//Setting up the master trees
	//mMasterOak.setMasterTree(&mMasterOak);
	//mMasterHazel.setMasterTree(&mMasterHazel);
	//mMasterBirch.setMasterTree(&mMasterBirch);
	//mMasterFir.setMasterTree(&mMasterFir);
	QTrees *newTree;
	for (int i{ 0 }; i < treeCount; ++i) {

		//Add trees
		tree = mGenerate.random();
		QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
		switch (tree) {

		case 0: 	newTree = new QOak(enviromnent, Oak); 
					break; 

		case 1: 	newTree = new QFir(enviromnent, Fir);
					break; 

		case 2: 	newTree = new QHazel(enviromnent, Hazel);
					break; 

		case 3: 	newTree = new QBirch(enviromnent, Birch);
					break; 

		default:	newTree = new QOak(enviromnent, Oak);
					break;
		}

		this->addItem(newTree);
		newTree->setPos(spawnPoint);
		
	}

	//	//Add seeds
	//	//QSeeds *newSeed = new QSeeds(enviromnent);
	//	//this->addItem(newSeed);
	//	//newSeed->setPos(spawnPoint);
	//}
	//for (int i{ 0 }; i < treeCount; ++i) {
	//	//Add trees
	//	QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
	//	QTrees *newTree = new QHazel(enviromnent);
	//	this->addItem(newTree);
	//	newTree->setPos(spawnPoint);
	//}
	//for (int i{ 0 }; i < treeCount; ++i) {
	//	//Add trees
	//	QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
	//	QTrees *newTree = new QBirch(enviromnent);
	//	this->addItem(newTree);
	//	newTree->setPos(spawnPoint);
	//}
	//for (int i{ 0 }; i < treeCount; ++i) {
	//	//Add trees
	//	QPointF spawnPoint = QPointF(rand() % 2049 + 100, rand() % 2049 + 100);
	//	QTrees *newTree = new QFir(enviromnent);
	//	this->addItem(newTree);
	//	newTree->setPos(spawnPoint);
	//}

	//QPointF spawnPoint = QPointF(1050,1050);
	//QTrees *newTree = new QOak(enviromnent);
	//this->addItem(newTree);
	//newTree->setPos(spawnPoint);

	QSquirrel *squirrel = new QSquirrel(enviromnent);
	this->addItem(squirrel);
	squirrel->setPos(QPointF(1000, 1000));


}


QForestScene::~QForestScene()
{
	

}




void QForestScene::closestTree(QPointF pt2D)
{

}

void QForestScene::lightningStrike(QPointF pt2D)
{

}
