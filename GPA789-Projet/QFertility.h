#ifndef Q_FERTILITY_H
#define Q_FERTILITY_H

#include "QLocal.h"

#include <QImage>
#include <QPointF>

class QFertility : public QLocal
{

public:
	QFertility();
	~QFertility();
	char getFertility(qreal x, qreal y);
	void setFertility(qreal x, qreal y, char fertility);
	void setFertility(QPointF f, char fertility);
	void showFertility(bool enable);
	void enableFertility();
	void disableFertility();
	float germinate(QPointF pt2D);
	float grow(QPointF pt2D);

private:
	//list<table<char>> mFertility
	QImage mMap;

};

#endif //Q_FERTILITY_H
