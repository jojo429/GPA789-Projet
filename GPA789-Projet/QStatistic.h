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
	//Mise à jour du graphique
	void updateData();
	//Réception du temps passé pour une boucle du programme
	void ticTime(qint64 timePassed);
	//Mise à jour du nombre de boucle exécuté depuis le début de la simulation
	void updateAdvanceCount(int advanceCount);
	//Ajout d'un point de donnée pour les statistiques
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
	//Permet de rendre visible ou invisible une série de donnée dans l'espace graphiqe
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