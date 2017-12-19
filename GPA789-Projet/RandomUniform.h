// QRandomUniform.h
//
// Description:
// classe permettant de cr�er une distribution uniforme de nombre al�atoires.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef RANDOM_UNIFORM_H
#define RANDOM_UNIFORM_H

#include "RandomGenerator.h"

class RandomUniform : public RandomGenerator
{

public:
	RandomUniform(int min = 0, int max = 100);
	~RandomUniform()=default;

	//Retourne un nombre al�atoire entre les valeurs d�finit par le constructeur
	int random();
	//Retourne des un nombre al�atoire entre les valeurs d�finit par la fonctction.
	int random(int min, int max);

protected:
	//D�claration de l'engin pour g�n�rer des nombres al�atoire
	// de format "int" selon une distribution uniform
	std::uniform_int_distribution<int> mDistribution;
};

#endif