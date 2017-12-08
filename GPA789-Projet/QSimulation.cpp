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
	
	connect(mSimulationMenu, &QSimulationMenu::Play, this, &QSimulation::Play);
	connect(mSimulationMenu, &QSimulationMenu::Pause, this, &QSimulation::Pause);
	connect(mSimulationMenu, &QSimulationMenu::Stop, this, &QSimulation::Stop);
	connect(mSimulationMenu, &QSimulationMenu::Step, this, &QSimulation::Step);


}

QSimulation::~QSimulation()
{
	
}

void QSimulation::Play()
{
	//mSimulationParameters.PrecipitationCycle = mSimulationMenu->mPrecipitation.getCycle();
	//mSimulationParameters.PrecipitationAverage = mSimulationMenu->mPrecipitation.getAverage();
	//mSimulationParameters.PrecipitationVariation = mSimulationMenu->mPrecipitation.getVariation();

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
