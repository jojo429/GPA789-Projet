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
	float germinate() override;
	float grow() override;
	float adjustDryness() override;

private:
	int mTemperatureMax;
	int mTemperatureMin;
	int mTemperature;

};

#endif //Q_TEMPERATURE_H

