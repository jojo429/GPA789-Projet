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
	
	//Générer les graphiques
	mMainGraph = new QEvolutionGraph(11);
	mMainGraph->initializeGraph("Time", "General units", "");

	QLabel *ticTimeLabel = new QLabel("Refresh time (ms) :");
	mTicTimeValue = new QLabel("0");

	QLabel *mNbAdvanceCountLabel = new QLabel("Advance executed :");
	mNbAdvanceCountValue = new QLabel("0");

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

	QVBoxLayout * generalStatRightLayout = new QVBoxLayout;
	generalStatRightLayout->addWidget(ticTimeLabel);
	generalStatRightLayout->addWidget(mNbAdvanceCountLabel);

	QVBoxLayout * generalStatLeftLayout = new QVBoxLayout;
	generalStatLeftLayout->addWidget(mTicTimeValue);
	generalStatLeftLayout->addWidget(mNbAdvanceCountValue);

	QHBoxLayout * generalStatLayout = new QHBoxLayout;
	generalStatLayout->addLayout(generalStatRightLayout);
	generalStatLayout->addLayout(generalStatLeftLayout);

	QGroupBox * generalStatGroupBox = new QGroupBox("Runtime");
	generalStatGroupBox->setLayout(generalStatLayout);

	QVBoxLayout * valueRightLayout = new QVBoxLayout;
	valueRightLayout->addWidget(mTemperatureStat);
	valueRightLayout->addWidget(mPrecipitationStat);
	valueRightLayout->addWidget(mLuminosityStat);
	valueRightLayout->addWidget(mWindStat);
	valueRightLayout->addWidget(mSeedsStat);
	valueRightLayout->addStretch();

	QVBoxLayout * valueLeftLayout = new QVBoxLayout;
	valueLeftLayout->addWidget(mTreesStat);
	valueLeftLayout->addWidget(mOakStat);
	valueLeftLayout->addWidget(mFirStat);
	valueLeftLayout->addWidget(mBirchStat);
	valueLeftLayout->addWidget(mHazelStat);
	valueLeftLayout->addWidget(mGerminationStat);
	valueLeftLayout->addStretch();

	QHBoxLayout * valueSpecificStatLayout = new QHBoxLayout;
	valueSpecificStatLayout->addLayout(valueRightLayout);
	valueSpecificStatLayout->addLayout(valueLeftLayout);

	QVBoxLayout * valueGeneralStatLayout = new QVBoxLayout;
	valueGeneralStatLayout->addWidget(generalStatGroupBox);
	valueGeneralStatLayout->addLayout(valueSpecificStatLayout);

	QGroupBox * valueStatGroupBox = new QGroupBox;
	valueStatGroupBox->setLayout(valueGeneralStatLayout);
	valueStatGroupBox->setFlat(true);

	QScrollArea * statsScrollArea = new QScrollArea;
	statsScrollArea->setWidget(valueStatGroupBox);
	statsScrollArea->setWidgetResizable(true);
	statsScrollArea->setBackgroundRole(QPalette::Light);
	statsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	statsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	statsScrollArea->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

	QHBoxLayout * widgetToLayout = new QHBoxLayout;
	widgetToLayout->addWidget(statsScrollArea);

	QGroupBox * valueLayoutGroupBox = new QGroupBox("Statistics");
	valueLayoutGroupBox->setLayout(widgetToLayout);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addWidget(mMainGraph);
	mainLayout->addWidget(valueLayoutGroupBox);

	setLayout(mainLayout);

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
	
	mTime++;

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

void QStatistic::updateData()
{
	mMainGraph->updateAxis();
}

void QStatistic::ticTime(qint64 timePassed) {
	mTicTimeValue->setText(QString::number(timePassed));
}
void QStatistic::updateAdvanceCount(int advanceCount) {
	mNbAdvanceCountValue->setText(QString::number(advanceCount));
}

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