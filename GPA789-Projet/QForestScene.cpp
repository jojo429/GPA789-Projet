#include "QForestScene.h"
#include "QTrees.h"


QForestScene::QForestScene(QGraphicsScene * parent )
	: QGraphicsScene(parent)
{
	QTrees *mTree1 = new QTrees;
	QTrees *mTree2 = new QTrees;
	QTrees *mTree3 = new QTrees;
	this->addItem(mTree1);
	this->addItem(mTree2);
	this->addItem(mTree3);
	mTree1->setPos(25, 25);
	mTree2->setPos(80, 25);
	mTree3->setPos(40, 75);

}


QForestScene::~QForestScene()
{
	

}
