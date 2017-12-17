// QRandomGenerator.cpp
//
// Description:
// classe permettant de générer des nombers aléatoires.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "RandomGenerator.h"

std::random_device RandomGenerator::mRD;
std::mt19937 RandomGenerator::mMT32(mRD());
