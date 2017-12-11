#include "SinusTable.h"
#include <math.h>



SinusTable::SinusTable()
{


}

void SinusTable::initialize(int cycle, int average, int variation, int lenght)
{
	SinusTable::initialize(cycle, average, variation, lenght, false);

}

void SinusTable::initialize(int cycle, int average, int variation, int lenght, bool noNegative)
{
	mLenght = lenght;
	mNoNegative = noNegative;

	SinusTable::set(cycle, average, variation);
	
	

}
	
void SinusTable::set(int cycle, int average, int variation)
{
	mTable.clear();

	double temporary = 0;

	if (mNoNegative)
	{

		for (int i(0); i < mLenght; i++)
		{
			temporary = average + variation*cos(((2 * 3.14159265 / cycle)*i));

			if (temporary<0)
				mTable.push_back(0);
			else
				mTable.push_back(temporary);

		}

	}
	else
	{
		for (int i(0); i < mLenght; i++)
		{
			mTable.push_back(average + variation*cos((2 * 3.14159265 / cycle)*i));

		}

	}



}


SinusTable::~SinusTable()
{
}
double SinusTable::getValue(int position)
{

	return mTable[position];
}
