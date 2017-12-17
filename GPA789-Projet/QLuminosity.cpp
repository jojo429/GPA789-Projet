// QLuminosity.cpp
//
// Description:
// Classe représentant un facteur de luminosité généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QLuminosity.h"


QLuminosity::QLuminosity(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, false)
{
	
}
