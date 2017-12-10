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
	void set(int cycle, int average, int variation);
	//double getValue(int value);

protected:
	std::vector <double> mTable;
	int mLenght;
	bool mNoNegative;
};

#endif //SINUS_TABLE_H
