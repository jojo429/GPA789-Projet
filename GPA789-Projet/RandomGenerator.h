// QRandomGenerator.h
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

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

class RandomGenerator
{
public:
	RandomGenerator() = default;
	~RandomGenerator() = default;

protected:
	//D�claration du g�n�rateur de nombre al�atoire
	static std::random_device mRD;
	//Param�tre de pour l'objet al�atoire correspondant � mt19937
	static std::mt19937 mMT32;
};

#endif