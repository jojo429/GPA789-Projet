#include "QCyclic.h"

QCyclic::QCyclic(int cycle, int average, int variation, bool noNegative)
{
	int year = 2190;
	mSinusTable.Initialize(cycle, average, variation, year, noNegative);
}

QCyclic::QCyclic(int cycle, int average, int variation)
{
	QCyclic::QCyclic(cycle, average, variation, false);
}

QCyclic::~QCyclic()
{

}

void QCyclic::setCycle(int cycle)
{

}

void QCyclic::setAverage(int average)
{

}

void QCyclic::setVariation(int variation)
{

}
