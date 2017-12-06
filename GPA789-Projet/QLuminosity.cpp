#include "QLuminosity.h"

QLuminosity::QLuminosity(int cycle, int average, int variation)
	: QCyclic{ cycle, average, variation, true }
{

}

QLuminosity::~QLuminosity()
{

}

float QLuminosity::germinate()
{
	return 0;
}

float QLuminosity::grow()
{
	return 0;
}
