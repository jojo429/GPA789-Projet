// QWind.cpp
//
// Description:
// Classe représentant un facteur de vent généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QWind.h"

QWind::QWind(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, true)
{



}
