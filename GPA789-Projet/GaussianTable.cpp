// GaussianTable.cpp
//
// Description:
// Table contenant les valeurs pr�-calcul�es d'une fonction de Gausse.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
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
	//Retourne la position avec un d�calage s'il y a lieu
	return FunctionTable::getValue(position - mShiftFactor);
}