// GaussianTable.h
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

#ifndef GAUSSIAN_TABLE_H
#define GAUSSIAN_TABLE_H

#include "FunctionTable.h"

class GaussianTable : public FunctionTable
{
public:
	GaussianTable(int lenght, int mainValue, int spreadFactor, int shiftFactor=0);
	~GaussianTable()=default;

	void set(int mainValue, int spreadFactor);
	double getValue(int position) override;

protected:
	int mShiftFactor;
};

#endif
