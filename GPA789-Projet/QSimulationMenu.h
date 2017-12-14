#ifndef Q_SIMULATION_MENU_H
#define	Q_SIMULATION_MENU_H

#include "QCyclicOptions.h"
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

class QSimulationMenu : public QWidget
{
	Q_OBJECT

public:
	QSimulationMenu(QWidget *parent = Q_NULLPTR);
	~QSimulationMenu();

	void getParameters(SimulationParameters *simulationParameters);

	void freeze();
	void unfreeze();

signals:
	void play();
	void pause();
	void stop();
	void step();

private:
	QVBoxLayout *mMenuLayout;
	QHBoxLayout *mThunderLayout;
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
};

#endif //Q_SIMULATION_MENU_H
