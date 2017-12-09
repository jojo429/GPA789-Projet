#include "QCyclic.h"

QCyclic::QCyclic()
{
	
}


QCyclic::~QCyclic()
{

}

void QCyclic::initialize(int cycle, int average, int variation, bool noNegative)
{
	int year = 2190;
	mSinusTable.initialize(cycle, average, variation, year, noNegative);
}

void QCyclic::initialize(int cycle, int average, int variation)
{
	QCyclic::initialize(cycle, average, variation, false);
}


