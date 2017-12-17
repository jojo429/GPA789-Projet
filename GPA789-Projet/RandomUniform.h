// QRandomUniform.h
//
// Description:
// classe permettant de créer une distribution uniforme de nombre aléatoires.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef RANDOM_UNIFORM_H
#define RANDOM_UNIFORM_H

#include "RandomGenerator.h"

class RandomUniform : public RandomGenerator
{

public:
	RandomUniform(int min = 0, int max = 100);
	~RandomUniform()=default;

	int random();
	int random(int min, int max);
	//double randomDouble(double max, double min);

protected:
	std::uniform_int_distribution<int> mDistribution;
	//std::uniform_int_distribution<double> mDistributionDouble;
};

#endif