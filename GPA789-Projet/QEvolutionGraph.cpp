#include "QEvolutionGraph.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

QEvolutionGraph::QEvolutionGraph(QWidget *parent)
	: QWidget(parent)
{

	mNbAdvanceInOneDay = 6;
	mNbAdvanceInOneWeek = mNbAdvanceInOneDay * 7;
	mNbAdvanceInOneMonth = mNbAdvanceInOneDay * 30;
	mNbAdvanceInOneYear = mNbAdvanceInOneDay * 365;
	mMaxNbData = mNbAdvanceInOneYear * 100;

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
		static qreal offsetX{ 1 }; 
		static qreal offsetY{ 1 };
		if (index == 0) {
			mXmin = mXmax = mDataSerie->at(index).x();
			mYmin = mYmax = mDataSerie->at(index).y();
			mXAxis->setRange(mXmin, mNbDataVisible + offsetX);
			mYAxis->setRange(mYmin, mYmax + offsetY);
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
			if (xChanged)
			{ 
				if (mXmax < mNbDataVisible) { mXAxis->setRange(mXmin, mNbDataVisible + offsetX);}
				else { mXAxis->setRange(mXmax - mNbDataVisible, mXmax + offsetX);}
			}
			if (yChanged) { mYAxis->setRange(mYmin, mYmax + offsetY); }
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
	
	mScaleOneWeek = new QRadioButton("One Week");
	mScaleOneMonth = new QRadioButton("One Month");
	mScaleFiveMonths = new QRadioButton("Five Month");
	mScaleOneYear = new QRadioButton("One Year");
	mScaleTwoYears = new QRadioButton("Two Years");
	mScaleFiveYears = new QRadioButton("Five Years");
	mScaleTenYears = new QRadioButton("Ten Years");
	mScaleHundredYears = new QRadioButton("Hundred Years");

	mScaleOneYear->setChecked(true);
	setScaleOneYear();
	
	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(mScaleOneWeek);
	layout->addWidget(mScaleOneMonth);
	layout->addWidget(mScaleFiveMonths);
	layout->addWidget(mScaleOneYear);
	layout->addWidget(mScaleTwoYears);
	layout->addWidget(mScaleFiveYears);
	layout->addWidget(mScaleTenYears);
	layout->addWidget(mScaleHundredYears);

	connect(mScaleOneWeek, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneWeek);
	connect(mScaleOneMonth, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneMonth);
	connect(mScaleFiveMonths, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleFiveMonths);
	connect(mScaleOneYear, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneYear);
	connect(mScaleTwoYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTwoYears);
	connect(mScaleFiveYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleFiveYears);
	connect(mScaleTenYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTenYears);
	connect(mScaleHundredYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleHundredYears);

	QWidget * widget = new QWidget;
	widget->setLayout(layout);

	return widget;
}
void QEvolutionGraph::addPoint(double value) {
	*mDataSerie << QPointF(mTime, value);
	mTime++;
}

void QEvolutionGraph::setScaleOneWeek()
{
	mNbDataVisible = mNbAdvanceInOneWeek;
}
void QEvolutionGraph::setScaleOneMonth()
{
	mNbDataVisible = mNbAdvanceInOneMonth;
}
void QEvolutionGraph::setScaleFiveMonths()
{
	mNbDataVisible = mNbAdvanceInOneMonth*5;
}
void QEvolutionGraph::setScaleOneYear()
{
	mNbDataVisible = mNbAdvanceInOneYear;
}
void QEvolutionGraph::setScaleTwoYears()
{
	mNbDataVisible = mNbAdvanceInOneYear * 2;
}
void QEvolutionGraph::setScaleFiveYears()
{
	mNbDataVisible = mNbAdvanceInOneYear * 5;
}
void QEvolutionGraph::setScaleTenYears()
{
	mNbDataVisible = mNbAdvanceInOneYear * 10;
}
void QEvolutionGraph::setScaleHundredYears()
{
	mNbDataVisible = mNbAdvanceInOneYear * 100;
}