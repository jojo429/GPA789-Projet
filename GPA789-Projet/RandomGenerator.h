#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

class RandomGenerator
{
public:
	RandomGenerator() = default;
	~RandomGenerator() = default;
protected:

	static std::random_device mRD;
	static std::mt19937 mMT32;
	//static std::mt19937 mMT64;
};
#endif