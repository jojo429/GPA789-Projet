// QEvoluationGraph.cpp
//
// Description:
// Widget g�rant les graphiques affichant les statistiques de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QEvolutionGraph.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <stdexcept>

using namespace std;

QEvolutionGraph::QEvolutionGraph(size_t nSeries, QWidget *parent)
	: QWidget(parent), mNSeries{ nSeries }
{
	//Trow une erreur si on indique qu'on a 0 s�rie de donn�es au graphique. 
	if (nSeries == 0) {
		throw invalid_argument("invalid argument at QEvolutionGraph::QEvolutionGraph : nSeries > 0");
	}

	//D�claration des s�ries de donn�es
	mDataSeries.resize(nSeries);
	for (auto & serie : mDataSeries) {
		serie = new QLineSeries;
	}
	//D�claration des min max correxpondant � chaque courbe
	mYMaxEachSeries.resize(nSeries);
	mYMinEachSeries.resize(nSeries);

	//Calcul du nombre d'advance correspondant � diff�rente dur�e
	mNbAdvanceInOneDay = 6;
	mNbAdvanceInOneWeek = mNbAdvanceInOneDay * 7;
	mNbAdvanceInOneMonth = mNbAdvanceInOneDay * 30;
	mNbAdvanceInOneYear = mNbAdvanceInOneDay * 365;
	mMaxNbData = mNbAdvanceInOneYear * 100;

	//Cr�ation du graphique
	//Mettre un titre par d�faut au graphique
	//Cach� la l�gende du graphique
	//Ajuster la largeur minimal du graphique � 700 pixel.
	mChart = new QChart;
	mChart->setTitle("DefaultTitle");
	mChart->legend()->hide();
	mChart->setMinimumWidth(700);

	//Affichage du graphique avec Antialiasing
	mChartView = new QChartView(mChart);
	mChartView->setRenderHint(QPainter::Antialiasing);

	//Cr�ation d'un axe X et Y et assignation d'un titre par d�faut
	mXAxis = new QValueAxis;
	mXAxis->setTitleText("DefaultX");
	mYAxis = new QValueAxis;
	mYAxis->setTitleText("DefaultY");

	//Positionnement des axes X et Y.
	mChart->addAxis(mXAxis, Qt::AlignBottom);
	mChart->addAxis(mYAxis, Qt::AlignLeft);

	//Association des s�rie de donn�es au graphique puis aux axes.
	//Les s�rie de donn�es sont cach� par d�faut
	for (auto const & serie : mDataSeries) {
		mChart->addSeries(serie);
		serie->attachAxis(mXAxis);
		serie->attachAxis(mYAxis);
		serie->hide();
	}

	//D�finition de la plage de d�part des axes X et Y
	mXAxis->setRange(mXmin, mXmax);
	mYAxis->setRange(mYmin, mYmax);
	
	//Mettre le graphique dans un Layout pour son utilisation par des objets externes
	QVBoxLayout * chartLayout = new QVBoxLayout;
	chartLayout->addWidget(mChartView);

	QGroupBox * chartGroupBox = new QGroupBox("Evolution chart");
	chartGroupBox->setLayout(chartLayout);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	//Ajout du graphique au Layout principale
	mainLayout->addWidget(chartGroupBox);
	//Ajout du choix de time scale � droite du graphique
	mainLayout->addWidget(initializeTimeScale());

	mainLayout->setMargin(0);

	setLayout(mainLayout);
}


void QEvolutionGraph::initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle) {
	//D�finition du titre, et du nom des axes du graphiques
	mChart->setTitle(graphTitle);
	mXAxis->setTitleText(xAxisName);
	mYAxis->setTitleText(yAxisName);
}

