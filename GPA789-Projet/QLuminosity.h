#ifndef Q_LUMINOSITY_H
#define Q_LUMINOSITY_H

#include "QCyclic.h"

class QLuminosity : public QCyclic
{

public:
	QLuminosity(int cycle, int average, int variation);
	~QLuminosity();
	float germinate();
	float grow();

};

#endif //Q_LUMINOSITY_H

