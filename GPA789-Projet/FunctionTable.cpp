#include "FunctionTable.h"



FunctionTable::FunctionTable(int lenght)
	:mLenght{ lenght }
{
}


FunctionTable::~FunctionTable()
{
}

double FunctionTable::getValue(int position)
{

	return mTable[position];
}


void FunctionTable::set()
{

}

