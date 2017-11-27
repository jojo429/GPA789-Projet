#ifndef FERTILITY_H
#define FERTILITY_H

#include "Local.h"

#include <QImage>
#include <QPoint>

class Fertility : public Local
{
	Q_OBJECT

public:
	Fertility();
	~Fertility();
	char getFertility(qreal x, qreal y);
	void setFertility(qreal x, qreal y, char fertility);
	void setFertility(QPoint f, char fertility);
	void showFertility(bool enable);
	void fertility(bool enable);

private:
	QImage mMap;

};

#endif //FERTILITY_H
