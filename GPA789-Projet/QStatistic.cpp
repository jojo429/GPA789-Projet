#include "QStatistic.h"

#include "QStatisticAdvanceMenu.h"


#include <QVBoxLayout>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	
	//G�n�rer les graphiques
	mMainGraph = new QEvolutionGraph(4);
	mMainGraph->initializeGraph("Time", "General units", "Main Graph");
	
	QVBoxLayout * graphLayout = new QVBoxLayout;
	graphLayout->addWidget(mMainGraph);
	graphLayout->addStretch();

	QLabel *mTestLabel = new QLabel;
	mTestLabel->setText("TEST TEST TEST ");
	mTemperatureVisibility = new QCheckBox;
	mTemperatureVisibility->setText("Set Visible");

	QStatisticAdvanceMenu * TestStat = new QStatisticAdvanceMenu(true, true, true);

	QVBoxLayout * valueLayout = new QVBoxLayout;
	valueLayout->addWidget(mTestLabel);
	valueLayout->addWidget(mTemperatureVisibility);
	valueLayout->addWidget(TestStat);
	valueLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(graphLayout);
	mainLayout->addLayout(valueLayout);

	setLayout(mainLayout);

	connect(mTemperatureVisibility, &QCheckBox::toggled, this, &QStatistic::setTemperatureVisible);

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
}

void QStatistic::updateData()
{
	mMainGraph->updateAxis();
}

void QStatistic::setTemperatureVisible(bool isVisible) {
	mMainGraph->setDataSerieVisibility(0, isVisible);
}