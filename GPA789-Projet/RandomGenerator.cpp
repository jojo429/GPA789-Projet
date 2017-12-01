#include "RandomGenerator.h"



RandomGenerator::RandomGenerator()
{
	
	//std::mt19937 engine{ mRD() };
	//std::mt19937 generator();
	//std::uniform_real_distribution<double> dis(0.0, 1.0);
	
	// Template 32 bits
	/*std::mersenne_twister_engine<std::uint_fast32_t, 32, 624, 397, 31,
		0x9908b0df, 11,
		0xffffffff, 7,
		0x9d2c5680, 15,
		0xefc60000, 18, 1812433253>*/
	// Template 64 bits
	/*std::mersenne_twister_engine<std::uint_fast64_t, 64, 312, 156, 31,
		0xb5026f5aa96619e9, 29,
		0x5555555555555555, 17,
		0x71d67fffeda60000, 37,
		0xfff7eee000000000, 43, 6364136223846793005>*/
		
	//class mersenne_twister_engine
}


RandomGenerator::~RandomGenerator()
{
}
