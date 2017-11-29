#include "QSimulation.h"
#include "QForestScene.h"
#include "QSimulationMenu.h"
#include <QSplitter>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsRectItem>

QSimulation::QSimulation(QForestScene & forestScene, QWidget *parent)
	: QWidget(parent)
{

	

	QSimulationMenu * SimulationMenu = new QSimulationMenu;
	QHBoxLayout * mainLayout = new QHBoxLayout;


	QGraphicsView *mForestView = new QGraphicsView();
	mForestView->setScene(&forestScene);

	QPen mainPen(Qt::black);

	QGraphicsRectItem * rectangle = new QGraphicsRectItem(0, 0, 80, 100);

	forestScene.addItem(rectangle);

	mainLayout->addWidget(mForestView);
	mainLayout->addWidget(SimulationMenu);
	
	setLayout(mainLayout);
}

QSimulation::~QSimulation()
{
}
