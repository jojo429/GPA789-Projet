#include "DoubleSinusTable.h"

#define PI 3.14159265

DoubleSinusTable::DoubleSinusTable(int cycle, int average, int variation,  int lenght, bool noNegative, int baseVariation)
	:SinusTable(cycle, average, variation, lenght, noNegative)
{

	for (int i(0); i < mLenght; i++)
	{
		mTable[i] = mTable[i] + baseVariation*cos((2 * PI / lenght)*i);



	}
}


DoubleSinusTable::~DoubleSinusTable()
{
}



