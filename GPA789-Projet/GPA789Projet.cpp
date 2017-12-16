#include "GPA789Projet.h"

#include "QSimulation.h"
#include "QSimulationMenu.h"
#include "QStatistic.h"
#include "QRandomMap.h"
#include "SimulationStatistics.h"
#include "QSupplement.h"

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

#include "QFertility.h"

GPA789Projet::GPA789Projet(QWidget *parent)
	: QMainWindow(parent), mForestScene(mEnvironment)
{
	ui.setupUi(this);

	//Icône et titre de la fenêtre du programme
	setWindowIcon(QIcon(":/GPA789Projet/iconForestSimulation"));
	setWindowTitle("Forest Simulation");

	QSimulation *mSimulation = new QSimulation(mForestScene, mEnvironment);
	QStatistic *mStatistic = new QStatistic;
	QSupplement *mSupplement = new QSupplement;

	QTabWidget *mMainTab = new QTabWidget;

	mMainTab->addTab(mSimulation, "Simulation");
	mMainTab->addTab(mStatistic, "Statistics");
	mMainTab->addTab(mSupplement, "Supplement");

	
	connect(mSimulation, &QSimulation::advanceDone, mStatistic, &QStatistic::updateData);
	connect(mSimulation, &QSimulation::ticTime, mStatistic, &QStatistic::ticTime);
	connect(mSimulation, &QSimulation::updateAdvanceCount, mStatistic, &QStatistic::updateAdvanceCount);
	connect(mSimulation, &QSimulation::sendStatistics, mStatistic, &QStatistic::addPoints);

	setCentralWidget(mMainTab);

}
