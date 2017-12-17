// QCyclicOptions.cpp
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

#include "QCyclicOptions.h"

QCyclicOptions::QCyclicOptions(QWidget *parent)
	: QWidget(parent)
{

}

QCyclicOptions::QCyclicOptions(QString caption, QString iconName, QString averageName,
	QString variationName, QString cycleName, int averageMin, int averageMax, int variationMin, 
	int variationMax, int cycleMin, int cycleMax, bool enableAverage, bool enableVariation, 
	bool enableCycle, int averageInitValue, int variationInitValue, int cycleInitValue)
{
	//Définir le label pour l'affichage
	mCaption = caption;

	//Mettre l'icône à la bonne taille
	mIcon = QPixmap(iconName);
	QPixmap mTmpPixmap = mIcon.scaled(QSize(50, 50), Qt::KeepAspectRatio);

	//Afficher l'icône
	mIconLabel = new QLabel;
	mIconLabel->setPixmap(mTmpPixmap);

	//Définition du minimum et du maximum du slider moyenne
	mAverageSlider = new QSlider(Qt::Horizontal);
	this->defineSlider(mAverageSlider, averageMin, averageMax, averageInitValue);

	//Définition du minimum et du maximum du slider variation
	mVariationSlider = new QSlider(Qt::Horizontal);
	this->defineSlider(mVariationSlider, variationMin, variationMax, variationInitValue);

	//Définition du minimum et du maximum du slider cycle
	mCycleSlider = new QSlider(Qt::Horizontal);
	this->defineSlider(mCycleSlider, cycleMin, cycleMax, cycleInitValue);

	//Déclaration des étiquettes de slider
	mAverageLabel = new QLabel(averageName);
	mVariationLabel = new QLabel(variationName);
	mCycleLabel = new QLabel(cycleName);

	//Declaration de la valeur des étiquettes
	mAverageValue = new QLabel(QString::number(averageInitValue));
	mVariationValue = new QLabel(QString::number(variationInitValue));
	mCycleValue = new QLabel(QString::number(cycleInitValue));

	//Affichage des slider voulus
	mCyclicOptionsGridLayout = new QGridLayout;
	if (enableAverage) {
		mCyclicOptionsGridLayout->addWidget(mAverageLabel, 0, 0);
		mCyclicOptionsGridLayout->addWidget(mAverageSlider, 0, 1);
		mCyclicOptionsGridLayout->addWidget(mAverageValue, 0, 2);
	}

	if (enableVariation) {
		mCyclicOptionsGridLayout->addWidget(mVariationLabel, 1, 0);
		mCyclicOptionsGridLayout->addWidget(mVariationSlider, 1, 1);
		mCyclicOptionsGridLayout->addWidget(mVariationValue, 1, 2);
	}
	
	if (enableCycle) {
		mCyclicOptionsGridLayout->addWidget(mCycleLabel, 2, 0);
		mCyclicOptionsGridLayout->addWidget(mCycleSlider, 2, 1);
		mCyclicOptionsGridLayout->addWidget(mCycleValue, 2, 2);
	}

	// Assemblage
	mCyclicOptionsGroupBox = new QGroupBox(caption);
	mCyclicOptionsGroupBox->setLayout(mCyclicOptionsGridLayout);
	mLayout = new QHBoxLayout;
	mLayout->addWidget(mIconLabel);
	mLayout->addWidget(mCyclicOptionsGroupBox);

	//Connection entre les sliders
	if (enableAverage) {
		connect(mAverageSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	}

	if (enableVariation) {
		connect(mVariationSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	}

	if (enableCycle) {
		connect(mCycleSlider, &QSlider::valueChanged, this, &QCyclicOptions::cycleValueStep);
		connect(mCycleSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	}
	
	//Show layout
	setLayout(mLayout);
}

void QCyclicOptions::defineSlider(QSlider *slider, int min, int max, int initValue)
{
	// Définition des valeurs minimum, maximum, de la position et de la valeur du slider
	slider->setMinimum(min);
	slider->setMaximum(max);
	slider->setSliderPosition(initValue);
	slider->setValue(initValue);
}

void QCyclicOptions::updateValues()
{
	//Mise à jour des étiquettes du slider
	mAverageValue->setText(QString::number(mAverageSlider->value()));
	mVariationValue->setText(QString::number(mVariationSlider->value()));
	mCycleValue->setText(QString::number(mCycleSlider->value()));
}

void QCyclicOptions::cycleValueStep()
{
	// Choisis une valeur prédéterminée en fonction de la valeur choisie. 
	// Les valeurs gardées sont celles qui font un cycle complet sur 2190
	if (mCycleSlider->value() >= 0 && mCycleSlider->value() <= 50) {
		mCycleSlider->setSliderPosition(30);
		mCycleSlider->setValue(30);
	}
	else if (mCycleSlider->value() > 50 && mCycleSlider->value() <= 200) {
		mCycleSlider->setSliderPosition(73);
		mCycleSlider->setValue(73);
	}
	else if (mCycleSlider->value() > 200 && mCycleSlider->value() <= 500) {
		mCycleSlider->setSliderPosition(365);
		mCycleSlider->setValue(365);
	}
	else if (mCycleSlider->value() > 500 && mCycleSlider->value() <= 900) {
		mCycleSlider->setSliderPosition(730);
		mCycleSlider->setValue(730);
	}
	else if (mCycleSlider->value() > 900 && mCycleSlider->value() <= 1500) {
		mCycleSlider->setSliderPosition(1095);
		mCycleSlider->setValue(1095);
	}
	else {
		mCycleSlider->setSliderPosition(2190);
		mCycleSlider->setValue(2190);
	}
}

// Les trois fonction suivantes retournent les valeurs des slider de moyenne, de cycle et de vatiation
int QCyclicOptions::getAverageValue()
{
	return mAverageSlider->value();
}

int QCyclicOptions::getCycleValue()
{
	return mCycleSlider->value();
}

int QCyclicOptions::getVariationValue()
{
	return mVariationSlider->value();
}