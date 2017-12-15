#ifndef Q_STATISTIC_H
#define Q_STATISTIC_H

#include "QEvolutionGraph.h"
#include "SimulationStatistics.h"
#include <QWidget>
#include <QCheckBox>


class QStatistic : public QWidget
{
	Q_OBJECT

public:
	QStatistic(QWidget *parent = Q_NULLPTR);
	~QStatistic();

public slots:
	void updateData();
	void addPoints(SimulationStatistics stats);
	
private: 
	//QEvolutionGraph * mTemperatureGraph;
	//QEvolutionGraph * mPrecipitationGraph;
	//QEvolutionGraph * mLuminosityGraph;
	//QEvolutionGraph * mWindGraph;
	QEvolutionGraph * mMainGraph;
	QCheckBox * mTemperatureVisibility;

	int mTime{ 0 };

private slots: 
	void setTemperatureVisible(bool isVisible);

};
#endif //Q_STATISTIC_H