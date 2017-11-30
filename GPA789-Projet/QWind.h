#ifndef Q_WIND_H
#define Q_WIND_H

#include "QGlobal.h"

class QWind : public QGlobal
{

public:
	QWind();
	~QWind();
	float getWindAngle();
	int getWindForce();
	void setWindAngle(int angle); //float angle?
	void setWindForce(int force);
	float adjustDryness() override;
	//array<double,3> airDisplacement()

private:
	float mWindAngle;
	int mWindForce;

};

#endif //Q_WIND_H

