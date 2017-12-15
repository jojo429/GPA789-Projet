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
