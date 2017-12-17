// QPrecipitation.cpp
//
// Description:
// Classe représentant un facteur de précipitation généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QPrecipitation.h"

QPrecipitation::QPrecipitation(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, true)
{
}
