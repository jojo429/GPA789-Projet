// QLuminosity.cpp
//
// Description:
// Classe repr�sentant un facteur de luminosit� g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QLuminosity.h"


QLuminosity::QLuminosity(int cycle, int average, int variation)
	: QCyclic(cycle, average, variation, false)
{
	
}
