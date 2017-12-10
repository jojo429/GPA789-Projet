#include "QEvolutionGraph.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

QEvolutionGraph::QEvolutionGraph(QWidget *parent)
	: QWidget(parent)
{

	mNbTicInOneHour = 30 * 60;
	mNbTicInOneDay = mNbTicInOneHour * 24;
	mNbTicInOneWeek = mNbTicInOneDay * 7;
	mNbTicInOneMonth = mNbTicInOneWeek * 31;
	mNbTicInOneYear = mNbTicInOneMonth * 12;

	mChart = new QChart;
	mChart->setTitle("DefaultTitle");
	mChart->legend()->hide();

	mChartView = new QChartView(mChart);
	mChartView->setRenderHint(QPainter::Antialiasing);

	mXAxis = new QValueAxis;
	mXAxis->setTitleText("DefaultX");
	mYAxis = new QValueAxis;
	mYAxis->setTitleText("DefaultY");

	//Introduire les axes X et Y
	mChart->addAxis(mXAxis, Qt::AlignBottom); 
	mChart->addAxis(mYAxis, Qt::AlignLeft);

	//Déclaration de la série de données
	mDataSerie = new QLineSeries;
	mChart->addSeries(mDataSerie);
	mDataSerie->attachAxis(mXAxis);
	mDataSerie->attachAxis(mYAxis);

	

	connect(mDataSerie, &QLineSeries::pointAdded, [this](int index) {

		if (index == 0) {
			mXmin = mXmax = mDataSerie->at(index).x();
			mYmin = mYmax = mDataSerie->at(index).y();
			mXAxis->setRange(mXmin, mXmax);
			mYAxis->setRange(mYmin, mXmax);
		}
		else {
			qreal x = mDataSerie->at(index).x();
			qreal y = mDataSerie->at(index).y();
			bool xChanged{ false };
			bool yChanged{ false };
			if (x < mXmin) { xChanged = true; mXmin = x; }
			if (x > mXmax) { xChanged = true; mXmax = x; }
			if (y < mYmin) { yChanged = true; mYmin = y; }
			if (y > mYmax) { yChanged = true; mYmax = y; }
			if (xChanged) { mXAxis->setRange(mXmin, mXmax); }
			if (yChanged) { mYAxis->setRange(mYmin, mYmax); }
		}

		if (mDataSerie->count() > mMaxNbData) {
			mDataSerie->remove(0);
		}
	});

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addWidget(mChartView);
	mainLayout->addWidget(chooseScale());

	setLayout(mainLayout);
}

QEvolutionGraph::~QEvolutionGraph()
{
}

void QEvolutionGraph::initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle) {
	mChart->setTitle(graphTitle);
	mXAxis->setTitleText(xAxisName);
	mYAxis->setTitleText(yAxisName);
}

QWidget* QEvolutionGraph::chooseScale() {
	
	mScaleOneHour = new QRadioButton("One Hour");
	mScaleOneWeek = new QRadioButton("One Week");
	mScaleOneMonth = new QRadioButton("One Month");
	mScaleFiveMonths = new QRadioButton("Five Month");
	mScaleOneYear = new QRadioButton("One Year");
	mScaleTwoYears = new QRadioButton("Two Years");
	mScaleFiveYears = new QRadioButton("Five Years");
	mScaleTenYears = new QRadioButton("Ten Years");
	mScaleUndredYears = new QRadioButton("Undred Years");

	mScaleOneYear->setChecked(true);
	setScaleOneYear();
	
	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(mScaleOneHour);
	layout->addWidget(mScaleOneWeek);
	layout->addWidget(mScaleOneMonth);
	layout->addWidget(mScaleFiveMonths);
	layout->addWidget(mScaleOneYear);
	layout->addWidget(mScaleTwoYears);
	layout->addWidget(mScaleFiveYears);
	layout->addWidget(mScaleTenYears);
	layout->addWidget(mScaleUndredYears);

	connect(mScaleOneHour, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneHour);
	connect(mScaleOneWeek, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneWeek);
	connect(mScaleOneMonth, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneMonth);
	connect(mScaleFiveMonths, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleFiveMonths);
	connect(mScaleOneYear, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTwoYears);
	connect(mScaleTwoYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTwoYears);
	connect(mScaleFiveYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleFiveYears);
	connect(mScaleTenYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTenYears);
	connect(mScaleUndredYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleUndredYears);

	QWidget * widget = new QWidget;
	widget->setLayout(layout);

	return widget;
}
void QEvolutionGraph::addPoint(QPointF pt2D) {
	*mDataSerie << pt2D;
}

void QEvolutionGraph::setScaleOneHour()
{  
	while (mDataSerie->count() > mNbTicInOneHour) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneHour;
}

void QEvolutionGraph::setScaleOneWeek()
{
	while (mDataSerie->count() > mNbTicInOneWeek) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneWeek;
}
void QEvolutionGraph::setScaleOneMonth()
{
	while (mDataSerie->count() > mNbTicInOneMonth) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneMonth;
}
void QEvolutionGraph::setScaleFiveMonths()
{
	while (mDataSerie->count() > mNbTicInOneMonth*5) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneMonth*5;
}
void QEvolutionGraph::setScaleOneYear()
{
	while (mDataSerie->count() > mNbTicInOneYear) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneYear;
}
void QEvolutionGraph::setScaleTwoYears()
{
	while (mDataSerie->count() > mNbTicInOneYear * 2) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneYear * 2;
}
void QEvolutionGraph::setScaleFiveYears()
{
	while (mDataSerie->count() > mNbTicInOneYear * 5) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneYear * 5;
}
void QEvolutionGraph::setScaleTenYears()
{
	while (mDataSerie->count() > mNbTicInOneYear * 10) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneYear * 10;
}
void QEvolutionGraph::setScaleUndredYears()
{
	while (mDataSerie->count() > mNbTicInOneYear * 100) { mDataSerie->remove(0); }
	mMaxNbData = mNbTicInOneYear * 100;
}