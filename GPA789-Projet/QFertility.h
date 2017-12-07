#ifndef Q_FERTILITY_H
#define Q_FERTILITY_H

#include "QPonctual.h"

#include <list>
#include <QImage>
#include <QPointF>

class QFertility : public QPonctual
{

public:
	QFertility();
	~QFertility();
	char getFertility(qreal x, qreal y);
	char getFertility(QPointF pt2D);
	void setFertility(qreal x, qreal y, char fertility);
	void setFertility(QPointF pt2D, char fertility);
	void enableFertility();
	void disableFertility();
	float germinate(QPointF pt2D);
	float grow(QPointF pt2D);

	void setFertility(double maxFertilityValue);
	void drawFertility();

private:
	std::list<std::list<char>> mFertility;
	QImage mMap;
	int mFertilityMap[2049][2049];

};

#endif //Q_FERTILITY_H
