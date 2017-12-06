#ifndef SINUS_TABLE_H
#define SINUS_TABLE_H

#include <vector>

class SinusTable
{
public:
	SinusTable();
	~SinusTable();
	void initialize(int cycle, int average, int variation, int lenght);
	void initialize(int cycle, int average, int variation, int lenght, bool noNegative);
	void reset(int cycle, int average, int variation);
	double getValue(int );

private:
	std::vector <double> mTable;
	int mLenght;
	bool mNoNegative;
};

#endif //SINUS_TABLE_H
