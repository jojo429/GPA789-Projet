// QRandomUniform.cpp
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

#include "RandomUniform.h"

RandomUniform::RandomUniform(int min, int max) 
	: mDistribution(min, max)
{
}

int RandomUniform::random() {
	return  mDistribution(RandomGenerator::mMT32);
}

int RandomUniform::random(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(mMT32);
}