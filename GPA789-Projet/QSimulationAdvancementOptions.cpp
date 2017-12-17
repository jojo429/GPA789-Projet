// QSimlationAdvancementOptions.cpp
//
// Description:
// Widget g�rant l'affichage d'un bouton de simulation (play, pause, stop, step).
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QSimulationAdvancementOptions.h"

QSimulationAdvancementOptions::QSimulationAdvancementOptions(QWidget *parent)
	: QWidget(parent)
{
}

QSimulationAdvancementOptions::QSimulationAdvancementOptions(QString caption, QString iconName)
{
	mIcon = QPixmap(iconName);

	mButton = new QPushButton;
	mButton->setText(caption); // D�finir le nom du bouton
	mButton->setIcon(mIcon); // D�finir l'ic�ne du bouton

	// Assemblage
	mLayout = new QGridLayout;
	mLayout->addWidget(mButton);
	setLayout(mLayout);

	// Connection
	connect(mButton, &QPushButton::clicked, this, & QSimulationAdvancementOptions::clicked);
}




