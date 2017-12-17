// QEnvironment.h
//
// Description:
// Classe principale gérant les facteurs environnementaux de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_ENVIRONMENT_H
#define Q_ENVIRONMENT_H

#include <list>
#include <array>
#include <vector>
#include "QEnvironmentalFactor.h"
#include "SimulationParameters.h"
#include "SimulationStatistics.h"
class QSeeds;
class QTrees;
#include "QPrecipitation.h"
#include "QTemperature.h"
#include "QLuminosity.h"
#include "QFertility.h"
#include "QWind.h"
#include "RandomUniform.h"

class QEnvironment : public QObject
{
	Q_OBJECT

public:
	QEnvironment();
	~QEnvironment();

	void calculateFactors(int Time);
	void setParameters(SimulationParameters &simulationParameters);
	void getStatistics(SimulationStatistics *simulationStatistics);
	std::vector<float> mFactors;
	QFertility mFertility;

public slots:
	void advance();

private:
	std::vector< QEnvironmentalFactor*> mEnvironmentalFactor;
	QLuminosity mLuminosity;
	QPrecipitation mPrecipitation;
	QTemperature mTemperature;
	QWind mWind;
	int mTime{ 0 };
	RandomUniform mGenerate;

};

#endif //Q_ENVIRONMENT_H

