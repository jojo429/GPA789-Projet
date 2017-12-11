#include "QCyclicOptions.h"

QCyclicOptions::QCyclicOptions(QWidget *parent)
	: QWidget(parent)
{

}

QCyclicOptions::QCyclicOptions(QString caption, QString iconName, QString averageName,
	QString variationName, QString cycleName, int averageMin, int averageMax, int variationMin, 
	int variationMax, int cycleMin, int cycleMax)
{
	//Define member caption
	mCaption = caption;

	//Scale icon
	mIcon = QPixmap(iconName);
	QPixmap mTmpPixmap = mIcon.scaled(QSize(50, 50), Qt::KeepAspectRatio);

	//Define minimum and maximum of average slider
	mAverageSlider = new QSlider(Qt::Horizontal);
	mAverageSlider->setMinimum(averageMin);
	mAverageSlider->setMaximum(averageMax);

	//Define minimum and maximum of variation slider
	mVariationSlider = new QSlider(Qt::Horizontal);
	mVariationSlider->setMinimum(variationMin);
	mVariationSlider->setMaximum(variationMax);

	//Define minimum and maximum of cycle slider
	mCycleSlider = new QSlider(Qt::Horizontal);
	mCycleSlider->setMinimum(cycleMin);
	mCycleSlider->setMaximum(cycleMax);

	//Declare sliders labels
	mAverageLabel = new QLabel(averageName);
	mVariationLabel = new QLabel(variationName);
	mCycleLabel = new QLabel(cycleName);

	//Declare sliders values labels
	mAverageValue = new QLabel("0");
	mVariationValue = new QLabel("0");
	if (mCaption == "Precipitation")
	{
		mCycleValue = new QLabel("Day");
	}
	else {
		mCycleValue = new QLabel("0");
	}

	//Show icon
	mIconLabel = new QLabel;
	mIconLabel->setPixmap(mTmpPixmap);

	//Define layout of cyclic options menu
	mCyclicOptionsGridLayout = new QGridLayout;
	mCyclicOptionsGridLayout->addWidget(mAverageLabel, 0, 0);
	mCyclicOptionsGridLayout->addWidget(mAverageSlider, 0, 1);
	mCyclicOptionsGridLayout->addWidget(mAverageValue, 0, 2);
	mCyclicOptionsGridLayout->addWidget(mVariationLabel, 1, 0);
	mCyclicOptionsGridLayout->addWidget(mVariationSlider, 1, 1);
	mCyclicOptionsGridLayout->addWidget(mVariationValue, 1, 2);
	mCyclicOptionsGridLayout->addWidget(mCycleLabel, 2, 0);
	mCyclicOptionsGridLayout->addWidget(mCycleSlider, 2, 1);
	mCyclicOptionsGridLayout->addWidget(mCycleValue, 2, 2);

	mCyclicOptionsGroupBox = new QGroupBox(caption);
	mCyclicOptionsGroupBox->setLayout(mCyclicOptionsGridLayout);

	mLayout = new QHBoxLayout;
	mLayout->addWidget(mIconLabel);
	mLayout->addWidget(mCyclicOptionsGroupBox);

	//Define sliders connections
	connect(mAverageSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	connect(mVariationSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);
	connect(mCycleSlider, &QSlider::valueChanged, this, &QCyclicOptions::updateValues);

	//Show layout
	setLayout(mLayout);
}

QCyclicOptions::~QCyclicOptions()
{

}

void QCyclicOptions::updateValues()
{

		mAverageValue->setText(QString::number(mAverageSlider->value()));;
		mVariationValue->setText(QString::number(mVariationSlider->value()));
		mCycleValue->setText(QString::number(mCycleSlider->value()));
	
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