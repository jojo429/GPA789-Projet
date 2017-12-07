#pragma once

#include <QWidget>

class QRandomMap : public QWidget
{
	Q_OBJECT

public:
	QRandomMap(QWidget *parent);
	~QRandomMap();

	void setFertility(double maxFertilityValue);
	void drawFertility();

private:
	int mFertilityMap[2049][2049];
};
