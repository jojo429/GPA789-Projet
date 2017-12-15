#include "QStatistic.h"


#include <QVBoxLayout>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	
	//Générer les graphiques
	mMainGraph = new QEvolutionGraph(4);
	//mTemperatureGraph = new QEvolutionGraph;
	//mPrecipitationGraph = new QEvolutionGraph;
	//mLuminosityGraph = new QEvolutionGraph;
	//mWindGraph = new QEvolutionGraph;
	mMainGraph->initializeGraph("Time", "Unit", "Main Graph");
	//mTemperatureGraph->initializeGraph("Time", "Temperature (°C)", "Temperature graphic");
	//mPrecipitationGraph->initializeGraph("Time","Rain level (mm)", "Precipitation graphic");
	//mLuminosityGraph->initializeGraph("Time", "Luminosity", "Luminosity graphic");
	//mWindGraph->initializeGraph("Time", "Wind Speed (?)", "Wind graphic");
	
	QVBoxLayout * graphLayout = new QVBoxLayout;
	graphLayout->addWidget(mMainGraph);
	//graphLayout->addWidget(mTemperatureGraph);
	//graphLayout->addWidget(mPrecipitationGraph);
	//graphLayout->addWidget(mLuminosityGraph);
	//graphLayout->addWidget(mWindGraph);
	graphLayout->addStretch();

	QLabel *mTestLabel = new QLabel;
	mTestLabel->setText("TEST TEST TEST ");
	QVBoxLayout * valueLayout = new QVBoxLayout;
	valueLayout->addWidget(mTestLabel);
	valueLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(graphLayout);
	mainLayout->addLayout(valueLayout);

	setLayout(mainLayout);


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