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
	void setFertility(double minValue, double maxValue);
	void updateFertility(int x, int y, double fertility);
	void enableFertility();
	void disableFertility();
	float germinate(int x, int y);
	float grow(int x, int y);

private:
	QRandomMap *mFertilityMap;

	//std::list<std::list<char>> mFertility;
	//QImage mMap;

};

#endif //Q_FERTILITY_H
