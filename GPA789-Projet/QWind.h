#ifndef Q_WIND_H
#define Q_WIND_H

#include "QCyclic.h"
#include <array>

class QWind : public QCyclic
{

public:
	QWind(int cycle, int average, int variation);
	~QWind();
	float adjustDryness();
	std::array<double, 3> airDisplacement();

};

#endif //Q_WIND_H

