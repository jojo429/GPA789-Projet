#include "QCyclicOptions.h"

QCyclicOptions::QCyclicOptions(QWidget *parent)
	: QWidget(parent)
{

}

QCyclicOptions::QCyclicOptions(QString name, QString iconName, int averageMin, int averageMax,
	int variationMin, int variationMax, int cycleMin, int cycleMax)
{
	mIcon = QPixmap(iconName);
	QPixmap mTmpPixmap = mIcon.scaled(QSize(50, 50), Qt::KeepAspectRatio);

	mAverageSlider = new QSlider(Qt::Horizontal);
	mAverageSlider->setMinimum(averageMin);
	mAverageSlider->setMaximum(averageMax);

	mVariationSlider = new QSlider(Qt::Horizontal);
	mVariationSlider->setMinimum(variationMin);
	mVariationSlider->setMaximum(variationMax);

	mCycleSlider = new QSlider(Qt::Horizontal);
	mCycleSlider->setMinimum(cycleMin);
	mCycleSlider->setMaximum(cycleMax);

	mAverageLabel = new QLabel("Average");
	mVariationLabel = new QLabel("Variation");
	mCycleLabel = new QLabel("Cycle");

	mIconLabel = new QLabel;
	mIconLabel->setPixmap(mTmpPixmap);

	mCyclicOptionsGridLayout = new QGridLayout;
	mCyclicOptionsGridLayout->addWidget(mAverageLabel, 0, 0);
	mCyclicOptionsGridLayout->addWidget(mAverageSlider, 0, 1);
	mCyclicOptionsGridLayout->addWidget(mVariationLabel, 1, 0);
	mCyclicOptionsGridLayout->addWidget(mVariationSlider, 1, 1);
	mCyclicOptionsGridLayout->addWidget(mCycleLabel, 2, 0);
	mCyclicOptionsGridLayout->addWidget(mCycleSlider, 2, 1);

	mCyclicOptionsGroupBox = new QGroupBox(name);
	mCyclicOptionsGroupBox->setLayout(mCyclicOptionsGridLayout);

	mLayout = new QHBoxLayout;
	mLayout->addStretch();
	mLayout->addWidget(mIconLabel);
	mLayout->addWidget(mCyclicOptionsGroupBox);
	mLayout->addStretch();

	setLayout(mLayout);
}

QCyclicOptions::~QCyclicOptions()
{

}
