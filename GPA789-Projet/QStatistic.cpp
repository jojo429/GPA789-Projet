#include "QStatistic.h"


#include <QVBoxLayout>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout * mainLayout = new QVBoxLayout;
	mTemperatureGraph = new QEvolutionGraph;
	mPrecipitationGraph = new QEvolutionGraph;
	mLuminosityGraph = new QEvolutionGraph;
	mWindGraph = new QEvolutionGraph;
	mTemperatureGraph->initializeGraph("Time", "Temperature (°C)", "Temperature graphic");
	mPrecipitationGraph->initializeGraph("Time","Rain level (mm)", "Precipitation graphic");
	mLuminosityGraph->initializeGraph("Time", "Luminosity", "Luminosity graphic");
	mWindGraph->initializeGraph("Time", "Wind Speed (?)", "Wind graphic");
	mainLayout->addWidget(mTemperatureGraph);
	mainLayout->addWidget(mPrecipitationGraph);
	mainLayout->addWidget(mLuminosityGraph);
	mainLayout->addWidget(mWindGraph);
	
	setLayout(mainLayout);


}

QStatistic::~QStatistic()
{
}

void QStatistic::updateData(SimulationStatistics stats) 
{
	mTemperatureGraph->addPoint(stats.mTemperature);
	mPrecipitationGraph->addPoint(stats.mPrecipitation);
	mLuminosityGraph->addPoint(stats.mLuminosity);
	mWindGraph->addPoint(stats.mWind);
}