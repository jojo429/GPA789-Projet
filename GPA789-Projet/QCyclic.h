#ifndef Q_CYCLIC_H
#define Q_CYCLIC_H

#include "QEnvironmentalFactor.h"

class QCyclic : public QEnvironmentalFactor
{

public:
	QCyclic(int cycle, int average, int variation);
	~QCyclic();
	void setCycle(int cycle);
	void setAverage(int average);
	void setVariation(int variation);

private:
	int mCycle;
	int mAverage;
	int mVariation;

};

#endif //Q_CYCLIC_H

