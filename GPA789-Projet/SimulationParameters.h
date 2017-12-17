// SimulationParameters.h
//
// Description:
// Classe contenant les paramètres de de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef SIMULATION_PARAMETERS_H
#define SIMULATION_PARAMETERS_H

class SimulationParameters
{
public:
	SimulationParameters()=default;
	~SimulationParameters()=default;

	int mPrecipitationCycle;
	int mPrecipitationAverage;
	int mPrecipitationVariation;
	int mTemperatureCycle;
	int mTemperatureAverage;
	int mTemperatureVariation;
	int mLuminosityCycle;
	int mLuminosityAverage;
	int mLuminosityVariation;
	int mWindCycle;
	int mWindAverage;
	int mWindVariation;
	int mNumberOak;
	int mNumberFir;
	int mNumberHazel;
	int mNumberBirch;
	int mNumberSquirrel;

};

#endif
