// QCyclic.h
//
// Description:
// Classe repr�sentant un facteur environnemental changeant de mani�re cyclique avec le temps.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QCyclic.h"


QCyclic::QCyclic(int cycle, int average, int variation, bool noNegative)
	:mSinusTable(cycle, average, variation, 2190, noNegative)
{

}

// Cr�e la fonction sinusoidale repr�sentant un facteur environemental cyclique
void QCyclic::setTable(int cycle, int average, int variation)
{
	mSinusTable.set(cycle, average, variation);
}


float QCyclic::getFactor(int time)
{
	// Retourne la valeur de la fonction � un temps donn�
	return mSinusTable.getValue(time);
}
