#include "QSimulationMenu.h"

#include "QSimulation.h"
#include <QLabel>
#include <QScrollArea>
#include <QGroupBox>

QSimulationMenu::QSimulationMenu(QWidget *parent)
	: QWidget(parent)
{
	//Définition des options cycliques
	mLuminosity = new QCyclicOptions("Luminosity", ":/GPA789Projet/iconLuminosity",
		"Average", "Variation", "Cycle", 0, 0, 0, 100, 2190, 2190, false, true, false,
		0, 30, 2190);
	mPrecipitation = new QCyclicOptions("Precipitation", ":/GPA789Projet/iconRain",
		"Average", "Variation", "Cycle", 0, 6, 0, 20, 30, 2190, true, true, true,
		2, 2, 365);
	mTemperature = new QCyclicOptions("Temperature", ":/GPA789Projet/iconTemperature",
		"Average", "Variation", "Cycle", -30, 30, 0, 40, 2190, 2190, true, true, false,
		20, 10, 2190);
	mWind = new QCyclicOptions("Wind", ":/GPA789Projet/iconWind",
		"Average", "Variation", "Cycle", 0, 100, 0, 100, 30, 2190, true, true, true,
		30, 10, 365);

	//Définition des sliders d'arbres
	mOak = new QTreeOptions("Oak", 0, 25, 10);
	mBirch = new QTreeOptions("Birch", 0, 25, 10);
	mHazel = new QTreeOptions("Hazel", 0, 25, 10);
	mFir = new QTreeOptions("Fir", 0, 25, 10);

	QPixmap treeIcon = QPixmap(":/GPA789Projet/iconForest");
	QPixmap tmpPixmap = treeIcon.scaled(QSize(50, 50), Qt::KeepAspectRatio);
	QLabel *treeIconLabel = new QLabel;
	treeIconLabel->setPixmap(tmpPixmap);

	mTreesVBoxLayout = new QVBoxLayout;
	mTreesVBoxLayout->addStretch();
	mTreesVBoxLayout->addWidget(mOak);
	mTreesVBoxLayout->addWidget(mBirch);
	mTreesVBoxLayout->addWidget(mHazel);
	mTreesVBoxLayout->addWidget(mFir);
	mTreesVBoxLayout->addStretch();

	mTreesGroupBox = new QGroupBox("Trees");
	mTreesGroupBox->setLayout(mTreesVBoxLayout);

	mTreesHBoxLayout = new QHBoxLayout;
	mTreesHBoxLayout->addWidget(treeIconLabel);
	mTreesHBoxLayout->addWidget(mTreesGroupBox);

	//Définition du slider d'écureuils
	QPixmap squirrelIcon = QPixmap(":/GPA789Projet/iconSquirrel");
	QPixmap tmpPixmap2 = squirrelIcon.scaled(QSize(50, 50), Qt::KeepAspectRatio);
	QLabel *animalIconLabel = new QLabel;
	animalIconLabel->setPixmap(tmpPixmap2);

	mSquirrel = new QAnimalOptions("Squirrel", 0, 25, 3);

	mAnimalsVBoxLayout = new QVBoxLayout;
	mAnimalsVBoxLayout->addWidget(mSquirrel);

	mAnimalsGroupBox = new QGroupBox("Animals");
	mAnimalsGroupBox->setLayout(mAnimalsVBoxLayout);

	mAnimalsHBoxLayout = new QHBoxLayout;
	mAnimalsHBoxLayout->addWidget(animalIconLabel);
	mAnimalsHBoxLayout->addWidget(mAnimalsGroupBox);

	//Définition du slider d'angle du vent
	mAngleDial = new QDial;
	mAngleDial->setMinimum(0);
	mAngleDial->setMaximum(359);
	mAngleDial->setWrapping(true);
	mAngleDial->setFixedHeight(100);
	mAngleDial->setFixedWidth(100);

	QLabel *dialLabel = new QLabel("Wind Direction");
	
	mAngleDialLayout = new QHBoxLayout;
	mAngleDialLayout->addStretch();
	mAngleDialLayout->addWidget(dialLabel);
	mAngleDialLayout->addWidget(mAngleDial);
	mAngleDialLayout->addStretch();
	
	////Définition de l'icône de l'éclair
	//mThunderIcon = QPixmap(":/GPA789Projet/iconThunder");

	////Définition du bouton générant un éclair
	//mThunderButton = new QCheckBox;
	//mThunderButton->setText("Act of God");
	//mThunderButton->setIcon(mThunderIcon);

	////Définition du layout du bouton générant un éclair
	//mThunderLayout = new QHBoxLayout;
	//mThunderLayout->addStretch();
	//mThunderLayout->addWidget(mThunderButton);
	//mThunderLayout->addStretch();

	//Définition des boutons d'avancement
	mPlayButton = new QSimulationAdvancementOptions("Play", ":/GPA789Projet/iconPlay");
	mPauseButton = new QSimulationAdvancementOptions("Pause", ":/GPA789Projet/iconPause");
	mStopButton = new QSimulationAdvancementOptions("Stop", ":/GPA789Projet/iconStop");
	mStepButton = new QSimulationAdvancementOptions("Step", ":/GPA789Projet/iconStep");

	//Initialiser l'état des boutons: play, step, pause et stop
	this->initAdvancementButtons();

	//Comportement du bouton play
	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::play);
	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freeze);
	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freezePlayButton);
	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freezeStepButton);
	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezePauseButton);
	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezeStopButton);

	//Comportement du bouton pause
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::pause);
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freeze);
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezePlayButton);
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezeStepButton);
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freezePauseButton);
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezeStopButton);

	//Comportement du bouton stop
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::stop);
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreeze);
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezePlayButton);
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::unfreezeStepButton);
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freezePauseButton);
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freezeStopButton);

	//Comportement du bouton step
	connect(mStepButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::step);

	//Comportement du bouton d'angle du vent
	connect(mAngleDial, &QDial::valueChanged, this, &QSimulationMenu::windAngle);

	//Définition du slider de point de vue
	mTimeScaleSlider = new QSimulationTimeScale("Time Scale", ":/GPA789Projet/iconSquirrel", ":/GPA789Projet/iconForest");

	connect(mStepButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::freeze);

	//Définition du layout de certains boutons
	mMenuGridLayout = new QGridLayout;
	mMenuGridLayout->addWidget(mPlayButton, 0, 0);
	mMenuGridLayout->addWidget(mStepButton, 0, 1);
	mMenuGridLayout->addWidget(mPauseButton, 0, 2);
	mMenuGridLayout->addWidget(mStopButton, 0, 3);

	//Definition du advance counter
	mAdvanceCounterLabel = new QLabel(QString::number(0));

	//Assemblage final
	mOptionsLayout = new QVBoxLayout;
	mOptionsLayout->addLayout(mTreesHBoxLayout);
	mOptionsLayout->addLayout(mAnimalsHBoxLayout);
	mOptionsLayout->addWidget(mTemperature);
	mOptionsLayout->addWidget(mPrecipitation);
	mOptionsLayout->addWidget(mLuminosity);
	mOptionsLayout->addWidget(mWind);
	

	QGroupBox *mMenuGroupBox = new QGroupBox;
	mMenuGroupBox->setLayout(mOptionsLayout);

	QScrollArea *optionsArea = new QScrollArea;
	optionsArea->setWidget(mMenuGroupBox);
	optionsArea->setWidgetResizable(true);
	optionsArea->setBackgroundRole(QPalette::Light);

	mBottomMenuLayout = new QHBoxLayout;
	mBottomMenuLayout->addLayout(mAngleDialLayout);
	mBottomMenuLayout->addWidget(mTimeScaleSlider);

	mMenuLayout = new QVBoxLayout;
	mMenuLayout->addWidget(optionsArea);
	//mMenuLayout->addLayout(mThunderLayout);
	mMenuLayout->addLayout(mMenuGridLayout);
	mMenuLayout->addLayout(mBottomMenuLayout);
	mMenuLayout->addWidget(mAdvanceCounterLabel);

	setLayout(mMenuLayout);
}

