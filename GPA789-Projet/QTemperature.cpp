// QTemperature.h
//
// Description:
// Classe repr�sentant un facteur de temp�rature g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QTemperature.h"

QTemperature::QTemperature(int cycle, int average, int variation)
	:QCyclic(cycle, average, variation, false)
{
	
}

