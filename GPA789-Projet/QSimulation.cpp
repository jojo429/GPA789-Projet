#include "QSimulation.h"
#include "QSimulationMenu.h"
#include <QSplitter>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsRectItem>
#include <QTimer>

QSimulation::QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent)
	: QWidget(parent)
{

	

	QSimulationMenu * SimulationMenu = new QSimulationMenu;
	QHBoxLayout * mainLayout = new QHBoxLayout;


	QGraphicsView *mForestView = new QGraphicsView();
	mForestView->setRenderHint(QPainter::Antialiasing);
	mForestView->setScene(&forestScene);


	mainLayout->addWidget(mForestView);
	mainLayout->addWidget(SimulationMenu);
	
	setLayout(mainLayout);


	


	connect(&mTimer, SIGNAL(timeout()), &environment, SLOT(advance()));
	connect(&mTimer, SIGNAL(timeout()), &forestScene, SLOT(advance()));
	
	connect(SimulationMenu, &QSimulationMenu::Play, this, &QSimulation::Play);
	connect(SimulationMenu, &QSimulationMenu::Pause, this, &QSimulation::Pause);
	connect(SimulationMenu, &QSimulationMenu::Stop, this, &QSimulation::Stop);
	connect(SimulationMenu, &QSimulationMenu::Step, this, &QSimulation::Step);


}

QSimulation::~QSimulation()
{
	
}

void QSimulation::Play()
{
	mTimer.start(30);

}

void QSimulation::Pause()
{

	mTimer.stop();
}

void QSimulation::Stop()
{

	mTimer.stop();
}

void QSimulation::Step()
{
}
