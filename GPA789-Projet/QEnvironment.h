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
#include "QWind.h"
#include "RandomUniform.h"

class QEnvironment : public QObject
{
	Q_OBJECT

public:
	QEnvironment();
	~QEnvironment();
	//void germinateFactors(int time);
	//void growFactors(int time);
	//void adjustDrynessFactors(int time);
	//void airDisplacementFactors(int time);
	//std::vector<float> getGerminate() const;
	//std::vector<float> getGrow() const;
	//std::vector<float> getAdjustDryness() const;
	//std::array<double,2>  getAirDisplacement() const;

	void calculateFactors(int Time);
	void setParameters(SimulationParameters &simulationParameters);
	void getStatistics(SimulationStatistics *simulationStatistics);
	std::vector<float> mFactors;
	/*std::vector<float> const getFactors();*/

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

