#include "GPA789Projet.h"

#include "QSimulation.h"
#include "QSimulationMenu.h"
#include "QStatistic.h"

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
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mForestScene.initialize(mEnvironment);

	QSimulation *mSimulation = new QSimulation(mForestScene, mEnvironment);
	QStatistic *mStatistic = new QStatistic;

	QTabWidget *mMainTab = new QTabWidget;

	//TEST
	QSimulationMenu *mSimulationMenu = new QSimulationMenu();
	mMainTab->addTab(mSimulation, "Simulation");
	mMainTab->addTab(mSimulationMenu, "Simulation");
	mMainTab->addTab(mStatistic, "Statistics");

	

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
