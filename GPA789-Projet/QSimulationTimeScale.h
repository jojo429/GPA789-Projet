#ifndef Q_SIMULATION_TIME_SCALE_H
#define Q_SIMULATION_TIME_SCALE_H

#include <QWidget>
//#include <QString>
//#include <QPixmap>
#include <QSlider>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>

class QSimulationTimeScale : public QWidget
{
	Q_OBJECT

public:
	QSimulationTimeScale(QWidget *parent = Q_NULLPTR);
	QSimulationTimeScale(QString caption, QString iconNameLow, QString iconNameHigh);
	~QSimulationTimeScale();
	int getValue();

private:
	QPixmap mIconLow;
	QPixmap mIconHigh;
	QHBoxLayout *mSliderHLayout;
	QHBoxLayout *mLayout;
	QSlider *mTimeScaleSlider;
	QGroupBox * mTimeScaleGroupBox;
	QLabel *mIconLabelLow;
	QLabel *mIconLabelHigh;
};

#endif