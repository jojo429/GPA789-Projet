// FunctionTable.h
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

#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H
#include <vector>

class FunctionTable
{
public:
	FunctionTable(int lenght);
	~FunctionTable()=default;

	virtual void set();
	virtual double getValue(int position);

protected:
	std::vector <double> mTable;
	int mLenght;
};

#endif
