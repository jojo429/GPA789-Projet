// QSupplement.h
//
// Description:
// Widget g�rant l'affichage du menu � propos de l'application.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QSupplement.h"
#include <QApplication>

QSupplement::QSupplement(QWidget * parent)
	: QWidget(parent)
{
	// D�finir les boutons de l'onglet "Suppl�ments"
	mButtonAbout = setPushButton(QStringLiteral("� propos de Forest Simulation"));

	// D�finir le layout des boutons
	mLayout = new QGridLayout;
	mLayout->addWidget(mButtonAbout, 0, 0);

	// D�placer le layout vers la droite
	mHLayout = new QHBoxLayout;
	mHLayout->addStretch();
	mHLayout->addLayout(mLayout);

	// D�placer le layout vers le bas
	mVLayout = new QVBoxLayout;
	mVLayout->addStretch();
	mVLayout->addLayout(mHLayout);

	// G�n�rer le layout
	setLayout(mVLayout);

	// Connecter les boutons aux fen�tres de dialogues
	connect(mButtonAbout, &QPushButton::clicked, this, &QSupplement::setMesBoxAbout);
}

QPushButton * QSupplement::setPushButton(QString const & caption)
{
	return new QPushButton(caption, Q_NULLPTR);
}

void QSupplement::setMesBoxAbout()
{
	QString messageAbout{ QStringLiteral(R"(Le programme Forest Simulation permet de simuler la croissance d'un �cosyst�me form� de 4 types d'arbres et d'�cureuils. 

L'�cosyst�me est affect� par les facteurs suivants: la fertilit� du sol, la temp�rature, la pluie, le niveau d'ensoleillement et le vent.

Ce programme est r�dig� par:
Jo� Charest
Genevi�ve Dao Phan
F�lix Girard
Alex Gosselin Provonost

Dans le cadre du cours:
- GPA789 Analyse et conception orient�es objet
- Laboratoire 3

Version 1.0 )") };

	QMessageBox::about(this, QStringLiteral("� propos de Forest Simulation"), messageAbout);
}