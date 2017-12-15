#include "QAnimalOptions.h"

QAnimalOptions::QAnimalOptions(QWidget *parent)
	: QWidget(parent)
{

}

QAnimalOptions::QAnimalOptions(QString animalName, int minNumbAnimals, int maxNumbAnimals, int numbAnimalsInit)
{
	mAnimalLabel = new QLabel(animalName);

	mAnimalSlider = new QSlider(Qt::Horizontal);
	mAnimalSlider->setMinimum(minNumbAnimals);
	mAnimalSlider->setMaximum(maxNumbAnimals);
	mAnimalSlider->setSliderPosition(numbAnimalsInit);

	mAnimalValue = new QLabel(QString::number(numbAnimalsInit));

	mAnimalOptionsGridLayout = new QGridLayout;
	mAnimalOptionsGridLayout->addWidget(mAnimalLabel, 0, 0);
	mAnimalOptionsGridLayout->addWidget(mAnimalSlider, 0, 1);
	mAnimalOptionsGridLayout->addWidget(mAnimalValue, 0, 2);

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