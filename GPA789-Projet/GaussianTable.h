#ifndef GAUSSIAN_TABLE_H
#define GAUSSIAN_TABLE_H

#include "FunctionTable.h"

class GaussianTable : public FunctionTable
{
public:
	GaussianTable(int lenght, int mainValue, int spreadFactor, int shiftFactor=0);
	~GaussianTable();

	void set(int mainValue, int spreadFactor);
	double getValue(int position) override;
protected:
	int mShiftFactor;
};


#endif
