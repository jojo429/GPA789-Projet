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

signals:
	void play();
	void pause();
	void stop();
	void step();

private:
	QVBoxLayout *mMenuLayout;
	QVBoxLayout *mOptionsLayout;
	QVBoxLayout *mTreesVBoxLayout;
	QVBoxLayout *mAnimalsVBoxLayout;
	QHBoxLayout *mThunderLayout;
	QHBoxLayout *mTreesHBoxLayout;
	QHBoxLayout *mAnimalsHBoxLayout;
	QGridLayout *mMenuGridLayout;

	QPixmap mThunderIcon;

	QSimulationAdvancementOptions *mPlayButton;
	QSimulationAdvancementOptions *mPauseButton;
	QSimulationAdvancementOptions *mStopButton;
	QSimulationAdvancementOptions *mStepButton;

	QSimulationTimeScale *mTimeScaleSlider;

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
};

#endif //Q_SIMULATION_MENU_H
