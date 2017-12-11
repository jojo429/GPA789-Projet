#ifndef Q_RANDOM_MAP_H
#define Q_RANDOM_MAP_H

#include <QWidget>
#include <QPixmap>

class QRandomMap : public QWidget
{
	Q_OBJECT

public:
	QRandomMap(QWidget *parent = Q_NULLPTR);
	~QRandomMap();

	void setMap();
	void scaleMap();
	void findMinMax();
	void drawMap();

private:
	qreal mMap[513][513]; //mMap[2049][2049];
	int mMin;
	int mMax;
	
	QPixmap mPixelsMap;
};

#endif //Q_RANDOM_MAP_H
