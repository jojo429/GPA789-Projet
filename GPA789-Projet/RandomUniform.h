#ifndef RANDOM_UNIFORM_H
#define RANDOM_UNIFORM_H

#include "RandomGenerator.h"
class RandomUniform : public RandomGenerator
{
public:
	RandomUniform();
	~RandomUniform();
	int randomInt(int max, int min);
	double randomDouble(double max, double min);
//private:
	//std::uniform_int_distribution<int> mDistributionInt;
	//std::uniform_int_distribution<double> mDistributionDouble;
};

#endif