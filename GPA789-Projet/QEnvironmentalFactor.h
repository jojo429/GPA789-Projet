#ifndef Q_ENVIRONMENTAL_FACTOR_H
#define Q_ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>

#include "QEnvironment.h"

class QEnvironmentalFactor : public QGraphicsItem
{

public:
	QEnvironmentalFactor(QGraphicsItem * parent = Q_NULLPTR);
	~QEnvironmentalFactor();
};

#endif //Q_ENVIRONMENTAL_FACTOR_H
