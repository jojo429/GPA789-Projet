#ifndef Q_WIND_H
#define Q_WIND_H

#include "QGlobal.h"

class QWind : public QGlobal
{

public:
	QWind();
	~QWind();
	int getWindAngle();
	int getWindForce();
	void setWindAngle(int angle);
	void setWindForce(int force);

private:
	int mWindAngle;
	int mWindForce;

};

#endif //Q_WIND_H

