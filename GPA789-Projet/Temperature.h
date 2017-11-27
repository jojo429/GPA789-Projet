#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Global.h"

class Temperature : public Global
{

public:
	Temperature();
	~Temperature();
	int getTemperature();
	void setTemperature();

private:
	int mTemperatureMax;
	int mTemperatureMin;
	int mTemperature;

};

#endif //TEMPERATURE_H

