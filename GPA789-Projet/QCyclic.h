#ifndef Q_CYCLIC_H
#define Q_CYCLIC_H

#include "QEnvironmentalFactor.h"
#include "SinusTable.h"

class QCyclic : public QEnvironmentalFactor
{

public:

	QCyclic(int cycle, int average, int variation, bool noNegative);
	virtual ~QCyclic();
	void setTable(int cycle, int average, int variation);
	float getFactor(int time);

protected:

	SinusTable mSinusTable;
	
};

#endif //Q_CYCLIC_H

