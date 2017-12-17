// QSimulationMenu.h
//
// Description:
// Widget gérant l'affichage et la connection du menu de la section simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

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
#include <QGroupBox>
#include <QDial>

class QSimulationMenu : public QWidget
{
	Q_OBJECT

public:
	QSimulationMenu(QWidget *parent = Q_NULLPTR);
	~QSimulationMenu()=default;

	void getParameters(SimulationParameters *simulationParameters); // Permet de récupérer tous les paramètres de la simulation
	void freeze(); // Disable les sliders des facteurs suivants: luminosity, precipitation, wind, temperature, oak, birch, hazel, fir, squirrel
	void unfreeze(); // Enable les sliders des facteurs suivants: luminosity, precipitation, wind, temperature, oak, birch, hazel, fir, squirrel
	void freezePlayButton(); // Disable le bouton play
	void freezeStepButton(); // Disable le bouton step
	void freezePauseButton(); // Disable le bouton pause
	void freezeStopButton(); // Disable le bouton stop
	void unfreezePlayButton(); // Enable le bouton play
	void unfreezeStepButton(); // Enable le bouton step
	void unfreezePauseButton(); // Enable le bouton pause
	void unfreezeStopButton(); // Enable le bouton stop
	void initAdvancementButtons(); // Initialise l'état des boutons suivantes: play, step, pause, stop
	int getTimeScaleValue(); // Retourner la valeur du time scale
	int getAngleDialValue(); // Retourner l'angle du vent
	void setAdvanceCounter(int advanceCounter); // Affichage le compteur d'advance

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
	QSimulationAdvancementOptions *mPlayButton;
	QSimulationAdvancementOptions *mPauseButton;
	QSimulationAdvancementOptions *mStopButton;
	QSimulationAdvancementOptions *mStepButton;
	QSimulationTimeScale *mTimeScaleSlider;
	QLabel *mAdvanceCounterLabel;
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
