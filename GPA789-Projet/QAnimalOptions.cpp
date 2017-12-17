#include "QAnimalOptions.h"

QAnimalOptions::QAnimalOptions(QWidget *parent)
	: QWidget(parent)
{

}

QAnimalOptions::QAnimalOptions(QString animalName, int minNumbAnimals, int maxNumbAnimals, int numbAnimalsInit)
{
	// Définir le nom du slider
	mAnimalLabel = new QLabel(animalName);

	// Créer le slider
	mAnimalSlider = new QSlider(Qt::Horizontal);
	mAnimalSlider->setMinimum(minNumbAnimals);
	mAnimalSlider->setMaximum(maxNumbAnimals);
	mAnimalSlider->setSliderPosition(numbAnimalsInit);

	// Afficher la valeur initiale du slider
	mAnimalValue = new QLabel(QString::number(numbAnimalsInit));

	// Assemblage
	mAnimalOptionsGridLayout = new QGridLayout;
	mAnimalOptionsGridLayout->setContentsMargins(QMargins(0, 0, 0, 0));
	mAnimalOptionsGridLayout->addWidget(mAnimalLabel, 0, 0);
	mAnimalOptionsGridLayout->addWidget(mAnimalSlider, 0, 1);
	mAnimalOptionsGridLayout->addWidget(mAnimalValue, 0, 2);

	// Connection du slider au label d'affichage
	connect(mAnimalSlider, &QSlider::valueChanged, this, &QAnimalOptions::updateValues);

	setLayout(mAnimalOptionsGridLayout);
}

QAnimalOptions::~QAnimalOptions()
{

}

void QAnimalOptions::updateValues()
{
	mAnimalValue->setText(QString::number(mAnimalSlider->value()));
}


int QAnimalOptions::getValue()
{
	return mAnimalSlider->value();
}