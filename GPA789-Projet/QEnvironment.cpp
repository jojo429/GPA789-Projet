#include "QEnvironment.h"
#include "QSeeds.h"
#include "QTrees.h"
#include "QPrecipitation.h"
#include "QTemperature.h"
#include "QLuminosity.h"
#include "QWind.h"

QEnvironment::QEnvironment()
	: mWind(6,0,0), mPrecipitation(6,0,0), mTemperature(6,0,0), mLuminosity(6,0,0)
{

	mEnvironmentalFactor.emplace_back(&mTemperature);
	mEnvironmentalFactor.emplace_back(&mPrecipitation);
	mEnvironmentalFactor.emplace_back(&mLuminosity);
	mEnvironmentalFactor.emplace_back(&mWind);
	mFactors.resize((mEnvironmentalFactor.size()));

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

void QEnvironment::getStatistics(SimulationStatistics *simulationStatistics)
{
	simulationStatistics->mTemperature = mFactors[0];
	simulationStatistics->mPrecipitation = mFactors[1];
	simulationStatistics->mLuminosity = mFactors[2];
	simulationStatistics->mWind = mFactors[3];
}

void QEnvironment::calculateFactors(int Time)
{
	
	for (int i(0); i < mEnvironmentalFactor.size(); i++)
	{
		mFactors[i] = (mEnvironmentalFactor[i])->getFactor(Time);
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
	mEnvironmentalFactor[0]->setTable(simulationParameters.mTemperatureCycle, simulationParameters.mTemperatureAverage, simulationParameters.mTemperatureVariation);
	mEnvironmentalFactor[1]->setTable(simulationParameters.mPrecipitationCycle, simulationParameters.mPrecipitationAverage, simulationParameters.mPrecipitationVariation);
	mEnvironmentalFactor[2]->setTable(simulationParameters.mLuminosityCycle, simulationParameters.mLuminosityAverage, simulationParameters.mLuminosityVariation);
	mEnvironmentalFactor[3]->setTable(simulationParameters.mWindCycle, simulationParameters.mWindAverage, simulationParameters.mWindVariation);

	mFactors.resize((mEnvironmentalFactor.size()));


}