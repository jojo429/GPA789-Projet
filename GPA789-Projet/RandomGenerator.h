#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

class RandomGenerator
{
public:
	RandomGenerator();
	~RandomGenerator();
protected:
	//Mettre en static ? 
	std::random_device mRD;
	std::mt19937 mMT32{ mRD() };
	//static std::mt19937 mMT64;
};
#endif