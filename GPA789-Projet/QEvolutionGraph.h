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

	void addPoint(QPointF pt2D);
	void initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle);

private:

	QChart * mChart;
	QChartView * mChartView;
	QLineSeries *mDataSerie;
	QValueAxis * mXAxis;
	QValueAxis * mYAxis;
	qreal mXmin, mXmax, mYmin, mYmax;

	QWidget* chooseScale();

	QRadioButton * mScaleOneHour;
	QRadioButton * mScaleOneWeek;
	QRadioButton * mScaleOneMonth;
	QRadioButton * mScaleFiveMonths;
	QRadioButton * mScaleOneYear;
	QRadioButton * mScaleTwoYears;
	QRadioButton * mScaleFiveYears;
	QRadioButton * mScaleTenYears;
	QRadioButton * mScaleUndredYears;

	long int mMaxNbData;
	long int mNbTicInOneHour;
	long int mNbTicInOneDay;
	long int mNbTicInOneWeek;
	long int mNbTicInOneMonth;
	long int mNbTicInOneYear;

private slots:
	void setScaleOneHour();
	void setScaleOneWeek();
	void setScaleOneMonth();
	void setScaleFiveMonths();
	void setScaleOneYear();
	void setScaleTwoYears();
	void setScaleFiveYears();
	void setScaleTenYears();
	void setScaleUndredYears();

};

#endif