// QSimlationAdvancementOptions.cpp
//
// Description:
// Widget gérant l'affichage d'un bouton de simulation (play, pause, stop, step).
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
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
	mButton->setText(caption); // Définir le nom du bouton
	mButton->setIcon(mIcon); // Définir l'icône du bouton

	// Assemblage
	mLayout = new QGridLayout;
	mLayout->addWidget(mButton);
	setLayout(mLayout);

	// Connection
	connect(mButton, &QPushButton::clicked, this, & QSimulationAdvancementOptions::clicked);
}




