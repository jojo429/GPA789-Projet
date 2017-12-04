#include "CyclicTable.h"
#include <math.h>

#define PI 3.14159265

CyclicTable::CyclicTable()
{


}

void CyclicTable::Initialize(int cycle, int average, int variation, int lenght)
{
	mLenght = lenght;

	for (int i(0); i < lenght; i++)
	{
		mTable.push_back(average + variation*cos((2 * PI / cycle)*i));

	}


}


CyclicTable::~CyclicTable()
{
}
