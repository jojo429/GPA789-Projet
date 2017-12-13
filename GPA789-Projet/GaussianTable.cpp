#include "GaussianTable.h"
#include "math.h"


GaussianTable::GaussianTable(int lenght, int mainValue, int spreadFactor)
	: FunctionTable(lenght)
{


}


GaussianTable::~GaussianTable()
{
}

void GaussianTable::set(int mainValue, int spreadFactor)
{
	mTable.clear();

	double temporary = 0;

	for (int x(0); x < mLenght; x++)
	{

		mTable.push_back(exp(((-(x - mainValue))*(-(x - mainValue))) / spreadFactor));
	}

}
