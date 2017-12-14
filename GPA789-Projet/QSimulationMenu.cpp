#include "QSimulationMenu.h"

QSimulationMenu::QSimulationMenu(QWidget *parent)
	: QWidget(parent)
{
	//Définition des options cycliques
	mLuminosity = new QCyclicOptions("Luminosity", ":/GPA789Projet/iconLuminosity",
		"Average", "Variation", "Cycle", 0, 0, 0, 100, 2190, 2190);
	mPrecipitation = new QCyclicOptions("Precipitation", ":/GPA789Projet/iconRain",
		"Average", "Variation", "Cycle", 0, 6, 0, 20, 6, 2190);
	mTemperature = new QCyclicOptions("Temperature", ":/GPA789Projet/iconTemperature",
		"Average", "Variation", "Cycle", -30, 30, 0, 40, 2190, 2190);
	mWind = new QCyclicOptions("Wind", ":/GPA789Projet/iconWind",
		"Average", "Variation", "Cycle", 0, 100, 0, 100, 6, 2190);


	//Définition de l'icône de l'éclar
	mThunderIcon = QPixmap(":/GPA789Projet/iconThunder");

	//Définition du bouton générant un éclair
	mThunderButton = new QCheckBox;
	mThunderButton->setText("Act of God");
	mThunderButton->setIcon(mThunderIcon);

	//Définition du layout du bouton générant un éclair
	mThunderLayout = new QHBoxLayout;
	mThunderLayout->addStretch();
	mThunderLayout->addWidget(mThunderButton);
	mThunderLayout->addStretch();

	//Définition des boutons d'avancement
	mPlayButton = new QSimulationAdvancementOptions("Play", ":/GPA789Projet/iconPlay");
	mPauseButton = new QSimulationAdvancementOptions("Pause", ":/GPA789Projet/iconPause");
	mStopButton = new QSimulationAdvancementOptions("Stop", ":/GPA789Projet/iconStop");
	mStepButton = new QSimulationAdvancementOptions("Step", ":/GPA789Projet/iconStep");


	connect(mPlayButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::play);
	connect(mPauseButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::pause);
	connect(mStopButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::stop);
	connect(mStepButton, &QSimulationAdvancementOptions::clicked, this, &QSimulationMenu::step);
		//Définition du slider de point de vue
	mPointOfViewSlider = new QSlider(Qt::Horizontal);

	//Définition du layout de certains boutons
	mMenuGridLayout = new QGridLayout;
	mMenuGridLayout->addWidget(mPlayButton, 0, 0);
	mMenuGridLayout->addWidget(mStepButton, 0, 1);
	mMenuGridLayout->addWidget(mPauseButton, 0, 2);
	mMenuGridLayout->addWidget(mStopButton, 0, 3);

	//Assemblage final
	mMenuLayout = new QVBoxLayout;
	mMenuLayout->addWidget(mTemperature);
	mMenuLayout->addWidget(mPrecipitation);
	mMenuLayout->addWidget(mLuminosity);
	mMenuLayout->addWidget(mWind);
	mMenuLayout->addLayout(mThunderLayout);
	mMenuLayout->addLayout(mMenuGridLayout);
	mMenuLayout->addWidget(mPointOfViewSlider);
	mMenuLayout->addStretch();

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



}


