#include "QForestScene.h"
#include "QTrees.h"


QForestScene::QForestScene(QGraphicsScene * parent )
	: QGraphicsScene(parent)
{
	int treeCount{ 150 };

	for (int i{ 0 }; i < treeCount; ++i) {
		QPointF spawnPoint = QPointF(rand() % 1920 + 100, rand() % 1080 + 100);
		QTrees *newTree = new QTrees;
		this->addItem(newTree);
		newTree->setPos(spawnPoint);
	}


}


QForestScene::~QForestScene()
{
	

}
