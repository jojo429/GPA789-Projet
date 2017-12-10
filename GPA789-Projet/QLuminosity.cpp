#include "QLuminosity.h"

QLuminosity::QLuminosity()
	: QCyclic()
{

}

void QLuminosity::initialize(int cycle, int average, int variation)
{
	QCyclic::initialize(cycle, average, variation, true);


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
