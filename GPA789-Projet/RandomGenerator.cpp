// QRandomGenerator.cpp
//
// Description:
// classe permettant de g�n�rer des nombers al�atoires.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "RandomGenerator.h"

std::random_device RandomGenerator::mRD;
std::mt19937 RandomGenerator::mMT32(mRD());
