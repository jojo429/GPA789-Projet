// QRandomUniform.h
//
// Description:
// classe permettant de créer une distribution uniforme de nombre aléatoires.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
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

	//Retourne un nombre aléatoire entre les valeurs définit par le constructeur
	int random();
	//Retourne des un nombre aléatoire entre les valeurs définit par la fonctction.
	int random(int min, int max);

protected:
	//Déclaration de l'engin pour générer des nombres aléatoire
	// de format "int" selon une distribution uniform
	std::uniform_int_distribution<int> mDistribution;
};

#endif