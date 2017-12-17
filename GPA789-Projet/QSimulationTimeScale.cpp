// QSimulationTimeScale.cpp
//
// Description:
// Widget gérant l'affichage d'un slider de contrôle du temps.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QSimulationTimeScale.h"

QSimulationTimeScale::QSimulationTimeScale(QWidget *parent)
	: QWidget(parent)
{
}

QSimulationTimeScale::QSimulationTimeScale(QString caption, QString iconNameLow, QString iconNameHigh) 
{
	mIconLow = QPixmap(iconNameLow);
	mIconHigh = QPixmap(iconNameHigh);

	//Scale icon
	mIconLow = QPixmap(iconNameLow);
	QPixmap tmpPixmapLow = mIconLow.scaled(QSize(25, 25), Qt::KeepAspectRatio);
	mIconHigh = QPixmap(iconNameHigh);
	QPixmap tmpPixmapHigh = mIconHigh.scaled(QSize(25, 25), Qt::KeepAspectRatio);

	//Show icon
	mIconLabelLow = new QLabel;
	mIconLabelLow->setPixmap(tmpPixmapLow);
	mIconLabelHigh = new QLabel;
	mIconLabelHigh->setPixmap(tmpPixmapHigh);

	//Define slider
	mTimeScaleSlider = new QSlider(Qt::Horizontal);
	mTimeScaleSlider->setMinimum(1);
	mTimeScaleSlider->setMaximum(50);

	mSliderHLayout = new QHBoxLayout;
	mSliderHLayout->addWidget(mIconLabelLow);
	mSliderHLayout->addWidget(mTimeScaleSlider);
	mSliderHLayout->addWidget(mIconLabelHigh);
	
	mTimeScaleGroupBox = new QGroupBox(caption);
	mTimeScaleGroupBox->setLayout(mSliderHLayout);

	mLayout = new QHBoxLayout;
	mLayout->addWidget(mTimeScaleGroupBox);

	//Show layout
	setLayout(mLayout);
}

int QSimulationTimeScale::getValue()
{
	return mTimeScaleSlider->value();
}
