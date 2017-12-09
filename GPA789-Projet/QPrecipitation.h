#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QCyclic.h"
#include <array>

class QPrecipitation : public QCyclic
{

public:
	QPrecipitation();
	~QPrecipitation();
	float germinate();
	float grow();
	float adjustDryness();
	void initialize(int cycle, int average, int variation);
	std::array<double,3> airDisplacement();

};

#endif //Q_PRECIPITATION_H

