// QCyclicOptions.h
//
// Description:
// Widget permetant de choisir les paramètres de simulation d'un facteur environmental cyclique.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_CYCLIC_OPTIONS_H
#define Q_CYCLIC_OPTIONS_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QGroupBox>

class QCyclicOptions : public QWidget
{
	Q_OBJECT

public:
	QCyclicOptions(QWidget *parent = Q_NULLPTR);
	QCyclicOptions(QString caption, QString iconName, QString averageName,
	QString variationName, QString cycleName, int averageMin, int averageMax,
	int variationMin, int variationMax, int cycleMin, int cycleMax,
	bool enableAverage, bool enableVariation, bool enableCycle,
	int averageInitValue, int variationInitValue, int cycleInitValue);
	~QCyclicOptions();

	void defineSlider(QSlider *slider, int min, int max, int initValue); // Définir le minimum, le maximum, la valeur initiale d'un slider
	int getAverageValue();
	int getCycleValue();
	int getVariationValue();

private:
	QString mCaption;
	QPixmap mIcon;
	QSlider *mAverageSlider;
	QSlider *mVariationSlider;
	QSlider *mCycleSlider;
	QLabel *mIconLabel;
	QLabel *mAverageLabel;
	QLabel *mVariationLabel;
	QLabel *mCycleLabel;
	QLabel *mAverageValue;
	QLabel *mVariationValue;
	QLabel *mCycleValue;
	QGridLayout *mCyclicOptionsGridLayout;
	QHBoxLayout *mLayout;
	QGroupBox *mCyclicOptionsGroupBox;

protected slots:
	void updateValues(); // Mise à jour de l'affichage des valeurs: average, variation, cycle
	void cycleValueStep(); // Définir des sauts pour le slider de cycle
};

#endif //Q_CYCLIC_OPTIONS_H
