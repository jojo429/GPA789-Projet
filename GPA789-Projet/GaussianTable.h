#ifndef GAUSSIAN_TABLE_H
#define GAUSSIAN_TABLE_H

#include "FunctionTable.h"

class GaussianTable : public FunctionTable
{
public:
	GaussianTable(int lenght, int mainValue, int spreadFactor);
	~GaussianTable();

	void set(int mainValue, int spreadFactor);

};


#endif
