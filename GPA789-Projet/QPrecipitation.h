#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QCyclic.h"
#include <array>

class QPrecipitation : public QCyclic
{

public:
	QPrecipitation(int cycle, int average, int variation);
	~QPrecipitation();
	//float germinate(int time);
	//float grow(int time);
	//float adjustDryness(int time);
	//std::array<double,3> airDisplacement(int time);

};

#endif //Q_PRECIPITATION_H

