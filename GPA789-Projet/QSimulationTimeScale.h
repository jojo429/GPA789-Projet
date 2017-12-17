// QSimulationTimeScale.h
//
// Description:
// Widget g�rant l'affichage d'un slider de contr�le du temps.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_SIMULATION_TIME_SCALE_H
#define Q_SIMULATION_TIME_SCALE_H

#include <QWidget>
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