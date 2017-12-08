#include "QCyclic.h"

QCyclic::QCyclic()
{
	
}


QCyclic::~QCyclic()
{

}

void QCyclic::Initialize(int cycle, int average, int variation, bool noNegative)
{
	int year = 2190;
	mSinusTable.initialize(cycle, average, variation, year, noNegative);
}

void QCyclic::Initialize(int cycle, int average, int variation)
{
	QCyclic::Initialize(cycle, average, variation, false);
}


