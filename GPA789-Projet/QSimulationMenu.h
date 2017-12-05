#ifndef Q_SIMULATION_MENU_H
#define	Q_SIMULATION_MENU_H

#include "QCyclicOptions.h"

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QCheckBox>
#include <QRadioButton>

class QSimulationMenu : public QWidget
{
	Q_OBJECT

public:
	QSimulationMenu(QWidget *parent = Q_NULLPTR);
	~QSimulationMenu();
	
private:
	QVBoxLayout *mMenuLayout;
	QGridLayout *mMenuGridLayout;

	QSlider *mPointOfViewSlider;

	QRadioButton *mPlayButton;
	QRadioButton *mPauseButton;
	QRadioButton *mStopButton;
	QRadioButton *mStepButton;

	QCheckBox *mThunderButton;

	QCyclicOptions *mLuminosity;
	QCyclicOptions *mWind;
	QCyclicOptions *mPrecipitation;
	QCyclicOptions *mTemperature;
};

#endif //Q_SIMULATION_MENU_H
