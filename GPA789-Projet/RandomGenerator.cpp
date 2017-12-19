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

//Déclaration de l'outil de génération de nombres aléatoires
std::random_device RandomGenerator::mRD;
//Assignation des paramètres à l'outil de génération de nombres aléatoires
std::mt19937 RandomGenerator::mMT32(mRD());
