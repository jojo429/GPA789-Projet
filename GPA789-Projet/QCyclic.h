#ifndef Q_CYCLIC_H
#define Q_CYCLIC_H

#include "QEnvironmentalFactor.h"
#include "SinusTable.h"

class QCyclic : public QEnvironmentalFactor
{

public:
	QCyclic(int cycle, int average, int variation);
	QCyclic(int cycle, int average, int variation, bool noNegative);
	~QCyclic();



private:

	SinusTable mSinusTable;

};

#endif //Q_CYCLIC_H

