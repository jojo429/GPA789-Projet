#ifndef Q_ENVIRONMENTAL_FACTOR_H
#define Q_ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>

#include "QEnvironment.h"
#include <array>

class QEnvironmentalFactor : public QGraphicsItem
{

public:
	QEnvironmentalFactor(QGraphicsItem * parent = Q_NULLPTR);
	~QEnvironmentalFactor();
	float germinate();
	float grow();
	float adjustDryness();
	std::array<double,3> airDisplacement();
};

#endif //Q_ENVIRONMENTAL_FACTOR_H
