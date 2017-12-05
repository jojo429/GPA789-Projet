#include "QSimulationMenu.h"

QSimulationMenu::QSimulationMenu(QWidget *parent)
	: QWidget(parent)
{
	//Définition des options cycliques
	mLuminosity = new QCyclicOptions("Luminosity", ":/GPA789Projet/iconLuminosity",
		0, 100, 0, 100, 0, 100);
	mWind = new QCyclicOptions("Wind", ":/GPA789Projet/iconWind",
		0, 100, 0, 100, 0, 100);
	mPrecipitation = new QCyclicOptions("Precipitation", ":/GPA789Projet/iconRain",
		0, 100, 0, 100, 0, 100);
	mTemperature = new QCyclicOptions("Temperature", ":/GPA789Projet/iconTemperature",
		0, 100, 0, 100, 0, 100);

	//Définition du bouton générant un éclair
	mThunderButton = new QCheckBox;

	//Définition des boutons d'avancement
	mPlayButton = new QRadioButton(QStringLiteral("Play"));
	mPauseButton = new QRadioButton(QStringLiteral("Pause"));
	mStopButton = new QRadioButton(QStringLiteral("Stop"));
	mStepButton = new QRadioButton(QStringLiteral("Step"));

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
	mMenuLayout->addWidget(mThunderButton, 1, 0);
	mMenuLayout->addLayout(mMenuGridLayout);
	mMenuLayout->addWidget(mPointOfViewSlider);
	mMenuLayout->addStretch();

	setLayout(mMenuLayout);
}

QSimulationMenu::~QSimulationMenu()
{

}
