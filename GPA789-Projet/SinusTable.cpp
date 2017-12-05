#include "SinusTable.h"
#include <math.h>

#define PI 3.14159265

SinusTable::SinusTable()
{


}

void SinusTable::Initialize(int cycle, int average, int variation, int lenght)
{
	mLenght = lenght;

	for (int i(0); i < lenght; i++)
	{
		mTable.push_back(average + variation*cos((2 * PI / cycle)*i));

	}


}


SinusTable::~SinusTable()
{
}
