#ifndef SIMULATION_PARAMETERS_H
#define SIMULATION_PARAMETERS_H

class SimulationParameters
{
public:
	SimulationParameters();
	~SimulationParameters();

	int PrecipitationCycle;
	int PrecipitationAverage;
	int PrecipitationVariation;
	int TemperatureCycle;
	int TemperatureAverage;
	int TemperatureVariation;
	int LuminosityCycle;
	int LuminosityAverage;
	int LuminosityVariation;
	int WindCycle;
	int WindAverage;
	int WindVariation;

};


#endif
