// FunctionTable.h
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
