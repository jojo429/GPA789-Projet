#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QCyclic.h"
#include <array>

class QPrecipitation : public QCyclic
{

public:
	QPrecipitation(int cycle, int average, int variation);
	~QPrecipitation();


};

#endif //Q_PRECIPITATION_H

