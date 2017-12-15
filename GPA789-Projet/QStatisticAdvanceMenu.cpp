#include "QStatisticAdvanceMenu.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

QStatisticAdvanceMenu::QStatisticAdvanceMenu(bool meanOption, bool standardDeviationOption, bool minMaxOption, QWidget *parent)
	: QWidget(parent), mMeanOption{ meanOption }, mStandardDeviationOption{ standardDeviationOption }, mMinMaxOption{ minMaxOption }
{

	QVBoxLayout * mainLayout = new QVBoxLayout;

	mActualValueLabel = new QLabel("Actual Value :");
	mActualValueValue = new QLabel(QString::number(mActualValue));
	
	QHBoxLayout * actualValueLayout = new QHBoxLayout;
	actualValueLayout->addWidget(mActualValueLabel);
	actualValueLayout->addWidget(mActualValueValue);
	
	mainLayout->addLayout(actualValueLayout);

	if (meanOption) {
		mMeanValueLabel = new QLabel("Mean :");
		mMeanValueValue = new QLabel(QString::number(mMean));
		
		QHBoxLayout * meanValueLayout = new QHBoxLayout;
		meanValueLayout->addWidget(mMeanValueLabel);
		meanValueLayout->addWidget(mMeanValueValue);
		
		mainLayout->addLayout(meanValueLayout);
	}

	if (standardDeviationOption) {
		mStandardDeviationValueLabel = new QLabel("Standard deviation :");
		mStandardDeviationValueValue = new QLabel(QString::number(mStandardDeviation));

		QHBoxLayout * standardDeviationValueLayout = new QHBoxLayout;
		standardDeviationValueLayout->addWidget(mStandardDeviationValueLabel);
		standardDeviationValueLayout->addWidget(mStandardDeviationValueValue);

		mainLayout->addLayout(standardDeviationValueLayout);
	}

	if (minMaxOption) {
		mMinValueLabel = new QLabel("Minimum reached value :");
		mMinValueValue = new QLabel(QString::number(mMinValue));

		QHBoxLayout * minValueLayout = new QHBoxLayout;
		minValueLayout->addWidget(mMinValueLabel);
		minValueLayout->addWidget(mMinValueValue);

		mainLayout->addLayout(minValueLayout);

		mMaxValueLabel = new QLabel("Minimum reached value :");
		mMaxValueValue = new QLabel(QString::number(mMaxValue));

		QHBoxLayout * maxValueLayout = new QHBoxLayout;
		maxValueLayout->addWidget(mMinValueLabel);
		maxValueLayout->addWidget(mMinValueValue);

		mainLayout->addLayout(maxValueLayout);
	}

	
	mainLayout->addStretch();

	setLayout(mainLayout);
}

QStatisticAdvanceMenu::~QStatisticAdvanceMenu()
{
}

void QStatisticAdvanceMenu::setNewValue(int count, qreal value) {
	
	mActualValueValue->setText(QString::number(mActualValue));
	
	if (mMeanOption) {
		cauculateMean();
		mMeanValueValue->setText(QString::number(mMean));
	}
	if (mStandardDeviationOption) {
		calculateStandardDeviation();
		mStandardDeviationValueValue->setText(QString::number(mStandardDeviation));
	}
	if (mMinMaxOption) {
		calculateMinMaxValues(); 
			mMinValueValue->setText(QString::number(mMinValue));
			mMaxValueValue->setText(QString::number(mMaxValue));
	}
}

void QStatisticAdvanceMenu::cauculateMean() {

}

qreal QStatisticAdvanceMenu::getMean() {
	return 0.0;
}

void QStatisticAdvanceMenu::calculateStandardDeviation() {

}

qreal QStatisticAdvanceMenu::getStandardDeviation() {
	return 0.0;
}

void QStatisticAdvanceMenu::calculateMinMaxValues() {

}

qreal QStatisticAdvanceMenu::getMaxValues() {
	return 0.0;
}