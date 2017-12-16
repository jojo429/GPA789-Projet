#include "QEvolutionGraph.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <stdexcept>

using namespace std;

QEvolutionGraph::QEvolutionGraph(size_t nSeries, QWidget *parent)
	: QWidget(parent), mNSeries{ nSeries }
{
	//Trow une erreur si on indique qu'on a 0 série de données au graphique. 
	if (nSeries == 0) {
		throw invalid_argument("invalid argument at QEvolutionGraph::QEvolutionGraph : nSeries > 0");
	}

	//Déclaration des séries de données
	mDataSeries.resize(nSeries);
	for (auto & serie : mDataSeries) {
		serie = new QLineSeries;
	}
	//Déclaration des min max correxpondant à chaque courbe
	mYMaxEachSeries.resize(nSeries);
	mYMinEachSeries.resize(nSeries);

	mNbAdvanceInOneDay = 6;
	mNbAdvanceInOneWeek = mNbAdvanceInOneDay * 7;
	mNbAdvanceInOneMonth = mNbAdvanceInOneDay * 30;
	mNbAdvanceInOneYear = mNbAdvanceInOneDay * 365;
	mMaxNbData = mNbAdvanceInOneYear * 100;

	mChart = new QChart;
	mChart->setTitle("DefaultTitle");
	mChart->legend()->hide();
	mChart->setMinimumWidth(700);

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
	for (auto const & serie : mDataSeries) {
		mChart->addSeries(serie);
		serie->attachAxis(mXAxis);
		serie->attachAxis(mYAxis);
		serie->hide();
	}

	mXAxis->setRange(mXmin, mXmax);
	mYAxis->setRange(mYmin, mYmax);
	
	QVBoxLayout * chartLayout = new QVBoxLayout;
	chartLayout->addWidget(mChartView);

	QGroupBox * chartGroupBox = new QGroupBox("Evolution chart");
	chartGroupBox->setLayout(chartLayout);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addWidget(chartGroupBox);
	mainLayout->addWidget(initializeTimeScale());

	mainLayout->setMargin(0);

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

QWidget* QEvolutionGraph::initializeTimeScale() {
	
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

	QGroupBox * timeScaleGroupBox = new QGroupBox("Graphic time scale");
	timeScaleGroupBox->setLayout(layout);

	return timeScaleGroupBox;
}

void QEvolutionGraph::addPoint(size_t index, qreal t, qreal value) {

	*(mDataSeries[index]) << QPointF(t, value);

	//Mise à jour du minimum et du maximum pour la série de data spécifique 
	updateMinMaxValues(index, mDataSeries[index]->count()-1);

	if (mDataSeries[index]->count() > mMaxNbData) {
			mDataSeries[index]->remove(0);
	}
}

void QEvolutionGraph::updateMinMaxValues(size_t index, int count) {

	qreal y = mDataSeries[index]->at(count).y();

	if (y < mYMinEachSeries[index]) { mYMinEachSeries[index] = y; }
	if (y > mYMaxEachSeries[index]) { mYMaxEachSeries[index] = y; }
}

void QEvolutionGraph::updateAxis() {

	//Mise à jour de l'axe Y
	qreal yHiest{1};
	qreal yLowest{0};
	bool initVariables = true;
	for (int i{ 0 }; i < mNSeries; i++) {
		if (mDataSeries[i]->isVisible()) {
			if (initVariables) { 
				initVariables = false; 
				yLowest = mYMinEachSeries[i];
				yHiest = mYMaxEachSeries[i];
			}
			else {
				if (mYMinEachSeries[i] < yLowest) { yLowest = mYMinEachSeries[i]; }
				if (mYMaxEachSeries[i] > yHiest) { yHiest = mYMaxEachSeries[i]; }
			}
		}
	}

	bool yChanged{ false };
	if (mYmin != yLowest) { yChanged = true; mYmin = yLowest; }
	if (mYmax != yHiest) { yChanged = true; mYmax = yHiest; }
	if (mYmin == mYmax) { yChanged = true; mYmax = mYmin + 1; }
	if (yChanged) { mYAxis->setRange(mYmin, mYmax); }

	mXmax = mDataSeries[0]->at(mDataSeries[0]->count() - 1).x();

	//Mise à jour de l'axe X
	if (initVariables) {
		mXAxis->setRange(mXmin, 1);
	}
	else {
		if (mXmax < mNbDataVisible) { mXAxis->setRange(mXmin, mNbDataVisible); }
		else { mXAxis->setRange(mXmax - mNbDataVisible, mXmax); }
	}
}

void QEvolutionGraph::setDataSerieVisibility(int index, bool setVisible) {
	mDataSeries[index]->setVisible(setVisible);
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