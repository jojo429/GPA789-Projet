#include "QSimulation.h"
#include "QForestScene.h"
#include "QSimulationMenu.h"
#include <QSplitter>
#include <QGraphicsView>

QSimulation::QSimulation(QWidget *parent)
	: QWidget(parent)
{

	

	QSimulationMenu *mSimulationMenu = new QSimulationMenu;
	QForestScene *mForestScene = new QForestScene;
	QSplitter *mSimulationSplitter = new QSplitter;



	QGraphicsView *mForestView = new QGraphicsView(mForestScene, Q_NULLPTR);



	mSimulationSplitter->addWidget(mForestView);
	mSimulationSplitter->addWidget(mSimulationMenu);
}

QSimulation::~QSimulation()
{
}
