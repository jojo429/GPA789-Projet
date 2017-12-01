#include "RandomUniform.h"



RandomUniform::RandomUniform()
{
}


RandomUniform::~RandomUniform()
{
}

int RandomUniform::randomInt(int min, int max) {
	if (min >= max) {
		return 0;
	}
	std::uniform_int_distribution<int> distributionInt{ min , max };
	return  distributionInt(RandomGenerator::mMT32);
}

double RandomUniform::randomDouble(double min, double max) {
	if (min >= max) {
		return 0.0;
	}
	
	std::uniform_real_distribution<double> distributionDouble{ min , max };
	return distributionDouble(RandomGenerator::mMT32);
}