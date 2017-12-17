// GaussianTable.cpp
//
// Description:
// Table contenant les valeurs pré-calculées d'une fonction de Gausse.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "GaussianTable.h"
#include "math.h"


GaussianTable::GaussianTable(int lenght, int mainValue, int spreadFactor, int shiftFactor)
	: FunctionTable(lenght), mShiftFactor{shiftFactor}
{
	GaussianTable::set(mainValue, spreadFactor);
}


void GaussianTable::set(int mainValue, int spreadFactor)
{
	//S'assure que la table est vide.
	mTable.clear();
	double temporary = 0;

	for (int x(mShiftFactor); x < (mLenght + mShiftFactor); x++)
	{
		mTable.push_back(exp(-((x - mainValue)*(x - mainValue)) / static_cast<double>(spreadFactor)));
	}

}


double GaussianTable::getValue(int position)
{
	//Retourne la position avec un décalage s'il y a lieu
	return FunctionTable::getValue(position - mShiftFactor);
}