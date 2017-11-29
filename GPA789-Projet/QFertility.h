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
	void fertility(bool enable);

private:
	QImage mMap;

};

#endif //Q_FERTILITY_H
