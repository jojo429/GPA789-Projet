// SinusTable.h
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

#ifndef SINUS_TABLE_H
#define SINUS_TABLE_H

#include "FunctionTable.h"

class SinusTable : public FunctionTable
{
public:
	SinusTable(int cycle, int average, int variation, int lenght, bool noNegative);
	~SinusTable()=default;

	void set(int cycle, int average, int variation);

protected:
	bool mNoNegative;
};

#endif //SINUS_TABLE_H
