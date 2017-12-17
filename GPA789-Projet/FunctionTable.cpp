// FunctionTable.cpp
//
// Description:
// Table contenant les valeurs pré-calculées d'une fonction pour un interval donné.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "FunctionTable.h"


FunctionTable::FunctionTable(int lenght)
	:mLenght{ lenght }
{
}


double FunctionTable::getValue(int position)
{
	//Retourne la valeur à une position donnée.
	return mTable[position];
}


void FunctionTable::set()
{

}

