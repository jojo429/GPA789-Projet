// SinusTable.cpp
//
// Description:
// Table contenant les valeurs pré-calculées d'une fonction sinusoidale.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
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
				// Si la valeur est négative on met 0 à la place
				mTable.push_back(0);
			else
				// Ajoute la valeur calculée à la table de sinus
				mTable.push_back(temporary);
		}
	}
	else
	{
		for (int i(0); i < mLenght; i++)
		{
			// Calcule et ajoute la valeur à la table de sinus
			mTable.push_back(average - variation*cos((2 * 3.14159265 / static_cast<double>(cycle))*i));
		}
	}
}



