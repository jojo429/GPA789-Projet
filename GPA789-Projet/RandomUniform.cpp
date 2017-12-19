// QRandomUniform.cpp
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

#include "RandomUniform.h"

RandomUniform::RandomUniform(int min, int max) 
	: mDistribution(min, max)
{
}

int RandomUniform::random() {
	//Retourne un nombre aléatoire entre les valeurs
	//min et max fournit au constructeur
	return  mDistribution(RandomGenerator::mMT32);
}

int RandomUniform::random(int min, int max)
{
	//Retourne un nombre aléatoire entre les valeurs
	//min et max fournit à la fonction
	return std::uniform_int_distribution<int>(min, max)(mMT32);
}