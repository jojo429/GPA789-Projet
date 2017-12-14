#ifndef DOUBLE_SINUS_TABLE_H
#define DOUBLE_SINUS_TABLE_H

#include "SinusTable.h"
class DoubleSinusTable : public SinusTable
{
public:
	DoubleSinusTable(int cycle, int average, int variation, int lenght, bool noNegative, int baseVariation);
	~DoubleSinusTable();

	
};

#endif

