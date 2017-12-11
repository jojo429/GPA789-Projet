#ifndef Q_FERTILITY_H
#define Q_FERTILITY_H

#include "QPonctual.h"
#include "QRandomMap.h"

#include <list>
#include <QImage>
#include <QPointF>

class QFertility : public QPonctual
{

public:
	QFertility();
	~QFertility();
	double getFertility(int x, int y);
	//char getFertility(QPointF pt2D);
	void setFertility(double minValue, double maxValue);
	void updateFertility(int x, int y, double fertility);
	//void setFertility(QPointF pt2D, char fertility);
	void enableFertility();
	void disableFertility();
	float germinate(QPointF pt2D);
	float grow(QPointF pt2D);

private:
	QRandomMap *mFertilityMap;

	//std::list<std::list<char>> mFertility;
	//QImage mMap;

};

#endif //Q_FERTILITY_H
