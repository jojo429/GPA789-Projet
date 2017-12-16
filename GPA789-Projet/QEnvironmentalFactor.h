#ifndef Q_ENVIRONMENTAL_FACTOR_H
#define Q_ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>
#include <array>

class QEnvironmentalFactor
{

public:
	QEnvironmentalFactor();
	virtual ~QEnvironmentalFactor();
	
	virtual float getFactor(int Time);
	virtual void setTable(int cycle, int average, int variation);
};

#endif //Q_ENVIRONMENTAL_FACTOR_H
