// QEvoluationGraph.cpp
//
// Description:
// Widget gérant les graphiques affichant les statistiques de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
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

	//Calcul du nombre d'advance correspondant à différente durée
	mNbAdvanceInOneDay = 6;
	mNbAdvanceInOneWeek = mNbAdvanceInOneDay * 7;
	mNbAdvanceInOneMonth = mNbAdvanceInOneDay * 30;
	mNbAdvanceInOneYear = mNbAdvanceInOneDay * 365;
	mMaxNbData = mNbAdvanceInOneYear * 100;

	//Création du graphique
	//Mettre un titre par défaut au graphique
	//Caché la légende du graphique
	//Ajuster la largeur minimal du graphique à 700 pixel.
	mChart = new QChart;
	mChart->setTitle("DefaultTitle");
	mChart->legend()->hide();
	mChart->setMinimumWidth(700);

	//Affichage du graphique avec Antialiasing
	mChartView = new QChartView(mChart);
	mChartView->setRenderHint(QPainter::Antialiasing);

	//Création d'un axe X et Y et assignation d'un titre par défaut
	mXAxis = new QValueAxis;
	mXAxis->setTitleText("DefaultX");
	mYAxis = new QValueAxis;
	mYAxis->setTitleText("DefaultY");

	//Positionnement des axes X et Y.
	mChart->addAxis(mXAxis, Qt::AlignBottom);
	mChart->addAxis(mYAxis, Qt::AlignLeft);

	//Association des série de données au graphique puis aux axes.
	//Les série de données sont caché par défaut
	for (auto const & serie : mDataSeries) {
		mChart->addSeries(serie);
		serie->attachAxis(mXAxis);
		serie->attachAxis(mYAxis);
		serie->hide();
	}

	//Définition de la plage de départ des axes X et Y
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
	//Ajout du choix de time scale à droite du graphique
	mainLayout->addWidget(initializeTimeScale());

	mainLayout->setMargin(0);

	setLayout(mainLayout);
}


void QEvolutionGraph::initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle) {
	//Définition du titre, et du nom des axes du graphiques
	mChart->setTitle(graphTitle);
	mXAxis->setTitleText(xAxisName);
	mYAxis->setTitleText(yAxisName);
}

QWidget* QEvolutionGraph::initializeTimeScale() {
	
	//Déclaration des échel de temps disponible pour l'affichage des données dans le graphique
	mScaleOneWeek = new QRadioButton("One Week");
	mScaleOneMonth = new QRadioButton("One Month");
	mScaleFiveMonths = new QRadioButton("Five Month");
	mScaleOneYear = new QRadioButton("One Year");
	mScaleTwoYears = new QRadioButton("Two Years");
	mScaleFiveYears = new QRadioButton("Five Years");
	mScaleTenYears = new QRadioButton("Ten Years");
	mScaleHundredYears = new QRadioButton("Hundred Years");

	//Mettre un ans comme échel de temps de départ
	mScaleOneYear->setChecked(true);
	setScaleOneYear();
	
	//Ajout des bouton permettant de choisir l'échel 
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

	//Conecter les boutons à sa fonction permettant de redéfinir l'échel de temps en fonction du bouton cliqué
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

	//Ajout du point à la série de data
	*(mDataSeries[index]) << QPointF(t, value);

	//Mise à jour du minimum et du maximum pour la série de data spécifique 
	updateMinMaxValues(index, mDataSeries[index]->count()-1);

	//Supression de la plus vieille donné si l'on dépasse le nombre de 
	//données maximal pouvant être affiché au graphique
	if (mDataSeries[index]->at(mDataSeries[index]->count()-1).x() > mMaxNbData) {
			mDataSeries[index]->remove(0);
	}
}

void QEvolutionGraph::updateMinMaxValues(size_t index, int count) {
	//Assigne la donnée la plus récente 
	qreal y = mDataSeries[index]->at(count).y();

	//Si la donnée est la plus petite de la série de donnée on l'assigne
	if (y < mYMinEachSeries[index]) { mYMinEachSeries[index] = y; }
	//Si la donnée est la plus grande de la série de donnée on l'assigne
	if (y > mYMaxEachSeries[index]) { mYMaxEachSeries[index] = y; }
}

void QEvolutionGraph::updateAxis() {

	//Mise à jour de l'axe Y
	qreal yHiest{1};
	qreal yLowest{0};

	//La valeur minimale et maximal doit être initialisé
	bool initVariables = true;
	//Mise à jour de l'axe y pour les séries de data visible
	for (int i{ 0 }; i < mNSeries; i++) {
		if (mDataSeries[i]->isVisible()) {
			//Initialisation de la valeur minimale et maximale
			if (initVariables) { 
				initVariables = false; 
				yLowest = mYMinEachSeries[i];
				yHiest = mYMaxEachSeries[i];
			}
			else {
				//Si la donnée est la plus petite parmis tout les série de data visibe, on l'assigne
				if (mYMinEachSeries[i] < yLowest) { yLowest = mYMinEachSeries[i]; }
				//Si la donnée est la plus grande parmis tout les série de data visibe, on l'assigne
				if (mYMaxEachSeries[i] > yHiest) { yHiest = mYMaxEachSeries[i]; }
			}
		}
	}
	//Mise à jour de l'axe Y si celle ci a changé par par rapport à l'update précédent des axes
	bool yChanged{ false };
	if (mYmin != yLowest) { yChanged = true; mYmin = yLowest; }
	if (mYmax != yHiest) { yChanged = true; mYmax = yHiest; }
	//Si la valeur minimale et maximal de l'axe y est la même on ajoute 1 de plus à Y max
	if (mYmin == mYmax) { yChanged = true; mYmax = mYmin + 1; }
	//Mise à jour de l'axe Y
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
	//Rend la série de données choisi visible ou invisible
	mDataSeries[index]->setVisible(setVisible);
}
//Les fonction ci-dessous permettent d'ajuster le nombre de données visible sur le graphique. 
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