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