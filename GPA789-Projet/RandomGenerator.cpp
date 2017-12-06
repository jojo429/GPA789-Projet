#include "RandomGenerator.h"

std::random_device RandomGenerator::mRD;
std::mt19937 RandomGenerator::mMT32(mRD());
