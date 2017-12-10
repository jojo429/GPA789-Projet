#ifndef Q_ENVIRONMENT_H
#define Q_ENVIRONMENT_H

#include <list>
#include <array>
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
	void germinateFactors();
	void growFactors();
	void adjustDrynessFactors();
	void airDisplacementFactors();
	std::list<float> getGerminate() const;
	std::list<float> getGrow() const;
	std::list<float> getAdjustDryness() const;
	std::array<double,2>  getAirDisplacement() const;
	void setParameters(SimulationParameters &simulationParameters);

public slots:
	void advance();

private:
	std::list<QEnvironmentalFactor> mEnvironmentalFactor;
	//std::list<QEnvironmentalFactor>::iterator it;

};

#endif //Q_ENVIRONMENT_H

