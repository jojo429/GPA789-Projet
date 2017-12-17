// QStatisticAdvanceMenu.h
//
// Description:
// Widget g�rant l'affichage des valeurs instantan�es d'une statistique.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_STATISTIC_ADVANCE_MENU_H
#define Q_STATISTIC_ADVANCE_MENU_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>


class QStatisticAdvanceMenu : public QWidget
{
	Q_OBJECT

public:
	QStatisticAdvanceMenu(bool setMean, bool setStandardDeviation, bool setMinMax, QString groupBoxName = "Default Name", QWidget *parent = Q_NULLPTR);
	~QStatisticAdvanceMenu();

	void setNewValue(int count, qreal value);

signals: 
	void showGraphToggled(bool toggled);

private:
	void calculateStandardDeviation();
	void cauculateMean(int count);
	void calculateMinMaxValues();
	qreal mActualValue;
	qreal mMean;
	qreal mMinValue;
	qreal mMaxValue;
	qreal mStandardDeviation;
	bool mMeanOption; 
	bool mStandardDeviationOption; 
	bool mMinMaxOption;
	bool mInitMinMax{true};
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
	QCheckBox * mVisibilityCheckBox;
};

#endif