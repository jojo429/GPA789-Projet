#ifndef SINUS_TABLE_H
#define SINUS_TABLE_H


#include "FunctionTable.h"

class SinusTable : public FunctionTable
{
public:
	SinusTable(int cycle, int average, int variation, int lenght, bool noNegative);
	~SinusTable();
	void set(int cycle, int average, int variation);

protected:
	bool mNoNegative;
};

#endif //SINUS_TABLE_H
