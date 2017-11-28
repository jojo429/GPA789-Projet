#ifndef ENVIRONMENTAL_FACTOR_H
#define ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>

#include "Environment.h"

class EnvironmentalFactor : public QGraphicsItem
{

public:
	EnvironmentalFactor(QGraphicsItem * parent = Q_NULLPTR);
	~EnvironmentalFactor();
};

#endif //ENVIRONMENTAL_FACTOR_H
