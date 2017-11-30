#ifndef Q_SIMULATION_MENU_H
#define	Q_SIMULATION_MENU_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QCheckBox>
#include <QRadioButton>
#include <QDial>

class QSimulationMenu : public QWidget
{
	Q_OBJECT

public:
	QSimulationMenu(QWidget *parent = Q_NULLPTR);
	~QSimulationMenu();
	//QDial setWindAngleButton();
	
private:
	QVBoxLayout *mMenuLayout;
	QGridLayout *mMenuGridLayout;

	QSlider *mTemperatureSlider;
	QSlider *mPrecipitationSlider;
	QSlider *mLuminositySlider;
	QSlider *mWindForceSlider;
	QSlider *mPointOfViewSlider;

	QRadioButton *mPlayButton;
	QRadioButton *mPauseButton;
	QRadioButton *mStopButton;
	QRadioButton *mStepButton;

	QCheckBox *mThunderButton;

	QDial *mWindAngleButton;
};

#endif //Q_SIMULATION_MENU_H
