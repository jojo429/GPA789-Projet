#ifndef Q_TEMPERATURE_H
#define Q_TEMPERATURE_H

#include "QGlobal.h"

class QTemperature : public QGlobal
{

public:
	QTemperature();
	~QTemperature();
	int getTemperature();
	void setTemperature();
	float germinate();
	float grow();
	float adjustDryness();

private:
	int mTemperatureMax;
	int mTemperatureMin;
	int mTemperature;
	int mCycle;

};

#endif //Q_TEMPERATURE_H

