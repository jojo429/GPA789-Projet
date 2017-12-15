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
	//Define member caption
	mCaption = caption;

	//Scale icon
	mIcon = QPixmap(iconName);
	QPixmap mTmpPixmap = mIcon.scaled(QSize(50, 50), Qt::KeepAspectRatio);

	//Show icon
	mIconLabel = new QLabel;
	mIconLabel->setPixmap(mTmpPixmap);

	//Define minimum and maximum of average slider
	mAverageSlider = new QSlider(Qt::Horizontal);
	this->defineSlider(mAverageSlider, averageMin, averageMax, averageInitValue);

	//Define minimum and maximum of variation slider
	mVariationSlider = new QSlider(Qt::Horizontal);
	this->defineSlider(mVariationSlider, variationMin, variationMax, variationInitValue);

	//Define minimum and maximum of cycle slider
	mCycleSlider = new QSlider(Qt::Horizontal);
	this->defineSlider(mCycleSlider, cycleMin, cycleMax, cycleInitValue);

	//Declare sliders labels
	mAverageLabel = new QLabel(averageName);
	mVariationLabel = new QLabel(variationName);
	mCycleLabel = new QLabel(cycleName);

	//Declare sliders initial labels
	mAverageValue = new QLabel(QString::number(averageInitValue));
	mVariationValue = new QLabel(QString::number(variationInitValue));
	mCycleValue = new QLabel(QString::number(cycleInitValue));

	//Define layout of cyclic options menu
	mCyclicOptionsGridLayout = new QGridLayout;
	if (enableAverage == true) {
		mCyclicOptionsGridLayout->addWidget(mAverageLabel, 0, 0);
		mCyclicOptionsGridLayout->addWidget(mAverageSlider, 0, 1);
		mCyclicOptionsGridLayout->addWidget(mAverageValue, 0, 2);
	}

	if (enableVariation == true) {
		mCyclicOptionsGridLayout->addWidget(mVariationLabel, 1, 0);
		mCyclicOptionsGridLayout->addWidget(mVariationSlider, 1, 1);
		mCyclicOptionsGridLayout->addWidget(mVariationValue, 1, 2);
	}
	
	if (enableCycle == true) {
		mCyclicOptionsGridLayout->addWidget(mCycleLabel, 2, 0);
		mCyclicOptionsGridLayout->addWidget(mCycleSlider, 2, 1);
		mCyclicOptionsGridLayout->addWidget(mCycleValue, 2, 2);
	}

	mCyclicOptionsGroupBox = new QGroupBox(caption);
	mCyclicOptionsGroupBox->setLayout(mCyclicOptionsGridLayout);

	mLayout = new QHBoxLayout;
	mLayout->addWidget(mIconLabel);
	mLayout->addWidget(mCyclicOptionsGroupBox);

	//Define sliders connections
	if (enableAverage == true) {
		connect(mAverageSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	}

	if (enableVariation == true) {
		connect(mVariationSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	}

	if (enableCycle == true) {
		connect(mCycleSlider, &QSlider::valueChanged, this, &QCyclicOptions::cycleValueStep);
		connect(mCycleSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	}
	
	//Show layout
	setLayout(mLayout);
}

QCyclicOptions::~QCyclicOptions()
{

}

void QCyclicOptions::defineSlider(QSlider *slider, int min, int max, int initValue)
{
	slider->setMinimum(min);
	slider->setMaximum(max);
	slider->setSliderPosition(initValue);
	slider->setValue(initValue);
}

void QCyclicOptions::updateValues()
{
	mAverageValue->setText(QString::number(mAverageSlider->value()));;
	mVariationValue->setText(QString::number(mVariationSlider->value()));
	mCycleValue->setText(QString::number(mCycleSlider->value()));
}

void QCyclicOptions::cycleValueStep()
{
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