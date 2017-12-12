#include "QCyclic.h"

QCyclic::QCyclic(int cycle, int average, int variation)
{
	QCyclic::QCyclic(cycle, average, variation, false);
}


QCyclic::QCyclic(int cycle, int average, int variation, bool noNegative)
{
	int year = 2190;
	mSinusTable.initialize(cycle, average, variation, year, noNegative);
}



QCyclic::~QCyclic()
{

}

float QCyclic::getFactor(int time)
{
	return mSinusTable.getValue(time);
}
