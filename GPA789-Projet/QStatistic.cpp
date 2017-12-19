// QStatistic.cpp
//
// Description:
// Widget gérant l'affichage de l'onglet statistique de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QStatistic.h"
#include <QVBoxLayout>
#include <QGroupBox>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	
	//Générer le graphique avec 11 série de donnée
	mMainGraph = new QEvolutionGraph(11);
	mMainGraph->initializeGraph("Time", "General units", "");

	//Label permettant d'afficher le temps de rafraichissement de la simulation
	QLabel *ticTimeLabel = new QLabel("Refresh time (ms) :");
	mTicTimeValue = new QLabel("0");
	//Label pertettant d'afficher le nombre de cycle exécuté 
	QLabel *mNbAdvanceCountLabel = new QLabel("Advance executed :");
	mNbAdvanceCountValue = new QLabel("0");

	//Déclaration de statistiques diverses entourant les facteurs environnementaux 
	//et les entitées présent sur la scène
	mTemperatureStat = new QStatisticAdvanceMenu(true, false, true, "Temperature");
	mPrecipitationStat = new QStatisticAdvanceMenu(true, false, true, "Precipitation");
	mLuminosityStat = new QStatisticAdvanceMenu(true, false, true, "Luminosity");
	mWindStat = new QStatisticAdvanceMenu(true, false, true, "Wind");
	mTreesStat = new QStatisticAdvanceMenu(true, false, true, "Trees");
	mOakStat = new QStatisticAdvanceMenu(true, false, true, "Oak");
	mFirStat = new QStatisticAdvanceMenu(true, false, true, "Fir");
	mBirchStat = new QStatisticAdvanceMenu(true, false, true, "Birch");
	mHazelStat = new QStatisticAdvanceMenu(true, false, true, "Hazel");
	mSeedsStat = new QStatisticAdvanceMenu(true, false, true, "Seeds");
	mGerminationStat = new QStatisticAdvanceMenu(true, false, true, "Germination");

	//Mise en forme de l'affichage des statistiques
	QVBoxLayout * generalStatRightLayout = new QVBoxLayout;
	generalStatRightLayout->addWidget(ticTimeLabel);
	generalStatRightLayout->addWidget(mNbAdvanceCountLabel);

	//Mise en forme des statistique consernant le runtime
	QVBoxLayout * generalStatLeftLayout = new QVBoxLayout;
	generalStatLeftLayout->addWidget(mTicTimeValue);
	generalStatLeftLayout->addWidget(mNbAdvanceCountValue);

	QHBoxLayout * generalStatLayout = new QHBoxLayout;
	generalStatLayout->addLayout(generalStatRightLayout);
	generalStatLayout->addLayout(generalStatLeftLayout);

	QGroupBox * generalStatGroupBox = new QGroupBox("Runtime");
	generalStatGroupBox->setLayout(generalStatLayout);

	//Mises en forme des statistique général du programme
	//dans la colone de gauche
	QVBoxLayout * valueRightLayout = new QVBoxLayout;
	valueRightLayout->addWidget(mTemperatureStat);
	valueRightLayout->addWidget(mPrecipitationStat);
	valueRightLayout->addWidget(mLuminosityStat);
	valueRightLayout->addWidget(mWindStat);
	valueRightLayout->addWidget(mSeedsStat);
	valueRightLayout->addStretch();

	//Mises en forme des statistique général du programme
	//dans la colone de droite
	QVBoxLayout * valueLeftLayout = new QVBoxLayout;
	valueLeftLayout->addWidget(mTreesStat);
	valueLeftLayout->addWidget(mOakStat);
	valueLeftLayout->addWidget(mFirStat);
	valueLeftLayout->addWidget(mBirchStat);
	valueLeftLayout->addWidget(mHazelStat);
	valueLeftLayout->addWidget(mGerminationStat);
	valueLeftLayout->addStretch();

	//Mises en forme des colones de statistiques générales
	QHBoxLayout * valueSpecificStatLayout = new QHBoxLayout;
	valueSpecificStatLayout->addLayout(valueRightLayout);
	valueSpecificStatLayout->addLayout(valueLeftLayout);

	//Ajout des statistiques générales en dessous des statistiques du runtime
	QVBoxLayout * valueGeneralStatLayout = new QVBoxLayout;
	valueGeneralStatLayout->addWidget(generalStatGroupBox);
	valueGeneralStatLayout->addLayout(valueSpecificStatLayout);

	//Mettre les statistique dans un groupbox avant de les définir 
	//dans une scroll bar
	QGroupBox * valueStatGroupBox = new QGroupBox;
	valueStatGroupBox->setLayout(valueGeneralStatLayout);
	valueStatGroupBox->setFlat(true);

	//Définition d'une zone de défilement pour pouvoir inclure un grand nombre 
	//de statistique sans affecter le layout général de la zone graphique
	QScrollArea * statsScrollArea = new QScrollArea;
	statsScrollArea->setWidget(valueStatGroupBox);
	statsScrollArea->setWidgetResizable(true);
	statsScrollArea->setBackgroundRole(QPalette::Light);
	statsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	statsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	statsScrollArea->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

	QHBoxLayout * widgetToLayout = new QHBoxLayout;
	widgetToLayout->addWidget(statsScrollArea);

	//Mettre tout les statistiques dans un group box général
	QGroupBox * valueLayoutGroupBox = new QGroupBox("Statistics");
	valueLayoutGroupBox->setLayout(widgetToLayout);

	//Mettre l'espace graphique à gauche des statistiques
	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addWidget(mMainGraph);
	mainLayout->addWidget(valueLayoutGroupBox);

	setLayout(mainLayout);

	//Créer le lien permettant d'afficher ou non les statistiques du programme
	connect(mTemperatureStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setTemperatureVisible);
	connect(mPrecipitationStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setPrecipitationVisible);
	connect(mLuminosityStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setLuminosityVisible);
	connect(mWindStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setWindVisible);

	connect(mTreesStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setTreesVisible);
	connect(mOakStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setOakVisible);
	connect(mFirStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setFirVisible);
	connect(mBirchStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setBirchVisible);
	connect(mHazelStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setHazelVisible);
	connect(mSeedsStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setSeedsVisible);
	connect(mGerminationStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setGerminationVisible);
}


