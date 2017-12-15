#include "QForestScene.h"
#include "QSeeds.h"
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"
#include "QSquirrel.h"


QForestScene::QForestScene(QEnvironment const & environment, QGraphicsScene * parent)
	: QGraphicsScene(parent), mGenerate(0, 3), mEnvironment{environment}
{
	//Delimitation de la zone de simulation
	this->addLine(0, 0, 2050, 0);
	this->addLine(0, 0, 0, 2050);
	this->addLine(2050, 0, 2050, 2050);
	this->addLine(0, 2050, 2050, 2050);



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

		case 0: 	newTree = new QOak(environment,*this, Oak);
					break; 

		case 1: 	newTree = new QFir(environment,*this, Fir);
					break; 

		case 2: 	newTree = new QHazel(environment,*this, Hazel);
					break; 

		case 3: 	newTree = new QBirch(environment,*this, Birch);
					break; 

		default:	newTree = new QOak(environment, *this,Oak);
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

	QSquirrel *squirrel = new QSquirrel(environment, *this);
	this->addItem(squirrel);
	squirrel->setPos(QPointF(1000, 1000));
	

}


QForestScene::~QForestScene()
{
	

}

void QForestScene::createSeed(QTrees* parent)
{
	QSeeds *newSeed = new QSeeds(mEnvironment, *this , parent->mTreeType);
	newSeed->mHeight = parent->getHeight();
	addItem(newSeed);
	newSeed->setPos(QPointF((parent->pos().x() + parent->getRadius()/2),( parent->pos().y()+parent->getRadius() / 2)));

}


void QForestScene::closestTree(QPointF pt2D)
{

}

void QForestScene::lightningStrike(QPointF pt2D)
{

}
