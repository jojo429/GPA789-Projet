#include "GPA789Projet.h"

#include "QSimulation.h"
#include "QSimulationMenu.h"
#include "QStatistic.h"
#include "QRandomMap.h"
#include "SimulationStatistics.h"

#include <QGraphicsGridLayout>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QWidget>
#include <QSplitter>
#include <QScrollBar>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>

GPA789Projet::GPA789Projet(QWidget *parent)
	: QMainWindow(parent), mForestScene(mEnvironment)
{
	ui.setupUi(this);



	QSimulation *mSimulation = new QSimulation(mForestScene, mEnvironment);
	QStatistic *mStatistic = new QStatistic;

	QTabWidget *mMainTab = new QTabWidget;

	mMainTab->addTab(mSimulation, "Simulation");
	mMainTab->addTab(mStatistic, "Statistics");

	/*
	// Test Geneviève
	QRandomMap *mMap= new QRandomMap;
	mMap->setMap();
	mMap->findMinMax();
	mMap->scaleValuesRangeMap(0.0, 100.0);
	mMap->drawMap(244, 164, 96); //244, 164, 96
	mMap->resizeMap();
	mMap->setMapValue(1000, 500, 50.0);
	mMap->updateDrawMap(1000, 500);*/
	
	connect(mSimulation, &QSimulation::advanceDone, mStatistic, &QStatistic::updateData);
	connect(mSimulation, &QSimulation::ticTime, mStatistic, &QStatistic::ticTime);
	connect(mSimulation, &QSimulation::updateAdvanceCount, mStatistic, &QStatistic::updateAdvanceCount);
	connect(mSimulation, &QSimulation::sendStatistics, mStatistic, &QStatistic::addPoints);
/*

	QHBoxLayout *firstLvlSettings = new QHBoxLayout;

	QSlider *luminositySlider = new QSlider;
	QSlider *rainSlider = new QSlider;

	firstLvlSettings->addWidget(luminositySlider);
	firstLvlSettings->addWidget(rainSlider);

	QVBoxLayout *settingsLayout = new QVBoxLayout;

	settingsLayout->addLayout(firstLvlSettings);

	QWidget *settingsWidget = new QWidget;
	settingsWidget->setLayout(settingsLayout);

	settingsScene->addWidget(settingsWidget);

	QGraphicsView *animationView = new QGraphicsView(animationScene, Q_NULLPTR);
	QGraphicsView *settingsView = new QGraphicsView(settingsScene, Q_NULLPTR);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(animationView);
	layout->addWidget(settingsView);

	QWidget *mainWindow = new QWidget;
	mainWindow->setLayout(layout);*/

	setCentralWidget(mMainTab);

}
