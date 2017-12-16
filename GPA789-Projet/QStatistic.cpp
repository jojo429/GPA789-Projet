#include "QStatistic.h"
#include <QVBoxLayout>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	
	//Générer les graphiques
	mMainGraph = new QEvolutionGraph(4);
	mMainGraph->initializeGraph("Time", "General units", "Main Graph");
	
	QVBoxLayout * graphLayout = new QVBoxLayout;
	graphLayout->addWidget(mMainGraph);
	graphLayout->addStretch();

	QLabel *titleLabel = new QLabel("Statistiques diverses");
	mTemperatureStat = new QStatisticAdvanceMenu(true, false, true);
	mPrecipitationStat = new QStatisticAdvanceMenu(true, false, true);
	mLuminosityStat = new QStatisticAdvanceMenu(true, false, true);
	mWindStat = new QStatisticAdvanceMenu(true, false, true);

	QVBoxLayout * valueLayout = new QVBoxLayout;
	valueLayout->addWidget(titleLabel);
	valueLayout->addWidget(mTemperatureStat);
	valueLayout->addWidget(mPrecipitationStat);
	valueLayout->addWidget(mLuminosityStat);
	valueLayout->addWidget(mWindStat);
	valueLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(graphLayout);
	mainLayout->addLayout(valueLayout);

	setLayout(mainLayout);

	connect(mTemperatureStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setTemperatureVisible);
	connect(mPrecipitationStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setPrecipitationVisible);
	connect(mLuminosityStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setLuminosityVisible);
	connect(mWindStat, &QStatisticAdvanceMenu::showGraphToggled, this, &QStatistic::setWindVisible);
}

QStatistic::~QStatistic()
{
}

void QStatistic::addPoints(SimulationStatistics stats) 
{
	mMainGraph->addPoint(0, mTime, stats.mTemperature);
	mMainGraph->addPoint(1, mTime, stats.mPrecipitation);
	mMainGraph->addPoint(2, mTime, stats.mLuminosity);
	mMainGraph->addPoint(3, mTime, stats.mWind);
	
	mTime++;

	mTemperatureStat->setNewValue(mTime, stats.mTemperature);
	mPrecipitationStat->setNewValue(mTime, stats.mPrecipitation);
	mLuminosityStat->setNewValue(mTime, stats.mLuminosity);
	mWindStat->setNewValue(mTime, stats.mWind);
}

void QStatistic::updateData()
{
	mMainGraph->updateAxis();
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