#include "QTemperature.h"

QTemperature::QTemperature(int cycle, int average, int variation)
	:QCyclic(cycle, average, variation)
{
	


}





QTemperature::~QTemperature()
{

}



//float QTemperature::germinate(int time)
//{
//	return mSinusTable.getValue(time);
//}
//
//float QTemperature::grow(int time)
//{
//	return mSinusTable.getValue(time);
//}
//
//float QTemperature::adjustDryness(int time)
//{
//	return mSinusTable.getValue(time);
//}
