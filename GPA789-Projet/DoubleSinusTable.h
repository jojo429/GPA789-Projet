#ifndef DOUBLE_SINUS_TABLE_H
#define DOUBLE_SINUS_TABLE_H

#include "SinusTable.h"
class DoubleSinusTable : public SinusTable
{
public:
	DoubleSinusTable();
	~DoubleSinusTable();

	void initialize(int cycle, int average, int variation,int baseVariation, int lenght);
	void initialize(int cycle, int average, int variation,int baseVariation, int lenght, bool noNegative);
};

#endif

