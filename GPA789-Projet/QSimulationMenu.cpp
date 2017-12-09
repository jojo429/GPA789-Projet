#include "QSimulationMenu.h"

QSimulationMenu::QSimulationMenu(QWidget *parent)
	: QWidget(parent)
{
	//Définition des options cycliques
	mLuminosity = new QCyclicOptions("Luminosity", ":/GPA789Projet/iconLuminosity",
		"Average", "Variation", "Cycle", 0, 100, 0, 100, 0, 100);
	mWind = new QCyclicOptions("Wind", ":/GPA789Projet/iconWind",
		"Average", "Variation", "Cycle", 0, 100, 0, 100, 0, 100);
	mPrecipitation = new QCyclicOptions("Precipitation", ":/GPA789Projet/iconRain",
		"Middle Value", "Variation", "Cycle", 0, 100, 0, 100, 0, 1);
	mTemperature = new QCyclicOptions("Temperature", ":/GPA789Projet/iconTemperature",
		"Average", "Variation", "Cycle", 0, 100, 0, 100, 0, 100);

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


	connect(mPlayButton, &QSimulationAdvancementOptions::Clicked, this, &QSimulationMenu::Play);
	connect(mPauseButton, &QSimulationAdvancementOptions::Clicked, this, &QSimulationMenu::Pause);
	connect(mStopButton, &QSimulationAdvancementOptions::Clicked, this, &QSimulationMenu::Stop);
	connect(mStepButton, &QSimulationAdvancementOptions::Clicked, this, &QSimulationMenu::Step);
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
	mMenuLayout->addWidget(mLuminosity);
	mMenuLayout->addWidget(mWind);
	mMenuLayout->addWidget(mPrecipitation);
	mMenuLayout->addWidget(mTemperature);
	mMenuLayout->addLayout(mThunderLayout);
	mMenuLayout->addLayout(mMenuGridLayout);
	mMenuLayout->addWidget(mPointOfViewSlider);
	mMenuLayout->addStretch();

	setLayout(mMenuLayout);
}

QSimulationMenu::~QSimulationMenu()
{

}


void QSimulationMenu::GetParameters(SimulationParameters *simulationParameters)
{

	simulationParameters->PrecipitationAverage = mPrecipitation->getAverageValue();
	simulationParameters->PrecipitationCycle = mPrecipitation->getCycleValue();
	simulationParameters->PrecipitationVariation = mPrecipitation->getVariationValue();
	simulationParameters->TemperatureAverage = mTemperature->getAverageValue();
	simulationParameters->TemperatureCycle = mTemperature->getCycleValue();
	simulationParameters->TemperatureVariation = mTemperature->getVariationValue();
	simulationParameters->LuminosityAverage = mLuminosity->getAverageValue();
	simulationParameters->LuminosityCycle = mLuminosity->getCycleValue();
	simulationParameters->LuminosityVariation = mLuminosity->getVariationValue();
	simulationParameters->WindAverage = mWind->getAverageValue();
	simulationParameters->WindCycle = mWind->getCycleValue();
	simulationParameters->WindVariation = mWind->getVariationValue();



}


