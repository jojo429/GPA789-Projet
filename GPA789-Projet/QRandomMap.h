#ifndef Q_RANDOM_MAP_H
#define Q_RANDOM_MAP_H

#include <QWidget>
#include <QPixmap>
#include <QPointF>
#include <QPainter>

class QRandomMap : public QWidget
{
	Q_OBJECT

public:
	QRandomMap(QWidget *parent = Q_NULLPTR);
	~QRandomMap();

	void setMap();
	void scaleMap(double minScaleValue, double maxScaleValue);
	void findMinMax();
	void drawMap(int rColor, int gColor, int bColor);
	void updateDrawMap(int x, int y, int rColor, int gColor, int bColor);
	double getMapValue(int x, int y);
	void setMapValue(int x, int y, double value);

private:
	int mMin;
	int mMax;
	double mMap[513][513];
	
	QPixmap mPixelsMap;
	
	QPainter mPainterMap;
};

#endif //Q_RANDOM_MAP_H
