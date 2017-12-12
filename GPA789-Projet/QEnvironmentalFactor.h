#ifndef Q_ENVIRONMENTAL_FACTOR_H
#define Q_ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>
#include <array>

class QEnvironmentalFactor
{

public:
	QEnvironmentalFactor();
	~QEnvironmentalFactor();
	
	float getFactor(int Time);

	/*float germinate();
	float grow();
	float adjustDryness();
	std::array<double,3> airDisplacement();
	float germinate(int time);
	float grow(int time);
	float adjustDryness(int time);
	std::array<double, 3> airDisplacement(int time);*/
};

#endif //Q_ENVIRONMENTAL_FACTOR_H
