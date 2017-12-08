#include "QLuminosity.h"

QLuminosity::QLuminosity()
	: QCyclic()
{

}

void QLuminosity::Initialize(int cycle, int average, int variation)
{
	QCyclic::Initialize(cycle, average, variation, true);


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
