#include "QStatistic.h"
#include <QVBoxLayout>
#include <QGroupBox>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	
	//Générer les graphiques
	mMainGraph = new QEvolutionGraph(4);
	mMainGraph->initializeGraph("Time", "General units", "Main Graph");

	QLabel *ticTimeLabel = new QLabel("Refresh time (ms) :");
	mTicTimeValue = new QLabel("0");

	QLabel *mNbAdvanceCountLabel = new QLabel("Advance executed :");
	mNbAdvanceCountValue = new QLabel("0");

	mTemperatureStat = new QStatisticAdvanceMenu(true, false, true, "Temperature");
	mPrecipitationStat = new QStatisticAdvanceMenu(true, false, true, "Precipitation");
	mLuminosityStat = new QStatisticAdvanceMenu(true, false, true, "Luminosity");
	mWindStat = new QStatisticAdvanceMenu(true, false, true, "Wind");
	
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

	QVBoxLayout * valueLayout = new QVBoxLayout;
	valueLayout->addWidget(generalStatGroupBox);
	valueLayout->addWidget(mTemperatureStat);
	valueLayout->addWidget(mPrecipitationStat);
	valueLayout->addWidget(mLuminosityStat);
	valueLayout->addWidget(mWindStat);
	valueLayout->addStretch();

	QGroupBox * valueLayoutGroupBox = new QGroupBox("Statistics");
	valueLayoutGroupBox->setLayout(valueLayout);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addWidget(mMainGraph);
	mainLayout->addWidget(valueLayoutGroupBox);

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