QWidget* QEvolutionGraph::initializeTimeScale() {
	
	//D�claration des �chel de temps disponible pour l'affichage des donn�es dans le graphique
	mScaleOneWeek = new QRadioButton("One Week");
	mScaleOneMonth = new QRadioButton("One Month");
	mScaleFiveMonths = new QRadioButton("Five Month");
	mScaleOneYear = new QRadioButton("One Year");
	mScaleTwoYears = new QRadioButton("Two Years");
	mScaleFiveYears = new QRadioButton("Five Years");
	mScaleTenYears = new QRadioButton("Ten Years");
	mScaleHundredYears = new QRadioButton("Hundred Years");

	//Mettre un ans comme �chel de temps de d�part
	mScaleOneYear->setChecked(true);
	setScaleOneYear();
	
	//Ajout des bouton permettant de choisir l'�chel 
	//de temps dans un Layout vertical
	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(mScaleOneWeek);
	layout->addWidget(mScaleOneMonth);
	layout->addWidget(mScaleFiveMonths);
	layout->addWidget(mScaleOneYear);
	layout->addWidget(mScaleTwoYears);
	layout->addWidget(mScaleFiveYears);
	layout->addWidget(mScaleTenYears);
	layout->addWidget(mScaleHundredYears);

	//Conecter les boutons � sa fonction permettant de red�finir l'�chel de temps en fonction du bouton cliqu�
	connect(mScaleOneWeek, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneWeek);
	connect(mScaleOneMonth, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneMonth);
	connect(mScaleFiveMonths, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleFiveMonths);
	connect(mScaleOneYear, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleOneYear);
	connect(mScaleTwoYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTwoYears);
	connect(mScaleFiveYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleFiveYears);
	connect(mScaleTenYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleTenYears);
	connect(mScaleHundredYears, &QRadioButton::clicked, this, &QEvolutionGraph::setScaleHundredYears);

	//Ajout des bouton dans un Group box 
	QGroupBox * timeScaleGroupBox = new QGroupBox("Graphic time scale");
	timeScaleGroupBox->setLayout(layout);

	//Renvoie du groupBox 
	return timeScaleGroupBox;
}

void QEvolutionGraph::addPoint(size_t index, qreal t, qreal value) {

	//Ajout du point � la s�rie de data
	*(mDataSeries[index]) << QPointF(t, value);

	//Mise � jour du minimum et du maximum pour la s�rie de data sp�cifique 
	updateMinMaxValues(index, mDataSeries[index]->count()-1);

	//Supression de la plus vieille donn� si l'on d�passe le nombre de 
	//donn�es maximal pouvant �tre affich� au graphique
	if (mDataSeries[index]->at(mDataSeries[index]->count()-1).x() > mMaxNbData) {
			mDataSeries[index]->remove(0);
	}
}

void QEvolutionGraph::updateMinMaxValues(size_t index, int count) {
	//Assigne la donn�e la plus r�cente 
	qreal y = mDataSeries[index]->at(count).y();

	//Si la donn�e est la plus petite de la s�rie de donn�e on l'assigne
	if (y < mYMinEachSeries[index]) { mYMinEachSeries[index] = y; }
	//Si la donn�e est la plus grande de la s�rie de donn�e on l'assigne
	if (y > mYMaxEachSeries[index]) { mYMaxEachSeries[index] = y; }
}

void QEvolutionGraph::updateAxis() {

	//Mise � jour de l'axe Y
	qreal yHiest{1};
	qreal yLowest{0};

	//La valeur minimale et maximal doit �tre initialis�
	bool initVariables = true;
	//Mise � jour de l'axe y pour les s�ries de data visible
	for (int i{ 0 }; i < mNSeries; i++) {
		if (mDataSeries[i]->isVisible()) {
			//Initialisation de la valeur minimale et maximale
			if (initVariables) { 
				initVariables = false; 
				yLowest = mYMinEachSeries[i];
				yHiest = mYMaxEachSeries[i];
			}
			else {
				//Si la donn�e est la plus petite parmis tout les s�rie de data visibe, on l'assigne
				if (mYMinEachSeries[i] < yLowest) { yLowest = mYMinEachSeries[i]; }
				//Si la donn�e est la plus grande parmis tout les s�rie de data visibe, on l'assigne
				if (mYMaxEachSeries[i] > yHiest) { yHiest = mYMaxEachSeries[i]; }
			}
		}
	}
	//Mise � jour de l'axe Y si celle ci a chang� par par rapport � l'update pr�c�dent des axes
	bool yChanged{ false };
	if (mYmin != yLowest) { yChanged = true; mYmin = yLowest; }
	if (mYmax != yHiest) { yChanged = true; mYmax = yHiest; }
	//Si la valeur minimale et maximal de l'axe y est la m�me on ajoute 1 de plus � Y max
	if (mYmin == mYmax) { yChanged = true; mYmax = mYmin + 1; }
	//Mise � jour de l'axe Y
	if (yChanged) { mYAxis->setRange(mYmin, mYmax); }

	mXmax = mDataSeries[0]->at(mDataSeries[0]->count() - 1).x();

	//Mise � jour de l'axe X
	if (initVariables) {
		mXAxis->setRange(mXmin, 1);
	}
	else {
		if (mXmax < mNbDataVisible) { mXAxis->setRange(mXmin, mNbDataVisible); }
		else { mXAxis->setRange(mXmax - mNbDataVisible, mXmax); }
	}
}

void QEvolutionGraph::setDataSerieVisibility(int index, bool setVisible) {
	//Rend la s�rie de donn�es choisi visible ou invisible
	mDataSeries[index]->setVisible(setVisible);
}
//Les fonction ci-dessous permettent d'ajuster le nombre de donn�es visible sur le graphique. 
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