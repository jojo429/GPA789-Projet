// FunctionTable.cpp
//
// Description:
// Table contenant les valeurs pr�-calcul�es d'une fonction pour un interval donn�.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "FunctionTable.h"


FunctionTable::FunctionTable(int lenght)
	:mLenght{ lenght }
{
}


double FunctionTable::getValue(int position)
{
	//Retourne la valeur � une position donn�e.
	return mTable[position];
}


void FunctionTable::set()
{

}

