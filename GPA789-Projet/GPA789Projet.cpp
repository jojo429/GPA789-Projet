// GPA789Projet.cpp
//
// Description:
// Classe principale en charge de cr�er l'interface graphique principal, la simulation et l'environement.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

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

	//Ic�ne et titre de la fen�tre du programme
	setWindowIcon(QIcon(":/GPA789Projet/iconForestSimulation"));
	setWindowTitle("Forest Simulation");

	//Cr�ation des ongleets principaux
	QSimulation *mSimulation = new QSimulation(mForestScene, mEnvironment);
	QStatistic *mStatistic = new QStatistic;
	QSupplement *mSupplement = new QSupplement;
	QTabWidget *mMainTab = new QTabWidget;
	mMainTab->addTab(mSimulation, "Simulation");
	mMainTab->addTab(mStatistic, "Statistics");
	mMainTab->addTab(mSupplement, "Supplement");

	//Mise � jour de l'espace graphique des statistiques quand un cycle complet est termin�
	connect(mSimulation, &QSimulation::advanceDone, mStatistic, &QStatistic::updateData);
	//Calcul du temps d'ex�cution d'un tic et rend la donn�e disponible � l'onglet statistique
	connect(mSimulation, &QSimulation::ticTime, mStatistic, &QStatistic::ticTime);
	//Mise � jour du nombre de cycle �coul� depuis le d�part de la simulation et transfert de l'information � l'onglet statistique
	connect(mSimulation, &QSimulation::updateAdvanceCount, mStatistic, &QStatistic::updateAdvanceCount);
	//Indique que de nouveaux points sont disponibles
	connect(mSimulation, &QSimulation::sendStatistics, mStatistic, &QStatistic::addPoints);

	//Affichage des onglets
	setCentralWidget(mMainTab);

}
