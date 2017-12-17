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

#ifndef Q_SUPPLEMENT_H
#define Q_SUPPLEMENT_H

#include <QString>
#include <QWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

class QSupplement : public QWidget
{
	Q_OBJECT

public:
	QSupplement(QWidget * parent = Q_NULLPTR);

protected:
	QPushButton * mButtonAbout;
	QMessageBox * mMesBoxExec;
	QGridLayout * mLayout;
	QHBoxLayout * mHLayout;
	QVBoxLayout * mVLayout;
	QPushButton * setPushButton(QString const & caption);

protected slots:
	void setMesBoxAbout(); // Configurer la fen�tre "� propos de Forest Simulation"
};

#endif // Q_SUPPLEMENT_H

