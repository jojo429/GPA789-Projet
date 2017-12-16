#ifndef Q_FERTILITY_H
#define Q_FERTILITY_H

#include "QPonctual.h"
#include "QRandomMap.h"

#include <list>
#include <QImage>
#include <QPointF>
#include <QPainter>

class QFertility : public QPonctual
{

public:
	QFertility();
	~QFertility();
	double getFertility(int x, int y) const;
	void setFertility(double minValue, double maxValue);
	void updateFertility(int x, int y, double fertility);
	void enableFertility();
	void disableFertility();
	QPixmap getFertilityPixmap();


private:
	QRandomMap *mFertilityMap;



};

#endif //Q_FERTILITY_H
