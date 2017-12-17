// SinusTable.cpp
//
// Description:
// Table contenant les valeurs pr�-calcul�es d'une fonction sinusoidale.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "SinusTable.h"
#include <math.h>


SinusTable::SinusTable(int cycle, int average, int variation,int lenght, bool noNegative)
	:FunctionTable(lenght), mNoNegative{noNegative}
{
	if (cycle<=0)
	{
		SinusTable::set(2190, average, variation);
	}
	else 
	{
		SinusTable::set(cycle, average, variation);
	}
	
}


void SinusTable::set(int cycle, int average, int variation)
{
	// S'assure que la table est vide
	mTable.clear();
	double temporary = 0.0;

	if (mNoNegative)
	{
		for (int i(0); i < mLenght; i++)
		{
			// Calcule la valeur du sinus attendu
			temporary = average - variation*cos(((2 * 3.14159265 / static_cast<double>(cycle))*i));
			if (temporary<0)
				// Si la valeur est n�gative on met 0 � la place
				mTable.push_back(0);
			else
				// Ajoute la valeur calcul�e � la table de sinus
				mTable.push_back(temporary);
		}
	}
	else
	{
		for (int i(0); i < mLenght; i++)
		{
			// Calcule et ajoute la valeur � la table de sinus
			mTable.push_back(average - variation*cos((2 * 3.14159265 / static_cast<double>(cycle))*i));
		}
	}
}



