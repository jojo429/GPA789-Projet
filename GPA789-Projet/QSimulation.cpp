#include "QSimulation.h"

#include <QSplitter>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsRectItem>
#include <QTimer>

QSimulation::QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent)
	: QWidget(parent), mEnvironment {environment}
{

	

	mSimulationMenu = new QSimulationMenu;
	QHBoxLayout * mainLayout = new QHBoxLayout;


	QGraphicsView *mForestView = new QGraphicsView();
	mForestView->setRenderHint(QPainter::Antialiasing);
	mForestView->setScene(&forestScene);


	mainLayout->addWidget(mForestView);
	mainLayout->addWidget(mSimulationMenu);
	
	setLayout(mainLayout);


	


	connect(&mTimer, &QTimer::timeout, &environment, &QEnvironment::advance);
	connect(&mTimer, &QTimer::timeout, &forestScene, &QForestScene::advance);
	
	connect(mSimulationMenu, &QSimulationMenu::play, this, &QSimulation::play);
	connect(mSimulationMenu, &QSimulationMenu::pause, this, &QSimulation::pause);
	connect(mSimulationMenu, &QSimulationMenu::stop, this, &QSimulation::stop);
	connect(mSimulationMenu, &QSimulationMenu::step, this, &QSimulation::step);


}

QSimulation::~QSimulation()
{
	
}

void QSimulation::play()
{
	
	mSimulationMenu->getParameters(&mSimulationParameters);

	mTimer.start(30);

}

void QSimulation::pause()
{

	mTimer.stop();
}

void QSimulation::stop()
{

	mTimer.stop();
}

void QSimulation::step()
{



}
