#ifndef Q_EVOLUTION_GRAPH_H
#define Q_EVOLUTION_GRAPH_H

#include <QtWidgets>
#include <QtCharts>
using namespace QtCharts;

class QEvolutionGraph : public QWidget
{
	Q_OBJECT

public:
	QEvolutionGraph(QWidget *parent = Q_NULLPTR);
	~QEvolutionGraph();

	void addPoint(double value);
	void initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle);

private:

	QChart * mChart;
	QChartView * mChartView;
	QLineSeries *mDataSerie;
	QValueAxis * mXAxis;
	QValueAxis * mYAxis;
	qreal mXmin, mXmax, mYmin, mYmax;
	double mTime{ 0 };

	QWidget* chooseScale();

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