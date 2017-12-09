#ifndef Q_TEMPERATURE_H
#define Q_TEMPERATURE_H

#include "QCyclic.h"

class QTemperature : public QCyclic
{

public:
	QTemperature();

	~QTemperature();
	float germinate();
	float grow();
	float adjustDryness();
	void initialize(int cycle, int average, int variation);

};

#endif //Q_TEMPERATURE_H

