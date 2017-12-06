#include "SinusTable.h"
#include <math.h>

#define PI 3.14159265

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

	double temporary = 0;

	if (mNoNegative)
	{

		for (int i(0); i < mLenght; i++)
		{
			temporary = average + variation*cos((2 * PI / cycle)*i);

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
			mTable.push_back(average + variation*cos((2 * PI / cycle)*i));

		}

	}
	
	

}

void SinusTable::reset(int cycle, int average, int variation)
{
	mTable.clear();

	double temporary = 0;

	if (mNoNegative)
	{

		for (int i(0); i < mLenght; i++)
		{
			temporary = average + variation*cos((2 * PI / cycle)*i);

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
			mTable.push_back(average + variation*cos((2 * PI / cycle)*i));

		}

	}



}


SinusTable::~SinusTable()
{
}
