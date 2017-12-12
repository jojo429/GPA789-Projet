#ifndef Q_ENVIRONMENT_H
#define Q_ENVIRONMENT_H

#include <list>
#include <array>
#include <vector>
#include "QEnvironmentalFactor.h"
#include "SimulationParameters.h"
class QSeeds;
class QTrees;

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
	std::vector<float> getFactors();

public slots:
	void advance();

private:
	std::vector<QEnvironmentalFactor> mEnvironmentalFactor;
	std::vector<float> mFactors;

	int mTime = 0;

};

#endif //Q_ENVIRONMENT_H

