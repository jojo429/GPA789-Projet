#ifndef SINUS_TABLE_H
#define SINUS_TABLE_H

#include <vector>

class SinusTable
{
public:
	SinusTable();
	~SinusTable();
	void Initialize(int cycle, int average, int variation, int lenght);
	void Initialize(int cycle, int average, int variation, int lenght, bool noNegative);
	void Reset(int cycle, int average, int variation);

private:
	std::vector <double> mTable;
	int mLenght;
	bool mNoNegative;
};

#endif //SINUS_TABLE_H
