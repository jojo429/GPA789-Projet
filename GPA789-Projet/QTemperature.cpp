// QTemperature.h
//
// Description:
// Classe représentant un facteur de température généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QTemperature.h"

QTemperature::QTemperature(int cycle, int average, int variation)
	:QCyclic(cycle, average, variation, false)
{
	
}

