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

//D�claration de l'outil de g�n�ration de nombres al�atoires
std::random_device RandomGenerator::mRD;
//Assignation des param�tres � l'outil de g�n�ration de nombres al�atoires
std::mt19937 RandomGenerator::mMT32(mRD());
