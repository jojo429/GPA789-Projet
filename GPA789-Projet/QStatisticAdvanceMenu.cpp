// QStatisticAdvanceMenu.h
//
// Description:
// Widget gérant l'affichage des valeurs instantanées d'une statistique.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QStatisticAdvanceMenu.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSizePolicy>

QStatisticAdvanceMenu::QStatisticAdvanceMenu(bool meanOption, bool standardDeviationOption, bool minMaxOption, QString groupBoxName, QWidget *parent)
	: QWidget(parent), mMeanOption{ meanOption }, mStandardDeviationOption{ standardDeviationOption }, mMinMaxOption{ minMaxOption }
{
	QVBoxLayout * labelLayout = new QVBoxLayout;
	QVBoxLayout * valueLayout = new QVBoxLayout;

	mActualValueLabel = new QLabel("Actual Value :");
	mActualValueValue = new QLabel(QString::number(mActualValue));
	
	labelLayout->addWidget(mActualValueLabel);
	valueLayout->addWidget(mActualValueValue);

	if (meanOption) {
		mMeanValueLabel = new QLabel("Mean :");
		mMeanValueValue = new QLabel(QString::number(mMean));
		
		labelLayout->addWidget(mMeanValueLabel);
		valueLayout->addWidget(mMeanValueValue);
	}

	if (standardDeviationOption) {
		mStandardDeviationValueLabel = new QLabel("Standard deviation :");
		mStandardDeviationValueValue = new QLabel(QString::number(mStandardDeviation));

		labelLayout->addWidget(mStandardDeviationValueLabel);
		valueLayout->addWidget(mStandardDeviationValueValue);
	}

	if (minMaxOption) {
		mMinValueLabel = new QLabel("Minimum reached value :");
		mMinValueValue = new QLabel(QString::number(mMinValue));

		labelLayout->addWidget(mMinValueLabel);
		valueLayout->addWidget(mMinValueValue);

		mMaxValueLabel = new QLabel("Maximum reached value :");
		mMaxValueValue = new QLabel(QString::number(mMaxValue));

		labelLayout->addWidget(mMaxValueLabel);
		valueLayout->addWidget(mMaxValueValue);
	}

	QHBoxLayout * dataLayout = new QHBoxLayout;
	dataLayout->addLayout(labelLayout);
	dataLayout->addLayout(valueLayout);

	mVisibilityCheckBox = new QCheckBox("Show values on graph");

	QHBoxLayout * showDataLayout = new QHBoxLayout;
	showDataLayout->addWidget(mVisibilityCheckBox);

	QVBoxLayout * prepLayout = new QVBoxLayout;
	prepLayout->addLayout(dataLayout);
	prepLayout->addLayout(showDataLayout);

	QGroupBox * statisticGroupBox = new QGroupBox(groupBoxName);
	statisticGroupBox->setLayout(prepLayout);
	//statisticGroupBox->setFixedWidth(250);
	//statisticGroupBox->setFixedHeight(statisticGroupBox->sizeHint());
	statisticGroupBox->setFixedSize(statisticGroupBox->sizeHint());
	//statisticGroupBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);

	QVBoxLayout * mainLayout = new QVBoxLayout;
	mainLayout->addWidget(statisticGroupBox);
	mainLayout->setMargin(0);

	setLayout(mainLayout);

	connect(mVisibilityCheckBox, &QCheckBox::toggled, this, &QStatisticAdvanceMenu::showGraphToggled);
}

void QStatisticAdvanceMenu::setNewValue(int count, qreal value) {
	
	mActualValue = value;
	mActualValueValue->setText(QString::number(mActualValue));
	
	if (mMeanOption) {
		cauculateMean(count);
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

void QStatisticAdvanceMenu::cauculateMean(int count) {	
	if (count > 1) {
		mMean = (mMean * (count - 1) + mActualValue) / count;
	}
	else {
		mMean = mActualValue;
	}
}

void QStatisticAdvanceMenu::calculateStandardDeviation() {

}

void QStatisticAdvanceMenu::calculateMinMaxValues() {
	if (mInitMinMax) {
		mInitMinMax = false;
		mMinValue = mMaxValue = mActualValue;
	}
	else {
		if (mActualValue < mMinValue) { mMinValue = mActualValue; };
		if (mActualValue > mMaxValue) { mMaxValue = mActualValue; };
	}
}