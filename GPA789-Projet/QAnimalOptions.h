// QAnimalOptions.h
//
// Description:
// Widget Graphique permettant de choisir le nombre d'animal voulu.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_ANIMAL_OPTIONS_H
#define Q_ANIMAL_OPTIONS_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>

class QAnimalOptions : public QWidget
{
	Q_OBJECT

public:
	QAnimalOptions(QWidget *parent = Q_NULLPTR);
	QAnimalOptions(QString animalName, int minNumbAnimals, int maxNumbAnimals, int numbAnimalsInit);
	~QAnimalOptions()=default;

	int getValue();

private:
	QSlider *mAnimalSlider;
	QLabel *mAnimalLabel;
	QLabel *mAnimalValue;
	QGridLayout *mAnimalOptionsGridLayout;

protected slots:
	void updateValues(); // Mise à jour du label qui affiche la valeur du slider
};

#endif //Q_ANIMAL_OPTIONS_H
