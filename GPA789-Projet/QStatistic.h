// QStatistic.h
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

#ifndef Q_STATISTIC_H
#define Q_STATISTIC_H

#include "QEvolutionGraph.h"
#include "QStatisticAdvanceMenu.h"
#include "SimulationStatistics.h"
#include <QWidget>
#include <QCheckBox>
#include <QElapsedTimer>

class QStatistic : public QWidget
{
	Q_OBJECT

public:
	QStatistic(QWidget *parent = Q_NULLPTR);
	~QStatistic()=default;

public slots:
	void updateData(); 
	void ticTime(qint64 timePassed);
	void updateAdvanceCount(int advanceCount);
	void addPoints(SimulationStatistics stats);
	
private: 
	QEvolutionGraph * mMainGraph;
	QStatisticAdvanceMenu * mTemperatureStat;
	QStatisticAdvanceMenu * mPrecipitationStat;
	QStatisticAdvanceMenu * mLuminosityStat;
	QStatisticAdvanceMenu * mWindStat;
	QStatisticAdvanceMenu * mTreesStat;
	QStatisticAdvanceMenu *	mOakStat;
	QStatisticAdvanceMenu *	mFirStat;
	QStatisticAdvanceMenu *	mBirchStat;
	QStatisticAdvanceMenu *	mHazelStat;
	QStatisticAdvanceMenu * mSeedsStat;
	QStatisticAdvanceMenu *	mGerminationStat;
	QLabel * mTicTimeValue;
	QLabel * mNbAdvanceCountValue;
	int mTime{ 0 };

private slots: 
	void setTemperatureVisible(bool isVisible);
	void setPrecipitationVisible(bool isVisible);
	void setLuminosityVisible(bool isVisible);
	void setWindVisible(bool isVisible);
	void setTreesVisible(bool isVisible);
	void setOakVisible(bool isVisible);
	void setFirVisible(bool isVisible);
	void setBirchVisible(bool isVisible);
	void setHazelVisible(bool isVisible);
	void setSeedsVisible(bool isVisible);
	void setGerminationVisible(bool isVisible);

};
#endif //Q_STATISTIC_H