#ifndef Q_CYCLIC_H
#define Q_CYCLIC_H

#include "QEnvironmentalFactor.h"
#include "SinusTable.h"

class QCyclic : public QEnvironmentalFactor
{

public:
	QCyclic();
	~QCyclic();
	void Initialize(int cycle, int average, int variation);
	void Initialize(int cycle, int average, int variation, bool noNegative);


private:

	SinusTable mSinusTable;

};

#endif //Q_CYCLIC_H

