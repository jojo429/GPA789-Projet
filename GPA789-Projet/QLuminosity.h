#ifndef Q_LUMINOSITY_H
#define Q_LUMINOSITY_H

#include "QCyclic.h"

class QLuminosity : public QCyclic
{

public:
	QLuminosity();
	~QLuminosity();
	float germinate();
	float grow();
	void initialize(int cycle, int average, int variation);
};

#endif //Q_LUMINOSITY_H

