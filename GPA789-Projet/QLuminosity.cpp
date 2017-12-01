#include "QLuminosity.h"

QLuminosity::QLuminosity(int cycle, int average, int variation)
	: QCyclic{ cycle, average, variation }
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
