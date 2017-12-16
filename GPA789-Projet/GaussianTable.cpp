#include "GaussianTable.h"
#include "math.h"


GaussianTable::GaussianTable(int lenght, int mainValue, int spreadFactor, int shiftFactor)
	: FunctionTable(lenght), mShiftFactor{shiftFactor}
{

	GaussianTable::set(mainValue, spreadFactor);
}


GaussianTable::~GaussianTable()
{
}

void GaussianTable::set(int mainValue, int spreadFactor)
{
	mTable.clear();

	double temporary = 0;

	for (int x(mShiftFactor); x < (mLenght + mShiftFactor); x++)
	{

		mTable.push_back(exp(-((x - mainValue)*(x - mainValue)) / static_cast<double>(spreadFactor)));
	}

}


double GaussianTable::getValue(int position)
{
	return FunctionTable::getValue(position - mShiftFactor);

}