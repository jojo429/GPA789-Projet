// QPrecipitation.cpp
//
// Description:
// Classe repr�sentant un facteur de pr�cipitation g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QPrecipitation.h"

QPrecipitation::QPrecipitation(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, true)
{
}
