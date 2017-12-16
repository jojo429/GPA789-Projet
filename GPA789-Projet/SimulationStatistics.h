#ifndef SIMULATION_STATISTICS_H
#define SIMULATION_STATISTICS_H


class SimulationStatistics
{
public:
	SimulationStatistics() = default;
	~SimulationStatistics() = default;

	double mPrecipitation{ 0.0 };
	double mWind{ 0.0 };
	double mTemperature{ 0.0 };
	double mLuminosity{ 0.0 };

	int mNumberOfTrees{ 0 };
	int mNumberOfOak{ 0 };
	int mNumberOfFir{ 0 };
	int mNumberOfBirch{ 0 };
	int mNumberOfHazel{ 0 };
	int mNumberOfSeeds{ 0 };
	int mNumberOfGermination{ 0 };
	int mNumberOfSquirrel{ 0 };

};
#endif

