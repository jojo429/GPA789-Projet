#ifndef Q_ENVIRONMENTAL_FACTOR_H
#define Q_ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>
#include <array>

class QEnvironmentalFactor
{

public:
	QEnvironmentalFactor();
	~QEnvironmentalFactor();
	float germinate();
	float grow();
	float adjustDryness();
	std::array<double,3> airDisplacement();
};

#endif //Q_ENVIRONMENTAL_FACTOR_H
