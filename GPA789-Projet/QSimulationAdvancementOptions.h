// QSimlationAdvancementOptions.h
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

#ifndef Q_SIMULATION_ADVANCEMENT_OPTIONS_H
#define Q_SIMULATION_ADVANCEMENT_OPTIONS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>

class QSimulationAdvancementOptions : public QWidget
{
	Q_OBJECT

public:
	QSimulationAdvancementOptions(QWidget *parent = Q_NULLPTR );
	QSimulationAdvancementOptions(QString caption, QString iconName);
	~QSimulationAdvancementOptions();

signals:
	void clicked();

private:
	QPixmap mIcon;
	QPushButton *mButton;
	QGridLayout *mLayout;

};

#endif //Q_SIMULATION_ADVANCEMENT_OPTIONS_H
