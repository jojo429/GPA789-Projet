#include "DoubleSinusTable.h"

#define PI 3.14159265

DoubleSinusTable::DoubleSinusTable()
{
}


DoubleSinusTable::~DoubleSinusTable()
{
}


void DoubleSinusTable::initialize(int cycle, int average, int variation, int baseVariation, int lenght)
{

	DoubleSinusTable::initialize(cycle, average, variation, lenght, false);
}
void DoubleSinusTable::initialize(int cycle, int average, int variation, int baseVariation, int lenght, bool noNegative)
{
	
	SinusTable::initialize(cycle, average, variation, lenght, noNegative);



	for (int i(0); i < mLenght; i++)
	{
		mTable[i]= mTable[i]+ baseVariation*cos((2 * PI / lenght)*i);
		
	

	}

}