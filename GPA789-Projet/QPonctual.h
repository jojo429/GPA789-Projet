#ifndef Q_PONCTUAL_H
#define Q_PONCTUAL_H

#include "QEnvironmentalFactor.h"

class QPonctual : public QEnvironmentalFactor
{

public:
	QPonctual();
	~QPonctual();
	float getFactor(int Time);

};

#endif //Q_PONCTUAL_H

