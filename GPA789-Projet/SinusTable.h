#ifndef SINUS_TABLE_H
#define SINUS_TABLE_H

#include <vector>

class SinusTable
{
public:
	SinusTable();
	~SinusTable();
	void Initialize(int cycle, int average, int variation, int lenght);

private:
	std::vector <double> mTable;
	int mLenght;
};

#endif //SINUS_TABLE_H