void QStatistic::addPoints(SimulationStatistics stats) 
{
	//Ajout d'un point à chacune des série de données pour l'affichage du graphique
	//à à tout les 5 point ajouté
	if (mTime % 5 == 0) {
		mMainGraph->addPoint(0, mTime, stats.mTemperature);
		mMainGraph->addPoint(1, mTime, stats.mPrecipitation);
		mMainGraph->addPoint(2, mTime, stats.mLuminosity);
		mMainGraph->addPoint(3, mTime, stats.mWind);

		mMainGraph->addPoint(4, mTime, stats.mNumberOfTrees);
		mMainGraph->addPoint(5, mTime, stats.mNumberOfOak);
		mMainGraph->addPoint(6, mTime, stats.mNumberOfFir);
		mMainGraph->addPoint(7, mTime, stats.mNumberOfBirch);
		mMainGraph->addPoint(8, mTime, stats.mNumberOfHazel);
		mMainGraph->addPoint(9, mTime, stats.mNumberOfSeeds);
		mMainGraph->addPoint(10, mTime, stats.mNumberOfGermination);
	}
	
	mTime++;

	//Calculs des statistisques pour cacune des données 
	mTemperatureStat->setNewValue(mTime, stats.mTemperature);
	mPrecipitationStat->setNewValue(mTime, stats.mPrecipitation);
	mLuminosityStat->setNewValue(mTime, stats.mLuminosity);
	mWindStat->setNewValue(mTime, stats.mWind);

	mTreesStat->setNewValue(mTime, stats.mNumberOfTrees);
	mOakStat->setNewValue(mTime, stats.mNumberOfOak);
	mFirStat->setNewValue(mTime, stats.mNumberOfFir);
	mBirchStat->setNewValue(mTime, stats.mNumberOfBirch);
	mHazelStat->setNewValue(mTime, stats.mNumberOfHazel);
	mSeedsStat->setNewValue(mTime, stats.mNumberOfSeeds);
	mGerminationStat->setNewValue(mTime, stats.mNumberOfGermination);

}
//Mise à jour des axes du graphique
void QStatistic::updateData()
{
	mMainGraph->updateAxis();
}

//Permet de mettre à jour le texte du temps passé pour une boucle du programme
void QStatistic::ticTime(qint64 timePassed) {
	mTicTimeValue->setText(QString::number(timePassed));
}
//Met à jour le nombre de boucle exécuté par le programme depuis le début d'une simulation
void QStatistic::updateAdvanceCount(int advanceCount) {
	mNbAdvanceCountValue->setText(QString::number(advanceCount));
}
//Les fonctions ci-dessous permettent de définir la visibilité d'une statistique particulière
void QStatistic::setTemperatureVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(0, isVisible);
}
void QStatistic::setPrecipitationVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(1, isVisible);
}
void QStatistic::setLuminosityVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(2, isVisible);
}
void QStatistic::setWindVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(3, isVisible);
}
void QStatistic::setTreesVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(4, isVisible);
}
void QStatistic::setOakVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(5, isVisible);
}
void QStatistic::setFirVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(6, isVisible);
}
void QStatistic::setBirchVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(7, isVisible);
}
void QStatistic::setHazelVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(8, isVisible);
}
void QStatistic::setSeedsVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(9, isVisible);
}
void QStatistic::setGerminationVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(10, isVisible);
}