QSimulationMenu::~QSimulationMenu()
{

}


void QSimulationMenu::getParameters(SimulationParameters *simulationParameters)
{
	simulationParameters->mPrecipitationAverage = mPrecipitation->getAverageValue();
	simulationParameters->mPrecipitationCycle = mPrecipitation->getCycleValue();
	simulationParameters->mPrecipitationVariation = mPrecipitation->getVariationValue();
	simulationParameters->mTemperatureAverage = mTemperature->getAverageValue();
	simulationParameters->mTemperatureCycle = mTemperature->getCycleValue();
	simulationParameters->mTemperatureVariation = mTemperature->getVariationValue();
	simulationParameters->mLuminosityAverage = mLuminosity->getAverageValue();
	simulationParameters->mLuminosityCycle = mLuminosity->getCycleValue();
	simulationParameters->mLuminosityVariation = mLuminosity->getVariationValue();
	simulationParameters->mWindAverage = mWind->getAverageValue();
	simulationParameters->mWindCycle = mWind->getCycleValue();
	simulationParameters->mWindVariation = mWind->getVariationValue();
	simulationParameters->mNumberBirch = mBirch->getValue();
	simulationParameters->mNumberOak = mOak->getValue();
	simulationParameters->mNumberFir = mFir->getValue();
	simulationParameters->mNumberHazel = mHazel->getValue();
	simulationParameters->mNumberSquirrel = mSquirrel->getValue();
}

