#ifndef Q_LUMINOSITY_H
#define Q_LUMINOSITY_H

#include "QCyclic.h"

class QLuminosity : public QCyclic
{

public:
	QLuminosity(int cycle, int average, int variation, int baseVariation);
	~QLuminosity();
	float germinate(int time);
	float grow(int time);

};

#endif //Q_LUMINOSITY_H

