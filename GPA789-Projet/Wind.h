#ifndef WIND_H
#define WIND_H

#include "Global.h"

class Wind : public Global
{

public:
	Wind();
	~Wind();
	int getWindAngle();
	int getWindForce();
	void setWindAngle(int angle);
	void setWindForce(int force);

private:
	int mWindAngle;
	int mWindForce;

};

#endif //WIND_H

