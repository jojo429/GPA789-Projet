#ifndef Q_TEMPERATURE_H
#define Q_TEMPERATURE_H

#include "QCyclic.h"

class QTemperature : public QCyclic
{

public:
	QTemperature(int cycle, int average, int variation);

	~QTemperature();


};

#endif //Q_TEMPERATURE_H

