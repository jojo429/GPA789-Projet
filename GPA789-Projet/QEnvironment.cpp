#include "QEnvironment.h"
#include "QSeeds.h"
#include "QTrees.h"
#include "QPrecipitation.h"
#include "QTemperature.h"
#include "QLuminosity.h"
#include "QWind.h"

QEnvironment::QEnvironment()
{

}

void QEnvironment::advance()
{



}

QEnvironment::~QEnvironment()
{

}

void QEnvironment::germinateFactors()
{

}


void QEnvironment::growFactors()
{

}

void QEnvironment::adjustDrynessFactors()
{

}

void QEnvironment::airDisplacementFactors()
{

}

std::list<float> QEnvironment::getGerminate() const
{
	std::list<float> tmp;

	return tmp;
}

std::list<float> QEnvironment::getGrow() const
{
	std::list<float> tmp;

	return tmp;
}

std::list<float> QEnvironment::getAdjustDryness() const
{
	std::list<float> tmp;

	return tmp;
}

std::array<double, 2> QEnvironment::getAirDisplacement() const
{
	std::array<double, 2> tmp;

	return tmp;
}


void QEnvironment::setParameters(SimulationParameters &simulationParameters)
{
	mEnvironmentalFactor.emplace_back((QTemperature(simulationParameters.mTemperatureCycle, simulationParameters.mTemperatureAverage, simulationParameters.mTemperatureVariation)));
	mEnvironmentalFactor.emplace_back((QPrecipitation(simulationParameters.mPrecipitationCycle, simulationParameters.mPrecipitationAverage, simulationParameters.mPrecipitationVariation)));
	mEnvironmentalFactor.emplace_back((QLuminosity(simulationParameters.mLuminosityCycle, simulationParameters.mLuminosityAverage,100, simulationParameters.mLuminosityVariation)));
	mEnvironmentalFactor.emplace_back((QWind(simulationParameters.mWindCycle, simulationParameters.mWindAverage, simulationParameters.mWindVariation)));
}