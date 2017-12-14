#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H

#include <vector>

class FunctionTable
{
public:
	FunctionTable(int lenght);
	~FunctionTable();

	virtual void set();
	double getValue(int position);

protected:
	std::vector <double> mTable;
	int mLenght;

};

#endif
