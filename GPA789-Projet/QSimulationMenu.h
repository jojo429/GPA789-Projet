#ifndef Q_SIMULATION_MENU_H
#define	Q_SIMULATION_MENU_H

#include "QCyclicOptions.h"
#include "QTreeOptions.h"
#include "QAnimalOptions.h"
#include "QSimulationAdvancementOptions.h"
#include "QSimulationTimeScale.h"
#include "SimulationParameters.h"
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QCheckBox>
#include <QRadioButton>
#include <QPixmap>
#include <QGroupBox>
#include <QDial>

class QSimulationMenu : public QWidget
{
	Q_OBJECT

public:
	QSimulationMenu(QWidget *parent = Q_NULLPTR);
	~QSimulationMenu();

	void getParameters(SimulationParameters *simulationParameters);

	void freeze();
	void unfreeze();
	int getTimeScaleValue();
	int getAngleDialValue();
	void setAdvanceCounter(int advanceCounter);

signals:
	void play();
	void pause();
	void stop();
	void step();
	void windAngle(int angle);


	

private:
	

	QVBoxLayout *mMenuLayout;
	QHBoxLayout *mBottomMenuLayout;
	QVBoxLayout *mOptionsLayout;
	QVBoxLayout *mTreesVBoxLayout;
	QVBoxLayout *mAnimalsVBoxLayout;
	QHBoxLayout *mThunderLayout;
	QHBoxLayout *mTreesHBoxLayout;
	QHBoxLayout *mAnimalsHBoxLayout;
	QHBoxLayout *mAngleDialLayout;
	QGridLayout *mMenuGridLayout;

	QPixmap mThunderIcon;

	QSimulationAdvancementOptions *mPlayButton;
	QSimulationAdvancementOptions *mPauseButton;
	QSimulationAdvancementOptions *mStopButton;
	QSimulationAdvancementOptions *mStepButton;

	QSimulationTimeScale *mTimeScaleSlider;
	QLabel *mAdvanceCounterLabel;

	QCheckBox *mThunderButton;

	QCyclicOptions *mLuminosity;
	QCyclicOptions *mWind;
	QCyclicOptions *mPrecipitation;
	QCyclicOptions *mTemperature;

	QTreeOptions *mOak;
	QTreeOptions *mBirch;
	QTreeOptions *mHazel;
	QTreeOptions *mFir;

	QAnimalOptions *mSquirrel;

	QGroupBox *mTreesGroupBox;
	QGroupBox *mAnimalsGroupBox;

	QDial *mAngleDial;
};

#endif //Q_SIMULATION_MENU_H
