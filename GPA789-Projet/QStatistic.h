#ifndef Q_STATISTIC_H
#define Q_STATISTIC_H

#include "QEvolutionGraph.h"
#include "QStatisticAdvanceMenu.h"
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
	QEvolutionGraph * mMainGraph;
	
	QStatisticAdvanceMenu * mTemperatureStat;
	QStatisticAdvanceMenu * mPrecipitationStat;
	QStatisticAdvanceMenu * mLuminosityStat;
	QStatisticAdvanceMenu * mWindStat;

	int mTime{ 0 };

private slots: 
	void setTemperatureVisible(bool isVisible);
	void setPrecipitationVisible(bool isVisible);
	void setLuminosityVisible(bool isVisible);
	void setWindVisible(bool isVisible);

};
#endif //Q_STATISTIC_H