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
	QEnvironment::calculateFactors(mTime);

	mTime++;
	if (mTime >= 2190)
	{
		mTime = mTime - 2190;
	}


}

std::vector<float> QEnvironment::getFactors()
{

	return mFactors;
}

void QEnvironment::calculateFactors(int Time)
{
	
	for (int i(0); i < mEnvironmentalFactor.size(); i++)
	{
		mFactors[i] = mEnvironmentalFactor[i].getFactor(Time);
	}

	mTime++;
	if (mTime >= 2190)
	{
		mTime = mTime - 2190;
	}


}

QEnvironment::~QEnvironment()
{

}

//void QEnvironment::germinateFactors(int time)
//{
//	for (int i(0); i < mEnvironmentalFactor.size(); i++)
//	{
//		mGerminateFactors[i] = mEnvironmentalFactor[i].germinate(time);
//
//	}
//	
//}
//
//
//void QEnvironment::growFactors(int time)
//{
//	for (int i(0); i < mEnvironmentalFactor.size(); i++)
//	{
//		mGrowFactors[i] = mEnvironmentalFactor[i].germinate(time);
//
//	}
//}

//void QEnvironment::adjustDrynessFactors(int time)
//{
//
//}
//
//void QEnvironment::airDisplacementFactors(int time)
//{
//
//}
//
//std::vector<float> QEnvironment::getGerminate() const
//{
//
//	return mGerminateFactors;
//}
//
//std::vector<float> QEnvironment::getGrow() const
//{
//	std::list<float> tmp;
//
//	return mGrowFactors;
//}
//
//std::vector<float> QEnvironment::getAdjustDryness() const
//{
//
//	return mAdjustDrynessFactors;
//}
//
//std::array<double, 2> QEnvironment::getAirDisplacement() const
//{
//
//	return mAirDisplacementFactors;
//}


void QEnvironment::setParameters(SimulationParameters &simulationParameters)
{
	mEnvironmentalFactor.emplace_back((QTemperature(simulationParameters.mTemperatureCycle, simulationParameters.mTemperatureAverage, simulationParameters.mTemperatureVariation)));
	mEnvironmentalFactor.emplace_back((QPrecipitation(simulationParameters.mPrecipitationCycle, simulationParameters.mPrecipitationAverage, simulationParameters.mPrecipitationVariation)));
	mEnvironmentalFactor.emplace_back((QLuminosity(simulationParameters.mLuminosityCycle, simulationParameters.mLuminosityAverage,100, simulationParameters.mLuminosityVariation)));
	mEnvironmentalFactor.emplace_back((QWind(simulationParameters.mWindCycle, simulationParameters.mWindAverage, simulationParameters.mWindVariation)));

	mFactors.resize((mEnvironmentalFactor.size()));


}