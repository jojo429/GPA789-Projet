#ifndef Q_WIND_H
#define Q_WIND_H

#include "QCyclic.h"
#include <array>

class QWind : public QCyclic
{

public:
	QWind(int cycle, int average, int variation);
	~QWind();


};

#endif //Q_WIND_H

