#include "QSimulationMenu.h"

QSimulationMenu::QSimulationMenu(QWidget *parent)
	: QWidget(parent)
{
	//Définition des éléments du menu
	mTemperatureSlider = new QSlider;
	mPrecipitationSlider = new QSlider;
	mLuminositySlider = new QSlider;
	mWindForceSlider = new QSlider;
	mPointOfViewSlider = new QSlider(Qt::Horizontal);
	mThunderButton = new QCheckBox;
	mPlayButton = new QRadioButton(QStringLiteral("Play"));
	mPauseButton = new QRadioButton(QStringLiteral("Pause"));
	mStopButton = new QRadioButton(QStringLiteral("Stop"));
	mStepButton = new QRadioButton(QStringLiteral("Step"));

	//Définition du layout de certains boutons
	mMenuGridLayout = new QGridLayout;
	mMenuGridLayout->addWidget(mTemperatureSlider, 0, 0);
	mMenuGridLayout->addWidget(mPrecipitationSlider, 0, 1);
	mMenuGridLayout->addWidget(mLuminositySlider, 0, 2);
	mMenuGridLayout->addWidget(mWindForceSlider, 1, 1);
	mMenuGridLayout->addWidget(mThunderButton, 1, 2);
	mMenuGridLayout->addWidget(mPlayButton, 2, 0);
	mMenuGridLayout->addWidget(mStepButton, 2, 1);
	mMenuGridLayout->addWidget(mPauseButton, 2, 2);
	mMenuGridLayout->addWidget(mStopButton, 2, 3);

	//Assemblage final
	mMenuLayout = new QVBoxLayout;
	mMenuLayout->addLayout(mMenuGridLayout);
	mMenuLayout->addWidget(mPointOfViewSlider);
	mMenuLayout->addStretch();

	setLayout(mMenuLayout);
}

QSimulationMenu::~QSimulationMenu()
{

}

QDial QSimulationMenu::setWindAngleButton()
{

}
