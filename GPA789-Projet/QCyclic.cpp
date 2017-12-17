// QCyclic.h
//
// Description:
// Classe représentant un facteur environnemental changeant de manière cyclique avec le temps.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QCyclic.h"


QCyclic::QCyclic(int cycle, int average, int variation, bool noNegative)
	:mSinusTable(cycle, average, variation, 2190, noNegative)
{

}

// Crée la fonction sinusoidale représentant un facteur environemental cyclique
void QCyclic::setTable(int cycle, int average, int variation)
{
	mSinusTable.set(cycle, average, variation);
}


float QCyclic::getFactor(int time)
{
	// Retourne la valeur de la fonction à un temps donné
	return mSinusTable.getValue(time);
}
