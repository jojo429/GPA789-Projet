#ifndef CYCLIC_TABLE_H
#define CYCLIC_TABLE_H

#include <vector>

class CyclicTable
{
public:
	CyclicTable();
	~CyclicTable();
	void Initialize(int cycle, int average, int variation, int lenght);

private:
	std::vector <double> mTable;
	int mLenght;
};

#endif //CYCLIC_TABLE_H