void QSimulationMenu::freeze()
{
	mLuminosity->setEnabled(false);
	mPrecipitation->setEnabled(false);
	mTemperature->setEnabled(false);
	mWind->setEnabled(false);
	mOak->setEnabled(false);
	mBirch->setEnabled(false);
	mHazel->setEnabled(false);
	mFir->setEnabled(false);
	mSquirrel->setEnabled(false);
}

void QSimulationMenu::unfreeze()
{
	mLuminosity->setEnabled(true);
	mPrecipitation->setEnabled(true);
	mTemperature->setEnabled(true);
	mWind->setEnabled(true);
	mOak->setEnabled(true);
	mBirch->setEnabled(true);
	mHazel->setEnabled(true);
	mFir->setEnabled(true);
	mSquirrel->setEnabled(true);
}

void QSimulationMenu::freezePlayButton()
{
	mPlayButton->setEnabled(false);
}

void QSimulationMenu::freezeStepButton()
{
	mStepButton->setEnabled(false);
}

void QSimulationMenu::freezePauseButton()
{
	mPauseButton->setEnabled(false);
}

void QSimulationMenu::freezeStopButton()
{
	mStopButton->setEnabled(false);
}

void QSimulationMenu::unfreezePlayButton()
{
	mPlayButton->setEnabled(true);
}

void QSimulationMenu::unfreezeStepButton()
{
	mStepButton->setEnabled(true);
}

void QSimulationMenu::unfreezePauseButton()
{
	mPauseButton->setEnabled(true);
}

void QSimulationMenu::unfreezeStopButton()
{
	mStopButton->setEnabled(true);
}

void QSimulationMenu::initAdvancementButtons()
{
	mPlayButton->setEnabled(true);
	mStepButton->setEnabled(true);
	mPauseButton->setEnabled(false);
	mStopButton->setEnabled(false);
}

int QSimulationMenu::getTimeScaleValue() {
	return mTimeScaleSlider->getValue();
}

int QSimulationMenu::getAngleDialValue()
{
	return mAngleDial->value();
}


void QSimulationMenu::setAdvanceCounter(int advanceCounter)
{
	mAdvanceCounterLabel->setText(QString::number(advanceCounter));
}

