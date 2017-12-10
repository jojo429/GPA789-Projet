#ifndef SIMULATION_PARAMETERS_H
#define SIMULATION_PARAMETERS_H

class SimulationParameters
{
public:
	SimulationParameters();
	~SimulationParameters();

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

};


#endif
