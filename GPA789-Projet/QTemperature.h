#ifndef Q_TEMPERATURE_H
#define Q_TEMPERATURE_H

#include "QCyclic.h"

class QTemperature : public QCyclic
{

public:
	QTemperature(int cycle, int average, int variation);

	~QTemperature();
	//float germinate(int time);
	//float grow(int time);
	//float adjustDryness(int time);


};

#endif //Q_TEMPERATURE_H

