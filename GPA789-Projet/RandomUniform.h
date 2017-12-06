#ifndef RANDOM_UNIFORM_H
#define RANDOM_UNIFORM_H

#include "RandomGenerator.h"
class RandomUniform : public RandomGenerator
{
public:
	RandomUniform(int min = 0, int max = 100);
	~RandomUniform();
	int random();
	//double randomDouble(double max, double min);
protected:
	std::uniform_int_distribution<int> mDistribution;
	//std::uniform_int_distribution<double> mDistributionDouble;
};

#endif