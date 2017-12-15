#ifndef Q_EVOLUTION_GRAPH_H
#define Q_EVOLUTION_GRAPH_H

#include <QtWidgets>
#include <QtCharts>
using namespace QtCharts;

#include <QVector>

class QEvolutionGraph : public QWidget
{
	Q_OBJECT

public:
	QEvolutionGraph(size_t nSeries = 1, QWidget *parent = Q_NULLPTR);
	~QEvolutionGraph();

	void addPoint(size_t index, qreal t, qreal value);
	void initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle);
	void updateMinMaxValues(size_t index, int count);
	void updateAxis();

private:

	QChart * mChart;
	QChartView * mChartView;
	QVector<QLineSeries*> mDataSeries;
	QValueAxis * mXAxis;
	QValueAxis * mYAxis;
	qreal mXmin{ 0 }, mYmin{ 0 };
	qreal mXmax{ 1 }, mYmax{ 1 };
	qreal mX, mY;
	QVector<qreal> mYMaxEachSeries;
	QVector<qreal> mYMinEachSeries;
	size_t mNSeries;

	QWidget* initializeChooseScale();

	QRadioButton * mScaleOneHour;
	QRadioButton * mScaleOneWeek;
	QRadioButton * mScaleOneMonth;
	QRadioButton * mScaleFiveMonths;
	QRadioButton * mScaleOneYear;
	QRadioButton * mScaleTwoYears;
	QRadioButton * mScaleFiveYears;
	QRadioButton * mScaleTenYears;
	QRadioButton * mScaleHundredYears;

	int mMaxNbData;
	int mNbDataVisible;
	int mTimeScaler;
	int mNbAdvanceInOneDay;
	int mNbAdvanceInOneWeek;
	int mNbAdvanceInOneMonth;
	int mNbAdvanceInOneYear;

private slots:
	void setScaleOneWeek();
	void setScaleOneMonth();
	void setScaleFiveMonths();
	void setScaleOneYear();
	void setScaleTwoYears();
	void setScaleFiveYears();
	void setScaleTenYears();
	void setScaleHundredYears();

};

#endif