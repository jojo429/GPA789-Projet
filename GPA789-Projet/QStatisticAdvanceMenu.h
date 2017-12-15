#pragma once

#include <QWidget>
#include <QLabel>

class QStatisticAdvanceMenu : public QWidget
{
	Q_OBJECT

public:
	QStatisticAdvanceMenu(bool setMean, bool setStandardDeviation, bool setMinMax, QWidget *parent = Q_NULLPTR);
	~QStatisticAdvanceMenu();

	void setNewValue(int count, qreal value);
	qreal getMean();
	qreal getStandardDeviation();
	qreal getMaxValues();

private:
	void calculateStandardDeviation();
	void cauculateMean();
	void calculateMinMaxValues();

	qreal mActualValue;
	qreal mMean;
	qreal mMinValue;
	qreal mMaxValue;
	qreal mStandardDeviation;

	bool mMeanOption; 
	bool mStandardDeviationOption; 
	bool mMinMaxOption;

	QLabel * mActualValueLabel;
	QLabel * mActualValueValue;
	QLabel * mMeanValueLabel;
	QLabel * mMeanValueValue;
	QLabel * mStandardDeviationValueLabel;
	QLabel * mStandardDeviationValueValue;
	QLabel * mMinValueLabel;
	QLabel * mMinValueValue;
	QLabel * mMaxValueLabel;
	QLabel * mMaxValueValue;

};
