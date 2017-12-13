#include "QCyclic.h"



QCyclic::QCyclic(int cycle, int average, int variation, bool noNegative)
	:mSinusTable(cycle, average, variation, 2190, noNegative)
{


}


void QCyclic::setTable(int cycle, int average, int variation)
{

	mSinusTable.set(cycle, average, variation);

}


QCyclic::~QCyclic()
{

}

float QCyclic::getFactor(int time)
{
	return mSinusTable.getValue(time);
}
