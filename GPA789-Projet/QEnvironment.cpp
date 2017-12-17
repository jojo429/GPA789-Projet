// QEnvironment.cpp
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

#include "QEnvironment.h"
#include "QSeeds.h"
#include "QTrees.h"
#include "QPrecipitation.h"
#include "QTemperature.h"
#include "QLuminosity.h"
#include "QWind.h"

QEnvironment::QEnvironment()
	: mWind(6,0,0), mPrecipitation(6,0,0), mTemperature(6,0,0), mLuminosity(6,0,0), mGenerate(-100,100)
{
	//Création de la zone de fertilité aléatoire
	mFertility.setFertility(10.0, 100.0);

	// Construction de la table des facteurs environmentaux
	mEnvironmentalFactor.emplace_back(&mTemperature);
	mEnvironmentalFactor.emplace_back(&mPrecipitation);
	mEnvironmentalFactor.emplace_back(&mLuminosity);
	mEnvironmentalFactor.emplace_back(&mWind);
	mFactors.resize((mEnvironmentalFactor.size()));
	

}

void QEnvironment::advance()
{
	//Calcul à quel temps on se trouve dans un cycle de 2190 advance
	calculateFactors(mTime);
	mTime++;
	if (mTime >= 2190)
	{
		mTime = mTime - 2190;
	}


}



void QEnvironment::getStatistics(SimulationStatistics *simulationStatistics)
{
	// Calcule la valeur aléatoire des facteurs environmentaux pour le advance en cours
	// et les inscrits dans les statistiques.
	simulationStatistics->mTemperature = ((0.05 * mGenerate.random() / 100.0) + 1)*(mFactors[0]);
	simulationStatistics->mPrecipitation = ((0.05 * mGenerate.random() / 100.0) + 1)*(mFactors[1]);
	simulationStatistics->mLuminosity = mFactors[2];
	simulationStatistics->mWind = ((0.05 * mGenerate.random() / 100.0) + 1)*(mFactors[3]);
	
}

void QEnvironment::calculateFactors(int Time)
{
	// Va chercher les valeurs standards des facteurs environmentaux selon le temps
	for (int i(0); i < mEnvironmentalFactor.size(); i++)
	{
		mFactors[i] = (mEnvironmentalFactor[i])->getFactor(Time);
	}

}


void QEnvironment::setParameters(SimulationParameters &simulationParameters)
{
	// Initialisation des facteurs environmentaux selon les valeurs des sliders de l'utilisateur.
	mEnvironmentalFactor[0]->setTable(simulationParameters.mTemperatureCycle, simulationParameters.mTemperatureAverage, simulationParameters.mTemperatureVariation);
	mEnvironmentalFactor[1]->setTable(simulationParameters.mPrecipitationCycle, simulationParameters.mPrecipitationAverage, simulationParameters.mPrecipitationVariation);
	mEnvironmentalFactor[2]->setTable(simulationParameters.mLuminosityCycle, simulationParameters.mLuminosityAverage, simulationParameters.mLuminosityVariation);
	mEnvironmentalFactor[3]->setTable(simulationParameters.mWindCycle, simulationParameters.mWindAverage, simulationParameters.mWindVariation);
	mFactors.resize((mEnvironmentalFactor.size()));
	mTime = 0;

}