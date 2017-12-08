#include "RandomUniform.h"



RandomUniform::RandomUniform(int min, int max) 
	: mDistribution(min, max)
{
}


RandomUniform::~RandomUniform()
{
}

int RandomUniform::random() {
	return  mDistribution(RandomGenerator::mMT32);
}

int RandomUniform::random(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(mMT32);
}