#ifndef Q_STATISTIC_H
#define Q_STATISTIC_H

#include "QEvolutionGraph.h"
#include "SimulationStatistics.h"
#include <QWidget>


class QStatistic : public QWidget
{
	Q_OBJECT

public:
	QStatistic(QWidget *parent = Q_NULLPTR);
	~QStatistic();

public slots:
	void updateData(SimulationStatistics stats);

private: 
	QEvolutionGraph * mTemperatureGraph;
	QEvolutionGraph * mPrecipitationGraph;
	QEvolutionGraph * mLuminosityGraph;
	QEvolutionGraph * mWindGraph;


	//TEST/////
	long int x{ 0 }, y{ 0 };
	///////////
};
#endif //Q_STATISTIC_H