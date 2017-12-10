#ifndef Q_CYCLIC_H
#define Q_CYCLIC_H

#include "QEnvironmentalFactor.h"
#include "SinusTable.h"

class QCyclic : public QEnvironmentalFactor
{

public:
	QCyclic();
	~QCyclic();
	void initialize(int cycle, int average, int variation);
	void initialize(int cycle, int average, int variation, bool noNegative);


private:

	SinusTable mSinusTable;

};

#endif //Q_CYCLIC_H

