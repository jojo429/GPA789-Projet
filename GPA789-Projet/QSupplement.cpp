// QSupplement.h
//
// Description:
// Widget gérant l'affichage du menu à propos de l'application.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QSupplement.h"
#include <QApplication>

QSupplement::QSupplement(QWidget * parent)
	: QWidget(parent)
{
	// Définir les boutons de l'onglet "Suppléments"
	mButtonAbout = setPushButton(QStringLiteral("À propos de Forest Simulation"));

	// Définir le layout des boutons
	mLayout = new QGridLayout;
	mLayout->addWidget(mButtonAbout, 0, 0);

	// Déplacer le layout vers la droite
	mHLayout = new QHBoxLayout;
	mHLayout->addStretch();
	mHLayout->addLayout(mLayout);

	// Déplacer le layout vers le bas
	mVLayout = new QVBoxLayout;
	mVLayout->addStretch();
	mVLayout->addLayout(mHLayout);

	// Générer le layout
	setLayout(mVLayout);

	// Connecter les boutons aux fenêtres de dialogues
	connect(mButtonAbout, &QPushButton::clicked, this, &QSupplement::setMesBoxAbout);
}

QPushButton * QSupplement::setPushButton(QString const & caption)
{
	return new QPushButton(caption, Q_NULLPTR);
}

void QSupplement::setMesBoxAbout()
{
	QString messageAbout{ QStringLiteral(R"(Le programme Forest Simulation permet de simuler la croissance d'un écosystème formé de 4 types d'arbres et d'écureuils. 

L'écosystème est affecté par les facteurs suivants: la fertilité du sol, la température, la pluie, le niveau d'ensoleillement et le vent.

Ce programme est rédigé par:
Joé Charest
Geneviève Dao Phan
Félix Girard
Alex Gosselin Provonost

Dans le cadre du cours:
- GPA789 Analyse et conception orientées objet
- Laboratoire 3

Version 1.0 )") };

	QMessageBox::about(this, QStringLiteral("À propos de Forest Simulation"), messageAbout);
}